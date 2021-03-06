#ifndef __WIDGETINTERFACE_H__
#define __WIDGETINTERFACE_H__

#include <list>
#include <string>

#define LOG(m) { \
	FILE* pfile = fopen("log.log", "a+"); \
	if( pfile ) \
	{ \
		fprintf(pfile, (m) ); \
		fclose(pfile); \
	} \
}


class IWidget
{
	// preven construction without paren
	IWidget(){}
protected:
	typedef std::list<IWidget*> ChildList;
	
	struct CursorReturn
	{
		int m_X;
		int m_Y;
	};
public:
	enum FocusDir
	{
		FOCUS_BACK = -1,
		FOCUS_UP = 0,
		FOCUS_FWD = 1
	};
public:
	IWidget(IWidget* parent);
	~IWidget();	

	virtual void OnResize(int x0, int y0, int w, int h);
	virtual bool OnInput(int in);
	void Hide(bool hide){ m_Hidden = hide; }
	bool IsHidden(){ return m_Hidden; }
	virtual void RemoveChild(IWidget* widget);
	virtual void Reparent(IWidget* widget);
	void SetName(std::string name);
	std::string GetName();
	virtual void Draw(CursorReturn& cret);
	virtual bool OnFocus(FocusDir focusDir);
	bool IsFocused(){return m_Focused;}
protected:
	virtual void RegisterChild(IWidget* child);
	virtual void UnRegisterChild(IWidget* child);
	virtual void Redraw();
	
	int m_X0;
	int m_Y0;
	int m_H;
	int m_W;	
	bool m_Hidden;
	bool m_Focused;
	std::string m_Name;
	IWidget* m_Parent;
	ChildList m_Children;
};

#endif //__WIDGETINTERFACE_H__
