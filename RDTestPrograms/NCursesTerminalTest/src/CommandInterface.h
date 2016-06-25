#ifndef __COMMANDINTERFACE_H__
#define __COMMANDINTERFACE_H__

#include <string>

#define _S(c) std::string(c)

class ICommandInterface
{
public:	
	virtual void Exec(std::string str) = 0;

	virtual std::string Help() = 0;

	virtual bool UsesOptArg(){ return false; }

	virtual std::string Man() = 0;	
};




#endif //__COMMANDINTERFACE_H__
