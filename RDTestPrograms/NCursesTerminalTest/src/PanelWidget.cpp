#include "PanelWidget.h"
#include "SizerWidget.h"
#include <stdlib.h>
#include <ncurses.h>

PanelWidget::PanelWidget(IWidget* parent, int style)
	: IWidget(parent), m_Sizer(NULL), m_Style(style)
{
}

PanelWidget::~PanelWidget()
{
	
}

void PanelWidget::Draw(CursorReturn& cret)
{
	DrawBorder();

	
}


void PanelWidget::OnResize(int x0, int y0, int w, int h)
{
	// first thing is first, call the IWidget
	IWidget::OnResize(x0, y0, w, h);

	// check to see if we have a boarder
	if( (m_Style & STYLE_BORDER) != 0 )
	{
		m_X0 = x0 + 1;
		m_Y0 = y0 + 1;
		m_W = w - 2;
		m_H = h - 2;
	}
	
	if( m_Sizer != NULL )
	{
		m_Sizer->OnResize(m_X0, m_Y0, m_W, m_H);
	}
}

void PanelWidget::SetSizer(SizerWidget* sizer)
{
	m_Sizer = sizer;
}

void PanelWidget::SetStyle(int style)
{
	m_Style = style;

	// make sure to resize just in case
	OnResize(m_X0, m_Y0, m_W, m_H);
}

bool PanelWidget::OnFocus(FocusDir focusDir)
{
	if( (m_Style & STYLE_NOINPUT) != 0)
		return false; // unable to give focus

	if( m_Hidden )
		return false; // can't take focus while hidden

	// otherwise set the focus, and return true
			
	//bool tfocus = FocusChildren(focusDir);

	bool tfocus = false;
	switch( focusDir )
	{
	case IWidget::FOCUS_FWD:
		if( m_Children.size() == 0 )
		{
			tfocus = !m_Focused;
		}
		else 
		{
			tfocus = FocusChildren(focusDir);
		}
		if( m_Focused && !tfocus )
		{
			// do it again
			tfocus = FocusChildren(focusDir);
		}
		
		m_Focused = tfocus;

		break;
	case IWidget::FOCUS_BACK:
		if( m_Children.size() == 0 )
		{
			tfocus = !m_Focused;
		}
		else 
		{
			tfocus = FocusChildren(focusDir);
		}
		if( m_Focused && !tfocus )
		{
			// do it again
			tfocus = FocusChildren(focusDir);
		}
		
		m_Focused = tfocus;
		break;
	case IWidget::FOCUS_UP:
		if( m_Focused && !tfocus )
		{
			// unfocus
			m_Focused = false;
		}
		else if( (m_Children.size() == 0) && m_Focused)
		{
			m_Focused = false;
		}
		
		break;
	}
		
	return m_Focused;
	
}
bool PanelWidget::FocusChildren(FocusDir dir)
{
	bool cfocused = false;
	bool anyFocused = false;
        // check to see if any are focused
        for(ChildList::iterator it = m_Children.begin();
                it != m_Children.end(); it++)
        {
                if( (*it) != NULL )
                        anyFocused = anyFocused || (*it)->IsFocused();
        }

        bool found = false;
	
	switch( dir )
	{
	case IWidget::FOCUS_FWD:

		for( ChildList::iterator it = m_Children.begin(); 
			it != m_Children.end(); it++ )
		{
			if( (*it) != NULL )
			{
			
				found = found || (*it)->IsFocused();

				if( found || !anyFocused )
                                {
                                        if( (*it)->OnFocus( dir ) )
                                        {
                                                return true;
                                        }
                                }

	
				//cfocused |= (*it)->OnFocus(dir);
				
				// we have a focus
				//if( cfocused ) break;
			}	
		}
		break;
	case IWidget::FOCUS_UP:
		
	case IWidget::FOCUS_BACK:
		for( ChildList::reverse_iterator rit = m_Children.rbegin();
			rit != m_Children.rend(); rit++ )
		{
			if( (*rit) != NULL )
			{
				found = found || (*rit)->IsFocused();

				if( found || !anyFocused )
                                {
                                        if( (*rit)->OnFocus( dir ) )
                                        {
                                                return true;
                                        }
                                }

				
				//cfocused |= (*rit)->OnFocus(dir);

				// we have focus 
				//if( cfocused ) break;
			}
		}
		
		break;
	}

	return cfocused;
}
void PanelWidget::RemoveChild(IWidget* child)
{
	if( m_Sizer != NULL )
	{
		m_Sizer->Remove(child);
	}
	

	IWidget::RemoveChild(child);
}

void PanelWidget::DrawBorder()
{
	if( (m_Style & STYLE_BORDER) == 0)
		return; // no boarder to draw

	if( m_Focused )
	{
		attron(A_STANDOUT);		
	}
	else
	{
		attroff(A_STANDOUT);
	}


	// draw the boarder
	int start = m_X0;
	int end = m_X0 + m_W;
	for( int x = start; x < end; x++ )
	{
		mvprintw(m_Y0-1, x, "-");
		mvprintw(m_Y0 + m_H, x, "-"); 
	}

	start = m_Y0;
	end = m_Y0 + m_H;

	for( int y = start; y < end; y++ )
	{
		mvprintw(y, m_X0-1, "|");
		mvprintw(y, m_X0 + m_W, "|"); 
	}

	// draw the corners
	mvprintw(m_Y0-1, m_X0-1, "+");
	mvprintw(m_Y0-1, m_X0+m_W, "+");
	mvprintw(m_Y0+m_H, m_X0-1, "+");
	mvprintw(m_Y0+m_H, m_X0+m_W, "+");

	attroff(A_STANDOUT);

}
