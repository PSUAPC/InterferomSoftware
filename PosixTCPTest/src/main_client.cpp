#include "Includes.h"
#include "Contexts.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <sstream>

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

void *ListenThread(void* t)
{
	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;

	// create the socket for listening
	if ( (lct->m_Sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 )
	{
		LogMsgToTerminal("ERROR CREATING LISTEN SOCKET");
		pthread_exit(NULL);
		return NULL;	
	}

	// set non-blocking just in case
	int flags; 
	if ((flags = fcntl(lct->m_Sockfd, F_GETFL, 0)) < 0) 
	{
		LogMsgToTerminal("ERROR GETTING LISTEN SOCKET CTL"); 
	} 


	if (fcntl(lct->m_Sockfd, F_SETFL, flags | O_NONBLOCK) < 0) 
	{ 
		LogMsgToTerminal("ERROR SETTING LISTEN SOCKET CTL");
	}
	 	
	// bind the socket
	int yes = 1;
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(struct sockaddr_in));
	servAddr.sin_family = AF_INET; /* Internet address family */
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);/* Any incoming interface */
	servAddr.sin_port = htons(ct->m_DPort); /* Local port */
	
	// let the kernel know we are willing to reuse the socket if still around
	setsockopt(lct->m_Sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
	
	if (bind(lct->m_Sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
	{
		LogMsgToTerminal("ERROR BINDING LISTEN SOCKET");
		close(lct->m_Sockfd);
        pthread_exit(NULL);
        return NULL;

	}

	LogMsgToTerminal("SUCCESSFUL LISTEN SOCKET CREATED");
	
	// start listening
	if (listen(lct->m_Sockfd, MAXPENDING) < 0)
	{
		LogMsgToTerminal("ERROR LISTENING LISTEN SOCKET");
		close(lct->m_Sockfd);
		pthread_exit(NULL);
		return NULL;
	}

	LogMsgToTerminal("LISTENER WAITING FOR CONNECTIONS");


	// create the selection set
	fd_set active_fd_set, read_fd_set;
	// Initialize the set of active sockets.
	FD_ZERO (&active_fd_set);
	FD_SET (lct->m_Sockfd, &active_fd_set);
	
	// set the timeout
	struct timeval tv;
	// Wait up to one seconds.
    tv.tv_sec = 1;
	tv.tv_usec = 0;
	
	struct sockaddr_storage clntAddr;
	socklen_t clntLen = sizeof(clntAddr);
	int clntSock;
	
	// enter the main loop
	while( ct->m_Running )
	{

		// Block until input arrives on one or more active sockets.
		read_fd_set = active_fd_set;
		if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, &tv) < 0)
        {
			LogMsgToTerminal("LISTENER ERROR SELECTION");

			continue;
        }
		for (int i = 0; i < FD_SETSIZE; ++i)
		{
			if (FD_ISSET (i, &read_fd_set))
			{
				if (i == lct->m_Sockfd)
				{
					if ((clntSock=accept(lct->m_Sockfd,(struct sockaddr*)&clntAddr,&clntLen)) < 0)
					{
						LogMsgToTerminal("LISTENER ERROR ACCEPTING CONNECTION");
					}
					else
					{
						LogMsgToTerminal("LISTENER ACCEPTED CONNECTION");
						
						// now lets add the new socket
						LocalContext* newCT = ct->MakeThread(RecvThread);
						newCT->m_Sockfd = clntSock;
						//newCT->m_Addr = clntAddr; 


						stringstream ss;
						ss << "FROM: " << GetIPFromStruct(&clntAddr);
						LogMsgToTerminal(ss.str());
					}
				}
			}
		}
	}

	close(lct->m_Sockfd);
	pthread_exit(NULL);
}

void *RecvThread(void* t)
{
	
	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
 	while( ct->m_Running )
	{
	}
    pthread_exit(NULL);

}

void *InputThread(void* t)
{
    cout << "entry" << endl;
    LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
    string line;

	// variable to signal the main thread
	bool signalMain = false;

    while( ct->m_Running )
    {
		// set the signal to false
		signalMain = false;

		cout << "here" << endl;
        std::getline (std::cin, line);
		cout << "--" << line << endl;

        if( line.find("exit") != NOT_FOUND )
        {
			ct->m_Running = false;
            cout << "exiting" << endl;
			// set the signal flag
			signalMain = true;
        }


		// check to see if we need to signal the main thread
		if( signalMain )
		{
			// signal the main thread
			// lock the mutex
			pthread_mutex_lock(&(ct->m_PollMutex));
			pthread_cond_signal(&(ct->m_PollCondition));
			// unlock the mutex
			pthread_mutex_unlock(&(ct->m_PollMutex));


		}
    }


    pthread_exit(NULL);

}


