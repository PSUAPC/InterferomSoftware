#ifndef __SIZERWIDGET_H__
#define __SIZERWIDGET_H__

#include "WidgetInterface.h"

class SizerWidget : public IWidget
{
	struct WidgetContainer
	{
		IWidget* m_Widget;
		float m_Ratio;
	};
	typedef std::list<WidgetContainer> WidgetList;
public:
	enum SizerDirection
	{
		DIR_HORZ,
		DIR_VERT,
		DIR_MAX
	};
public:
	SizerWidget(IWidget* parent);
	SizerWidget(IWidget* parent, SizerDirection dir);
	~SizerWidget();
	void Add(IWidget* widget, float ratio = 1.0);	
	void Remove(IWidget* widget);
	virtual void OnResize(int x0, int y0, int w, int h);
	void SetDirection(SizerDirection dir);
private:
	SizerDirection m_Dir;
	WidgetList m_Widgets;
};



#endif //__SIZERWIDGET_H__
