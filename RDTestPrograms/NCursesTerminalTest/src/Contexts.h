#pragma once
#include "Includes.h"
#include <netdb.h>

#include <map>
#include <queue>

using namespace std;

// ----------------------------------
// ---------   U I D D I C T --------
// ----------------------------------

class UIDDict
{
public:
	UIDDict();

	unsigned int GetNewUID();
	void UnRegisterUID(unsigned int uid);
	void ResetUID(unsigned int baseUID = 1);
	
private:

	unsigned int m_NextUID;
	priority_queue<unsigned int> m_Queue;

};



struct LocalContext;

// --------------------------------
// -----   C O N T E X T   --------
// --------------------------------

class Context
{
public:
	
	//  ----------- TypeDefs -------------
	typedef map<unsigned int, LocalContext*> CTMap;
	typedef pair<unsigned int, LocalContext*> CTPair;
	typedef queue<unsigned int> UIDQueu;

	// ------------ Singleton ----------
	Context();
	~Context();
	static Context* Get();
	
	// ------------ Functions ----------
	LocalContext* MakeThread(void *(*fcn)(void*));
	void RemoveThreadTS(unsigned int uid);
	void RemoveThread(unsigned int uid);
	LocalContext* FindThread(unsigned int uid);
	void BroadcastAll(string msg, unsigned int exception = 0);
	void SetThreadAsGarbage(unsigned int uid);
	void CollectGarbage();
	void DestroyAllThreads();
	void Init();
	void Shutdown();

	// ------------ Variables ----------

    	// context variables
    	int     	m_Mode;
    	int     	m_SPort;
    	int     	m_DPort;
    	bool    	m_Running;
    	CTMap 		m_Contexts;
	UIDDict 	m_UIDDict;
	UIDQueu 	m_Garbage;
	int		m_Caller;
	string		m_SerialName;
	int		m_SerialBaud;

	// specific threads
	LocalContext* 	m_TCPThread;
	LocalContext* 	m_InputThread;
	LocalContext*	m_TtyThread;

    	// socket variables
    	struct sockaddr_in m_Sa;

    	// posix variables
	pthread_mutex_t m_CreateMutex;
    	pthread_mutex_t m_PollMutex;
	pthread_mutex_t m_TerminalMutex;
    	pthread_cond_t  m_PollCondition;
    	pthread_attr_t  m_Attr;

};

// --------------------------------------------
// -----   L O C A L   C O N T E X T   --------
// --------------------------------------------


struct LocalContext
{
	enum ContextType 
	{
		T_UNKNOWN = 0,
		T_INPUT = 1,
		T_TCP,
		T_UDP,
		T_TTY,
		T_MAX
	};

    	// posix variables
    	pthread_t m_Thread;
    	Context* m_Context;
    	int  m_TID;

    	// socket variables
    	int m_Sockfd;
	struct sockaddr_storage m_Addr;
	bool m_Connected;

	// tty variables
	int m_Ttyfd;	

	// context variables
	string m_MSG;
	ContextType m_Type; 

};

