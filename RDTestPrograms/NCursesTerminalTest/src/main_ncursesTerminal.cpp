#include "Includes.h"
#include "Contexts.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <sstream>
#include <ncurses.h>
#include "NTerminal.h"
#include "NWindow.h"
#include "SizerWidget.h"
#include "NShell.h"
#include "CommCommands.h"
#include "TabbedPanel.h"
#include "HexViewer.h"
#include <glib.h>

using namespace std;

#define MAXPENDING 10     // how many pending connections queue will hold

void LogMsgToTerminal(const string& msg);
void *RecvThread(void* t);



string GetIPFromStruct(struct sockaddr_storage* addr)
{
	socklen_t len;
	//struct sockaddr_storage addr;
	char ipstr[INET6_ADDRSTRLEN];
	int port;


	// deal with both IPv4 and IPv6:
	if (addr->ss_family == AF_INET) 
	{
		LogMsgToTerminal("net4");
		struct sockaddr_in *s = (struct sockaddr_in *)addr;
		port = ntohs(s->sin_port);
		inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
	} 
	else // AF_INET6
	{ 	
		LogMsgToTerminal("net6");	
		struct sockaddr_in6 *s = (struct sockaddr_in6 *)addr;
		port = ntohs(s->sin6_port);
		inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
	}

	stringstream ss;
	ss << ipstr << ":" << port;
	return ss.str();
}

int TTYSetInterfaceAttribs (int fd, int speed, int parity)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                //error_message ("error %d from tcgetattr", errno);
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                //error_message ("error %d from tcsetattr", errno);
                return -1;
        }
        return 0;
}

void TTYSetBlocking (int fd, int should_block)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                //error_message ("error %d from tggetattr", errno);
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        //if (tcsetattr (fd, TCSANOW, &tty) != 0)
               // error_message ("error %d setting term attributes", errno);
}

int GetPortFromStruct(struct sockaddr_storage* addr)
{
	//struct sockaddr_storage addr;
	int port;


	// deal with both IPv4 and IPv6:
	if (addr->ss_family == AF_INET) 
	{
		struct sockaddr_in *s = (struct sockaddr_in *)addr;
		port = ntohs(s->sin_port);
	} 
	else // AF_INET6
	{ 	
		struct sockaddr_in6 *s = (struct sockaddr_in6 *)addr;
		port = ntohs(s->sin6_port);
	}

	return port;
}


