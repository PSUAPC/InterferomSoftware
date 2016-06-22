#include "Includes.h"
#include "Contexts.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <sstream>
#include <ncurses.h>

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



void *RecvThread(void* t)
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
		if( lct->m_Sockfd >= 0 )
		{
			rv = recv(lct->m_Sockfd, buff, len, 0);
		}
		else
		{
			rv = -1;
			// sleep to prevent constant loop
			// which could affect performance
			sleep(1);
			LogMsgToTerminal("waiting");
			
		}

		if( rv == -1 )
		{
			// no data sent - timed out
		}
		else if( rv == 0 )
		{
			// connection lost
			//LogMsgToTerminal("CONNECTION LOST");

			// signal the main thread
			// lock the mutex
			pthread_mutex_lock(&(ct->m_PollMutex));
			// set the caller
			ct->m_Caller = lct->m_TID;

			stringstream ss;	
			ss << "Connection lost from: " << GetPortFromStruct( &(lct->m_Addr) );	
			lct->m_MSG = ss.str();
		
			// close the socket
			close( lct->m_Sockfd );

			lct->m_Sockfd = 0;
			
			// send the signal
			pthread_cond_signal(&(ct->m_PollCondition));
			// unlock the mutex
			pthread_mutex_unlock(&(ct->m_PollMutex));
			
			// set the thread as garbage
			ct->SetThreadAsGarbage(lct->m_TID);

			// break out of the loop
			break;
		}
		else if( rv < -1 )
		{
			// error
		}
		else // rv > 0 
		{
			// msg recieved
			
			// signal the main thread
			// lock the mutex
			pthread_mutex_lock(&(ct->m_PollMutex));
			// set the caller
			ct->m_Caller = lct->m_TID;
		
			// set the msg
			if( rv < len )
				buff[rv] = '\0';
			else
				buff[len - 1] = '\0';

			lct->m_MSG = string(buff);	

			// send the signal
			pthread_cond_signal(&(ct->m_PollCondition));
			// unlock the mutex
			pthread_mutex_unlock(&(ct->m_PollMutex));


		}
		
	}

    pthread_exit(NULL);


}

//string line;

void *InputThread(void* t)
{
    	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
    	string line;

	// variable to signal the main thread
	bool signalMain = false;

    	while( ct->m_Running )
    	{
		// set the signal to false
		signalMain = false;

        	std::getline (std::cin, line);
	

        	if( line.find("exit") != NOT_FOUND )
        	{
			ct->m_Running = false;
            		cout << "exiting" << endl;
			// set the signal flag
			signalMain = true;
        	}
		else if( line.length() >= 1 )
		{
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


    pthread_exit(NULL);

}





void LogMsgToTerminal(const string& msg)
{

    	// this code is for writing to the termianl, while maintaining the prompt
    	// \033[1A - move cursor one line up
    	// \r      - move cursor to the start of the line
    	// \033[K  - erase from cursor to the end of the line
    	const char preface[] = "\033[1A\r\033[K";
    	//const char preface[] = "\r\033[K";

	write(STDOUT_FILENO, preface, sizeof(preface) - 1);

    	fprintf(stdout, "%s\n", msg.c_str());
	fflush(stdout);

    	const char epilogue[] = "\033[K";
    	write(STDOUT_FILENO, epilogue, sizeof(epilogue) - 1 );
	
	// prompt string
    	//fprintf(stdout, " ");
    	fflush(stdout);

    	struct termios tc;
    	tcgetattr(STDOUT_FILENO, &tc);
    	const tcflag_t lflag = tc.c_lflag;
    	// disable echo of control characters
    	tc.c_lflag &= ~ECHOK;
    	tcsetattr(STDOUT_FILENO, TCSANOW, &tc);
    	// reprint input buffer
    	ioctl(STDOUT_FILENO, TIOCSTI, &tc.c_cc[VREPRINT]);
	
    	tc.c_lflag = lflag;
    	tcsetattr(STDOUT_FILENO, TCSANOW, &tc);



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

	if( connect(sockfd, (struct sockaddr*) &(ct.m_Sa),sizeof(ct.m_Sa)) < 0 )
	{
		LogMsgToTerminal("ERROR CONNECTING");
	
		return false;
	}
	else
	{
		LogMsgToTerminal("SUCCESSFULL CONNECTION");
		// set the socket to non-blocking
		// and create the recv thread
		struct timeval timeout;
        	timeout.tv_sec = 2;
       		timeout.tv_usec = 0;

                setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
                setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

		return true;
	}
}


bool ConnectToServer(Context& ct, LocalContext* newCT)
{
	// close the socket if it is currently open
	if( newCT->m_Sockfd != -1 )
	{
		close(newCT->m_Sockfd);
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

	if( bind(sockfd, (struct sockaddr *)&saLoc, sizeof(struct sockaddr)) < 0 )
	{
		LogMsgToTerminal("ERROR BINDING SOCKET");

		newCT->m_Sockfd = -1;
		close(sockfd);
		return false;
	}

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
	ct.MakeThread(InputThread);

	bool success = true;

		
	// create the recv thread
	ct.m_RecvThread = ct.MakeThread(RecvThread);	
	ct.m_RecvThread->m_Sockfd = -1;

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
				LogMsgToTerminal( tLct->m_MSG );
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
	if( (ct.m_RecvThread)->m_Sockfd >= 0 )
	{
		
		
		close((ct.m_RecvThread)->m_Sockfd);
		
	}	

	// destroy and join the threads
	ct.DestroyAllThreads();
		
	// shut down the context
	ct.Shutdown();

	return 0;
}
