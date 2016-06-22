#include "Contexts.h"


// --------------------------------
// -----   C O N T E X T   --------
// --------------------------------

void Context::Init()
{
	// create the mutexes
	pthread_mutex_init(&m_CreateMutex, NULL);
    pthread_mutex_init(&m_PollMutex, NULL);
    pthread_cond_init(&m_PollCondition, NULL);

    // create the thread attributes 
    pthread_attr_init(&m_Attr);
    pthread_attr_setdetachstate(&m_Attr, PTHREAD_CREATE_JOINABLE);

}

void Context::Shutdown()
{
	// clean up the attributes and mutexes
    pthread_attr_destroy(&m_Attr);
    pthread_mutex_destroy(&m_PollMutex);
	pthread_mutex_destroy(&m_CreateMutex);
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