void *TTYRecvThread(void* t)
{
	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
 	while( ct->m_Running )
	{

		// enter the recv state
		int len = 100;
		char buff[100];
		int rv = 0;



		// only attempt to recieve if the socket fd is valid
		if( lct->m_Connected && ( lct->m_Sockfd >= 0 )  )
		{
	
			// check to see if there is a message pending to be sent
			if( lct->HasMessagePending() )
			{
				// get the top message and try to send it
				Message& msg = lct->GetNextMessage(false);

				// check to see if the msg is null
				if( msg.m_Len != 0 )
				{				
					size_t sent = write( lct->m_Sockfd, msg.m_Data + msg.m_Ptr, // the start pointer
									msg.m_Len - msg.m_Ptr); // the length if start pointer != 0
									 

					if( sent <= 0 )
					{
						// there was an error sending
						LogMsgToTerminal( _S("TTY SEND ERROR: ") + _S(strerror (errno)) );

						
					}
					else if( sent != msg.m_Len )
					{
						// update the pointer
						// since the entire thing wasnt sent
						msg.m_Ptr += sent;	
						LogMsgToTerminal("TTY PARTIAL PACKET SENT");
					}
					else
					{
						// fully sent, so lets pop it
						lct->GetNextMessage(true);
						LogMsgToTerminal("TTY PACKET SENT");
					}
				} 	
				
			}

			// always try to read
			rv = read(lct->m_Sockfd, buff, len);
		}
		else
		{
			rv = 0;
			// sleep to prevent constant loop
			// which could affect performance
			sleep(1);
			//LogMsgToTerminal("waiting");
			
		}

		if( rv == 0 )
		{
			// no data sent - timed out
		}	
		else if( rv < 0 )
		{
			// error
			LogMsgToTerminal(_S("TTY ERROR: ") + _S(strerror (errno)));
		}
		else // rv > 0 
		{
			// msg recieved
				
			// assume that the buffer has not been overrun
			Message msg;
			msg.m_Data = new char[rv];
			memcpy(msg.m_Data, buff, rv);
			msg.m_Len = rv;

			lct->AddToInbox(msg);

			LogMsgToTerminal("TTY NEW MESSAGE RCV");		

		}
	}

	pthread_exit(NULL);


}
void *TCPRecvThread(void* t)
{
	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
 	while( ct->m_Running )
	{
		// enter the recv state
		int len = 100;
		char buff[100];
		int rv = 0;

		

		// only attempt to recieve if the socket fd is valid
		if( lct->m_Connected && ( lct->m_Sockfd >= 0 )  )
		{
	
			// check to see if there is a message pending to be sent
			if( lct->HasMessagePending() )
			{
				// get the top message and try to send it
				Message& msg = lct->GetNextMessage(false);

				// check to see if the msg is null
				if( msg.m_Len != 0 )
				{				
					size_t sent = send( lct->m_Sockfd, msg.m_Data + msg.m_Ptr, // the start pointer
									msg.m_Len - msg.m_Ptr, // the length if start pointer != 0
									0 ); 

					if( sent <= 0 )
					{
						// there was an error sending
						LogMsgToTerminal( _S("TCP SEND ERROR: ") + _S(strerror (errno)) );

						
					}
					else if( sent != msg.m_Len )
					{
						// update the pointer
						// since the entire thing wasnt sent
						msg.m_Ptr += sent;	
						LogMsgToTerminal("TCP PARTIAL PACKET SENT");
					}
					else
					{
						// fully sent, so lets pop it
						lct->GetNextMessage(true);
						LogMsgToTerminal("TCP PACKET SENT");
					}
				} 	
				
			}

			// always try to recv
			rv = recv(lct->m_Sockfd, buff, len, 0);
		}
		else
		{
			rv = -1;
			// sleep to prevent constant loop
			// which could affect performance
			sleep(1);
			//LogMsgToTerminal("waiting");
			
		}

		if( rv == -1 )
		{
			// no data sent - timed out
		}
		else if( rv == 0 )
		{
			// connection was hungup
		
			
			// connection lost
			LogMsgToTerminal("TCP CONNECTION LOST");

			// lock the terminal mutex
			pthread_mutex_lock(&(ct->m_TerminalMutex));
			
			// close the fd
			close(lct->m_Sockfd);
			
			// set the fd to -1
			lct->m_Sockfd = -1;
			
			// set the status to disconnected
			lct->m_Connected = false;
			
			// unlock the mutex
			pthread_mutex_unlock(&(ct->m_TerminalMutex));

		}
		else if( rv < -1 )
		{
			// error
			LogMsgToTerminal(_S("TCP ERROR: ") + _S(strerror (errno)));
		}
		else // rv > 0 
		{
			// msg recieved
				
			// assume that the buffer has not been overrun
			Message msg;
			msg.m_Data = new char[rv];
			memcpy(msg.m_Data, buff, rv);
			msg.m_Len = rv;

			lct->AddToInbox(msg);

			LogMsgToTerminal("TCP NEW MESSAGE RCV");		

		}
		
	}

	pthread_exit(NULL);


}

