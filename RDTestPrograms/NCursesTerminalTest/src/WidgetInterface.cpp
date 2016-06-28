#include "WidgetInterface.h"
#include <stdlib.h>

IWidget::IWidget(IWidget* parent)
	: m_Parent(parent)
{
	if( m_Parent != NULL )
	{
		m_Parent->RegisterChild(this);
	}

	m_Hidden = false;
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
			(*it)->m_Parent = NULL;
			delete (*it);
		}
	}	
}

void IWidget::Draw(CursorReturn& cret)
{
	// draw the children
	for( ChildList::iterator it = m_Children.begin();
		it != m_Children.end(); it++ )
	{
		if( ((*it) != NULL) && !(*it)->IsHidden() )
		{
			(*it)->Draw(cret);
		}
	}
}

bool IWidget::OnInput(int in)
{
	return true;
}

void IWidget::SetName(std::string name)
{
	m_Name = name;
}

std::string IWidget::GetName()
{
	return m_Name;
}

void IWidget::OnResize(int x0, int y0, int w, int h)
{
	m_X0 = x0;
	m_Y0 = y0;
	m_W = w;
	m_H = h;
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

void IWidget::RemoveChild(IWidget* child)
{
	// simply unregister the child
	UnRegisterChild( child );
}

void IWidget::Reparent(IWidget* child)
{
	// find the parent of the child
	if( child == NULL )
		return;

	if( child->m_Parent != NULL )
	{
		child->m_Parent->RemoveChild(child);
	}
	
	// add the child
	RegisterChild(child);
}


