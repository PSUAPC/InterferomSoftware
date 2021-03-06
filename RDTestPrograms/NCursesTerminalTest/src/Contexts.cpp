#include "Contexts.h"
#include "NTerminal.h"

// --------------------------------
// -----   C O N T E X T   --------
// --------------------------------

Context* g_Context = NULL;

Context::Context()
{
	if( g_Context == NULL )
	{
		g_Context = this;
	}
	m_DPort = 0;
	m_SerialBaud = 0;
	m_TCPThread = NULL;
	m_InputThread = NULL;
	m_TTYThread = NULL;


}

Context::~Context()
{
	g_Context = NULL;
}

Context* Context::Get()
{
	return g_Context;
}


void Context::Init()
{
	// create the mutexes
	pthread_mutex_init(&m_CreateMutex, NULL);
	pthread_mutex_init(&m_TTYMutex, NULL);  
 	pthread_mutex_init(&m_TCPMutex, NULL);  
    	pthread_mutex_init(&m_PollMutex, NULL);
	pthread_mutex_init(&m_TerminalMutex, NULL);
    	pthread_cond_init(&m_PollCondition, NULL);

    	// create the thread attributes 
    	pthread_attr_init(&m_Attr);
    	pthread_attr_setdetachstate(&m_Attr, PTHREAD_CREATE_JOINABLE);

	m_TCPThread = NULL;
	m_InputThread = NULL;
	m_TTYThread = NULL;


}

void Context::Shutdown()
{
	// clean up the attributes and mutexes
    	pthread_attr_destroy(&m_Attr);
    	pthread_mutex_destroy(&m_TCPMutex);   
 	pthread_mutex_destroy(&m_TTYMutex);   
	pthread_mutex_destroy(&m_PollMutex);
	pthread_mutex_destroy(&m_CreateMutex);
	pthread_mutex_destroy(&m_TerminalMutex);
    	pthread_cond_destroy(&m_PollCondition);
    	pthread_exit(NULL);

}


LocalContext* Context::MakeThread(void *(*fcn)(void*))
{

	// lock the create mutex
	pthread_mutex_lock(&m_CreateMutex);

	// we need to assign a new UID
	unsigned int uid = m_UIDDict.GetNewUID();

	// create the local context
	LocalContext* lct = new LocalContext();
	
	// assign the relevant variables
	lct->m_Context = this;
	lct->m_TID = uid;

	// create the thread
	pthread_create(&(lct->m_Thread), &(m_Attr), fcn, (void *)(lct));

	// add the thread to the map
	m_Contexts.insert( CTPair(uid, lct) );

	// unlock the create mutex
	pthread_mutex_unlock(&m_CreateMutex);

	return lct;
}

LocalContext* Context::FindThread(unsigned int uid)
{
	// find the context
    	CTMap::iterator it = m_Contexts.find(uid);

    	// check for valid result
    	if( it != m_Contexts.end() )
    	{
		return (it->second);
	}	

	// not found
	return NULL;
}

void Context::RemoveThread(unsigned int uid)
{
	// find the context
	CTMap::iterator it = m_Contexts.find(uid);
	
	// check for valid result
	if( it != m_Contexts.end() )
	{
		// otherwise, lets join the thread, and delete it
		pthread_join((it->second)->m_Thread, NULL);
		m_UIDDict.UnRegisterUID( it->second->m_TID );
    		delete (it->second);
    		(it->second) = NULL;
		m_Contexts.erase(it);
	}

}

void Context::RemoveThreadTS(unsigned int uid)
{
	// lock the create mutex
	pthread_mutex_lock(&m_CreateMutex);

	RemoveThread(uid);

	// unlock the create mutex
	pthread_mutex_unlock(&m_CreateMutex);

}

void Context::SetThreadAsGarbage(unsigned int uid)
{
    	// lock the create mutex
    	pthread_mutex_lock(&m_CreateMutex);

	// add the UID to the garbage
	m_Garbage.push(uid);

    	// unlock the create mutex
    	pthread_mutex_unlock(&m_CreateMutex);

}

void Context::CollectGarbage()
{
	// lock the create mutex
	pthread_mutex_lock(&m_CreateMutex);
	
	while( !m_Garbage.empty() )
	{
		// remove the top item
		RemoveThread( m_Garbage.front() );

		// pop the element
		m_Garbage.pop();
	}

	// unlock the create mutex
	pthread_mutex_unlock(&m_CreateMutex);
	
}

void Context::DestroyAllThreads()
{

	// lock the create mutex
	pthread_mutex_lock(&m_CreateMutex);

	// iterate through all the local contexts
	for( CTMap::iterator it = m_Contexts.begin();
		it != m_Contexts.end(); it++ )
	{
		// if the context is not set to null
		// then join the thread and delete it
		if( it->second != NULL )
        	{
            		pthread_join((it->second)->m_Thread, NULL);
            		delete (it->second);
            		(it->second) = NULL;
        	}

	}

	// unlock the create mutex
	pthread_mutex_unlock(&m_CreateMutex);

}

void Context::BroadcastAll(string msg, unsigned int exception)
{
	for( CTMap::iterator it = m_Contexts.begin();
		it != m_Contexts.end(); it++ )
	{
		// skip 1,2, exception
		if( it->first == 1 )
			continue;
		if( it->first == 2 )
			continue;
		if( it->first == exception )
			continue;

		// otherwise send
		LocalContext* lct = it->second;
		send( lct->m_Sockfd, msg.c_str(), msg.length(), 0);
	}
}


