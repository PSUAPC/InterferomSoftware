#ifndef __HEXVIEWER_H__
#define __HEXVIEWER_H__

#include "PanelWidget.h"


class HexViewer : public PanelWidget
{
public:
	HexViewer(IWidget* parent, int style = 0);
	~HexViewer();	

	void SetLabel(std::string label);

	void SetStream(char* stream, int len);
	void SetSource(int src);
	void SetMode(int mode);
	void Update();

private:
	virtual void Draw(CursorReturn& cret);
	virtual void OnResize(int x0, int y0, int w, int h);  
	virtual void RegisterChild(IWidget* child); 
	virtual bool OnInput(int in);  

	char SanitizeChar(char c);

	std::string m_Label;
	char* 	m_Stream;
	int   	m_Len;
	int  	m_StartLine;
	int 	m_Src; // 0 for TTY, 1 for TCP
	int 	m_Mode; // 0 for packet, 1 for front
	int 	m_MsgNum;
	bool 	m_MsgMissMatch;
	char 	m_MsgCalcCS;
	char 	m_MsgReadCS;
};


#endif //__HEXVIEWER_H__
