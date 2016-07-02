#ifndef __COMMCOMMANDS_H__
#define __COMMCOMMANDS_H__

#include "CommandInterface.h"


// commands:
// tcp config -p <port> -a <address>
// tcp connect -s
// tcp stop

// udp config -p <port> -a <address>
// udp connect -s
// udp stop

// tty config -b <baud> -d <device>
// tty connect -s
// tty stop

class TCPCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};
/*
class UDPcmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};
*/
class TTYCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();

private:
	static int GetBaudFromInt(int baud);
};

#endif //__COMMCOMMANDS_H__