void *InputThread(void* t)
{

	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
    	

	NWindow nwindow;
	NTerminal* nterminal = new NTerminal(&nwindow);
	nwindow.SetMutex(ct->m_TerminalMutex);
	nterminal->SetMutex(ct->m_TerminalMutex);
	SizerWidget* sizer = new SizerWidget(&nwindow, SizerWidget::DIR_VERT);
	HexViewer* hexView = new HexViewer(&nwindow, STYLE_BORDER);

	NShell::Get()->RegisterCommand("tcp", new TCPCmd() );
	NShell::Get()->RegisterCommand("tty", new TTYCmd() );

	nwindow.Init();
	sizer->Add(hexView);
	sizer->Add(nterminal, 1.5);
	
	nterminal->SetStyle(STYLE_BORDER);
	nwindow.SetSizer(sizer);
	nwindow.ForceResize();
	nterminal->OnFocus(IWidget::FOCUS_FWD);

	string testS = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla eu purus commodo, tincidunt leo ac, volutpat turpis. Nullam risus nunc, elementum et ultricies in, efficitur ac magna. Etiam maximus mi non ante tempus, sit amet porttitor massa rutrum. Aenean congue scelerisque odio sed rhoncus posueree scelerisque odio sed rhoncus posuere  .";
	//hexView->SetStream("testing one, two, three", 24);
	hexView->SetStream((char*)testS.c_str(), testS.length());
	hexView->SetLabel("Hex Viewer");
	nterminal->SetHistorySize(10);
        nterminal->SetStdoutSize(100);
        nterminal->SetStdoutDispSize(-1);
	nterminal->SetName("Terminal");
	nwindow.ForceRedraw();
	
    	string line;

	// variable to signal the main thread
	bool signalMain = false;


    	while( ct->m_Running )
    	{
		// set the signal to false
		signalMain = false;


		bool isExit = false;
		
		isExit = !nwindow.WaitForInput();
        	
		if( isExit )
        	{
			sleep(1);
			ct->m_Running = false;
	     		//cout << "exiting" << endl;
			LogMsgToTerminal("EXITING");
			nwindow.Inhibit();		
			// set the signal flag
			signalMain = true;
        	}

		
		
		// check to see if we need to signal the main thread
		if( signalMain )
		{
			// signal the main thread
			// lock the mutex
			pthread_mutex_lock(&(ct->m_PollMutex));
			// set the caller
			ct->m_Caller = lct->m_TID;
			
			// set the line as the msg
			lct->m_MSG = line;

			// send the signal
			pthread_cond_signal(&(ct->m_PollCondition));
			// unlock the mutex
			pthread_mutex_unlock(&(ct->m_PollMutex));


		}
    }

    nwindow.Shutdown();

    pthread_exit(NULL);

}





void LogMsgToTerminal(const string& msg)
{
	// lock the terminal mutex
	if( NTerminal::Get() != NULL )
		NTerminal::Get()->PrintToStdout(msg);

}

bool AttemptConnection(Context& ct, LocalContext* newCT)
{
	
	int sockfd = newCT->m_Sockfd;
	
	if( sockfd < 0 )
	{
		LogMsgToTerminal("NO SOCKET BOUND");
		return false; // no socket bound
	}

	// set the destination parameters - the IP is already set
	ct.m_Sa.sin_family = AF_INET; // Internet address family
	ct.m_Sa.sin_port = htons(ct.m_DPort); // Server port


	LogMsgToTerminal("ATTEMPTING TO CONNECT");

	
	if(  connect(sockfd, (struct sockaddr*) &(ct.m_Sa),sizeof(ct.m_Sa)) < 0 )
	{
	
		switch( errno )
		{
		case ETIMEDOUT:
			LogMsgToTerminal("CONNECTION TIMED OUT");
			break;
		case ENETUNREACH:
			LogMsgToTerminal("NETWORK UNREACHABLE");
			break;
		case EISCONN:
			LogMsgToTerminal("SOCKET ALREADY CONNECTED");
			break;
		case ECONNREFUSED:
			LogMsgToTerminal("CONNECTION REFUSED");
			break;
		case EADDRINUSE:
			LogMsgToTerminal("ADDRESS IN USE");
			break;
		default:
			LogMsgToTerminal("ERROR CONNECTING");
			break;
		}
		
	
		return false;
	}
	else
	{
		LogMsgToTerminal("SUCCESSFULL CONNECTION");
		newCT->m_Connected = true;
		return true;
	}
}


