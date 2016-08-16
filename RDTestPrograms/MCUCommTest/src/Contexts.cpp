#include "Contexts.h"
#include "HexViewer.h"
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
	m_HexViewer = NULL;

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
	: m_FIFO(256), m_Verbose(false), m_Connected(false)
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
			// don't forget to increment
			ii++;
		}
		
	}

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);
	
	return ret;
}

void LocalContext::RemoveInboxEntry(int index)
{
	if( index < 0 )
		return;

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
				if( (*it).m_Data != NULL )
					delete []  (*it).m_Data;

				m_Inbox.erase(it);
				break;
			}
			// don't forget to increment
			ii++;
		}
		
	}

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);
	
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

void LocalContext::CheckFIFO()
{
	// check to see if the FIFO is empty
	if( m_FIFO.IsEmpty() )
		return;
	
	// lock the mutex
	pthread_mutex_lock(&m_Mutex);
	
	// start reading the FIFO
	bool ended = false;
	int tptr = m_FIFO.m_RdPtr;
	int msgStart = -1;
	int msgEnd = -1;
	int mvRdPtr = m_FIFO.m_RdPtr;

	while( !ended )
	{
	
		// check for an escape character
		if( m_FIFO.m_Data[tptr] == 0x1B )
		{
			// check the next character
			int ptptr = tptr;
		 	tptr = GetNextPtr(tptr);
			mvRdPtr = tptr;
			if( tptr == m_FIFO.m_WrPtr )
			{
				// we hit the end of the FIFO
				ended = true;
			}
			else
			{
				switch( m_FIFO.m_Data[tptr] )
				{
				case 0x1B:
					// we have a general escape character
					// do nothing for now
					break;
				case 0x01: // start of frame
					if( msgStart == -1 )
					{
						// set the frame start
						msgStart = tptr;
					}
					else
					{
						if( m_Verbose )
						{
							NTerminal::Get()->PrintToStdout("TTY ERROR: StartFrame \
								Encountered before EndFrame");
						}
						// end here
						ended = true;

						// move the FIFO ptr
						m_FIFO.m_RdPtr = ptptr;
						
					}
					break;
				case 0x04: // end of frame
					if( msgStart == -1 )
					{
						if( m_Verbose )
						{
							NTerminal::Get()->PrintToStdout("TTY ERROR: EndFrame \
								Encountered before StartFrame");
						}
						// end here
						ended = true;

						// move the FIFO ptr to go past the end of frame
						m_FIFO.m_RdPtr = GetNextPtr(tptr);

					}
					else
					{
						msgEnd = tptr;
						ended = true;
					}
					break;
				default:
					// we have an invalid escape sequence
					break;
				}
			}
		
		}
		else
		{
			// do nothing
		}


		// update the tptr
		tptr = GetNextPtr(tptr); 
		
		// reached the end of the FIFO
		if( tptr == m_FIFO.m_WrPtr )
			ended = true;
	}	

	// now lets check to see if we have a msg
	if( (msgStart != -1) && (msgEnd != -1) )
	{
	
		if( m_Verbose )
			NTerminal::Get()->PrintToStdout("TTY: Message Packet Found");

		// remove any garbage at the front by moving the ptr
		m_FIFO.m_RdPtr = msgStart; // should be the first byte
		
		// create a checksum variable and clear it
		char checksum = 0;

		// now the first element is the 0x01 from the frame
		// start, pull it and dump it
		m_FIFO.Read();

	
		// the next element is the size	
		unsigned char size = m_FIFO.Read();

		char* cdata = new char[size];

		if( m_Verbose )
		{
			char str[100];
			sprintf(str, "len: %d", size);
			NTerminal::Get()->PrintToStdout(str);
		}
		// overrun value
		bool overrun = false;

		// update the checksum
		checksum += size;

		// now read the message
		for( int ii = 0; (ii < size) && !overrun; ii++ )
		{
			// check for overflow
			if( m_FIFO.m_RdPtr == msgEnd )
			{
				overrun = true;
				continue;
			}
			
			// read the data
			char data = m_FIFO.Read();

			// check for escape characters
			if( data == 0x1B )
			{
				char tdat = m_FIFO.Read();
				size = size - 1;
				switch( tdat )
				{
				case 0x1B:
					// escaped escape
					data = tdat;
					break;
				default:
					// consume the next character too
					data = m_FIFO.Read();
					size = size - 1;
					if( m_FIFO.m_RdPtr == msgEnd )
					{
						overrun = true;
					}	
					break;
				}
			}

			// we have real data here
			if( !overrun )
			{
				checksum += data;
				cdata[ii] = data;	
			}
		
		}
		char calcChecksum = checksum;
		char readChecksum = m_FIFO.Read();
		// now we need to pull out the checksum
		//checksum += m_FIFO.Read();
		checksum += readChecksum;

		// we can now push the message
		// if size was decreased, we can ignore the loss of bytes
		// in cdata since it should be negligable
		Message msg;
                msg.m_Data = cdata;
                msg.m_Len = size;
		msg.m_Src = 0; // TTY
		msg.m_ReadChecksum = readChecksum;
		msg.m_CalcChecksum = calcChecksum;
	
		if( checksum != 0 )
		{
			msg.m_MissMatch = true;
			if( m_Verbose )
				NTerminal::Get()->PrintToStdout("TTY: Checksum mismatch");
		}
		else
		{
			msg.m_MissMatch = false;
		}
			
		m_Inbox.push_back(msg); 
		
		m_FIFO.m_RdPtr = msgEnd;
	
			
		

		if( overrun && m_Verbose )
			NTerminal::Get()->PrintToStdout("TTY FIFO: Frame Overflow");  
			
	}

	// unlock the mutex
	pthread_mutex_unlock(&m_Mutex);

	// update the hex viewer
	m_Context->m_HexViewer->Update();		
}

int LocalContext::GetNextPtr(int ptr)
{
	return (ptr == (m_FIFO.m_Size-1))? 0 : ptr + 1;
}

void LocalContext::ClearFIFO()
{
	// lock the mutex
	pthread_mutex_lock(&m_Mutex); 

	m_FIFO.m_RdPtr = 0;
	m_FIFO.m_WrPtr = 0;

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
{return ( !m_Outbox.empty() );
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
