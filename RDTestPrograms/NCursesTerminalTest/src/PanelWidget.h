#ifndef __PANELWIDGET_H__
#define __PANELWIDGET_H__

#include "WidgetInterface.h"

#define STYLE_NONE    0x00
#define STYLE_BOARDER 0x01
#define STYLE_NOINPUT 0x02


class SizerWidget;

class PanelWidget : public IWidget
{
public:
	PanelWidget(IWidget* parent, int style = 0);
	~PanelWidget();

	void SetStyle(int style);	
	void SetSizer(SizerWidget* sizer);
	void ShowSelected(bool show);

protected:
	SizerWidget* m_Sizer;
	int	     m_Style;
	bool	     m_Selected;
private:
	void DrawBoarder();
};



#endif //__PANELWIDGET_H__
