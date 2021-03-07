// LedCtrlUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LedCtrlUse.h"
#include "LedCtrlUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLedCtrlUseDlg dialog

CLedCtrlUseDlg::CLedCtrlUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLedCtrlUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLedCtrlUseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLedCtrlUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLedCtrlUseDlg)
	DDX_Control(pDX, IDC_LED, m_led);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLedCtrlUseDlg, CDialog)
	//{{AFX_MSG_MAP(CLedCtrlUseDlg)
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLedCtrlUseDlg message handlers

BOOL CLedCtrlUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	//设置背景色
	m_led.SetColorBackGround(RGB(255,0,0));
	//设置前景色
	m_led.SetColorForeGround(RGB(0,255,255));
    //设置定时器
	SetTimer(100,100,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CLedCtrlUseDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	
}

void CLedCtrlUseDlg::OnTimer(UINT nIDEvent) 
{
	//设置LED显示数字
    m_led.Display(Random());  	
	CDialog::OnTimer(nIDEvent);
}
