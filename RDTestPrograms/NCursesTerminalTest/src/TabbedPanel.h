#ifndef __TABBEDPANEL_H__
#define __TABBEDPANEL_H__

#include "PanelWidget.h"

#define TSTYLE_NONE 0
#define TSTYLE_SHOW 1

class TabbedPanel : public PanelWidget
{
private:
	typedef std::list<IWidget*> WidgetList;	
public:
	TabbedPanel(IWidget* parent, int tstyle = 0, int wstyle = 0);
	~TabbedPanel();
	
	virtual void Draw(CursorReturn& cret);
	virtual void OnResize(int x0, int y0, int w, int h);
	virtual bool OnInput(int in);	
	
	int NumberOfTabs();
	void SetActiveTab(int index);
protected:
	virtual void RegisterChild(IWidget* child); 
	virtual void UnRegisterChild(IWidget* child);	

private:
	void DrawTabs();
	int m_TStyle;
	WidgetList m_Tabs;
	int m_ActiveTab;
};


#endif //__TABBEDPANEL_H__
