#ifndef __NWINDOW_H__
#define __NWINDOW_H__

#include "Includes.h"
#include <ncurses.h>
#include <string>
#include <list>
#include "WidgetInterface.h"

class SizerWidget;

class NWindow : public IWidget
{
public:
	NWindow();
	~NWindow();

	static NWindow* Get();
	void Init();
	void Shutdown();
	
	void ForceRedraw();
	
	void Inhibit(){ m_Inhibit = true; }
	bool WaitForInput();
	void SetMutex(pthread_mutex_t mutex){ m_Mutex = mutex; }
	void SetSizer(SizerWidget* sizer);
	void ForceResize();
private:
	pthread_mutex_t m_Mutex;
	int m_Rows;
	int m_Cols;
	bool m_Inhibit;
	WINDOW* m_Win;
	static void SResize(int param);	
	virtual void Draw();
	virtual void Redraw();
	virtual void OnResize(int x0, int y0, int w, int h);
	SizerWidget* m_Sizer;	

};




#endif //__NWINDOW_H__
