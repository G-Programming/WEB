#if !defined(AFX_IPCCLIENT_H__B21E172B_AD88_480B_8B11_0EFDF78405B0__INCLUDED_)
#define AFX_IPCCLIENT_H__B21E172B_AD88_480B_8B11_0EFDF78405B0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IPCClient.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIPCClient window
//定义消息常量
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//当服务器断开连接时
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//当客户端断开连接时
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//当客户端连接请求时
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//当客户端连接响应时

//客户端连接事件
typedef void (CALLBACK* ONCLIENTCONNECTED)(CWnd*,HWND);
//客户端断开事件
typedef void (CALLBACK* ONCLIENTDISCONNECTED)(CWnd*,HWND);
//客户端接收数据事件
typedef void (CALLBACK* ONCLIENTDATAARRIVE)(CWnd*,LPVOID,DWORD);


class CIPCClient : public CWnd
{
// Construction
public:
	CIPCClient();

// Attributes
public:
    LPCTSTR m_SessionName; // 连接会话的名字
	ONCLIENTCONNECTED  m_ClientConnected; //客户端连接事件
	ONCLIENTDISCONNECTED m_ClientDisConnected; //客户端断开连接事件
	ONCLIENTDATAARRIVE m_ClientDataArrive; //客户端接收数据事件

    //同服务器建立连接
	void Open(CWnd *parentWnd);
    //关闭同服务器连接
	void Close(void);
	//发送数据
	void SendMsg(LPVOID MsgPointer,  DWORD ASize);
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCClient)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIPCClient();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIPCClient)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND m_ServerWinHwnd; //服务端窗体句柄
	CWnd* m_ParentWnd; ////指定创建此组件的窗体指针
	bool m_Active; //是否激活
    DWORD m_SessionHandle; //连接会话的消息标识符
    DWORD m_ServerDisconnectHwnd; //IPCServerDisconnecting消息标识符
    DWORD m_ConnectRequestHwnd; //IPCConnectRequest消息标识符
    DWORD m_ConnectResposeHwnd; //IPCConnectRespose消息标识符
    DWORD m_ClientDisconnectHwnd; //IPCClientDisconnecting消息标识符
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCCLIENT_H__B21E172B_AD88_480B_8B11_0EFDF78405B0__INCLUDED_)
