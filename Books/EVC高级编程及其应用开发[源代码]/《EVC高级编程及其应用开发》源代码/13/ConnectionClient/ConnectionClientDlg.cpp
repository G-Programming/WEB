// ConnectionClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ConnectionClient.h"
#include "ConnectionClientDlg.h"

#include "Sink.h"          // for our CSink class
#include <atlbase.h>       // for ATL smart pointers


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnectionClientDlg dialog

CConnectionClientDlg::CConnectionClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectionClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConnectionClientDlg)
	m_number1 = 0;
	m_number2 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConnectionClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConnectionClientDlg)
	DDX_Text(pDX, IDC_EDT_NUMBER1, m_number1);
	DDX_Text(pDX, IDC_EDT_NUMBER2, m_number2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CConnectionClientDlg, CDialog)
	//{{AFX_MSG_MAP(CConnectionClientDlg)
	ON_BN_CLICKED(IDC_BTN_EXEC, OnBtnExec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConnectionClientDlg message handlers

BOOL CConnectionClientDlg::OnInitDialog()
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




void CConnectionClientDlg::OnBtnExec() 
{
    HRESULT  hr;
	UpdateData(TRUE);

	//得到IAdd COM接口
	CComPtr<IAdd> pAdd;
	hr =pAdd.CoCreateInstance(CLSID_Add);
	ASSERT(hr == S_OK);

	//定义连接点容器指针
	IConnectionPointContainer   * pCPC;
	//定义连接点指针
    IConnectionPoint          * pCP;   
    DWORD				        dwAdvise; 

    //判断IAdd接口是否有连接点事件，并得到连接点容器对象
    hr = pAdd->QueryInterface(IID_IConnectionPointContainer,(void **)&pCPC);

    ASSERT(SUCCEEDED(hr));

	//得到连接点对象
    hr = pCPC->FindConnectionPoint(IID__IAddEvents,&pCP);
    
	ASSERT(SUCCEEDED(hr));

	//释放连接点容器对象
	pCPC->Release();
    
	IUnknown *pSinkUnk;
	
	//从CSink类创建一个连接点通知对象
	CSink *pSink;
    pSink = new CSink;

    ASSERT(pSink !=NULL);

	//得到CSink类的接口指针
	hr = pSink->QueryInterface (IID_IUnknown,(void **)&pSinkUnk);

	//同连接点对象建立连接
	hr = pCP->Advise(pSinkUnk,&dwAdvise); 

    //执行IAdd接口的Add方法
    pAdd->Add(m_number1 ,m_number2);

	//断开与连接点对象的连接
	pCP->Unadvise(dwAdvise); 									
	pCP->Release();	
	
}
