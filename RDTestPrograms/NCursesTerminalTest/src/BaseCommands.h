#ifndef __BASECOMMANDS_H__
#define __BASECOMMANDS_H__

#include "CommandInterface.h"

// declare some base commands
class ClearTerminal : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};


class ClearHistory : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

class ShowHistory : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};


class ListCmds : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

class HelpCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};
 
class ManCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};


#endif //__BASECOMMANDS_H__

