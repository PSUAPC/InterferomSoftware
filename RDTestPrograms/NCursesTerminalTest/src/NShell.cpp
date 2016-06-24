#include "NShell.h"
#include "NTerminal.h"
#include "CommandInterface.h"
#include "BaseCommands.h"

NShell* g_NShell = NULL;

NShell::NShell()
{
	// singleton
	if( g_NShell == NULL )
	{
		g_NShell = this;
	}

	// register the base commands
	RegisterCommand("clear", new ClearTerminal() );
	RegisterCommand("history", new ShowHistory() );
	RegisterCommand("list", new ListCmds() );
	RegisterCommand("help", new HelpCmd() );
	RegisterCommand("exit", NULL );
}

NShell::~NShell()
{
	g_NShell = NULL;
}

NShell* NShell::Get()
{
	return g_NShell;
}

void NShell::RegisterCommand(std::string cmd, ICommandInterface* cmdInterface)
{
	m_ShellCmds.insert( ShellCmdPair(cmd, cmdInterface) );
}

ICommandInterface* NShell::GetCommandByName(std::string cmd)
{
	ShellCmds::iterator it = m_ShellCmds.find( cmd );
	if( it == m_ShellCmds.end() )
		return NULL;
	else
		return (it->second);
}

std::list<std::string> NShell::GetCommandList()
{
	std::list<std::string> cmdList;
	for( ShellCmds::iterator it = m_ShellCmds.begin();
		it != m_ShellCmds.end(); it++ )
	{
		cmdList.push_back( it->first );
	}

	return cmdList;
}
void NShell::TrimpWhiteSpace(std::string& str)
{
	// trimp white space
	while( (str.length() > 0) && (str[0] == ' ') )
	{
		str = str.substr(1, str.length()-1);
	} 

	while( (str.length() > 0) && (str[str.length()-1] == ' ') )
	{
		str = str.substr(0, str.length()-1);
	}


}

void NShell::ParseCommand(std::string cmd)
{

	std::string basecmd = cmd;
	std::string args;
	// we need to find the option arguments, they begin with a -
	int sep = 0;
	bool charFound = false;
	for(sep = 0; sep < cmd.length(); sep++ )
	{
		if( (cmd[sep] == ' ') && charFound )
			break;
		else if( cmd[sep] != ' ' )
			charFound = true;
	}
	if( sep < cmd.length() )
	{
		args = cmd.substr(sep, cmd.length()-sep);
		cmd = cmd.substr(0, sep);
	}
	
	bool valid = false;

	TrimpWhiteSpace( cmd );
	TrimpWhiteSpace( args );

	if( cmd.length() > 0 )
	{

		ShellCmds::iterator it = m_ShellCmds.find(cmd);
	
		if( it != m_ShellCmds.end() )
		{
			if( it->second != NULL )
			{
				// check to see if we are using optarg
				// for this command.
				// optarg requires the full shell command
				if( it->second->UsesOptArg() )
				{
					it->second->Exec( basecmd );
				}
				else
				{
					it->second->Exec( args );
				}

				valid = true;
			}
		}
	}
	
	if( !valid )
	{
		NTerminal::Get()->PrintToStdout("Command Not Found: " + cmd);
	}
}

