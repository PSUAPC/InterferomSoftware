#include "CommCommands.h"
#include "NShell.h"
#include "NTerminal.h"
#include "Contexts.h"
#include <glib.h>

extern bool ConnectToServer(Context& ct, LocalContext* newCT, bool stop);
extern bool AttemptConnection(Context& ct, LocalContext* newCT);

void TCPCmd::Exec(std::string str)
{
	bool success = false;
	bool stop = false;
	int argc = 0;
	char ** argv = NULL;
	int mode = 0; // 0=default, 1=config, 2=connect, 3=stop
	Context* ct = Context::Get();
	if( ct == NULL )
	{
		NTerminal::Get()->PrintToStdout("No context found");
		return; // no context
	}

	// parse the arguments
	g_shell_parse_argv( str.c_str(), &argc, &argv, NULL );

		
	 	

	// must reset optind to 0 in case of previous call
	// this resets the arg list and the argv index
	optind = 0;
	
	if( argc > 0 )
	{
		// find the mode
		if( strcmp(argv[0],"config") == 0)
		{
			mode = 1; // config mode
		}
		else if( strcmp(argv[0], "connect") == 0 )
		{
			mode = 2; // connect
		}
		else if( strcmp(argv[0], "stop") == 0 )
		{
			mode = 3; // stop
			stop = true;
		}
		else
		{
			mode = 0; // default
		}

		char c;

		switch(mode)
		{
		case 1: // config

			while ( (c = getopt(argc, argv, "p:a:") ) != -1) 
			{
    				switch (c) 
    				{
        			case 'p':
					sscanf(optarg, "%d", &ct->m_DPort); 
            				break;
				case 'a':
					inet_aton(optarg, &ct->m_Sa.sin_addr);
					break;
        			case '?':
				default :
					
					NTerminal::Get()->PrintToStdout("Unknown argument ");	
            				break;
    				}
			}
			break;	

		case 2: // connect
			while ( (c = getopt(argc, argv, "s") ) != -1) 
			{
    				switch (c) 
    				{
        			case 's':
					stop = true;
            				break;
        			case '?':
				default :
					
					NTerminal::Get()->PrintToStdout("Unknown argument ");	
            				break;
    				}
			}
			break;	
		case 0:
		case 3:
		default:
			// do nothing
			break; 
		}

		
	}
	else
	{
		// default mode
		mode = 0;
	}
	
	g_strfreev(argv);

	// work based on mode
	switch( mode )	
	{
	case 1: // config
		{
			char portBuff[10];
			sprintf(portBuff, "%d", ct->m_DPort);
			
			// print the configuration
			std::string ret = _S("---- TCP CONFIGURATION ------\n") +
			  		  _S(" Port: ") + _S(portBuff) + _S("\n") +
					  _S(" IP  : ") + inet_ntoa(ct->m_Sa.sin_addr) + _S("\n") +
					  _S("-----------------------------\n");

			NTerminal::Get()->PrintToStdout(ret);
		
		}
		break;
	case 2: // connect
	case 3: // stop

		if( stop )
		{
			NTerminal::Get()->PrintToStdout("Stopping TCP Connection");
			// stop
			success = ConnectToServer(*Context::Get(), Context::Get()->m_TCPThread, true);
		}
		else
		{
			NTerminal::Get()->PrintToStdout("Starting TCP Connection");
			// retry or connect
			success = ConnectToServer(*Context::Get(), Context::Get()->m_TCPThread, false);
			success &= AttemptConnection(*Context::Get(), Context::Get()->m_TCPThread);

		}

		if( success )
		{
			NTerminal::Get()->PrintToStdout("[Success]");
		}
		else
		{
			NTerminal::Get()->PrintToStdout("[Failure]");
		}
		break;
	case 0: // default
	default:
		if( ct->m_TCPThread->m_Connected )
		{
			NTerminal::Get()->PrintToStdout("TCP Status = Connected");
		}
		else
		{
			NTerminal::Get()->PrintToStdout("TCP Status = Disconnected");
		}
		break;

	}

	
}


std::string TCPCmd::Help()
{
	return _S("Usage: \n") +
		_S(" tcp config [-p <port>] [-a <address>]\n") +
		_S(" tcp connect [-s] \n") +
		_S(" tcp stop \n") +
		_S(" tcp \n") +
		_S("Description: Inteface for setting up and connecting TCP\n") +
		_S("             [Returns connection status by default]\n") +
		_S("Options: \n") +
		_S(" config  : command used for configuring the TCP connection\n") +
		_S("	       [Returns configuration]\n") +
		_S(" connect : command used to establish the TCP connection\n") +
		_S("           If a connection exists, this will restart it\n") +
		_S("           [Returns success]\n") +
		_S(" stop    : command used to diconnect the TCP connection\n") +
		_S("           [Returns success]\n") +
		_S(" -p port : the TCP Port Number to connect to\n") + 
		_S(" -a address : the TCP Address to connect to\n") +
		_S(" -s stop : will disconnect the TCP if connected\n");
		
}

