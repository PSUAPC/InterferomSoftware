/// 
///   Name: CommBuffer.h
///   Purpose: Describe the Fixed buffer for reading / sending comm data
///

#include <stdio.h>
#include <stdlib.h>

#ifndef COMMBUFFER_H
#define COMMBUFFER_H

/// -------------- NOTES ---------------
///   + App reading sequence:
///		Fcn: uint8* ReadData(int& len) : returns data and length read
///     		len = m_RecvBuff.GetFilledSize();
///			if ((len > 0) && (len < m_BuffSize) )
///			{
///				outDat = new uint8[len];
///				memcpy(outDat, m_RecvBuff.GetBuffStart(), len);
///				m_RecvBuff.Clear();
///			}
///
///   + App writing sequence
///   		Fcn: int SendData(int len, char* data): returns sent length
/// 			int32 freeSpace = m_SendBuff.GetEmptySize();
///			if (freeSpace > 0)
///			{
///				if (freeSpace > len)
///				{
///					outLen = len;
///					memcpy(m_SendBuff.GetBuff(), data, len);
///					m_SendBuff.SetBuffReadLen(len);
///				}
///				else
///				{
///					outLen = len - freeSpace;
///					memcpy(m_SendBuff.GetBuff(), data, outLen);
///					m_SendBuff.SetBuffReadLen(outLen);
///
///				}
///			}
///			else
///			{
///				outLen = 0;
///			}
///
///	+ Comm Reading sequence
///		if( m_RecvBuff.GetEmptySize() > 0)
///		{
///			int len = (len < m_RecvBuff.GetEmptySize()) ? len : m_RecvBuff.GetEmptySize();
///			int32 Read = 0;
///			ConnectionSocket->Recv(m_RecvBuff.GetBuff(), len, Read);
///			m_RecvBuff.SetBuffReadLen(Read);
///		}
///
///	+ Comm Writing Sequence
///		int size = m_SendBuff.GetFilledSize();
///		if (size > 0)
///		{
///			int wrote = 0;
///			char* dat = m_SendBuff.GetBuffStart();
///			while (wrote < int(size))
///			{
///				if (!ConnectionSocket->Send(dat, size, wrote))
///					break; // send failure
///				// shift the buffer pointer
///				dat = dat + wrote;
///			}
///			// clear the buffer since it has all been sent
///			if (wrote >= int32(size))
///				m_SendBuff.Clear();
///		}
///

class CommBuffer
{
public:
	CommBuffer(int buffSize);
	~CommBuffer();

	void Clear();
	int GetEmptySize();
	int GetFilledSize();
	char* GetBuff();
	char* GetBuffStart();
	void SetBuffReadLen(int len);

private:
	int m_BuffSize;
	int m_BuffLoc;
	char* m_Buff;
};

#endif //COMMBUFFER_H
