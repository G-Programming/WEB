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
	//禁止程序全屏
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
	   AfxMessageBox(_T("创建进程通讯客户端类失败"));
	}

	m_IPCClient.m_ClientConnected = OnClientConnected;
	m_IPCClient.m_ClientDisConnected = OnClientDisConnected;
	m_IPCClient.m_ClientDataArrive = OnClientDataArrive;
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*函数介绍：客户端连接建立事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           hWnd : 服务器端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientConnected(CWnd* parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   
   pDlg->m_Status = _T("连接状态：连接成功");
   pDlg->UpdateData(FALSE);
}

/*
*函数介绍：客户端连接断开事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           hWnd : 服务器端窗口句柄
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MSGCLIENTDlg::OnClientDisConnected(CWnd * parentWnd,HWND hWnd)
{
   CIPC_MSGCLIENTDlg * pDlg;
   pDlg = (CIPC_MSGCLIENTDlg *)parentWnd;
   pDlg->m_Status = _T("连接状态：连接不成功");
   pDlg->UpdateData(FALSE);  
}

/*
*函数介绍：客户端接收数据事件处理函数
*入口参数：parentWnd：创建通讯类的窗体指针
           pData : 接收数据指针
		   bufLen : 接收数据长度
           hWnd : 服务器端窗口句柄
*出口参数：(无)
*返回值：(无)
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
*函数介绍：建立连接按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGCLIENTDlg::OnBtnconnect() 
{
	UpdateData(TRUE);
	m_IPCClient.m_SessionName = m_SessionName;
	m_IPCClient.Open(this);
}

/*
*函数介绍：断开连接按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGCLIENTDlg::OnBtndisconnect() 
{
   m_IPCClient.Close();			
}

/*
*函数介绍：发送数据按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值: (无)
*/
void CIPC_MSGCLIENTDlg::OnBtnsenddata() 
{
   UpdateData(TRUE);
   m_IPCClient.SendMsg(m_SendData.GetBuffer(m_SendData.GetLength()),
	                   m_SendData.GetLength()*2);	
}
