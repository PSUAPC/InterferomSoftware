#ifndef __HEXCOMMANDS_H__
#define __HEXCOMMANDS_H__

#include "CommandInterface.h"



class HexCmd : public ICommandInterface
{
public:
	virtual void Exec(std::string str);
	virtual std::string Help();
	virtual std::string Man();
};

#endif //__HEXCOMMANDS_H__
