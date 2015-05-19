/// 
///   Name: WirelessComm.h
///   Purpose: Describe the WirelessComm API
///

#ifndef WIRELESS_COMM_H
#define WIRELESS_COMM_H

#include <string>
#include <list>
using std::string;
using std::list;

class WirelessComm
{
public:
	/// constructor
	WirelessComm();

	/// destructor
	~WirelessComm();

	/// Initialization function
	/// <returns> success </returns>
	bool Init();

	/// Shutdown function
	/// <returns> success </returns>
	bool Shutdown();

	/// function to cycle the connection
	/// <returns> success </returns>
	bool Cycle();

	/// function to write a data stream
	/// <param name='data'> input data stream pointer </param>
	/// <param name='length'> length of input data stream in bytes </param>
	/// <returns> length of data written, -1 for failure </returns>
	int WriteStream(char* data, int length);

	/// function to read the data in the buffer
	/// <param name='data'> a buffer pointer to populate </param>
	/// <returns> length of data stream allocated, -1 for failure </param>
	int ReadStream(char*& data);

	/// function to check for data in buffer
	/// <returns> 1 for has data, 0 for none, -1 for error </returns>
	int HasData();

	/// function to get error message
	/// <returns> error message </returns>
	string GetErrorMessage();

private:

	// ---- private functions ----

	// ---- private variables ----
	list<string> m_ErrorMsgs;
	
};


#endif //WIRELESS_COMM_H
