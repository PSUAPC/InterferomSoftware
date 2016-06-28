#include <stdlib.h>
#include <stdio.h>
#include "SizerWidget.h"
#include "NTerminal.h"

SizerWidget::SizerWidget(IWidget* parent) 
	: IWidget(parent), m_Dir(SizerWidget::DIR_VERT)
{
}

SizerWidget::SizerWidget(IWidget* parent, SizerDirection dir)
	: IWidget(parent), m_Dir(dir)
{
}
SizerWidget::~SizerWidget()
{
}
	
void SizerWidget::OnResize(int x0, int y0, int w, int h)
{
	//NTerminal::Get()->PrintToStdout("here");
	if( m_Widgets.size() == 0 )
		return; // nothing to do

	// cycle through the widgets and get the ratio sum
	float sum = 0;
	for( WidgetList::iterator it = m_Widgets.begin();
		it != m_Widgets.end(); it++ )
	{
		if( ((*it).m_Widget != NULL) && ! (*it).m_Widget->IsHidden() )
			sum += (*it).m_Ratio;
	}

	if( sum <= 0 )
	{
		sum = 1;
	}
	//FILE* pfile = fopen("log.log","a+"); 
	//if( pfile )
	//{
	//	fprintf(pfile, "%d widgets, [%d,%d,%d,%d]\n", m_Widgets.size(), x0, y0, w, h);
	//	fclose(pfile);
	//}


	//char buff[100];
	//sprintf(buff, "%d widgets, %f sum", m_Widgets.size(), sum);
	//NTerminal::Get()->PrintToStdout(buff);

	int index = 0;
	int start = (m_Dir == SizerWidget::DIR_HORZ)? x0 : y0;
	int len = 0;

	// now we can cycle through and calculate the new position of each widget
	for( WidgetList::iterator it = m_Widgets.begin();
		it != m_Widgets.end(); it++ )
	{
		if( ((*it).m_Widget != NULL) && !(*it).m_Widget->IsHidden() )	
		{
			// go based on the direction
			if( m_Dir == SizerWidget::DIR_HORZ )
			{
				len = w*(*it).m_Ratio/sum;
				(*it).m_Widget->OnResize(start, y0, len, h);
			}
			else
			{
				len = h*(*it).m_Ratio/sum;
				(*it).m_Widget->OnResize(x0, start, w, len);
			}
			start += len;	
		}

		index++;
	}
	
}

void SizerWidget::SetDirection(SizerDirection dir)
{
	m_Dir = dir;
}

void SizerWidget::Add(IWidget* widget, float ratio)
{
	m_Widgets.push_back( WidgetContainer() );
	m_Widgets.back().m_Widget = widget;
	m_Widgets.back().m_Ratio = ratio;
}

void SizerWidget::Remove(IWidget* widget)
{
	if( widget == NULL )
	{
		m_Widgets.clear();
	}

	for( WidgetList::iterator it = m_Widgets.begin();
		it != m_Widgets.end(); it++ )
	{
		if( (*it).m_Widget == widget )
		{
			m_Widgets.erase(it);
			return;
		}
	}

	// not found, oh well
}

