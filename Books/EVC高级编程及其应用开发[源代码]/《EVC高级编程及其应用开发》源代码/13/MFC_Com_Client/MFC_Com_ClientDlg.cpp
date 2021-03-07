// MFC_Com_ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Com_Client.h"
#include "MFC_Com_ClientDlg.h"
#include "ITimeLogServer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_Com_ClientDlg dialog

CMFC_Com_ClientDlg::CMFC_Com_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_Com_ClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_Com_ClientDlg)
	m_log = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Com_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_Com_ClientDlg)
	DDX_Text(pDX, IDC_EDT_LOG, m_log);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_Com_ClientDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_Com_ClientDlg)
	ON_BN_CLICKED(IDC_BTN_EXEC, OnBtnExec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_Com_ClientDlg message handlers

BOOL CMFC_Com_ClientDlg::OnInitDialog()
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



void CMFC_Com_ClientDlg::OnBtnExec() 
{
	UpdateData(TRUE);
	HRESULT hResult;
    IUnknown* pIUnknown;
	//初始化COM库,对组件实例化
	hResult = CoInitializeEx(NULL,COINIT_MULTITHREADED);
	if(FAILED(hResult))
	{
		::AfxMessageBox(L"不能初始化COM库!");
		return ;
	}

    //创建组件实例
    pIUnknown = NULL;
	hResult = ::CoCreateInstance(CLSID_TimeLogServer,NULL,
		CLSCTX_INPROC_SERVER,IID_IUnknown,(void**)&pIUnknown);
	if(FAILED(hResult))
	{
		pIUnknown = NULL;
		::AfxMessageBox(L"不能创建TimeLog对象!");
		return ;
	}
    //查询接口并使用
    if(pIUnknown!=NULL)
	{
		ITimeLog* pITimeLog;
		hResult=pIUnknown->QueryInterface(IID_ITimeLog,(void**)&pITimeLog);
		if(FAILED(hResult))
		{
			::AfxMessageBox(L"不能获取接口ITimeLog!");
			pIUnknown->Release();
			return;
		}
		BSTR bstrLogText;
		bstrLogText = m_log.AllocSysString();
		CString text((LPCWSTR)bstrLogText);
		::AfxMessageBox(text);
		
		if(FAILED(pITimeLog->OutputLog(&bstrLogText)))
		{
			::AfxMessageBox(L"日志输出出错!");
			pITimeLog->Release();
			return;
		}
		pITimeLog->Release();
		::AfxMessageBox(L"日志已经写入!");
	}
	//释放组件
	pIUnknown->Release();
	pIUnknown = NULL;
	//释放COM库
	::CoUninitialize();
}
