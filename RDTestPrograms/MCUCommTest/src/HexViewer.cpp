#include "HexViewer.h"
#include <ncurses.h>
#include <stdlib.h>
#include "CommandInterface.h"
#include "Contexts.h"

HexViewer::HexViewer(IWidget* parent, int style)
	: PanelWidget(parent, style), m_Len(0), m_Stream(NULL),	
	m_StartLine(0), m_Src(0), m_MsgNum(0)
{
}

HexViewer::~HexViewer()
{
}

void HexViewer::RegisterChild(IWidget* child)
{
	throw "Adding a Child to a hexviewer widget is not allowed";   
}

void HexViewer::Draw(CursorReturn& cret)
{
	// draw the parent first
	PanelWidget::Draw(cret);  
	
	// get the total msg size
	int msgTot = 0;
	switch(m_Src)
	{
	case 0: // TTY
		msgTot = Context::Get()->m_TTYThread->GetInboxSize();
		break;
	case 1: // TCP
		msgTot = Context::Get()->m_TCPThread->GetInboxSize(); 
		break;
	default:
		// do nothing
		break;
	}	


	// draw the label at the top
	mvprintw(m_Y0, m_X0+5, "%s", m_Label.c_str());
	mvprintw(m_Y0, m_X0+5+m_Label.length()+2, "(%d/%d)", m_MsgNum, msgTot);

	// print the header
	std::string temp;
	temp = _S("offset(h)\t 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F");
	mvprintw(m_Y0+2, m_X0+2, "%s", temp.c_str());

	// now we need to go down the list
	int nlines = m_Len/16 + 1;
	int s0 = m_StartLine;
	if( nlines > (m_H-6) )
	{
		nlines = m_H-6;
		
	}
	else
	{
		s0 = 0;
	}

	for( int ii = 0; ii < nlines; ii ++ )
	{

		if( (ii + s0) >= (m_Len/16 + 1) )
			break;

		mvprintw(m_Y0+4+ii, m_X0+2, "%010X", ((ii + s0)*16));



		for(int jj = 0; jj < 16; jj++ )
		{
			int pos = jj + (s0 + ii)*16;
			
			// make sure we don't overrun the stream
			if( pos >= m_Len )
				break;

			// otherwise, print the value
			mvprintw(m_Y0+4+ii, m_X0+16+jj*3, "%02X", m_Stream[pos]);

			// and print the character
			mvprintw(m_Y0+4+ii, m_X0+16+16*3+4+jj, "%c", SanitizeChar( m_Stream[pos] ) );
		}

	}

	// print the instructions
	mvprintw(m_Y0 + m_H-1, m_X0 + 2, "Up[Scroll up], Down[Scroll Down], \
						n[Next Msg], p[Previous Msg]");

	if( m_Focused)
	{
		cret.m_X = -1;
		cret.m_Y = -1;
	}

}

void HexViewer::SetSource(int src)
{
	m_Src = src;
	m_MsgNum = 0;

	// obtain the first message
	switch( src )
	{
	case 0:
		{
			LocalContext* lct = Context::Get()->m_TTYThread;
			if( lct->GetInboxSize() == 0 )
			{
				SetStream(NULL, 0);
			}
			else
			{
				// get the first message
				Message msg = lct->GetInboxEntry(0);
				SetStream(msg.m_Data, m_Len);
			}
		}
		break;
	case 1:
		{
			LocalContext* lct = Context::Get()->m_TCPThread;
			if( lct->GetInboxSize() == 0 )
			{
				SetStream(NULL, 0);
			}
			else
			{
				// get the first message
				Message msg = lct->GetInboxEntry(0);
				SetStream(msg.m_Data, msg.m_Len);
			}
		}
		
		break;
	default:
		SetStream(NULL, 0);
		break;
	}
}


char HexViewer::SanitizeChar(char c)
{
	if( (c >= 32) && (c <= 126) )
		return c;
	else
		return '.';
}

void HexViewer::OnResize(int x0, int y0, int w, int h)
{
	// let the parent deal with it
	PanelWidget::OnResize(x0,y0,w,h); 
}

void HexViewer::SetLabel(std::string label)
{
	m_Label = label;
}

void HexViewer::SetStream(char* stream, int len)
{
	m_Len = (stream == NULL)? 0 : len;

	m_Stream = stream;

	// reset the startline
	m_StartLine = 0;
}

bool HexViewer::OnInput(int in)
{

	if( !m_Focused )
		return true;

	LocalContext* lct = NULL;

	switch(in)
	{
	case KEY_UP: // scroll up
		m_StartLine = (m_StartLine == 0)? 0 : m_StartLine-1;
		break;
	case KEY_DOWN: // scroll down
		m_StartLine = (m_StartLine >= (m_Len/16))? m_Len/16 : m_StartLine + 1;
		break;
	case 'n': // next msg
	case 'p': // previous msg
		
		switch(m_Src)
		{
		case 0: // TTY
			lct = Context::Get()->m_TTYThread;
			break;
		case 1: // TCP
			lct = Context::Get()->m_TCPThread;
			break;
		default:
			lct = NULL;
			break;
		}
		if( lct != NULL )
		{
			// get the inbox size
			int inboxSize = lct->GetInboxSize();
			if( inboxSize == 0 )
			{
				SetStream(NULL, 0);
				return true;
			}
				
			// generate the new index
			if( in == 'n' ) // next msg
			{
				m_MsgNum = (m_MsgNum >= (inboxSize-1))? inboxSize-1 : m_MsgNum + 1;
			}
			else // previous msg
			{
				m_MsgNum = (m_MsgNum <= 0)? 0 : m_MsgNum - 1;
			}	
			
			Message msg = lct->GetInboxEntry(m_MsgNum);
			SetStream(msg.m_Data, msg.m_Len);    
				
		}		

		break;
	}


	// always return true, this window cannot call exit
	return true;
}

