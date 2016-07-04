#include "CommCommands.h"
#include "NShell.h"
#include "NTerminal.h"
#include "Contexts.h"
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <termio.h>

extern bool ConnectToServer(Context& ct, LocalContext* newCT, bool stop);
extern bool AttemptConnection(Context& ct, LocalContext* newCT);
extern int TTYSetInterfaceAttribs (int fd, int speed, int parity);
extern void TTYSetBlocking (int fd, int should_block);

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
		else if( strcmp(argv[0], "send") == 0 )
		{
			mode = 4; // send
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
		case 4:	
			if( !ct->m_TCPThread->m_Connected )
			{
				success = false;
			}
			else
			{
				success = true;	
				// we will expect the string to be in the form
				// XX XX XX XX, where XX is an 8 byte hex number
				// they will be separated by spaces
				std::list<char> data;
				int tdata;
				for( int i = 1; i < argc; i++ )
				{
					tdata = strtoul(argv[i], NULL, 16);
					data.push_back((char)(tdata&0x000000FF));
				}

				// lets provide feedback
				char* sdata = new char[data.size()*3 +1];
				sdata[data.size()*3] = 0; // null terminate it
				char tsdat[3];

				int k = 0;
				for( std::list<char>::iterator it = data.begin();
					it != data.end(); it++ )
				{
					int a = (*it);
					a = a&0x000000FF;
					sprintf(tsdat, "%02X", a);

					sdata[k*3] = tsdat[0];
					sdata[k*3+1] = tsdat[1];
					sdata[k*3+2] = ' ';
					k++;
					
				}
				NTerminal::Get()->PrintToStdout("Sending: ");
				NTerminal::Get()->PrintToStdout(sdata);

				delete [] sdata;

				// now we allocate the stream to send
				// allocate the data stream
				char * stream = new char[data.size()];
				k = 0;
				for( std::list<char>::iterator it = data.begin(); 
					it != data.end(); it++ )
				{
					stream[k] = (*it);
					k++;
				}
				
				// create a message for this one
				Message msg;
				msg.m_Data = stream;
				msg.m_Len = data.size();

				// add the message to the outbox
				ct->m_TTYThread->AddToOutbox(msg);
	

				//int fd = ct->m_TCPThread->m_Sockfd;
				//size_t sent = send( fd, stream, data.size(), 0 );
				//if( sent != data.size() )
				//{
				//	NTerminal::Get()->PrintToStdout("Error sending");
				//}

				// clean up the stream 
				//delete [] stream;

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

	case 4: // send

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
		_S(" tcp send <byte string>\n") +
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
		_S(" send    : command used to send a specific byte string\n") +
		_S("           byte string should be in the form XX XX XX, where\n") + 
		_S("           XX is a 8 bit hex number, and each pair is seperated\n") +
		_S("           by a space\n") +
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
		else if( strcmp(argv[0], "send") == 0 )
		{
			mode = 4; // send	
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
					if( GetBaudFromInt(ct->m_SerialBaud) == 0 )
					{
						NTerminal::Get()->PrintToStdout("Invalid Baud");
						ct->m_SerialBaud = 0;
					}
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
		case 4:

			if( !ct->m_TTYThread->m_Connected )
			{
				success = false;
			}
			else
			{
				success = true;	
				// we will expect the string to be in the form
				// XX XX XX XX, where XX is an 8 byte hex number
				// they will be separated by spaces
				std::list<char> data;
				int tdata;
				for( int i = 1; i < argc; i++ )
				{
					tdata = strtoul(argv[i], NULL, 16);
					data.push_back((char)(tdata&0x000000FF));
				}

				// lets provide feedback
				char* sdata = new char[data.size()*3 +1];
				sdata[data.size()*3] = 0; // null terminate it
				char tsdat[3];

				int k = 0;
				for( std::list<char>::iterator it = data.begin();
					it != data.end(); it++ )
				{
					int a = (*it);
					a = a&0x000000FF;
					sprintf(tsdat, "%02X", a);

					sdata[k*3] = tsdat[0];
					sdata[k*3+1] = tsdat[1];
					sdata[k*3+2] = ' ';
					k++;
					
				}
				NTerminal::Get()->PrintToStdout("Sending: ");
				NTerminal::Get()->PrintToStdout(sdata);

				delete [] sdata;
				// now we allocate the stream to send
				// allocate the data stream
				char * stream = new char[data.size()];
				k = 0;
				for( std::list<char>::iterator it = data.begin(); 
					it != data.end(); it++ )
				{
					stream[k] = (*it);
					k++;
				}

				// create a message for this one
				Message msg;
				msg.m_Data = stream;
				msg.m_Len = data.size();

				// add the message to the outbox
				ct->m_TTYThread->AddToOutbox(msg);
	
				//int fd = ct->m_TTYThread->m_Sockfd;
				//size_t sent = write( fd, stream, data.size() );
				//if( sent != data.size() )
				//{
				//	NTerminal::Get()->PrintToStdout("Error sending");
				//}

				// clean up the stream 
				//delete [] stream;
				
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


		success = true;

		if( stop )
		{
			NTerminal::Get()->PrintToStdout("Stopping TTY Connection");
			// stop
			if( ct->m_TTYThread->m_Sockfd != -1 )
			{
				// attempt to close
				if( close(ct->m_TTYThread->m_Sockfd) != 0 )
					success = false;
				else
					success = true;

				// clear the fd anyways
				ct->m_TTYThread->m_Sockfd = -1;
			}
		}
		else
		{
			NTerminal::Get()->PrintToStdout("Starting TTY Connection");
			
			// retry or connect
			int fd = ct->m_TTYThread->m_Sockfd;
			if( fd != -1 )
			{
				// attempt to close
				if( close(fd) != 0 )
				{
					success = false;
					NTerminal::Get()->PrintToStdout(_S("ERROR: ") +
									_S(strerror (errno)));
				}
				else
				{
					success = true;
				}
				ct->m_TTYThread->m_Sockfd = -1;
			}	

			// now try opening
			fd = open (ct->m_SerialName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
			if (fd < 0)
			{
				success = false;
				NTerminal::Get()->PrintToStdout(_S("ERROR: ") + _S(strerror (errno)));
				
			}
			else
			{
				// set the stats
				TTYSetInterfaceAttribs (fd, GetBaudFromInt(ct->m_SerialBaud), 0);
				TTYSetBlocking (fd, 0); 
				success = success & true;
			}
			if( success )
			{
				ct->m_TTYThread->m_Sockfd = fd;
			}
		}

		if( success && !stop )
		{
			ct->m_TTYThread->m_Connected = true;
		}
		else
		{
			ct->m_TTYThread->m_Connected = false;
		}
	case 4: // print success response

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
		if( ct->m_TTYThread->m_Connected )
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
		_S(" tty send <byte string>\n") +
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
		_S(" send    : command used to send a specific byte string\n") +
		_S("           byte string should be in the form XX XX XX, where\n") + 
		_S("           XX is a 8 bit hex number, and each pair is seperated\n") +
		_S("           by a space\n") +
		_S("           [Returns success]\n") +  
		_S(" -b baud : baud rate for the TTY connection\n") + 
		_S(" -d device : the TTY device to connect to e.g. /dev/ttyUSB0\n") +
		_S(" -s stop : will disconnect the TTY if connected\n");
		
}

std::string TTYCmd::Man()
{
	return "";
}

int TTYCmd::GetBaudFromInt(int baud)
{

	// possible baud values	
#define B(x) case x: return B##x
        switch(baud) {
        B(50);     B(75);     B(110);    B(134);    B(150);
        B(200);    B(300);    B(600);    B(1200);   B(1800);
        B(2400);   B(4800);   B(9600);   B(19200);  B(38400);
        B(57600);  B(115200); B(230400); B(460800); B(500000);
        B(576000); B(921600); B(1000000);B(1152000);B(1500000);
    default: return 0;
    }
#undef B
}

