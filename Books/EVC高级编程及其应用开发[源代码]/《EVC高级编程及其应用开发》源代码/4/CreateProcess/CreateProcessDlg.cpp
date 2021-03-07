// CreateProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateProcess.h"
#include "CreateProcessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreateProcessDlg dialog

CCreateProcessDlg::CCreateProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateProcessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateProcessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateProcessDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateProcessDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateProcessDlg)
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateProcessDlg message handlers

BOOL CCreateProcessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



/*
*函数描述：调用可执行文件
*入口参数：FileName:字符串，用于指定可执行文件名
*出口参数：(无)
*返回值：true : 代表调用成功；false：代表调用失败
*/
bool CCreateProcessDlg::WinExec(LPCTSTR FileName)
{
    PROCESS_INFORMATION processInfo; //进程相关信息
    if (!CreateProcess(FileName, NULL, NULL, NULL, NULL
      , CREATE_NEW_CONSOLE
      , NULL, NULL, NULL, &processInfo))
    {
		return false;
	}
    CloseHandle(processInfo.hThread);
	CloseHandle(processInfo.hProcess);
	return true ;
}

void CCreateProcessDlg::OnBtnexec() 
{
	//打开计算器程序
    WinExec(_T("calc"));	
}
