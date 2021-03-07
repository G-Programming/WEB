// TCPClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TCPClient.h"
#include "TCPClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg dialog

CTCPClientDlg::CTCPClientDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTCPClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCPClientDlg)
	m_remoteHost = _T("");
	m_remotePort = 0;
	m_recvData = _T("");
	m_sendData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPClientDlg)
	DDX_Text(pDX, IDC_EDTREMOTEHOST, m_remoteHost);
	DDX_Text(pDX, IDC_EDTREMOTEPORT, m_remotePort);
	DDX_Text(pDX, IDC_EDTRECV, m_recvData);
	DDX_Text(pDX, IDC_EDTSENDDATA, m_sendData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTCPClientDlg, CDialog)
//{{AFX_MSG_MAP(CTCPClientDlg)
ON_BN_CLICKED(IDC_BTNCONN, OnBtnconn)
ON_BN_CLICKED(IDC_BTNDISCONN, OnBtndisconn)
ON_BN_CLICKED(IDC_BTNSENDDATA, OnBtnsenddata)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg message handlers

BOOL CTCPClientDlg::OnInitDialog()
{
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen
	
	//��ʼ������ֵ
	m_remoteHost = GetLocalIP();
	m_remotePort = 5000;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//���ӶϿ��¼�
void CALLBACK CTCPClientDlg::OnDisConnect(CWnd* pWnd)
{
	CTCPClientDlg * pDlg = (CTCPClientDlg*)pWnd;
	
	CStatic * pStatus = (CStatic *)pDlg->GetDlgItem(IDC_LBLCONNSTATUS);
	ASSERT(pStatus != NULL);
	pStatus->SetWindowText(_T("���ӶϿ�"));
	
	/*���ð�ť��������*/
	CButton * pBtnConn =(CButton*)pDlg->GetDlgItem(IDC_BTNCONN);
	CButton * pBtnDisConn = (CButton*)pDlg->GetDlgItem(IDC_BTNDISCONN);
	CButton * pBtnSendData =  (CButton*)pDlg->GetDlgItem(IDC_BTNSENDDATA);
	ASSERT(pBtnConn != NULL );
	ASSERT(pBtnDisConn != NULL );
	ASSERT(pBtnSendData != NULL );
	pBtnConn->EnableWindow(TRUE);
	pBtnDisConn->EnableWindow(FALSE);
	pBtnSendData->EnableWindow(FALSE);
}

//���ݽ����¼�
void CALLBACK CTCPClientDlg::OnRead(CWnd* pWnd,const char * buf,int len )
{
	CTCPClientDlg * pDlg = (CTCPClientDlg*)pWnd;
	CEdit * pEdtRecv = (CEdit*)pDlg->GetDlgItem(IDC_EDTRECV);
	ASSERT(pEdtRecv != NULL);
	CString strRecv = buf;
	//�����յ�������ʾ�������ı�����
	pEdtRecv->SetWindowText(strRecv);
}

//Socket�����¼�
void CALLBACK CTCPClientDlg::OnError(CWnd* pWnd,int nErrorCode)
{
	AfxMessageBox(_T("�ͻ���socket��������"));
}


//�������Ӱ�ť
void CTCPClientDlg::OnBtnconn() 
{
	UpdateData(TRUE);
	//����m_tcpClient����
	m_tcpClient.m_remoteHost = m_remoteHost;
	m_tcpClient.m_port = m_remotePort;
	m_tcpClient.OnDisConnect = OnDisConnect;
	m_tcpClient.OnRead = OnRead;
	m_tcpClient.OnError = OnError;
	//�򿪿ͻ���socket
	m_tcpClient.Open(this);
	
	//�����������������
	if (m_tcpClient.Connect())
	{
		CStatic *pStatus = (CStatic*)GetDlgItem(IDC_LBLCONNSTATUS);
		ASSERT(pStatus != NULL);
		pStatus->SetWindowText(L"��������");
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(_T("��������ʧ��"));
		CStatic *pStatus = (CStatic*)GetDlgItem(IDC_LBLCONNSTATUS);
		ASSERT(pStatus != NULL);
		pStatus->SetWindowText(L"���ӶϿ�");
		return;
	}
	/*���ð�ť��������*/
	CButton * pBtnConn =(CButton*)GetDlgItem(IDC_BTNCONN);
	CButton * pBtnDisConn = (CButton*)GetDlgItem(IDC_BTNDISCONN);
	CButton * pBtnSendData =  (CButton*)GetDlgItem(IDC_BTNSENDDATA);
	ASSERT(pBtnConn != NULL );
	ASSERT(pBtnDisConn != NULL );
	ASSERT(pBtnSendData != NULL );
	pBtnConn->EnableWindow(FALSE);
	pBtnDisConn->EnableWindow(TRUE);
	pBtnSendData->EnableWindow(TRUE);
	
}

//�Ͽ����Ӱ�ť�����¼�
void CTCPClientDlg::OnBtndisconn() 
{
	if (m_tcpClient.Close())
	{
		CStatic *pStatus = (CStatic*)GetDlgItem(IDC_LBLCONNSTATUS);
		ASSERT(pStatus != NULL);
		pStatus->SetWindowText(L"���ӶϿ�");
		CButton * pBtnConn =(CButton*)GetDlgItem(IDC_BTNCONN);
		CButton * pBtnDisConn = (CButton*)GetDlgItem(IDC_BTNDISCONN);
		CButton * pBtnSendData = (CButton*)GetDlgItem(IDC_BTNSENDDATA);
		ASSERT(pBtnConn != NULL );
		ASSERT(pBtnDisConn != NULL );
		ASSERT(pBtnSendData != NULL );
		pBtnConn->EnableWindow(TRUE);
		pBtnDisConn->EnableWindow(FALSE);
		pBtnSendData->EnableWindow(FALSE);
	}
	else
	{
		AfxMessageBox(_T("���ӶϿ�ʧ��"));
	}	
}

//�������ݰ�ť�����¼�����
void CTCPClientDlg::OnBtnsenddata() 
{
	char * sendBuf;
	int sendLen=0;
	UpdateData(TRUE);
	
	sendLen = m_sendData.GetLength();
	sendBuf = new char[sendLen*2];
	wcstombs(sendBuf,m_sendData,sendLen);
	if (!m_tcpClient.SendData(sendBuf,sendLen))
	{
		AfxMessageBox(_T("����ʧ��"));
	}
	delete[] sendBuf;
	sendBuf = NULL;		
}

//�õ����ص�IP��ַ
CString CTCPClientDlg::GetLocalIP()
{
	
	HOSTENT *LocalAddress;
	char	*Buff;
	TCHAR	*wBuff;
	CString strReturn = _T("");
	
	
	//�����µĻ�����
	Buff = new char[256];
	wBuff = new TCHAR[256];
	//�ÿջ�����
	memset(Buff, '\0', 256);
	memset(wBuff, TEXT('\0'), 256*sizeof(TCHAR));
	//�õ����ؼ������
	if (gethostname(Buff, 256) == 0)
	{
		//ת����˫�ֽ��ַ���
		mbstowcs(wBuff, Buff, 256);
		//�õ����ص�ַ
		LocalAddress = gethostbyname(Buff);
		//�ÿ�buff
		memset(Buff, '\0', 256);
		//��ϱ���IP��ַ
		sprintf(Buff, "%d.%d.%d.%d\0", LocalAddress->h_addr_list[0][0] & 0xFF,
			LocalAddress->h_addr_list[0][1] & 0x00FF, LocalAddress->h_addr_list[0][2] & 0x0000FF, LocalAddress->h_addr_list[0][3] & 0x000000FF);
		//�ÿ�wBuff
		memset(wBuff, TEXT('\0'), 256*sizeof(TCHAR));
		//ת����˫�ֽ��ַ���
		mbstowcs(wBuff, Buff, 256);
        //���÷���ֵ
		strReturn = wBuff;
	}
	else
	{
	}
	
	//�ͷ�Buff������
	delete[] Buff;
	//�ͷ�wBuff������
	delete[] wBuff;
	return strReturn;
}