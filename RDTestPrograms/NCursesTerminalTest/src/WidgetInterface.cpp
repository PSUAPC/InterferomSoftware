#include "WidgetInterface.h"
#include <stdlib.h>

IWidget::IWidget(IWidget* parent)
	: m_Parent(parent)
{
	if( m_Parent != NULL )
	{
		m_Parent->RegisterChild(this);
	}
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
