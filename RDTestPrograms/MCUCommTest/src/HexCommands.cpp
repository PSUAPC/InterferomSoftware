#include "HexCommands.h"
#include "HexViewer.h"
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

void HexCmd::Exec(std::string str)
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
		if( strcmp(argv[0],"packet") == 0)
		{
			mode = 0; // packet mode [default]
		}
		else if( strcmp(argv[0], "front") == 0 )
		{
			mode = 1; // front mode
		}
		

		int c;


		switch(mode)
		{
		case 0: // packet
			ct->m_HexViewer->HexViewer::SetMode(0);
			/*
			while (  (c = getopt(argc, argv, "p:a:vq") ) != -1) 
			{
    				switch (c) 
    				{
        			case 'p':
					sscanf(optarg, "%d", &ct->m_DPort); 
            				break;
				case 'a':
					inet_aton(optarg, &ct->m_Sa.sin_addr);
					break;
				case 'v':
					ct->m_TCPThread->m_Verbose = true;
					break;
				case 'q':
					ct->m_TCPThread->m_Verbose = false;
					break;
        			case '?':
				default :
					
					//NTerminal::Get()->PrintToStdout("Unknown argument ");	
            				break;
    				}
			}*/
			break;	

		case 1: // front
			ct->m_HexViewer->HexViewer::SetMode(1);
			/*while (  (c = getopt(argc, argv, "s") ) != -1) 
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
			}*/
			break;	

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

	

	
}


std::string HexCmd::Help()
{
	return _S("Usage: \n") +
		_S(" hex packets\n") +
		_S(" hex front \n") +
		_S("Description: Inteface for reading hex packets via the TTY terminal\n") +
		_S("Options: \n") +
		_S(" packets  : command used to display all packet messages\n") +
		_S(" front    : command used to identify only the most recent packet\n") +
		_S("            prints human readable data\n");
				
}

std::string HexCmd::Man()
{
	return "";
}

