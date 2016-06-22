#include "CommCommands.h"
#include "NShell.h"
#include "NTerminal.h"
#include "Contexts.h"

#if 0
void ClearTerminal::Exec(std::string str)
{
	NTerminal::Get()->ClearStdout();
}

std::string ClearTerminal::Help()
{
	return "";
}

#endif
extern bool ConnectToServer(Context& ct, LocalContext* newCT, bool stop);
extern bool AttemptConnection(Context& ct, LocalContext* newCT);

void DestIPGet::Exec(std::string str)
{
	Context* ct = Context::Get();
	if( ct != NULL )
		NTerminal::Get()->PrintToStdout(inet_ntoa(ct->m_Sa.sin_addr) );
}

std::string DestIPGet::Help()
{
	return "";
}

void DestPortGet::Exec(std::string str)
{
	Context* ct = Context::Get();
	if( ct != NULL )
	{
		char tcst[100];
		sprintf(tcst, "%d", ct->m_DPort);
		NTerminal::Get()->PrintToStdout(tcst);
	}
}

std::string DestPortGet::Help()
{
	return "";
}

void DestPortSet::Exec(std::string str)
{
	Context* ct = Context::Get();
	if( ct != NULL )
		sscanf(str.c_str(), "%d", &ct->m_DPort);
}

std::string DestPortSet::Help()
{
	return "Usage: PortSet <port>";
}

void DestIPSet::Exec(std::string str)
{
	Context* ct = Context::Get();
	if( ct != NULL )
		inet_aton(str.c_str(), &ct->m_Sa.sin_addr);
}

std::string DestIPSet::Help()
{
	return "Usage: IPSet <IP Address>";
}



void ConnectTCP::Exec(std::string str)
{
	
	bool success = false;

	if( str.find("-s") != -1 )
	{
		// stop
		success = ConnectToServer(*Context::Get(), Context::Get()->m_RecvThread, true);
	}
	else
	{
		// retry or connect
		success = ConnectToServer(*Context::Get(), Context::Get()->m_RecvThread, false);
		success &= AttemptConnection(*Context::Get(), Context::Get()->m_RecvThread);

	}

	if( success )
		NTerminal::Get()->PrintToStdout("[Success]");
	else
		NTerminal::Get()->PrintToStdout("[Failure]");

}

std::string ConnectTCP::Help()
{
	return "Usage: connect [-s]; s=stop";
}





