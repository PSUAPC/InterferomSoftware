#ifndef __WIDGETINTERFACE_H__
#define __WIDGETINTERFACE_H__

#include <list>

class IWidget
{
	// preven construction without paren
	IWidget(){}
protected:
	typedef std::list<IWidget*> ChildList;
public:
	IWidget(IWidget* parent);

	~IWidget();	


protected:
	void RegisterChild(IWidget* child);
	void UnRegisterChild(IWidget* child);

	IWidget* m_Parent;
	ChildList m_Children;
};

#endif //__WIDGETINTERFACE_H__
