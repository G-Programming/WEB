// ASynDllTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ASynDllTest.h"
#include "ASynDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CASynDllTestDlg dialog

CASynDllTestDlg::CASynDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CASynDllTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CASynDllTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CASynDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CASynDllTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CASynDllTestDlg, CDialog)
	//{{AFX_MSG_MAP(CASynDllTestDlg)
	ON_BN_CLICKED(IDC_BTNCALL, OnBtncall)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CASynDllTestDlg message handlers

BOOL CASynDllTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	//加载ASynDll
	m_hModule = LoadLibrary(_T("ASynDll.dll"));
    if (m_hModule == NULL)
	{
		AfxMessageBox(_T("加载DLL失败"));
		return FALSE;
	}
	//得到ASynDll中QueryData函数地址
	m_pQueryData = (TQueryData)GetProcAddress(m_hModule,_T("QueryData"));
	if ( m_pQueryData == NULL )
	{
		AfxMessageBox(_T("获取QueryData函数失败"));
		FreeLibrary(m_hModule);
		return FALSE;
	}
	
	//得到ASynDll中SetCallbackProcAddr函数地址
	m_pSetCallbackProcAddr = 
		(TSetCallbackProcAddr)GetProcAddress(m_hModule,_T("SetCallbackProcAddr"));
	if ( m_pSetCallbackProcAddr == NULL )
	{
		AfxMessageBox(_T("获取SetCallbackProcAddr函数失败"));
		FreeLibrary(m_hModule);
		return FALSE ;
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//回调函数，当DLL中QueryData方法执行完毕时执行
void QueryReadNotify(long lDBData)
{
	TCHAR sDBData[11];
	TCHAR sMessage[64];
	_ltow(lDBData, sDBData, 10);
	wcscpy(sMessage, _T("DBData from DLL is: "));
	wcscat(sMessage, sDBData);
	::MessageBox(0, sMessage, 
		_T("Sample App"), MB_OK + MB_ICONINFORMATION);

};


void CASynDllTestDlg::OnBtncall() 
{
	long lProcAdr;

   //设置回调函数地址
   lProcAdr = (long)(&QueryReadNotify);
   m_pSetCallbackProcAddr(lProcAdr);
   
   //执行异步查询操作
   m_pQueryData();
}



void CASynDllTestDlg::OnDestroy() 
{
	//释放AsynDll库
	FreeLibrary(m_hModule);
	CDialog::OnDestroy();	
}
