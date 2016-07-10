#ifndef __BASECOMMANDS_H__
#define __BASECOMMANDS_H__

#include "CommandInterface.h"

// declare some base commands

// ---------------------------------
//     C L E A R   C O M M A N D   
// ---------------------------------

class ClearTerminal : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

// --------------------------------------
//     H I S T O R Y   C O M M A N D   
// --------------------------------------

class ShowHistory : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

// ---------------------------------
//     L I S T   C O M M A N D   
// ---------------------------------

class ListCmds : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

// ---------------------------------
//     E C H O   C O M M A N D   
// ---------------------------------

class EchoCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

// ---------------------------------
//     R U N   C O M M A N D   
// ---------------------------------

class RunCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

// ---------------------------------
//     H E L P   C O M M A N D   
// ---------------------------------

class HelpCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};
 
// ---------------------------------
//    M A N   C O M M A N D   
// ---------------------------------

class ManCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};


#endif //__BASECOMMANDS_H__

