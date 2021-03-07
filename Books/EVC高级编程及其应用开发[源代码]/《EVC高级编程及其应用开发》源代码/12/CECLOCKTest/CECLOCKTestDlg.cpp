// CECLOCKTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CECLOCKTest.h"
#include "CECLOCKTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCECLOCKTestDlg dialog

CCECLOCKTestDlg::CCECLOCKTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCECLOCKTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCECLOCKTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCECLOCKTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCECLOCKTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCECLOCKTestDlg, CDialog)
	//{{AFX_MSG_MAP(CCECLOCKTestDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCECLOCKTestDlg message handlers

BOOL CCECLOCKTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	CRect rect(0,0,200,200);
	m_clock.Create(_T(""),_T(""),WS_VISIBLE | WS_CHILD, rect, this,0,NULL) ; 

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


