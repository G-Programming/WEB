// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PlugIn_Main.h"

#include "MainFrm.h"
#include "PlugInDlg.h"

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
ON_COMMAND(ID_MI_PLUGIN, OnMiPlugin)
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
	
	if(!m_wndCommandBar.Create(this) ||
	   !m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME) ||
	   !m_wndCommandBar.AddAdornments(dwAdornmentFlags))
	{
		TRACE0("Failed to create CommandBar\n");
		return -1;      // fail to create
	}

	m_wndCommandBar.SetBarStyle(m_wndCommandBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED);

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

//退出菜单单击事件
void CMainFrame::OnMiQuit() 
{
	this->OnClose();	
}

//插件菜单单击事件，用于打开插件对话框
void CMainFrame::OnMiPlugin() 
{
    CPlugInDlg dlg;
	dlg.DoModal();	
}

/*
*函数介绍：返回工具栏对象指针
*入口参数：(无)
*出口参数：(无)
*返 回 值：工具栏对象指针
*/
CToolBar* CMainFrame::GetToolBarObject(void)
{
	return &m_wndCommandBar;
}


BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	if (pHandlerInfo == NULL)
	{
		if (m_bIsPlugInLoaded)
		{
			for (int nNumDlls = 0 ;	nNumDlls < m_nNumberOfDLLs ; nNumDlls++)
			{
				if (m_pLoadedDLLs[nNumDlls].m_pDLLhInstance != NULL)
				{
					UINT nTempID = m_pLoadedDLLs[nNumDlls].GetToolBarButtonID();
					
					if (nTempID == nID)
					{
						if (nCode == CN_UPDATE_COMMAND_UI)
						{
							//设置插件按钮状态
							((CCmdUI *) pExtra)->Enable(TRUE);
							return TRUE;
						}
						if (nCode == CN_COMMAND)
						{
							//处理插件按钮单击事件
							m_pLoadedDLLs[nNumDlls].HandleOnClick();
							
						}
						return TRUE;
					}
				}
			}
		}
	}
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
