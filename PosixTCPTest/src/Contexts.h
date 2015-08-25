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
	
	// ------------ Functions ----------
	LocalContext* MakeThread(void *(*fcn)(void*));
	void RemoveThreadTS(unsigned int uid);
	void RemoveThread(unsigned int uid);
	void SetThreadAsGarbage(unsigned int uid);
	void CollectGarbage();
	void DestroyAllThreads();
	void Init();
	void Shutdown();

	// ------------ Variables ----------

    // context variables
    int     m_Mode;
    int     m_SPort;
    int     m_DPort;
    bool    m_Running;
    CTMap 	m_Contexts;
	UIDDict m_UIDDict;
	UIDQueu m_Garbage;

    // socket variables
    struct sockaddr_in m_Sa;

    // posix variables
	pthread_mutex_t m_CreateMutex;
    pthread_mutex_t m_PollMutex;
    pthread_cond_t  m_PollCondition;
    pthread_attr_t  m_Attr;

};

// --------------------------------------------
// -----   L O C A L   C O N T E X T   --------
// --------------------------------------------


struct LocalContext
{
    // posix variables
    pthread_t m_Thread;
    Context* m_Context;
    int  m_TID;

    // socket variables
    int m_Sockfd;
	struct sockaddr_storage m_Addr;

};

