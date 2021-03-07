// CEComClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CEComClient.h"
#include "CEComClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCEComClientDlg dialog

CCEComClientDlg::CCEComClientDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCEComClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCEComClientDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCEComClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCEComClientDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCEComClientDlg, CDialog)
//{{AFX_MSG_MAP(CCEComClientDlg)
	ON_BN_CLICKED(IDC_BTNCALL, OnBtncall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCEComClientDlg message handlers

BOOL CCEComClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen
	
	// TODO: Add extra initialization here
	
	HRESULT hr;
	hr = CLSIDFromProgID(OLESTR("CEComServer.Simple.1"),&clsid); 
	if(FAILED(hr))    
		MessageBox(NULL,_T("未找到ID"), MB_OK);  
	CoCreateInstance(clsid,NULL,CLSCTX_INPROC_SERVER,__uuidof(ISimple),(void**)&m_pSimple);  
	if(m_pSimple == NULL)    
		MessageBox(NULL,_T("接口指针失败"), MB_OK);  
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CCEComClientDlg::OnBtncall() 
{
   m_pSimple->ShowSvrMsg();	
}
