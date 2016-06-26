#include "NTerminal.h"
#include <signal.h>
#include <vector>

// singleton global variable for the terminal
NTerminal* g_Terminal = NULL;


NTerminal::NTerminal()
	: IWidget(NULL), m_Win(NULL), m_HistorySize(0), m_StdoutSize(0), 
	m_StdoutDispSize(0), m_Inhibit(true), m_HistoryPointer(0)
{
	// singleton assignment
	if( g_Terminal == NULL )
	{
		g_Terminal = this;
	}
	else
	{
		throw "Atempting to create a second Terminal, which is of type singleton";
	}
}

NTerminal::~NTerminal()
{
	// set the singleton global to null
	g_Terminal = NULL;
}

NTerminal* NTerminal::Get()
{ 
	// static function get the singleton instance
	return g_Terminal; 
}

void NTerminal::Init()
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
	signal(SIGWINCH, &NTerminal::OnResize); // register the resize function
	m_Inhibit = false;			// allow the terminal to function
}

void NTerminal::Shutdown()
{
	m_Inhibit = true;
	endwin();
}

void NTerminal::Redraw()
{
	if( m_Inhibit ) return;

	pthread_mutex_lock(&m_Mutex);
	
	// clear the window
	clear();

	int maxLines = m_StdoutDispSize;
	// print the stdout
	if( m_StdoutDispSize == -1 )
	{
		maxLines = m_Rows-1;
	}

	int ii = 0;
	for( History::iterator it = m_Stdout.begin();  
		(it != m_Stdout.end()) && (ii != maxLines); it++ )
	{
		int tloc = -1;
		// find the number of \n in the string
		tloc = (*it).find("\n", 0 ); 
		if( tloc == -1 )
		{
			mvprintw(m_Rows-2-ii, 0, "%s", (*it).c_str());
			ii++;
		}
		else
		{
			// search for the number of \n characters
			// to figure out how many lines we need to displace this string by
			int nlocs = 1;
			tloc = (*it).find("\n", tloc+1);
			while( tloc != -1 )
			{
				nlocs++;
				tloc = (*it).find("\n", tloc+1);
 
			}

			mvprintw(m_Rows-2-ii-nlocs, 0, "%s",(*it).c_str());
			ii = ii + nlocs + 1;
		}
	}
	// print the line
	mvprintw(m_Rows-1, 0, ">%s", m_Line.c_str() );
	// refresh
	refresh();

	pthread_mutex_unlock(&m_Mutex);

}

void NTerminal::OnResize(int param)
{

	if( g_Terminal != NULL )
	{
		if( g_Terminal->m_Inhibit ) return;

		// get the new size
		getmaxyx(stdscr, g_Terminal->m_Rows, g_Terminal->m_Cols);
		
		// force a redraw
		g_Terminal->Redraw();
	}
}

std::string NTerminal::WaitForInput()
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
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	case KEY_UP:
		
		m_HistoryPointer++;
		// make sure we are not out of range
		if( m_HistoryPointer > m_History.size() )
		{
			m_HistoryPointer--;
			// nothing to do
		}
		else
		{
			CopyHistoryAtPointer();
		}
		
		break;
	case KEY_DOWN:
		m_HistoryPointer--;
		if( m_HistoryPointer <= 0 )
		{
			m_HistoryPointer = 0;
			m_Line.clear();
		}
		else
		{
			CopyHistoryAtPointer();
		}
		break;	
	// new line
	case '\n':
	case KEY_ENTER:
		if( m_Line.length() > 0 )
		{
			// save the line
			temp = m_Line;
		
			pthread_mutex_unlock(&m_Mutex);

			// push it to the queue
			AddToHistory(m_Line);
			PrintToStdout(">" + m_Line);

			pthread_mutex_lock(&m_Mutex);

			// clear our copy
			m_Line.clear();

			// set the history pointer to zero
			m_HistoryPointer = 0;
		}  
		
		break;
	// delete characters
	case KEY_BACKSPACE:
	case '\b':
	case 127:
		if( m_Line.length() > 0 )
		{
			m_Line = m_Line.substr(0, m_Line.length()-1);
			
		}
		break;
	default:
		m_Line = m_Line + char(c);
		
		break;
	}

	pthread_mutex_unlock(&m_Mutex);

	Redraw();
	return temp;
}


void NTerminal::PrintToStdout(std::string str)
{
	if( m_Inhibit ) return;

	// lock the mutex
	pthread_mutex_lock(&m_Mutex);

	m_Stdout.push_front(str);
	if( m_Stdout.size() > m_StdoutSize )
	{
		m_Stdout.pop_back(); 
	}
	
	pthread_mutex_unlock(&m_Mutex);

	// force redraw
	Redraw();
}

void NTerminal::AddToHistory(std::string str)
{
	if( m_Inhibit ) return;

	pthread_mutex_lock(&m_Mutex);

	m_History.push_front(str);
	if( m_History.size() > m_HistorySize )
	{
		m_History.pop_back();
	}
	pthread_mutex_unlock(&m_Mutex);

}

void NTerminal::CopyHistoryAtPointer()
{

	int tptr = 0;
	for( History::iterator it = m_History.begin(); 
		it != m_History.end(); it++ )
	{
		tptr++;

		if( tptr == m_HistoryPointer )
		{
			m_Line = (*it);
			break;
		}
	
		
	}
}

void NTerminal::PrintHistory()
{
	int ii = 1;
	for( History::reverse_iterator it = m_History.rbegin();
		it != m_History.rend(); it++ )
	{
		char num[10];
		sprintf(num, " %d ", ii);
		PrintToStdout( num + (*it));
		ii++;
	}
}

void NTerminal::ClearHistory()
{
	m_History.clear();
}
void NTerminal::ClearStdout()
{
	m_Stdout.clear();
}



