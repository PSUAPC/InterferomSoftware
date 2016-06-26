#include "NWindow.h"
#include <signal.h>

// singleton global variable for the window
NWindow* g_Window = NULL;


NWindow::NWindow()
	: IWidget(NULL), m_Win(NULL), m_Inhibit(true)
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
	//mvprintw(m_Rows-1, 0, ">");		// print the command prompt
	//refresh();
	signal(SIGWINCH, &NWindow::SResize); // register the resize function
	m_Inhibit = false;			// allow the terminal to function
}

void NWindow::Shutdown()
{
	m_Inhibit = true;
	endwin();
}

void NWindow::ForceRedraw()
{
	Draw();
}

void NWindow::Draw()
{
	if( m_Inhibit ) return;

	pthread_mutex_lock(&m_Mutex);

	//OnResize(0,0, m_Cols, m_Rows);	
	// clear the window
	clear();

	IWidget::Draw();
	//mvprintw(m_Rows-1, 0, ">%s", "" );
	// refresh
	refresh();

	pthread_mutex_unlock(&m_Mutex);

}

void NWindow::SetChildDock(IWidget* child, DockOption opt)
{
}

void NWindow::SResize(int param)
{

	if( g_Window != NULL )
	{
		return;
		if( g_Window->m_Inhibit ) return;

		// get the new size
		getmaxyx(stdscr, g_Window->m_Rows, g_Window->m_Cols);
		
		// force a redraw
		g_Window->Redraw();
	}
}

bool NWindow::WaitForInput()
{


	if( m_Inhibit ) return true;
	
	// create the output variable
	bool out = true;
	
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
		
		for( ChildList::iterator it = m_Children.begin();
			it != m_Children.end(); it++ )
		{
			if( (*it) != NULL )
			{
				out &= (*it)->OnInput( c );
			}
		}
		break;
	}

	pthread_mutex_unlock(&m_Mutex);

	Redraw();
	return out;
}

void NWindow::Redraw()
{
	Draw();
}

void NWindow::OnResize(int x0, int y0, int w, int h)
{
	for(ChildList::iterator it = m_Children.begin(); 
		it != m_Children.end(); it++ )
	{
		if( (*it) != NULL )
		{
			(*it)->OnResize(0,0,m_Cols, m_Rows);
		}
	}
}
	



