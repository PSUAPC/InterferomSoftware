#include "PanelWidget.h"
#include "SizerWidget.h"
#include <stdlib.h>

PanelWidget::PanelWidget(IWidget* parent, int style)
	: IWidget(parent), m_Sizer(NULL), m_Style(style),
	m_Selected(false)
{
}

PanelWidget::~PanelWidget()
{
}


void PanelWidget::SetSizer(SizerWidget* sizer)
{
	m_Sizer = sizer;
}

void PanelWidget::SetStyle(int style)
{
	m_Style = style;
}

void PanelWidget::ShowSelected(bool show)
{
	m_Selected = show;
}

void PanelWidget::DrawBoarder()
{
	if( (m_Style & STYLE_BOARDER) == 0)
		return; // no boarder to draw

	if( m_Selected )
	{
	}
	else
	{
	}
}
