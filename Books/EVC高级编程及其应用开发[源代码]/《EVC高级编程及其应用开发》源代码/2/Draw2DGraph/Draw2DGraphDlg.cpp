// Draw2DGraphDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Draw2DGraph.h"
#include "Draw2DGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDraw2DGraphDlg dialog

CDraw2DGraphDlg::CDraw2DGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDraw2DGraphDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDraw2DGraphDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}
void CDraw2DGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDraw2DGraphDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDraw2DGraphDlg, CDialog)
	//{{AFX_MSG_MAP(CDraw2DGraphDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDraw2DGraphDlg message handlers

BOOL CDraw2DGraphDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen
	// TODO: Add extra initialization here
    CRect rect;
	rect.left = 10;
	rect.top = 10;
	rect.right = 240;
	rect.bottom = 160;
	//创建曲线控件实例
	m_2DGraph.m_crBackColor = RGB(118,146,131); //控件背景色
	m_2DGraph.m_crGridColor = RGB(56,104,169); //边框颜色
	m_2DGraph.m_crLineColor = RGB(136,253,57); //曲线颜色
	m_2DGraph.m_crTextColor = RGB(122,122,122); //字体颜色
	m_2DGraph.Create(_T(""),_T(""),WS_VISIBLE | WS_CHILD, rect, this,0,NULL) ; 
	m_pointCount = 0;
	//启动添加点计时器
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}




void CDraw2DGraphDlg::OnTimer(UINT nIDEvent) 
{
	int nRandomY, nRandomX;

	//产生一个1到10的随机数
	nRandomX = rand() % 10;
	nRandomY = rand() % 10;

	//如果曲线点数大于10个点，则删除第1个点。
	if (m_pointCount > 10 )
	{
		m_2DGraph.DeleteFirstPoint();
		m_pointCount--;
	}
	//给曲线添加点
	m_2DGraph.AppendPoint(nRandomX, nRandomY);	
	
	m_pointCount++;
	
	CDialog::OnTimer(nIDEvent);
}
