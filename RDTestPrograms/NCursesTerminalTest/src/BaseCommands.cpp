#include "BaseCommands.h"
#include "NShell.h"
#include "NTerminal.h"
#include <iostream>
#include <fstream>

// declare some base commands

void ClearTerminal::Exec(std::string str)
{

	// check for history flag
	if( str.find("-h") != -1 )
	{
		NTerminal::Get()->ClearHistory();
	}
	else
	{
		NTerminal::Get()->ClearStdout();
		NTerminal::Get()->Redraw();
	}
}

std::string ClearTerminal::Help()
{
	return _S("Usage: clear [-h] \n") + 
		_S("Description: Clears the stdout screen\n") +
		_S("Options:\n") + 
		_S("-h history: clears history");
}

std::string ClearTerminal::Man()
{
	return "Usage: clear [-h]; h=history";
}


void ShowHistory::Exec(std::string str)
{
	NTerminal::Get()->PrintHistory();
}

std::string ShowHistory::Help()
{
	return _S("Usage: history \n") +
		_S("Description: Shows the command history");
}


std::string ShowHistory::Man()
{
	return "";
}

void EchoCmd::Exec(std::string str)
{
	NTerminal::Get()->PrintToStdout(str);
}

std::string EchoCmd::Help()
{
	return _S("Usage: echo <str> \n") +
		_S("Description: Echos the string to stdout");
}


std::string EchoCmd::Man()
{
	return "";
}

void ListCmds::Exec(std::string str)
{
	std::list<std::string> clist = NShell::Get()->GetCommandList();	
	NTerminal::Get()->PrintToStdout("---------------");
	for( std::list<std::string>::iterator it = clist.begin();
		it != clist.end(); it++ )
	{
		NTerminal::Get()->PrintToStdout( (*it) );
	}

	NTerminal::Get()->PrintToStdout("---------------");
}

std::string ListCmds::Help()
{
	return _S("Usage: list\n") +
		_S("Descripton: lists avilable commands");
}

std::string ListCmds::Man()
{
	return "";
}

void RunCmd::Exec(std::string str)
{
	// attempt to open the file
    	std::ifstream infile(str.c_str());	
	if( !infile )
	{
		NTerminal::Get()->PrintToStdout(_S("Unable to open file: ") + str);
		return;
	}

	while( !infile.eof() )
	{
		std::string line;
		getline(infile, line, '\n');
		// skip this line if it does not contain at least 2 characters
		if( line.length() > 1 )
		{
			NShell::Get()->ParseCommand(line);
		}
	}
	// make sure to close the file
	infile.close();
}

std::string RunCmd::Help()
{
	return _S("Usage: run <filename>\n") +
		_S("Description: Reads the file specified and executes the commands");
}

std::string RunCmd::Man()
{
	return "Usage: run <filename>";
}

void HelpCmd::Exec(std::string str)
{
	ICommandInterface* cmd = NShell::Get()->GetCommandByName(str);
	if( cmd != NULL )
	{
		NTerminal::Get()->PrintToStdout(cmd->Help());
	}
}

std::string HelpCmd::Help()
{
	return _S("Usage: help <cmd>\n") +
		_S("Description: Displays the help synopsys for cmd");
}

std::string HelpCmd::Man()
{
	return "Usage: help <cmdName>";
}

void ManCmd::Exec(std::string str)
{
	ICommandInterface* cmd = NShell::Get()->GetCommandByName(str);
	if( cmd != NULL )
	{
		NTerminal::Get()->PrintToStdout(cmd->Man());
	}
}

std::string ManCmd::Help()
{
	return _S("Usage: man <cmd>\n") +
		_S("Description: Opens the manual entry for cmd");
}

std::string ManCmd::Man()
{
	return "Usage: man <cmdName>";
}
