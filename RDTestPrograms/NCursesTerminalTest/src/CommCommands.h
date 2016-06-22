#ifndef __COMMCOMMANDS_H__
#define __COMMCOMMANDS_H__

#include "CommandInterface.h"

#if 0
class ClearTerminal : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

void CGetDestIP(std::string str)
{
	NTerminal::Get()->PrintToStdout(inet_ntoa(ct.m_Sa.sin_addr) );
}

void CGetDestPort(std::string str)
{
	char tcst[100];
	sprintf(tcst, "%d", ct.m_DPort);
	NTerminal::Get()->PrintToStdout(tcst);
}

void CSetDestPort(std::string str)
{
	sscanf(str.c_str(), "%d", &ct.m_DPort);
}


void CSetDestIP(std::string str)
{
	inet_aton(str.c_str(), &ct.m_Sa.sin_addr);
}


#endif

class DestIPSet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

class DestIPGet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

class DestPortSet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

class DestPortGet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

#endif //__COMMCOMMANDS_H__
