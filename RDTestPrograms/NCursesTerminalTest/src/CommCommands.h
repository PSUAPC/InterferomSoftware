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
	virtual std::string Man();
};

class DestIPGet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

class DestPortSet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

class DestPortGet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

class ConnectTCP : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
	virtual bool UsesOptArg(){ return true; }
};

class SerialNameGet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

class SerialNameSet : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};


#endif //__COMMCOMMANDS_H__
