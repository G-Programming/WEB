// MyCEActiveX_TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyCEActiveX_Test.h"
#include "MyCEActiveX_TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveX_TestDlg dialog

CMyCEActiveX_TestDlg::CMyCEActiveX_TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyCEActiveX_TestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyCEActiveX_TestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCEActiveX_TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyCEActiveX_TestDlg)
	DDX_Control(pDX, IDC_MYCEACTIVEXCTRL1, m_myCEActiveX);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyCEActiveX_TestDlg, CDialog)
	//{{AFX_MSG_MAP(CMyCEActiveX_TestDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveX_TestDlg message handlers

BOOL CMyCEActiveX_TestDlg::OnInitDialog()
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



void CMyCEActiveX_TestDlg::OnButton1() 
{
   //设置MsgContext属性
   m_myCEActiveX.SetMsgContext(L"^_^");
   //调用ShowMessage方法
   m_myCEActiveX.ShowMessage();
}

BEGIN_EVENTSINK_MAP(CMyCEActiveX_TestDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMyCEActiveX_TestDlg)
	ON_EVENT(CMyCEActiveX_TestDlg, IDC_MYCEACTIVEXCTRL1, 1 /* OnMsgChange */, OnOnMsgChangeMyceactivexctrl1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


//MyCEActiveX控件MsgContext属性被改变事件
void CMyCEActiveX_TestDlg::OnOnMsgChangeMyceactivexctrl1() 
{
	AfxMessageBox(L"MsgContext属性已被改变");	
}
