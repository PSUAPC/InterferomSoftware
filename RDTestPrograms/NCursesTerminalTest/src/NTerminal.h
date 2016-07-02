
#ifndef __NTERMINAL_H__
#define __NTERMINAL_H__

#include "Includes.h"
#include <ncurses.h>
#include <string>
#include <list>
#include "WidgetInterface.h"
#include "PanelWidget.h"

class NShell;


class NTerminal : public PanelWidget
{
	typedef std::list<std::string> History;
public:
	NTerminal(IWidget* parent);
	~NTerminal();

	static NTerminal* Get();
	
	void PrintToStdout(std::string str);
	void SetHistorySize(int size) { m_HistorySize = size; }
	void SetStdoutSize(int size) { m_StdoutSize = size; }
	void SetStdoutDispSize(int size) { m_StdoutDispSize = size; }
	void SetMutex(pthread_mutex_t mutex){ m_Mutex = mutex; }
	void ClearHistory();
	void ClearStdout();
	void PrintHistory();
	virtual bool OnFocus(FocusDir focusdir);
	
private:
	pthread_mutex_t m_Mutex;
	std::string m_Line;
	History m_Stdout;
	History m_History;
	NShell* m_Shell;
	int m_HistorySize;
	int m_StdoutSize;
	int m_StdoutDispSize;
	int m_HistoryPointer;
	void AddToHistory(std::string str);
	void CopyHistoryAtPointer();
	void InternalPrint(std::string str);
	virtual void Draw(CursorReturn& cret);
	virtual void OnResize(int x0, int y0, int w, int h);
	virtual void RegisterChild(IWidget* child);
	virtual void UnRegisterChild(IWidget* child); 
	virtual bool OnInput(int in);  
};


#endif //__NTERMINAL_H__

