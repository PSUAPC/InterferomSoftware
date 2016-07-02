#include "NWindow.h"
#include "SizerWidget.h"
#include <signal.h>
#include "NTerminal.h"

// singleton global variable for the window
NWindow* g_Window = NULL;


NWindow::NWindow()
	: PanelWidget(NULL), m_Win(NULL), m_Inhibit(true)
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
	clear();				// clear the screen
	refresh();	
	getmaxyx(m_Win, m_Rows, m_Cols );	// get the screen size
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
	Redraw();
}
void NWindow::ForceResize()
{
	
	OnResize(0,0, m_Cols, m_Rows);
}
void NWindow::Draw(CursorReturn& cret)
{
	if( m_Inhibit ) return;

	// the resize callback doesnt seem to work
	// so we will have to manually do it
	int w, h;
	// need to use this struct to get the
	// current size
    	struct winsize ws;
    	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	
	// pull out the variables
	w = ws.ws_col;
	h = ws.ws_row;

	// check for a change in size
	// if there is no size change, no need
	// to update children
	if( (h != m_Rows) || (w != m_Cols) )
	{
		m_Rows = h;
		m_Cols = w;
		// force a resize
		// this will also call the draw function again	
		ForceResize();
	}	
	else
	{
		pthread_mutex_lock(&m_Mutex);
	
		//OnResize(0,0, m_Cols, m_Rows);	
		// clear the window
		clear();

		IWidget::Draw(cret);
		move(cret.m_Y, cret.m_X);
		//mvprintw(m_Rows-2, 0, ">%s", "" );
		// refresh
		refresh();

		pthread_mutex_unlock(&m_Mutex);
	}
}


void NWindow::SResize(int param)
{

	if( g_Window != NULL )
	{
		return;
		if( g_Window->m_Inhibit ) return;

		NTerminal::Get()->PrintToStdout("resizing");
		// get the new size
		getmaxyx(g_Window->m_Win, g_Window->m_Rows, g_Window->m_Cols);
		g_Window->ForceResize();
	
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
	//pthread_mutex_lock(&m_Mutex);

	int c = wgetch(m_Win);
	const char* key = keyname(c);
	
	switch( c )
	{
	// error character
	case ERR:
		break;
	case KEY_STAB:
	case '\t':
		/*if( (key != NULL) && (key[0] == '^') )
		{
			
			//for(int i = 0; (i < 10) && !onfocus(iwidget::focus_up); i++);
		}
		else*/
		{
			for(int i = 0; (i < 10) && !OnFocus(IWidget::FOCUS_BACK); i++);
		}
		break;
	case KEY_PPAGE: // page_up / home
		{
			bool res;
			res = OnFocus(IWidget::FOCUS_UP);
			if( !res )
				OnFocus(IWidget::FOCUS_FWD);
		}
		break;
	case KEY_CTAB:
	case KEY_BTAB:
		for(int i = 0; (i < 10) && !OnFocus(IWidget::FOCUS_FWD); i++);
		break;
	default:
		
		{
			for( ChildList::iterator it = m_Children.begin();
				it != m_Children.end(); it++ )
			{
				if( (*it) != NULL )
				{
					out &= (*it)->OnInput( c );
				}
			}
		}
		break;
	}

	//pthread_mutex_unlock(&m_Mutex);

	Redraw();
	return out;
}

bool NWindow::OnFocus(FocusDir focusdir)
{
	bool anyFocused = false;
	// check to see if any are focused
	for(ChildList::iterator it = m_Children.begin();
		it != m_Children.end(); it++)
	{
		if( (*it) != NULL )
			anyFocused = anyFocused || (*it)->IsFocused();
	}

	bool found = false;	
	switch(focusdir)
	{
	case IWidget::FOCUS_UP:
		// propgate to children
		
	case IWidget::FOCUS_FWD:
		// go based on direction
		for(ChildList::iterator it = m_Children.begin();
			it != m_Children.end(); it++ )
		{
			if( (*it) != NULL )
			{
				found = found || (*it)->IsFocused();

				
				if( found || !anyFocused )
				{
					if( (*it)->OnFocus( focusdir ) )
					{
						return true;
					}	
				}
			}
		}
		break;
	case IWidget::FOCUS_BACK:
		// go based on direction
		for(ChildList::reverse_iterator rit = m_Children.rbegin();
			rit != m_Children.rend(); rit++ )
		{
			if( (*rit) != NULL )
			{
				found = found || (*rit)->IsFocused();

				if( found || !anyFocused )
				{
					if( (*rit)->OnFocus( focusdir ) )
					{
						return true;
					}	
				}
			}
		}
		break;

	}
	return false;
}

void NWindow::Redraw()
{
	CursorReturn cret;
	cret.m_X = m_W + 1;
	cret.m_Y = m_H + 1;
	Draw(cret);
}

void NWindow::OnResize(int x0, int y0, int w, int h)
{
	
	PanelWidget::OnResize(x0,y0,w,h);
	Redraw();
}
	



