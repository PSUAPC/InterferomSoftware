#include "HexViewer.h"
#include <ncurses.h>
#include <stdlib.h>
#include "CommandInterface.h"
#include "Contexts.h"
#include <cmath>

HexViewer::HexViewer(IWidget* parent, int style)
	: PanelWidget(parent, style), m_Len(0), m_Stream(NULL),	
	m_StartLine(0), m_Src(0), m_MsgNum(0), m_MsgMissMatch(true),
	m_MsgCalcCS(0), m_MsgReadCS(0), m_Mode(0)
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
	// print the msg number, since m_MsgNum is zero based, we need to add 1
	if( m_Mode == 1 )
	{
		// declare the variables 
		float ax, ay, az, mx, my, mz;
		float alt, azm;

		// check the command and length
		if( (m_Len == 13) && (m_Stream[0] == 0x02) )
		{
			// we need to pull the shorts out
			short mxw = ((m_Stream[1]<<8)&0xFF00)|(m_Stream[2]&0xFF);
			short myw = ((m_Stream[3]<<8)&0xFF00)|(m_Stream[4]&0xFF);
			short mzw = ((m_Stream[5]<<8)&0xFF00)|(m_Stream[6]&0xFF);
			short axw = ((m_Stream[7]<<8)&0xFF00)|(m_Stream[8]&0xFF);
			short ayw = ((m_Stream[9]<<8)&0xFF00)|(m_Stream[10]&0xFF);
			short azw = ((m_Stream[11]<<8)&0xFF00)|(m_Stream[12]&0xFF);

			// divide the magnetometer by 16
			//mxw /= 16;
			//myw /= 16;
			//mzw /= 16;

			// multiply the scale
			//float ratio = 1.0f/450.0f;
			float ratio = 1.0f;
			mx = mxw*ratio;
			my = myw*ratio;
			mz = mzw*ratio;

			// multiply the acc scale
			//ratio = 2.0f/float(32767);
			//ax = fabs(axw*ratio); // x should only be positive
			ax = axw*ratio;
			ay = ayw*ratio;
			az = azw*ratio;
		}	

		float aXnorm = ax / sqrt( ax*ax + ay*ay + az*az );
		float aYnorm = ay / sqrt( ax*ax + ay*ay + az*az );
		float pitch = asin(aXnorm);
		float roll = -asin(aYnorm/cos(pitch));

		float magX = mx*cos(pitch) + mz*sin(pitch);
		float magY = mx*sin(roll)*sin(pitch) + my*cos(roll) - mz*sin(roll)*cos(pitch);
		float heading = 180.0*atan2(magY,magX)/M_PI;
		heading = (heading < 0)? heading + 360.0 : heading;

		pitch = pitch * 180.0/M_PI;

		roll = roll * 180.0/M_PI;

/*		float anorm = sqrt(ax*ax + az*az);
		if( anorm > 0.0f )
		{
			alt = 3.14159/2.0 - atan(az/ax);
			
			float ca = cos(alt);
			float sa = sin(alt);

			// now we can calculate the heading
			// -by / (ca*mx + sa*mz);
			azm = atan2( my, (ca*mx - sa*mz));
			

			// convert to degrees
			alt *= 180.0/3.14159;
			azm *= 180.0/3.14159;
			azm = (azm < 0.0f)? azm + 360.0 : azm;
			
		}
*/
		alt = pitch;
		azm = heading;	
			
		mvprintw(m_Y0, m_X0+5+m_Label.length()+2, "Acc: <%+8.5f, %+8.5f, %+8.5f> Mag: <%+8.5f, %+8.5f, %+8.5f> Alt: %+8.5f Az: %+8.5f Roll: %+8.5f", ax, ay, az, mx, my, mz, alt, azm, roll);
	}
	else
	{
		mvprintw(m_Y0, m_X0+5+m_Label.length()+2, "(%d/%d)", m_MsgNum+1, msgTot);
	}
	// make a temp string for checsum
	char str[100];
	sprintf(str, "(0x%02X/0x%02X)", m_MsgCalcCS, m_MsgReadCS);
	// print the header
	std::string temp;
	temp = _S("offset(h)\t 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F ");
	if( m_MsgMissMatch )
	{
		temp = temp + _S("[Checksum MissMatch]") + _S(str);
	}
	else
	{
		temp = temp + _S("[Checksum Match]");
	}

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
						n[Next Msg], b[Previous Msg]");

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
				m_MsgMissMatch = msg.m_MissMatch;
				m_MsgCalcCS = msg.m_CalcChecksum;
				m_MsgReadCS = msg.m_ReadChecksum;
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
				m_MsgMissMatch = msg.m_MissMatch;
				m_MsgCalcCS = msg.m_CalcChecksum;
				m_MsgReadCS = msg.m_ReadChecksum;

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

void HexViewer::SetMode(int mode)
{
	m_Mode = mode;
}

void HexViewer::Update()
{
	OnInput('r');

	// update
	Redraw();
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
	case 'b': // previous msg
	case 'r': // refresh
		
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
			else if( in == 'b' ) // previous msg
			{
				m_MsgNum = (m_MsgNum <= 0)? 0 : m_MsgNum - 1;
			}
			else // refresh
			{
				// do nothing
			}	

			Message msg;
			switch( m_Mode )
			{
			case 1: // front
				{
					// get the last inbox msg
					msg = lct->GetInboxEntry(inboxSize-1);
					if( inboxSize > 1 )
					{
						for( int i = 0; i < (inboxSize-2); i++ )
						{
							lct->RemoveInboxEntry(0);
						}
					}

				
				}
				break;	
			case 0:
			default:		
				msg = lct->GetInboxEntry(m_MsgNum);
			}  
			m_MsgMissMatch = msg.m_MissMatch;
			m_MsgCalcCS = msg.m_CalcChecksum;
			m_MsgReadCS = msg.m_ReadChecksum;
			SetStream(msg.m_Data, msg.m_Len); 
 
				
		}		

		break;
	}


	// always return true, this window cannot call exit
	return true;
}

