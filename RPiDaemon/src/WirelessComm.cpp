/// 
///   Name: WirelessComm.cpp
///   Purpose: Define the WirelessComm API
///

#include "WirelessComm.h"

/// constructor
WirelessComm::WirelessComm()
{
}

/// destructor
WirelessComm::~WirelessComm()
{
}

/// Initialization function
/// <returns> success </returns>
bool WirelessComm::Init()
{
	return false;
}

/// Shutdown function
/// <returns> success </returns>
bool WirelessComm::Shutdown()
{
	// clear the error logs
	m_ErrorMsgs.clear();


	return false;
}

/// function to cycle the connection
/// <returns> success </returns>
bool WirelessComm::Cycle()
{
	return false;
}

/// function to write a data stream
/// <param name='data'> input data stream pointer </param>
/// <param name='length'> length of input data stream in bytes </param>
/// <returns> length of data written, -1 for failure </returns>
int WirelessComm::WriteStream(char* data, int length)
{
	return -1;
}

/// function to read the data in the buffer
/// <param name='data'> a buffer pointer to populate </param>
/// <returns> length of data stream allocated, -1 for failure </param>
int WirelessComm::ReadStream(char*& data)
{
	data = NULL;
	return -1;
}

/// function to check for data in buffer
/// <returns> 1 for has data, 0 for none, -1 for error </returns>
int WirelessComm::HasData()
{
	return -1;
}

/// function to get error message
/// <returns> error message </returns>
string WirelessComm::GetErrorMessage()
{
	string msg;
	for(list<string>::iterator it = m_ErrorMsgs.begin();
		it != m_ErrorMsgs.end(); it++)
	{
		msg = msg + (*it);
		msg = msg + "\n";
	} 

	return msg;
}

