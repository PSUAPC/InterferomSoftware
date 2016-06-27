#include "WidgetInterface.h"
#include <stdlib.h>

IWidget::IWidget(IWidget* parent)
	: m_Parent(parent)
{
	if( m_Parent != NULL )
	{
		m_Parent->RegisterChild(this);
	}

	m_X0 = 0;
	m_Y0 = 0;
	m_H = 0;
	m_W = 0;
}

IWidget::~IWidget()
{
	//delete the children
	for( ChildList::iterator it = m_Children.begin();
		it != m_Children.end(); it++ )
	{
		if( (*it) != NULL )
		{
			delete (*it);
		}
	}	
}

void IWidget::Draw()
{
	// draw the children
	for( ChildList::iterator it = m_Children.begin();
		it != m_Children.end(); it++ )
	{
		if( (*it) != NULL )
		{
			(*it)->Draw();
		}
	}
}

bool IWidget::OnInput(int in)
{
	return true;
}

void IWidget::OnResize(int x0, int y0, int w, int h)
{
	// resize the children
	for( ChildList::iterator it = m_Children.begin();
		it != m_Children.end(); it++ )
	{
		if( (*it) != NULL )
		{
			(*it)->OnResize(x0, y0, w, h);
		}
	}
}


void IWidget::Redraw()
{
	// call redraw on the parent
	if( m_Parent != NULL )
	{
		m_Parent->Redraw();
	}
}

void IWidget::RegisterChild(IWidget* child)
{
	// add the child
	m_Children.push_back(child);
}

void IWidget::UnRegisterChild(IWidget* child)
{
	// remove the child 
	// this function will remove if found
	m_Children.remove(child);
}