bool ConnectToServer(Context& ct, LocalContext* newCT, bool stop)
{
	newCT->m_Connected = false;

	// close the socket if it is currently open
	if( newCT->m_Sockfd != -1 )
	{
		close(newCT->m_Sockfd);
	}

	if( stop )
	{
		return true;
	}

	// some variables for sockets
	int sockfd;
	struct sockaddr_in saLoc;

	//Create a reliable, stream socket using TCP
	if( (sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 )
	{
		LogMsgToTerminal("ERROR CREATING SOCKET");
		
		newCT->m_Sockfd = -1;
		return false;
	}

	// Local
	int yes = 1;
	memset(&saLoc, 0, sizeof(struct sockaddr_in));
	saLoc.sin_family = AF_INET; // Internet address family
	saLoc.sin_port = htons(ct.m_SPort); // the local port
	saLoc.sin_addr.s_addr = inet_addr("127.0.0.1"); // the local IP Addr

	// let the kernel know we are willing to reuse the socket if still around
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
	// set the socket to non-blocking
	struct timeval timeout;
        timeout.tv_sec = 2;
       	timeout.tv_usec = 0;

        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));


/*
	if( bind(sockfd, (struct sockaddr *)&saLoc, sizeof(struct sockaddr)) < 0 )
	{
		LogMsgToTerminal("ERROR BINDING SOCKET");

		newCT->m_Sockfd = -1;
		close(sockfd);
		return false;
	}
*/
	newCT->m_Sockfd = sockfd;
		
	// return success
	return true;

}


int main( int argc, char* argv[])
{


	// create the context on the stack
	Context ct;

	// init the context
	ct.Init();

	// set the run state
	ct.m_Running = true;

	// create the input thread
	ct.m_InputThread = ct.MakeThread(InputThread);
	ct.m_InputThread->m_Type = LocalContext::T_INPUT;

	bool success = true;

		
	// create the TCP thread
	ct.m_TCPThread = ct.MakeThread(TCPRecvThread);	
	ct.m_TCPThread->m_Sockfd = -1;
	ct.m_TCPThread->m_Type = LocalContext::T_TCP;
	ct.m_TCPThread->m_Mutex = ct.m_TCPMutex;
/*
	// create the UDP thread
	ct.m_TCPThread = ct.MakeThread(RecvThread);	
	ct.m_TCPThread->m_Sockfd = -1;
	ct.m_TCPThread->m_Type = LocalContext::T_TCP;

*/
	// create the TTY thread
	ct.m_TTYThread = ct.MakeThread(TTYRecvThread);	
	ct.m_TTYThread->m_Sockfd = -1;
	ct.m_TTYThread->m_Type = LocalContext::T_TTY;
	ct.m_TTYThread->m_Mutex = ct.m_TTYMutex;

	LogMsgToTerminal("INITIALIZATION COMPLETE");


	// start the loop
	pthread_mutex_lock(&(ct.m_PollMutex));
	while( ct.m_Running )
	{
		// wait on the condition
		pthread_cond_wait(&(ct.m_PollCondition), &(ct.m_PollMutex));

		// access the thread context
		LocalContext* tLct = ct.FindThread( ct.m_Caller );

		if( tLct == NULL )
			continue; // no thread context...

		// do work
		stringstream ss;
		// check the caller
		if( ct.m_Caller == 1 )  // called from the input thread
		{
							
			// simple: broadcast the input thread string to the server
			// make sure we have a valid connection, and 
			// this was not an exit command
			if( success && ct.m_Running ) 				
			{
				// send the message
				//LogMsgToTerminal( tLct->m_MSG );
				//size_t sent = send( sockfd, tLct->m_MSG.c_str(), tLct->m_MSG.length(), 0 );
										
			}
			

		}
		else // called from recv thread
		{
			// the recv threads
			// simply log the message to the screen

			LogMsgToTerminal(tLct->m_MSG);
			
			
		}


	}
	
	pthread_mutex_unlock(&(ct.m_PollMutex));

	// clean up the socket
	if( (ct.m_TCPThread)->m_Sockfd >= 0 )
	{
		
		
		close((ct.m_TCPThread)->m_Sockfd);
		
	}	

	// destroy and join the threads
	ct.DestroyAllThreads();
		
	// shut down the context
	ct.Shutdown();

	return 0;
}
