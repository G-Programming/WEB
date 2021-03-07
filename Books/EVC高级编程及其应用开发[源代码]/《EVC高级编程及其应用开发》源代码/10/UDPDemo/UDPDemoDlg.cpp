// UDPDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UDPDemo.h"
#include "UDPDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUDPDemoDlg dialog

CUDPDemoDlg::CUDPDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUDPDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUDPDemoDlg)
	m_LocalPort = 0;
	m_RecvNum = 0;
	m_RecvStr = _T("");
	m_RemoteHost = _T("");
	m_RemotePort = 0;
	m_SendNum = 0;
	m_SendStr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUDPDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUDPDemoDlg)
	DDX_Text(pDX, IDC_EDIT_LOCALPORT, m_LocalPort);
	DDX_Text(pDX, IDC_EDIT_RECVNUM, m_RecvNum);
	DDX_Text(pDX, IDC_EDIT_RECVSTR, m_RecvStr);
	DDX_Text(pDX, IDC_EDIT_REMOTEHOST, m_RemoteHost);
	DDX_Text(pDX, IDC_EDIT_REMOTEPORT, m_RemotePort);
	DDX_Text(pDX, IDC_EDIT_SENDNUM, m_SendNum);
	DDX_Text(pDX, IDC_EDIT_SENDSTR, m_SendStr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUDPDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CUDPDemoDlg)
	ON_BN_CLICKED(IDC_BTNOPEN, OnBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	ON_BN_CLICKED(IDC_BTNSEND, OnBtnsend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUDPDemoDlg message handlers

BOOL CUDPDemoDlg::OnInitDialog()
{
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CALLBACK CUDPDemoDlg::OnUdpCERecv(CWnd * pWnd,char* buf,int nLen,sockaddr * addr)
{
	CUDPDemoDlg * pDlg;
	pDlg = (CUDPDemoDlg*)pWnd;
	char * recvStr;
	int recvNum;
	recvStr = new char(nLen-4);
	//解析出收到的字符串
	CopyMemory(recvStr,buf,nLen-4);
	//解析出收到的数字
	CopyMemory(&recvNum,buf+nLen-4,4);

	//在字符串接收框中，显示收到的字符串
	CEdit *pRecvStrEdit = (CEdit*)pDlg->GetDlgItem(IDC_EDIT_RECVSTR);
	ASSERT(pRecvStrEdit != NULL);
	CString strRecv = recvStr;
	pRecvStrEdit->SetWindowText(strRecv);

	//在数字接收框中，显示接收到的数字
	CEdit *pRecvNumEdit = (CEdit*)pDlg->GetDlgItem(IDC_EDIT_RECVNUM);
	ASSERT(pRecvNumEdit != NULL);
	CString numRecv;
	numRecv.Format(L"%d",recvNum);	
	pRecvNumEdit->SetWindowText(numRecv);

    //删除动态内存
	delete[] recvStr;
	recvStr = NULL;
}

void CALLBACK CUDPDemoDlg::OnUdpCEError(CWnd * pWnd,int nError)
{

}


void CUDPDemoDlg::OnBtnopen() 
{
   UpdateData(TRUE);
   m_CEUdp.m_OnUdpRecv = OnUdpCERecv;
   m_CEUdp.m_OnUdpError = OnUdpCEError;
   DWORD nResult = m_CEUdp.Open(this,m_LocalPort,m_RemoteHost.GetBuffer(m_RemoteHost.GetLength()),m_RemotePort);
   if (nResult <=0) 
   {
	   AfxMessageBox(_T("打开端口失败"));
   }
   char hostName[255];
   ZeroMemory(hostName,255);
   gethostname(hostName,255);
}

void CUDPDemoDlg::OnBtnclose() 
{
  m_CEUdp.Close();	
}



void CUDPDemoDlg::OnBtnsend() 
{
   char * sendBuf;
   int sendLen=0;
   UpdateData(TRUE);
   
   sendLen = m_SendStr.GetLength()+4;
   sendBuf = new char(sendLen);
   WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,m_SendStr.GetBuffer(m_SendStr.GetLength())
	   ,m_SendStr.GetLength(),sendBuf,m_SendStr.GetLength(),NULL,NULL);

   CopyMemory(sendBuf+m_SendStr.GetLength(),&m_SendNum,4);
   m_CEUdp.SendData(sendBuf,sendLen);	
   delete[] sendBuf;
   sendBuf = NULL;
}
