// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DrawExam.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define PSPC_TOOLBAR_HEIGHT 24

const DWORD dwAdornmentFlags = 0; // exit button

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MI_QUIT, OnMiQuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//去掉窗体关闭按钮
    ModifyStyle(0, WS_NONAVDONEBUTTON, SWP_NOSIZE); 

	m_wndCommandBar.m_bShowSharedNewButton = TRUE;
	m_ToolTipsTable[0] = MakeString(IDS_NEW);
	m_ToolTipsTable[1] = MakeString(IDS_FILE);
	m_ToolTipsTable[2] = MakeString(IDS_MHELP);
	m_ToolTipsTable[3] = MakeString(IDS_CUT);
	m_ToolTipsTable[4] = MakeString(IDS_COPY);
	m_ToolTipsTable[5] = MakeString(IDS_PASTE);
	m_ToolTipsTable[6] = MakeString(IDS_ABOUT);  

	
	if(!m_wndCommandBar.Create(this) ||
	   !m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create CommandBar\n");
		return -1;      // fail to create
	}
    
	m_wndCommandBar.SetBarStyle(m_wndCommandBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED);


	//创建图形种类工具栏
	if (!m_drawBar.Create(this,
		WS_CHILD | WS_VISIBLE | CBRS_TOP) ||
		!m_drawBar.LoadToolBar(IDR_DRAWBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      
	}
	
	//设置图形种类按钮为选择状态
	for(int i=0;i<6;i++)
	{
		m_drawBar.SetButtonStyle(i,TBBS_CHECKGROUP);
	}

	//设置背景颜色工具栏
	if (!m_backColorBar.Create(this,
		WS_CHILD | WS_VISIBLE | CBRS_BOTTOM) || 
		!m_backColorBar.LoadToolBar(IDR_BACKCOLORBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      
	}

	//设置背景颜色按钮为选择状态
	for( i=0;i<8;i++)
	{
		m_backColorBar.SetButtonStyle(i,TBBS_CHECKGROUP);
	}
	
	//创建画笔颜色工具栏
	if (!m_frontColorBar.Create(this,
		WS_CHILD | WS_VISIBLE | CBRS_BOTTOM) ||
		!m_frontColorBar.LoadToolBar(IDR_FRONTCOLORBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;       
	}
	
	//设置画笔颜色按钮为选择状态
	for( i=0;i<8;i++)
	{
		m_frontColorBar.SetButtonStyle(i,TBBS_CHECKGROUP);
	}
	

	
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	return TRUE;
}



LPTSTR CMainFrame::MakeString(UINT stringID)
{
	TCHAR buffer[255];
	TCHAR* theString;

	::LoadString(AfxGetInstanceHandle(), stringID, buffer, 255);
	theString = new TCHAR[lstrlen(buffer) + 1];
	lstrcpy(theString, buffer);
	return theString;
}   

 
/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

//退出菜单，单击事件代码
void CMainFrame::OnMiQuit() 
{
	CMainFrame::OnClose();	
}
