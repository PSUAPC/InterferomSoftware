/// 
///   Name: CommBuffer.cpp
///   Purpose: Implement the Fixed buffer for reading / sending comm data
///

#include "CommBuffer.h"

CommBuffer::CommBuffer(int buffSize)
{
	m_BuffSize = buffSize;
	m_BuffLoc = 0;
	m_Buff = new char[buffSize];
}
CommBuffer::~CommBuffer()
{
	if (m_Buff)
		delete[] m_Buff;
}
void CommBuffer::Clear()
{
	m_BuffLoc = 0;
}
int CommBuffer::GetFilledSize()
{
	return m_BuffLoc;
}
int CommBuffer::GetEmptySize()
{
	return m_BuffSize - m_BuffLoc;
}
char* CommBuffer::GetBuff()
{
	return (m_Buff + m_BuffLoc);
}

char* CommBuffer::GetBuffStart()
{
	return m_Buff;
}
void CommBuffer::SetBuffReadLen(int len)
{
	m_BuffLoc += len;
}


