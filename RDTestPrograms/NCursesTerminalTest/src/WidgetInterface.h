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

	virtual void OnResize(int x0, int y0, int w, int h);
	virtual bool OnInput(int in);

protected:
	virtual void Draw();	
	virtual void RegisterChild(IWidget* child);
	virtual void UnRegisterChild(IWidget* child);
	virtual void Redraw();
		
	IWidget* m_Parent;
	ChildList m_Children;
};

#endif //__WIDGETINTERFACE_H__
