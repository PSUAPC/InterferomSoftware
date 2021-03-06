#include "NTerminal.h"
#include "NShell.h"
#include <signal.h>
#include <vector>

// singleton global variable for the terminal
NTerminal* g_Terminal = NULL;


NTerminal::NTerminal(IWidget* parent)
	: PanelWidget(parent),  m_HistorySize(0), m_StdoutSize(0), 
	m_StdoutDispSize(0), m_HistoryPointer(0), m_Shell(0)
{
	// singleton assignment
	if( g_Terminal == NULL )
	{
		g_Terminal = this;
		// also initialize the shell
		m_Shell = new NShell();
	}
	else
	{
		throw "Atempting to create a second Terminal, which is of type singleton";
	}
}

NTerminal::~NTerminal()
{
	if( m_Shell != 0 )
		delete m_Shell;

	// set the singleton global to null
	g_Terminal = NULL;
}

NTerminal* NTerminal::Get()
{ 
	// static function get the singleton instance
	return g_Terminal; 
}

void NTerminal::RegisterChild(IWidget* child)
{
	throw "Adding a Child to a terminal widget is not allowed";
}

void NTerminal::UnRegisterChild(IWidget* child)
{
	// do nothing
}

void NTerminal::Draw(CursorReturn& cret)
{
	// draw the parent first
	PanelWidget::Draw(cret);
	
	int bot = m_H + m_Y0;
	int maxLines = m_StdoutDispSize;
	// print the stdout
	if( m_StdoutDispSize == -1 )
	{
		maxLines = m_H-1;
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
			mvprintw(bot-2-ii, m_X0, "%s", (*it).c_str());
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
			
			std::string temp = (*it);
			
			int nlines = 0;
			if( (ii + nlocs + 1) > maxLines )
			{
				// calculate the number of lines that we can draw
				nlines = maxLines - (ii + 1);
				
				// find where to break the string to draw those lines
				tloc = 0;
				for(int jj = 0; jj < (nlocs - nlines); jj++ )
				{
					tloc = (*it).find("\n", tloc+1);
				}

			
				// remove the part that will not be printed (is cutoff)
				// from the string
				if( tloc < (*it).length() )
				{
					temp = temp.substr(tloc+1, temp.length()-tloc-1);
				}
			}
			else
			{
				nlines = nlocs;
			}

			tloc = 0;
			for(int jj = 0; jj < nlocs; jj++ )
			{
				
				// find the \n location, and strip the forward
				tloc = temp.find("\n", 0);
				std::string ttemp = temp.substr(0, tloc);
				
				// print the line in reverse order
				mvprintw(bot-2-ii-nlines+jj, m_X0, "%s",ttemp.c_str()); 
				
				// strip off the part we just printed
				temp = temp.substr(tloc+1, temp.length()-tloc-1);
			}

			ii = ii + nlines + 1;
		}
	}
	
	// print the line
	mvprintw(bot-1, m_X0, ">%s", m_Line.c_str() );
	if( m_Focused )
	{
		cret.m_X = m_X0 + 1 + m_Line.length();
		cret.m_Y = bot - 1;
	}

}
bool NTerminal::OnFocus(FocusDir focusdir)
{
	switch(focusdir)
	{
	case IWidget::FOCUS_FWD:
	case IWidget::FOCUS_BACK:
		m_Focused = !m_Focused;
		break;
	case IWidget::FOCUS_UP:
		m_Focused = false;
	}

	return m_Focused;
}

void NTerminal::OnResize(int x0, int y0, int w, int h)
{

	PanelWidget::OnResize(x0,y0,w,h);
	//m_X0 = x0;
	//m_Y0 = y0;
	//m_W = w;
	//m_H = h;
		// get the new size
		//getmaxyx(stdscr, g_Terminal->m_Rows, g_Terminal->m_Cols);
		
}

bool NTerminal::OnInput(int c)
{

	if( !m_Focused )
		return true;

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
			//temp = m_Line;
		
			// push it to the queue
			AddToHistory(m_Line);
			InternalPrint(">" + m_Line);

			// check for the exit condition
			if( m_Line.find("exit") != -1 )
			{
				return false;
			}

			// lets try to execute the shell command
			m_Shell->ParseCommand(m_Line);

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


	return true;
}

void NTerminal::PrintToStdout(std::string str)
{
	// lock the mutex
	pthread_mutex_lock(&m_Mutex);

	
	m_Stdout.push_front(str);
	if( m_Stdout.size() > m_StdoutSize )
	{
		m_Stdout.pop_back(); 
	}
	
	pthread_mutex_unlock(&m_Mutex);

	// force redraw
	IWidget::Redraw();

}
void NTerminal::InternalPrint(std::string str)
{


	m_Stdout.push_front(str);
	if( m_Stdout.size() > m_StdoutSize )
	{
		m_Stdout.pop_back(); 
	}
	
}

void NTerminal::AddToHistory(std::string str)
{


	m_History.push_front(str);
	if( m_History.size() > m_HistorySize )
	{
		m_History.pop_back();
	}

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



