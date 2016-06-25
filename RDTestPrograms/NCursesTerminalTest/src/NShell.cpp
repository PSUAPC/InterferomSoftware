
#include "NShell.h"
#include "NTerminal.h"
#include "CommandInterface.h"
#include "BaseCommands.h"

// singleton global variable for the shell
NShell* g_NShell = NULL;

NShell::NShell()
{
	// singleton assignment
	if( g_NShell == NULL )
	{
		g_NShell = this;
	}
	else
	{
		throw "Atempting to create a second shell, which is of type singleton";
	}

	// register the base commands
	RegisterCommand("clear", new ClearTerminal() );
	RegisterCommand("history", new ShowHistory() );
	RegisterCommand("echo", new EchoCmd() );
	RegisterCommand("list", new ListCmds() );
	RegisterCommand("run", new RunCmd() );
	RegisterCommand("help", new HelpCmd() );
	//RegisterCommand("man", new ManCmd() ); 	// disable man command for now
	RegisterCommand("exit", NULL );
}

NShell::~NShell()
{
	// set the singleton global to null
	g_NShell = NULL;
}

NShell* NShell::Get()
{
	// static function, return the global pointer
	return g_NShell;
}

void NShell::RegisterCommand(std::string cmd, ICommandInterface* cmdInterface)
{
	// insert the command into the map
	m_ShellCmds.insert( ShellCmdPair(cmd, cmdInterface) );
}

ICommandInterface* NShell::GetCommandByName(std::string cmd)
{
	// lookup the command in the map
	ShellCmds::iterator it = m_ShellCmds.find( cmd );
	if( it == m_ShellCmds.end() )
		return NULL;
	else
		return (it->second);
}

std::list<std::string> NShell::GetCommandList()
{
	// cycle through the map adding each key to a list
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
	// remove any white space before
	while( (str.length() > 0) && (str[0] == ' ') )
	{
		str = str.substr(1, str.length()-1);
	} 

	// remove any white space after
	while( (str.length() > 0) && (str[str.length()-1] == ' ') )
	{
		str = str.substr(0, str.length()-1);
	}


}

void NShell::ParseCommand(std::string cmd)
{
	// save the input for commands that rely on using optarg
	std::string basecmd = cmd;
	std::string args;
	
	// we need to break the string into a command
	// and an argument string, seperate by a ' ' (space) character
	int sep = 0;
	bool charFound = false;
	for(sep = 0; sep < cmd.length(); sep++ )
	{
		if( (cmd[sep] == ' ') && charFound )
			break;
		else if( cmd[sep] != ' ' )
			charFound = true;
	}

	// break the string into cmd and arg components 
	if( sep < cmd.length() )
	{
		args = cmd.substr(sep, cmd.length()-sep);
		cmd = cmd.substr(0, sep);
	}
	
	// assume the command is invalid before we attempt to execute it
	bool valid = false;

	// trim any white space which might mess with the key lookup in the map
	TrimpWhiteSpace( cmd );
	TrimpWhiteSpace( args );

	// verify that we have a command greater than 1 character long
	if( cmd.length() > 1 )
	{

		ShellCmds::iterator it = m_ShellCmds.find(cmd);
	
		// check to see if found
		if( it != m_ShellCmds.end() )
		{
			// verify that we have a command class associated
			// with the key
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

				// the command was executed thus was valid
				valid = true;
			}
		}
	}
	
	// if invalid, let the user know. This is here since there are
	// three nested if statements. If any of them hits the else, then
	// the command is not a valid command to execute
	if( !valid )
	{
		NTerminal::Get()->PrintToStdout("Command Not Found: " + cmd);
	}
}

