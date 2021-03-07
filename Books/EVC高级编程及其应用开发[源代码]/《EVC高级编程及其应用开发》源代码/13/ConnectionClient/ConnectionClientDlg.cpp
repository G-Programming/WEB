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

	//�õ�IAdd COM�ӿ�
	CComPtr<IAdd> pAdd;
	hr =pAdd.CoCreateInstance(CLSID_Add);
	ASSERT(hr == S_OK);

	//�������ӵ�����ָ��
	IConnectionPointContainer   * pCPC;
	//�������ӵ�ָ��
    IConnectionPoint          * pCP;   
    DWORD				        dwAdvise; 

    //�ж�IAdd�ӿ��Ƿ������ӵ��¼������õ����ӵ���������
    hr = pAdd->QueryInterface(IID_IConnectionPointContainer,(void **)&pCPC);

    ASSERT(SUCCEEDED(hr));

	//�õ����ӵ����
    hr = pCPC->FindConnectionPoint(IID__IAddEvents,&pCP);
    
	ASSERT(SUCCEEDED(hr));

	//�ͷ����ӵ���������
	pCPC->Release();
    
	IUnknown *pSinkUnk;
	
	//��CSink�ഴ��һ�����ӵ�֪ͨ����
	CSink *pSink;
    pSink = new CSink;

    ASSERT(pSink !=NULL);

	//�õ�CSink��Ľӿ�ָ��
	hr = pSink->QueryInterface (IID_IUnknown,(void **)&pSinkUnk);

	//ͬ���ӵ����������
	hr = pCP->Advise(pSinkUnk,&dwAdvise); 

    //ִ��IAdd�ӿڵ�Add����
    pAdd->Add(m_number1 ,m_number2);

	//�Ͽ������ӵ���������
	pCP->Unadvise(dwAdvise); 									
	pCP->Release();	
	
}
