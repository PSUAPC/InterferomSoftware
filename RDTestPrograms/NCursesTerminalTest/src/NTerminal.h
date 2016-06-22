
#ifndef __NTERMINAL_H__
#define __NTERMINAL_H__

#include "Includes.h"
#include <ncurses.h>
#include <string>
#include <list>

class NTerminal
{
	typedef std::list<std::string> History;
public:
	NTerminal();
	~NTerminal();

	static NTerminal* Get();
	void Init();
	void Shutdown();
	void Redraw();
	void Inhibit(){ m_Inhibit = true; }
	void PrintToStdout(std::string str);
	std::string WaitForInput();
	void SetHistorySize(int size) { m_HistorySize = size; }
	void SetStdoutSize(int size) { m_StdoutSize = size; }
	void SetStdoutDispSize(int size) { m_StdoutDispSize = size; }
	void SetMutex(pthread_mutex_t mutex){ m_Mutex = mutex; }
	void ClearHistory();
	void ClearStdout();
	void PrintHistory();
private:
	pthread_mutex_t m_Mutex;
	int m_Rows;
	int m_Cols;
	bool m_Inhibit;
	std::string m_Line;
	WINDOW* m_Win;
	History m_Stdout;
	History m_History;
	int m_HistorySize;
	int m_StdoutSize;
	int m_StdoutDispSize;
	int m_HistoryPointer;
	void AddToHistory(std::string str);
	static void OnResize(int param);
	void CopyHistoryAtPointer();
};


#endif //__NTERMINAL_H__

