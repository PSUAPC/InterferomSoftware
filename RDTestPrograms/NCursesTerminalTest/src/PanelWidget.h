#ifndef __PANELWIDGET_H__
#define __PANELWIDGET_H__

#include "WidgetInterface.h"

#define STYLE_NONE    0x00
#define STYLE_BORDER  0x01
#define STYLE_NOINPUT 0x02


class SizerWidget;

class PanelWidget : public IWidget
{
public:
	PanelWidget(IWidget* parent, int style = 0);
	~PanelWidget();

	void SetStyle(int style);	
	void SetSizer(SizerWidget* sizer);
	bool SetFocus(bool focus);
	virtual void OnResize(int x0, int y0, int w, int h);
	virtual void RemoveChild(IWidget* child);
	virtual void Draw(CursorReturn& cret);

protected:
	SizerWidget* m_Sizer;
	int	     m_Style;
	bool	     m_Focused;
	
private:
	void DrawBorder();
};



#endif //__PANELWIDGET_H__
