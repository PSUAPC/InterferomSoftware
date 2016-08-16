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

// ---------------------------------
// --------   M E S S A G E  -------
// ---------------------------------

struct Message
{
	Message() : m_Data(NULL), m_Len(0),
		m_Ptr(0), m_MissMatch(true), m_Src(-1),
		m_ReadChecksum(0), m_CalcChecksum(0){}
	
	char* 	m_Data;
	int   	m_Len;
	int 	m_Ptr;
	bool 	m_MissMatch;
	char	m_ReadChecksum;
	char 	m_CalcChecksum;
	int	m_Src; // 0 - TTY, 1 - TCP
};


// ---------------------------------
// ------- F I F O   B U F F E R ---
// ---------------------------------

class LocalContext;

class FIFOBuffer
{
private:
	FIFOBuffer() : m_Size(0) {}
public:

friend class LocalContext;

	FIFOBuffer(size_t size);
	~FIFOBuffer();
	
	bool IsFull();
	bool IsEmpty();
	bool Write(char c);
	char Read();
	

private:
	char* m_Data;
	int   m_RdPtr;
	int   m_WrPtr;
	const int m_Size;
};

class LocalContext;
class HexViewer;

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
	LocalContext*	m_TTYThread;

	// hex viewer
	HexViewer* 	m_HexViewer;

    	// socket variables
    	struct sockaddr_in m_Sa;

    	// posix variables
	pthread_mutex_t m_CreateMutex;
    	pthread_mutex_t m_PollMutex;
	pthread_mutex_t m_TerminalMutex;
	pthread_mutex_t m_TCPMutex;
	pthread_mutex_t m_TTYMutex;
    	pthread_cond_t  m_PollCondition;
    	pthread_attr_t  m_Attr;

};

// --------------------------------------------
// -----   L O C A L   C O N T E X T   --------
// --------------------------------------------


class LocalContext
{
public:
	typedef std::list<Message> MQueue;
	enum ContextType 
	{
		T_UNKNOWN = 0,
		T_INPUT = 1,
		T_TCP,
		T_UDP,
		T_TTY,
		T_MAX
	};

	LocalContext();
	~LocalContext();

	// interfacing functions
	bool AddToOutbox(Message msg);
	Message GetInboxEntry(int index);
	void RemoveInboxEntry(int index);
	int GetInboxSize();
	char FIFORead();

	// communication functions for the active thread
	void AddToInbox(Message msg);
	Message& GetNextMessage(bool pop = false);
	bool HasMessagePending();
	bool FIFOWrite(char c);
	void CheckFIFO();
	void ClearFIFO();
	
    	// posix variables
    	pthread_t m_Thread;
    	Context* m_Context;
    	int  m_TID;
	

    	// socket variables
    	int m_Sockfd;
	struct sockaddr_storage m_Addr;
	bool m_Connected;
	bool m_Verbose;

	// tty variables
	FIFOBuffer m_FIFO;

	// context variables
	pthread_mutex_t m_Mutex;
	MQueue m_Inbox;
	MQueue m_Outbox;
	string m_MSG;
	ContextType m_Type; 

	// helper functions
	int GetNextPtr(int ptr);

};