std::string TCPCmd::Man()
{
	return "";
}

void TTYCmd::Exec(std::string str)
{
	bool success = false;
	bool stop = false;
	int argc = 0;
	char ** argv = NULL;
	int mode = 0; // 0=default, 1=config, 2=connect, 3=stop
	Context* ct = Context::Get();
	if( ct == NULL )
	{
		NTerminal::Get()->PrintToStdout("No context found");
		return; // no context
	}

	// parse the arguments
	g_shell_parse_argv( str.c_str(), &argc, &argv, NULL );

		
	 	

	// must reset optind to 0 in case of previous call
	// this resets the arg list and the argv index
	optind = 0;
	
	if( argc > 0 )
	{
		// find the mode
		if( strcmp(argv[0],"config") == 0)
		{
			mode = 1; // config mode
		}
		else if( strcmp(argv[0], "connect") == 0 )
		{
			mode = 2; // connect
		}
		else if( strcmp(argv[0], "stop") == 0 )
		{
			mode = 3; // stop
			stop = true;
		}
		else
		{
			mode = 0; // default
		}

		char c;

		switch(mode)
		{
		case 1: // config

			while ( (c = getopt(argc, argv, "b:d:") ) != -1) 
			{
    				switch (c) 
    				{
        			case 'b':
					sscanf(optarg, "%d", &ct->m_SerialBaud); 
            				break;
				case 'd':
					ct->m_SerialName = _S(optarg);
					break;
        			case '?':
				default :
					
					NTerminal::Get()->PrintToStdout("Unknown argument ");	
            				break;
    				}
			}
			break;	

		case 2: // connect
			while ( (c = getopt(argc, argv, "s") ) != -1) 
			{
    				switch (c) 
    				{
        			case 's':
					stop = true;
            				break;
        			case '?':
				default :
					
					NTerminal::Get()->PrintToStdout("Unknown argument ");	
            				break;
    				}
			}
			break;	
		case 0:
		case 3:
		default:
			// do nothing
			break; 
		}

		
	}
	else
	{
		// default mode
		mode = 0;
	}
	
	g_strfreev(argv);

	// work based on mode
	switch( mode )	
	{
	case 1: // config
		{
			char baudBuff[10];
			sprintf(baudBuff, "%d", ct->m_SerialBaud);
			
			// print the configuration
			std::string ret = _S("---- TTY CONFIGURATION ------\n") +
			  		  _S(" Baud  : ") + _S(baudBuff) + _S("\n") +
					  _S(" Device: ") + _S(ct->m_SerialName) + _S("\n") +
					  _S("-----------------------------\n");

			NTerminal::Get()->PrintToStdout(ret);
		
		}
		break;
	case 2: // connect
	case 3: // stop

		if( stop )
		{
			NTerminal::Get()->PrintToStdout("Stopping TTY Connection");
			// stop
			//success = ConnectToServer(*Context::Get(), Context::Get()->m_RecvThread, true);
		}
		else
		{
			NTerminal::Get()->PrintToStdout("Starting TTY Connection");
			// retry or connect
			//success = ConnectToServer(*Context::Get(), Context::Get()->m_RecvThread, false);
			//success &= AttemptConnection(*Context::Get(), Context::Get()->m_RecvThread);

		}

		if( success )
		{
			NTerminal::Get()->PrintToStdout("[Success]");
		}
		else
		{
			NTerminal::Get()->PrintToStdout("[Failure]");
		}
		break;
	case 0: // default
	default:
		if( /*ct->m_RecvThread->m_Connected*/ false )
		{
			NTerminal::Get()->PrintToStdout("TTY Status = Connected");
		}
		else
		{
			NTerminal::Get()->PrintToStdout("TTY Status = Disconnected");
		}
		break;

	}

	
}


std::string TTYCmd::Help()
{
	return _S("Usage: \n") +
		_S(" tty config [-b <baud>] [-d <device>]\n") +
		_S(" tty connect [-s] \n") +
		_S(" tty stop \n") +
		_S(" tty \n") +
		_S("Description: Inteface for setting up and connecting TTY\n") +
		_S("             [Returns connection status by default]\n") +
		_S("Options: \n") +
		_S(" config  : command used for configuring the TTY connection\n") +
		_S("	       [Returns configuration]\n") +
		_S(" connect : command used to establish the TTY connection\n") +
		_S("           If a connection exists, this will restart it\n") +
		_S("           [Returns success]\n") +
		_S(" stop    : command used to diconnect the TTY connection\n") +
		_S("           [Returns success]\n") +
		_S(" -b baud : baud rate for the TTY connection\n") + 
		_S(" -d device : the TTY device to connect to e.g. /dev/ttyUSB0\n") +
		_S(" -s stop : will disconnect the TTY if connected\n");
		
}

std::string TTYCmd::Man()
{
	return "";
}