bool GetInput(Context* ct, int argc, char* argv[])
{
    bool good = true;
    int mode = 0;
    char ip[100];
	strcpy(ip, "127.0.0.1");
    int dPort = 8000;
    int sPort = 8001;
    char opt;
    while( (opt = getopt(argc, argv, "ha:p:l:m:")) != NOT_FOUND )
    {
		switch( opt )
        {
        case 'h':
			cout << "help" << endl;
			cout << " Options:" << endl
				<< " -h help" << endl
				<< " -a ip address (destination)" << endl
				<< " -p destination port" << endl
				<< " -l local port" << endl
				<< " -m mode flag" << endl
				<< "   (1) server" << endl
				<< "   (2) client" << endl
				<< endl;
			// asked for help, do not gen data => no good
			good = false;
			break;
        case 'a':
			sscanf(optarg, "%s", ip);
			break;
        case 'p':
			sscanf(optarg, "%i", &dPort);
			break;
        case 'l':
			sscanf(optarg, "%i", &sPort);
			break;
        case 'm':
			sscanf(optarg, "%i", &mode);
			break;
        case '?':
			// something went wrong, no good
			good = false;
			switch(optopt)
			{
			case 'a':
			case 'p':
			case 'l':
			case 'm':
				cout << "Expected argument after -" << optopt << endl;
				break;
			default:
				cout << "Unknown flag" << endl;
			}
		}
    }

	if( !good )
	{
		// input failure
		return false;
	}

	// display the input information
	cout 	<< "-------------------" << endl
		<< "IP: " << ip << endl
		<< "dPort: " << dPort << endl
		<< "sPort: " << sPort << endl
		<< "mode: " << mode << endl
		<< "-------------------" << endl;

	if( (mode != 1) && (mode != 2) )
	{
		cout << "Please select a valid mode" << endl;
		return false; // invalid mode
	}

	// assign the basic state variables	
    ct->m_Mode = mode;
    ct->m_SPort = sPort;
    ct->m_DPort = dPort;
	
	// zero the addr mem
	memset(&(ct->m_Sa), 0, sizeof(struct sockaddr_in));

	// get the IP
	inet_pton(AF_INET, ip, &(ct->m_Sa.sin_addr)); // IPv4

	// good to go
 	return true;
}

void LogMsgToTerminal(const string& msg)
{

	// this code is for writing to the termianl, while maintaining the prompt
	// \033[1A - move cursor one line up
    // \r      - move cursor to the start of the line
    // \033[K  - erase from cursor to the end of the line
    const char preface[] = "\033[1A\r\033[K";
    write(STDOUT_FILENO, preface, sizeof(preface) - 1);

    fprintf(stderr, "%s\n", msg.c_str());
    fflush(stdout);

    const char epilogue[] = "\033[K";
    write(STDOUT_FILENO, epilogue, sizeof(epilogue) - 1);
	
	// prompt string
    fprintf(stdout, "--------------");
    fflush(stdout);

    struct termios tc;
    tcgetattr(STDOUT_FILENO, &tc);
    const tcflag_t lflag = tc.c_lflag;
    // disable echo of control characters
    tc.c_lflag &= ~ECHOCTL;
    tcsetattr(STDOUT_FILENO, TCSANOW, &tc);
    // reprint input buffer
    ioctl(STDOUT_FILENO, TIOCSTI, &tc.c_cc[VREPRINT]);
    tc.c_lflag = lflag;
    tcsetattr(STDOUT_FILENO, TCSANOW, &tc);


}

int main( int argc, char* argv[])
{

	// create the context on the stack
	Context ct;

	// get the input, exit if failure
	if( !GetInput(&ct, argc, argv) )
		return 0;

	// init the context
	ct.Init();

	// set the run state
	ct.m_Running = true;

	// create the input thread
	ct.MakeThread(InputThread);

	// check the mode
	if( ct.m_Mode == 1 )
	{
		// create the server
		ct.MakeThread(ListenThread);
	}

	// some variables for sockets
	int sockfd;
	struct sockaddr_in saLoc;
	bool success = true;

	// lets do some socket creation (for the client)
	if( ct.m_Mode == 2 )
	{
		// place this in a for loop to create a breakable scope
		for(int dum = 0; dum < 1; dum++)
		{
			//Create a reliable, stream socket using TCP
			if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
			{
				LogMsgToTerminal("ERROR CREATING SOCKET");
				success = false;
				break;
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
				success = false;
				close(sockfd);
				break;
			}

			// set the destination parameters - the IP is already set
			ct.m_Sa.sin_family = AF_INET; // Internet address family
			ct.m_Sa.sin_port = htons(ct.m_DPort); // Server port
		
			LogMsgToTerminal("ATTEMPTING TO CONNECT");
			if (connect(sockfd, (struct sockaddr*) &(ct.m_Sa),sizeof(ct.m_Sa)) < 0)
			{
				LogMsgToTerminal("ERROR CONNECTING");
				success = false;
				break;
			}
			else
			{
				LogMsgToTerminal("SUCCESSFULL CONNECTION");
			}
		}
	}

	

	// start the loop
	pthread_mutex_lock(&(ct.m_PollMutex));
	while(ct.m_Running)
	{
		// wait on the condition
		pthread_cond_wait(&(ct.m_PollCondition), &(ct.m_PollMutex));

		// do work



	}	
	pthread_mutex_unlock(&(ct.m_PollMutex));

	// clean up the socket
	if( ct.m_Mode == 2 )
	{
		if( success )
		{
			close(sockfd);
		}
	}	

	// destroy and join the threads
	ct.DestroyAllThreads();
		
	// shut down the context
	ct.Shutdown();

	return 0;
}
