#include "NWindow.h"
#include <signal.h>

// singleton global variable for the window
NWindow* g_Window = NULL;


NWindow::NWindow()
	: IWidget(NULL), m_Win(NULL)
{
	// singleton assignment
	if( g_Window == NULL )
	{
		g_Window = this;
	}
	else
	{
		throw "Atempting to create a second Window, which is of type singleton";
	}
}

NWindow::~NWindow()
{
	// set the singleton global to null
	g_Window = NULL;
}

NWindow* NWindow::Get()
{ 
	// static function get the singleton instance
	return g_Window; 
}

void NWindow::Init()
{
	if( !m_Inhibit )
		return; // something is wrong

	m_Win = initscr();			// create the screen
	noecho();				// don't echo to the screen
	keypad(m_Win, TRUE);	 		// enable keypad
	cbreak();				// disable break commands
	getmaxyx(m_Win, m_Rows, m_Cols );	// get the screen size
	clear();				// clear the screen
	refresh();	
	mvprintw(m_Rows-1, 0, ">");		// print the command prompt
	refresh();
	signal(SIGWINCH, &NWindow::OnResize); // register the resize function
	m_Inhibit = false;			// allow the terminal to function
}

void NWindow::Shutdown()
{
	m_Inhibit = true;
	endwin();
}

void NWindow::Redraw()
{
	if( m_Inhibit ) return;

	pthread_mutex_lock(&m_Mutex);
	
	// clear the window
	clear();

	// refresh
	refresh();

	pthread_mutex_unlock(&m_Mutex);

}

void NWindow::OnResize(int param)
{

	if( g_Window != NULL )
	{
		if( g_Window->m_Inhibit ) return;

		// get the new size
		getmaxyx(stdscr, g_Window->m_Rows, g_Window->m_Cols);
		
		// force a redraw
		g_Window->Redraw();
	}
}

std::string NWindow::WaitForInput()
{

	std::string temp = "";

	if( m_Inhibit ) return temp;
	
	// set timeout
	//timeout(10);

	int c = wgetch(m_Win);
	
	pthread_mutex_lock(&m_Mutex);

	switch( c )
	{
	// error character
	case ERR:
		break;
	case KEY_STAB:
		break;
	default:
		break;
	}

	pthread_mutex_unlock(&m_Mutex);

	Redraw();
	return temp;
}




