#include "BaseCommands.h"
#include "NShell.h"
#include "NTerminal.h"

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
	}
}

std::string ClearTerminal::Help()
{
	return "Usage: clear [-h]; h=history";
}

void ClearHistory::Exec(std::string str)
{
	NTerminal::Get()->ClearHistory();

}

std::string ClearHistory::Help()
{
	return "";
}



void ShowHistory::Exec(std::string str)
{
	NTerminal::Get()->PrintHistory();
}

std::string ShowHistory::Help()
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
	return "";
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
	return "Usage: help <cmdName>";
}
