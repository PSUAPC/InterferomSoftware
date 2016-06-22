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

class ConnectTCP : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

#endif //__COMMCOMMANDS_H__