// --------------------------------------------
// -----   L O C A L   C O N T E X T   --------
// --------------------------------------------

LocalContext::LocalContext()
	: m_FIFO(1024)
{
}

LocalContext::~LocalContext()
{
	for( MQueue::iterator it = m_Outbox.begin(); 
		it != m_Outbox.end(); it++ )
	{
		if( (*it).m_Data != NULL )
			delete [] (*it).m_Data;
	}

	for( MQueue::iterator it = m_Inbox.begin(); 
		it != m_Inbox.end(); it++ )
	{
		if( (*it).m_Data != NULL )
			delete [] (*it).m_Data;
	}
}

bool LocalContext::AddToOutbox(Message msg)
{
	if( !m_Connected )
		return false;

	// lock the mutex
	pthread_mutex_lock(&m_Mutex);

	// add to the outbox
	m_Outbox.push_back(msg);

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);


	return true;	
}

Message LocalContext::GetInboxEntry(int index)
{
	if( index < 0 )
		return Message();

	Message ret;

	// lock the mutex
	pthread_mutex_lock(&m_Mutex);

	if( index < m_Inbox.size() )
	{
		int ii = 0;
		for( MQueue::iterator it = m_Inbox.begin();
			it != m_Inbox.end(); it++ )
		{
			if( ii == index )
			{
				ret = (*it);
				break;
			}
		}
	}

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);
	
	return ret;
}

int LocalContext::GetInboxSize()
{
	return m_Inbox.size();
}


void LocalContext::AddToInbox(Message msg)
{
	// lock the mutex
	pthread_mutex_lock(&m_Mutex);

	m_Inbox.push_back(msg);

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);
}

Message& LocalContext::GetNextMessage(bool pop)
{

	// lock the mutex
	pthread_mutex_lock(&m_Mutex);
	
	Message& ret = m_Outbox.front();

	if( pop )
	{
		m_Outbox.pop_front();
	}

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);

	return ret;
}

bool LocalContext::HasMessagePending()
{
	return ( !m_Outbox.empty() );
}

char LocalContext::FIFORead()
{
	// lock the mutex
	pthread_mutex_lock(&m_Mutex); 

	char ret = m_FIFO.Read();

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex); 

	return ret;
}

bool LocalContext::FIFOWrite(char c)
{
	// lock the mutex
	pthread_mutex_lock(&m_Mutex); 

	bool ret = m_FIFO.Write(c);

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex); 

	return ret;

}

// ---------------------------------
// ------- F I F O   B U F F E R ---
// ---------------------------------


FIFOBuffer::FIFOBuffer(size_t size)
		: m_Size(size)
{
	m_Data = new char[size];
	m_RdPtr = 0;
	m_WrPtr = 0;
}

FIFOBuffer::~FIFOBuffer()
{
	if( m_Data != NULL )
		delete [] m_Data;
}

bool FIFOBuffer::IsFull()
{
	//if(w_ptr>r_ptr)
	//ptr_diff<=w_ptr-r_ptr;
	//else if(w_ptr)
	//ptr_diff<=((f_depth-r_ptr)+w_ptr);
	//else ptr_diff<=0; end
	int ptrDiff = 0;
	if( m_WrPtr > m_RdPtr )
		ptrDiff = m_WrPtr - m_RdPtr;
	else if( m_WrPtr != 0 )
		ptrDiff = ((m_Size - m_RdPtr) + m_WrPtr);
	else
		ptrDiff = 0;

	//f_full_flag=(ptr_diff==(f_depth-1));
	return ( ptrDiff  == (m_Size - 1));	
}

bool FIFOBuffer::IsEmpty()
{
	//f_empty_flag=(ptr_diff==0);
	return ( m_RdPtr == m_WrPtr );
}

bool FIFOBuffer::Write(char c)
{
	if( !IsFull() )
	{
		m_Data[m_WrPtr] = c;
		m_WrPtr = (m_WrPtr == (m_Size-1))? 0 : m_WrPtr + 1;
		return true;
	}
	else
	{
		// cant write to a full buffer
		return false;
	}
}

char FIFOBuffer::Read()
{
	if( !IsEmpty() )
	{
		char ret = m_Data[m_RdPtr];
		m_RdPtr = (m_RdPtr == (m_Size-1))? 0 : m_RdPtr + 1; 

		return ret;
	}
	else
	{
		// it's empty...
		return 0;
	}
}


// ----------------------------------
// ---------   U I D D I C T --------
// ----------------------------------

UIDDict::UIDDict()
{
	// set the next UID
	m_NextUID = 1;
}

unsigned int UIDDict::GetNewUID()
{
	// check to see if we have an unregistered UID
	if( m_Queue.empty() )
	{
		// assign the next UID and increment the UID max
		unsigned int ret = m_NextUID;
		m_NextUID = m_NextUID + 1;
		return ret;
	}
	else
	{
		unsigned int ret = m_Queue.top();
		m_Queue.pop();
		return ret;
	}
}

void UIDDict::UnRegisterUID(unsigned int uid)
{
	// add the UID to the queue
	m_Queue.push( uid );
}

void UIDDict::ResetUID(unsigned int baseUID)
{
	// empty the queue
	while( !m_Queue.empty() )
	{
		m_Queue.pop();
	}

	m_NextUID = baseUID;
}
