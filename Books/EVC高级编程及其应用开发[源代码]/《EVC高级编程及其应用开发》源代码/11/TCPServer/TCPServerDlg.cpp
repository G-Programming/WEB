// TCPServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TCPServer.h"
#include "TCPServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCPServerDlg dialog

CTCPServerDlg::CTCPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTCPServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCPServerDlg)
	m_localPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPServerDlg)
	DDX_Text(pDX, IDC_EDTLOCALPORT, m_localPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTCPServerDlg, CDialog)
	//{{AFX_MSG_MAP(CTCPServerDlg)
	ON_BN_CLICKED(IDC_BTNLISTEN, OnBtnlisten)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPServerDlg message handlers

BOOL CTCPServerDlg::OnInitDialog()
{
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	//设置默认值
	m_localPort = 5000;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//客户端连接建立事件处理函数
void CALLBACK  CTCPServerDlg::OnClientConnect(CWnd* pWnd,CTCPCustom_CE* pTcpCustom)
{
	CTCPServerDlg * pDlg = (CTCPServerDlg*)pWnd;
	CListBox * pLstConn = (CListBox*)pDlg->GetDlgItem(IDC_LSTCONN);
	ASSERT(pLstConn != NULL);
	pLstConn->AddString(pTcpCustom->m_RemoteHost + _T("建立连接"));
}
//客户端SOCKET关闭事件处理函数
void  CALLBACK CTCPServerDlg::OnClientClose(CWnd* pWnd,CTCPCustom_CE* pTcpCustom)
{
	CTCPServerDlg * pDlg = (CTCPServerDlg*)pWnd;
	int iIndex;
	
	CListBox * pLstConn = (CListBox*)pDlg->GetDlgItem(IDC_LSTCONN);
	ASSERT(pLstConn != NULL);
	iIndex = pLstConn->FindString(iIndex,pTcpCustom->m_RemoteHost + _T("建立连接"));
	if (iIndex == LB_ERR)
	{
		return;
	}
	pLstConn->DeleteString(iIndex); 
}

//服务器端收到来自客户端的数据
void CALLBACK CTCPServerDlg::OnClientRead(CWnd* pWnd,CTCPCustom_CE* pTcpCustom,const char * buf,int len )
{
    CString strRecv;
	CString strLen;
	strLen.Format(L"%d",len);
	strRecv = buf;
	CTCPServerDlg * pDlg = (CTCPServerDlg*)pWnd;
	CListBox * pLstRecv = (CListBox*)pDlg->GetDlgItem(IDC_LSTRECV);
	ASSERT(pLstRecv != NULL);
	
	pLstRecv->AddString(_T("************************************"));
	pLstRecv->AddString(_T("来自: ") + pTcpCustom->m_RemoteHost );
	pLstRecv->AddString(_T("数据长度:")+strLen);
	pLstRecv->AddString(strRecv);
	if (!pTcpCustom->SendData("recv ok",strlen("recv ok")))
	{
		AfxMessageBox(_T("发送失败"));
	}
}

//客户端Socket错误事件处理函数
void CALLBACK CTCPServerDlg::OnClientError(CWnd* pWnd,CTCPCustom_CE* pTcpCustom,int nErrorCode)
{
	
}

//服务器端Socket错误事件处理函数
void CALLBACK CTCPServerDlg::OnServerError(CWnd* pWnd,CTCPServer_CE* pTcpServer_CE,int nErrorCode)
{
	
}

//监听按钮单击事件方法
void CTCPServerDlg::OnBtnlisten() 
{
	UpdateData(TRUE);
	//设置m_tcpServer属性
   	m_tcpServer.m_LocalPort = m_localPort;
	m_tcpServer.m_pOwnerWnd = this;
	m_tcpServer.OnClientConnect = OnClientConnect;
	m_tcpServer.OnClientClose = OnClientClose;
	m_tcpServer.OnClientRead = OnClientRead;
	m_tcpServer.OnClientError = OnClientError;
	m_tcpServer.OnServerError = OnServerError;
	if (m_tcpServer.Open() <= 0)
	{
		AfxMessageBox(_T("监听失败"));
		return;
	}
	CButton * pBtnListen = (CButton*)GetDlgItem(IDC_BTNLISTEN);
	ASSERT(pBtnListen != NULL);
	pBtnListen->EnableWindow(FALSE);

	CButton * pBtnClose = (CButton*)GetDlgItem(IDC_BTNCLOSE);
	ASSERT(pBtnClose != NULL);
	pBtnClose->EnableWindow(TRUE);	
}

//关闭按钮单击事件代码 
void CTCPServerDlg::OnBtnclose() 
{
	if (m_tcpServer.Close() <=0)
	{
		AfxMessageBox(_T("关闭TCP服务器失败"));
		return;
	}
	CButton * pBtnListen = (CButton*)GetDlgItem(IDC_BTNLISTEN);
	ASSERT(pBtnListen != NULL);
	pBtnListen->EnableWindow(TRUE);

	CButton * pBtnClose = (CButton*)GetDlgItem(IDC_BTNCLOSE);
	ASSERT(pBtnClose != NULL);
	pBtnClose->EnableWindow(FALSE);	

	CListBox * pLstConn = (CListBox*)GetDlgItem(IDC_LSTCONN);
	ASSERT(pLstConn != NULL);
	
	CListBox * pLstRecv = (CListBox*)GetDlgItem(IDC_LSTRECV);
	ASSERT(pLstRecv != NULL);
	
	pLstConn->ResetContent();
	pLstRecv->ResetContent();
	
}
