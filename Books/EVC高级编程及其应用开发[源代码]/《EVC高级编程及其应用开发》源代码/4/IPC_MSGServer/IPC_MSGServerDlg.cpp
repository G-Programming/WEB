// IPC_MSGServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPC_MSGServer.h"
#include "IPC_MSGServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerDlg dialog

CIPC_MSGServerDlg::CIPC_MSGServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MSGServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIPC_MSGServerDlg)
	m_RecvData = _T("");
	m_SendData = _T("");
	m_SessionName = _T("");
	m_Status = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MSGServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIPC_MSGServerDlg)
	DDX_Text(pDX, IDC_EDTRECV, m_RecvData);
	DDX_Text(pDX, IDC_EDTSEND, m_SendData);
	DDX_Text(pDX, IDC_EDTSESSIONNAME, m_SessionName);
	DDX_Text(pDX, IDC_STATICSTATUS, m_Status);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIPC_MSGServerDlg, CDialog)
	//{{AFX_MSG_MAP(CIPC_MSGServerDlg)
	ON_BN_CLICKED(IDC_BTNOPEN, OnBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	ON_BN_CLICKED(IDC_BTNSENDDATA, OnBtnsenddata)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerDlg message handlers

BOOL CIPC_MSGServerDlg::OnInitDialog()
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
	if (!m_IPCServer.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("��������ͬ���������ʧ��"));
	}

	m_IPCServer.m_ServerConnected = OnServerConnected;
	m_IPCServer.m_ServerDisConnected = OnServerDisConnected;
	m_IPCServer.m_ServerDataArrive = OnServerDataArrive;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*�������ܣ������������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �ͻ��˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerConnected(CWnd* parentWnd,HWND hWnd)
{

   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   pDlg->m_ClientWnd = hWnd;
   pDlg->m_Status = _T("����״̬�����ӳɹ�");
   pDlg->UpdateData(FALSE);
}

/*
*�������ܣ��������Ͽ������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           hWnd : �ͻ��˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerDisConnected(CWnd* parentWnd,HWND hWnd)
{

   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   pDlg->m_Status = _T("����״̬�����Ӳ��ɹ�");
   pDlg->UpdateData(FALSE);  
}

/*
*�������ܣ����������������¼�������
*��ڲ�����parentWnd������ͨѶ��Ĵ���ָ��
           pData : ��������ָ��
		   bufLen : �������ݳ���
           hWnd : �ͻ��˴��ھ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MSGServerDlg::OnServerDataArrive(CWnd* parentWnd
													,LPVOID pData,DWORD bufLen,HWND hWnd)
{
   CIPC_MSGServerDlg * pDlg;
   pDlg = (CIPC_MSGServerDlg *)parentWnd;
   
   pDlg->m_RecvData = LPCTSTR(pData);
   pDlg->UpdateData(FALSE);
}

/*
*�������ܣ�������ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGServerDlg::OnBtnopen() 
{
	UpdateData(TRUE);
	m_IPCServer.m_SessionName = m_SessionName;
	m_IPCServer.Open(this);
}

/*
*�������ܣ��رհ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGServerDlg::OnBtnclose() 
{
   m_IPCServer.Close();	
}

/*
*�������ܣ��������ݰ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CIPC_MSGServerDlg::OnBtnsenddata() 
{
   UpdateData(TRUE);
   m_IPCServer.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_ClientWnd,m_SendData.GetLength()*2);
}
