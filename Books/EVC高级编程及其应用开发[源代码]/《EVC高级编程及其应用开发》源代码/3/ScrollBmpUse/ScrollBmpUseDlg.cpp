// ScrollBmpUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScrollBmpUse.h"
#include "ScrollBmpUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollBmpUseDlg dialog

CScrollBmpUseDlg::CScrollBmpUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScrollBmpUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScrollBmpUseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollBmpUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScrollBmpUseDlg)
	DDX_Control(pDX, IDC_SCROLLBMP, m_scrollBmp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScrollBmpUseDlg, CDialog)
	//{{AFX_MSG_MAP(CScrollBmpUseDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollBmpUseDlg message handlers

BOOL CScrollBmpUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	//初始化滚动位图控件
	m_scrollBmp.InitBmpCtrl();
	//根据文件名，加载位图
	m_scrollBmp.LoadBmp(_T("\\My Documents\\abc.bmp"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}


