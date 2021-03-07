// ResDllTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ResDllTest.h"
#include "ResDllTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResDllTestDlg dialog

CResDllTestDlg::CResDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResDllTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResDllTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResDllTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CResDllTestDlg, CDialog)
	//{{AFX_MSG_MAP(CResDllTestDlg)
	ON_BN_CLICKED(IDC_BTNLOAD, OnBtnload)
	ON_BN_CLICKED(IDC_BTNFREE, OnBtnfree)
	ON_BN_CLICKED(IDC_BTNBMP, OnBtnbmp)
	ON_BN_CLICKED(IDC_BTNICON, OnBtnicon)
	ON_BN_CLICKED(IDC_BTNCUR, OnBtncur)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResDllTestDlg message handlers

BOOL CResDllTestDlg::OnInitDialog()
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

//加载资源DLL
void CResDllTestDlg::OnBtnload() 
{
	m_hDll = LoadLibrary(_T("ResDll.dll"));
	if (m_hDll == NULL)
	{
		AfxMessageBox(_T("加载Dll失败"));
	}	
}

//释放资源DLL
void CResDllTestDlg::OnBtnfree() 
{
   if (m_hDll != NULL)	
   {
	   FreeLibrary(m_hDll);
   }	
}

//调用DLL资源里的位图
void CResDllTestDlg::OnBtnbmp() 
{
	HBITMAP bmp = LoadBitmap(m_hDll,MAKEINTRESOURCE(IDB_RESBMP));	
	if (bmp == NULL)
	{
		AfxMessageBox(_T("调用位图资源失败"));
	}

	//获得绘图环境资源
	CDC memdc;
	CDC *pDC = new CClientDC(this);
	if(!memdc.GetSafeHdc())
	{
		memdc.CreateCompatibleDC(pDC);
		memdc.SelectObject(bmp);
	}
	pDC->BitBlt(0,0,200,200,&memdc,0,0,SRCCOPY);
	DeleteObject(bmp);
	delete pDC;
}

//调用DLL资源里的图标
void CResDllTestDlg::OnBtnicon() 
{
   HICON icn = LoadIcon(m_hDll,MAKEINTRESOURCE(IDI_RESICON));
   if (icn == NULL)
   {
		AfxMessageBox(_T("调用图标资源失败"));
   }
   	CDC *pDC = new CClientDC(this);
	pDC->DrawIcon(CPoint(100,100),icn);
	DeleteObject(icn);
    delete pDC;		
}

//调用DLL资源里的光标
void CResDllTestDlg::OnBtncur() 
{
   HCURSOR cur = ::LoadCursorW(m_hDll,MAKEINTRESOURCE(IDC_RESCUR));
   if (cur == NULL)
   {
		AfxMessageBox(_T("调用光标资源失败"));
   }
   ::SetCursor(cur);
   DeleteObject(cur);	
}
