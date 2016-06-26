#ifndef __NWINDOW_H__
#define __NWINDOW_H__

#include "Includes.h"
#include <ncurses.h>
#include <string>
#include <list>
#include "WidgetInterface.h"

class NWindow : public IWidget
{
	typedef std::list<std::string> History;
public:
	NWindow();
	~NWindow();

	static NWindow* Get();
	void Init();
	void Shutdown();
	void Redraw();
	void Inhibit(){ m_Inhibit = true; }
	std::string WaitForInput();
	void SetMutex(pthread_mutex_t mutex){ m_Mutex = mutex; }
private:
	pthread_mutex_t m_Mutex;
	int m_Rows;
	int m_Cols;
	bool m_Inhibit;
	WINDOW* m_Win;
	static void OnResize(int param);
};




#endif //__NWINDOW_H__
