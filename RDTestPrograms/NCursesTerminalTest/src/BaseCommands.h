#ifndef __BASECOMMANDS_H__
#define __BASECOMMANDS_H__

#include "CommandInterface.h"

// declare some base commands
class ClearTerminal : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};


class ClearHistory : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

class ShowHistory : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};


class ListCmds : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};

class HelpCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
};
 

#endif //__BASECOMMANDS_H__

