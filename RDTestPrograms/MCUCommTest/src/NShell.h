#ifndef __NSHELL_H__
#define __NSHELL_H__

#include <string>
#include <list>
#include <map>


class ICommandInterface;
typedef void(*ShellCmdFunc)(std::string);

class NShell
{
	typedef std::map<std::string, ICommandInterface*> ShellCmds;
	typedef std::pair<std::string, ICommandInterface*> ShellCmdPair;
public:
	NShell();
	~NShell();
	
	void RegisterCommand(std::string cmd, ICommandInterface* cmdInterface);
	void ParseCommand(std::string cmd);

	static NShell* Get();

	std::list<std::string> GetCommandList();
	ICommandInterface* GetCommandByName(std::string cmd);

	static void TrimpWhiteSpace(std::string& str);

private:

	ShellCmds m_ShellCmds;

};







#endif //__NSHELL_H__
