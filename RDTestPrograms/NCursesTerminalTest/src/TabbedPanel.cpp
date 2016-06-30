#include "TabbedPanel.h"
#include <ncurses.h>

TabbedPanel::TabbedPanel(IWidget* parent, int wstyle, int tstyle)
	: PanelWidget(parent, wstyle), m_TStyle(tstyle), m_ActiveTab(0)
{
}

TabbedPanel::~TabbedPanel()
{
	
}

int TabbedPanel::NumberOfTabs()
{
	return m_Tabs.size();
}

void TabbedPanel::SetActiveTab(int index)
{
	if( index < m_Tabs.size() )
		m_ActiveTab = index;
}

void TabbedPanel::RegisterChild(IWidget* child)
{
	m_Tabs.push_back(child);
	IWidget::RegisterChild(child);
}

void TabbedPanel::UnRegisterChild(IWidget* child)
{
	m_Tabs.remove(child);
	IWidget::UnRegisterChild(child);
}

void TabbedPanel::Draw(CursorReturn& cret)
{
	// draw the parent first
	PanelWidget::Draw(cret); 

	// draw the tabs
	DrawTabs();

	// draw the children	
	int index = 0;
	for( WidgetList::iterator it = m_Tabs.begin();
		it != m_Tabs.end(); it++ )
	{
		if( index == m_ActiveTab )
		{
			if( (*it)  != NULL )
			{
				(*it)->Draw( cret );
			}
			return;
			
		}

		index++;
	}
	
}

bool TabbedPanel::OnInput(int in)
{

	int index = 0;
	for( WidgetList::iterator it = m_Tabs.begin();
		it != m_Tabs.end(); it++ )
	{
		if( index == m_ActiveTab )
		{
			if( (*it)  != NULL )
			{
				return (*it)->OnInput(in);
			}
			
		}

		index++;
	}
	
	// no exit
	return true;
}

void TabbedPanel::OnResize(int x0, int y0, int w, int h)
{
	// resize the parent
	PanelWidget::OnResize(x0,y0,w,h); 
	
	// check to see if tabs are showing
	if( (m_TStyle & TSTYLE_SHOW) != 0 )
	{
		// manually resize the children
		for(ChildList::iterator it = m_Children.begin(); 
			it != m_Children.end(); it++ )
		{
			if( (*it) != NULL )
				(*it)->OnResize(m_X0, m_Y0+2, m_W, m_H-2);	
		}
	}
}

void TabbedPanel::DrawTabs()
{
	if( (m_TStyle & TSTYLE_SHOW) == 0 )
		return; // no tabs to draw


	int start = m_X0;
	int end = m_X0 + m_W;
	for(int x = start; x < end; x++ )
	{
		mvprintw(m_Y0+1, x, "-"); 
	}

	// now for the tabs
	int w = m_W;
	int n = m_Tabs.size();
	if( n == 0 ) n = 1;
	int maxS = w/n;
	if( maxS < 2 )
		maxS = 2;
	
	int npos = 0;
	int index = 0;
	for( WidgetList::iterator it = m_Tabs.begin();
		it != m_Tabs.end(); it++ )
	{
		if( (*it) == NULL )
			continue;

		std::string name = (*it)->GetName();

		// now for some magic
		// trim the name to fit the tab
		if( name.length() > (maxS-1) )
			name = name.substr(0, maxS-1); 	

		if( (npos + name.length() + 1) >= w )
		{
			mvprintw(m_Y0, npos + m_X0, "+\\");
			break;
		}
		
		if( index == m_ActiveTab )
			attron(A_STANDOUT);

		mvprintw(m_Y0, npos + m_X0, "%s\\", name.c_str());
		npos += name.length()+1;

		attroff(A_STANDOUT);		
		index++;
	} 	
		
}	
