// IPC_MSGCLIENTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPC_MSGCLIENT.h"
#include "IPC_MSGCLIENTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGCLIENTDlg dialog

CIPC_MSGCLIENTDlg::CIPC_MSGCLIENTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MSGCLIENTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIPC_MSGCLIENTDlg)
	m_SessionName = _T("");
	m_Status = _T("");
	m_RecvData = _T("");
	m_SendData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MSGCLIENTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIPC_MSGCLIENTDlg)
	DDX_Text(pDX, IDC_EDTSESSIONNAME, m_SessionName);
	DDX_Text(pDX, IDC_STATICSTATUS, m_Status);
	DDX_Text(pDX, IDC_EDTRECV, m_RecvData);
	DDX_Text(pDX, IDC_EDTSEND, m_SendData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIPC_MSGCLIENTDlg, CDialog)
	//{{AFX_MSG_MAP(CIPC_MSGCLIENTDlg)
	ON_BN_CLICKED(IDC_BTNCONNECT, OnBtnconnect)
	ON_BN_CLICKED(IDC_BTNDISCONNECT, OnBtndisconnect)
	ON_BN_CLICKED(IDC_BTNSENDDATA, OnBtnsenddata)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGCLIENTDlg message handlers

BOOL CIPC_MSGCLIENTDlg::OnInitDialog()
{
	//��ֹ����ȫ��
	m_bFullScreen = false;

	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here

	  if (!m_IPCClient.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("��������ͨѶ�ͻ�����ʧ��"));
	}

	m_IPCClient.m_ClientConnected = OnClientConnected;
	m_IPCClient.m_ClientDisConnected = OnClientDisConnected;
	m_IPCClient.m_ClientDataArrive = OnClientDataArrive;
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*�������ܣ��ͻ������ӽ����¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �������˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientConnected(CWnd* parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   
   pDlg->m_Status = _T("����״̬�����ӳɹ�");
   pDlg->UpdateData(FALSE);
}

/*
*�������ܣ��ͻ������ӶϿ��¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �������˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientDisConnected(CWnd * parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   pDlg->m_Status = _T("����״̬�����Ӳ��ɹ�");
   pDlg->UpdateData(FALSE);  
}

/*
*�������ܣ��ͻ��˽��������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           pData : ��������ָ��
		   bufLen : �������ݳ���
           hWnd : �������˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientDataArrive(CWnd* parentWnd
													,LPVOID pData,DWORD bufLen)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   
   pDlg->m_RecvData = LPCTSTR(pData);
   pDlg->UpdateData(FALSE);
}


/*
*�������ܣ��������Ӱ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGCLIENTDlg::OnBtnconnect() 
{
	UpdateData(TRUE);
	m_IPCClient.m_SessionName = m_SessionName;
	m_IPCClient.Open(this);
}

/*
*�������ܣ��Ͽ����Ӱ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGCLIENTDlg::OnBtndisconnect() 
{
   m_IPCClient.Close();			
}

/*
*�������ܣ��������ݰ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGCLIENTDlg::OnBtnsenddata() 
{
   UpdateData(TRUE);
   m_IPCClient.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_SendData.GetLength()*2);	
}
