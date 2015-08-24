#include "Includes.h"
#include "Contexts.h"


using namespace std;



void *ListenThread(void* t)
{
	LocalContext* lct = (LocalContext*)(t);
	Context* ct = lct->m_Context;
	while( ct->m_Running )
	{


	}

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
    int dPort = 0;
    int sPort = 0;
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

	cout << "here1" << endl;

	// create the input thread
	ct.MakeThread(InputThread);

	cout << "here2" << endl;
	// lets do some socket creation

	// start the loop
	pthread_mutex_lock(&(ct.m_PollMutex));
	while(ct.m_Running)
	{
		// wait on the condition
		pthread_cond_wait(&(ct.m_PollCondition), &(ct.m_PollMutex));

		// do work



	}	
	pthread_mutex_unlock(&(ct.m_PollMutex));
	

	// destroy and join the threads
	ct.DestroyAllThreads();
		
	// shut down the context
	ct.Shutdown();

	return 0;
}
