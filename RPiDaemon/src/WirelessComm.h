/// 
///   Name: WirelessComm.h
///   Purpose: Describe the WirelessComm API
///


/// ------------------ NOTES ------------------
///  + DIP Switch configuration should be:
///    (1,0,0,0,0,0) to enable multi-point, and RS232
///  + The defauly baud rate is 9600, but can be set higher
///

#ifndef WIRELESS_COMM_H
#define WIRELESS_COMM_H

#include <string>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>		//Used for UART
#include <fcntl.h>		//Used for UART
#include <termios.h>		//Used for UART

#include "CommBuffer.h"

using std::string;
using std::list;


#define UART_COMMFILE "/dev/ttyAMA0"
#define UART_BAUD B9600
#define RXBUFF_SIZE 65507


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
	/// <param name='data'> a buffer pointer to allocate and populate </param>
	/// <returns> length of data stream allocated, -1 for failure </param>
	int ReadStream(char*& data);

	/// function to check for data in buffer
	/// <returns> 1 for has data, 0 for none, -1 for error </returns>
	int HasData();

	/// function to get error message
	/// <returns> error message </returns>
	string GetErrorMessage();

	/// function to set the transmission level
	/// <param name='level'> Tx Level: 
	///	0 - 1mW
	///     1 - 10 mW
	///	2 - 100 mW
	///	3 - 500 mW
	///	4 - 1 W
	/// </param>
	void SetTxLevel(int level);

	/// function to set the modem's sleep mode
	/// <param name='mode'> Mode Setting:
	///	0 - Disabled
	///	1 - Pin Sleep
	///	2 - Serial Port Sleep
	///	3 - [reserved]
	///	4 - Cyclic 1.0 second sleep
	///		(RF modem wakes every
	///		1.0 seconds)
	///	5 - Cyclic 2.0 second sleep
	///	6 - Cyclic 4.0 second sleep
	///	7 - Cyclic 8.0 second sleep
	///	8 - Cyclic 16.0 second sleep
	/// </param>
	void SetSleepMode(int mode);

private:

	// ---- private functions ----
	void TxSend(unsigned char cmd, char* data, int len);

	// ---- private variables ----
	list<string> m_ErrorMsgs;
        int m_Filestream;	
	CommBuffer m_RxBuffer;
	// do not need a TxBuffer, since send is non-blocking
};


#endif //WIRELESS_COMM_H
