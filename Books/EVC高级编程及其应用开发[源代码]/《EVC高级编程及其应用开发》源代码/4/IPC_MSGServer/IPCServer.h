#if !defined(AFX_IPCSERVER_H__E3B9D56F_ECCE_413E_9519_9143A50FD136__INCLUDED_)
#define AFX_IPCSERVER_H__E3B9D56F_ECCE_413E_9519_9143A50FD136__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IPCServer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIPCServer window

//定义消息常量
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//当服务器断开连接时
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//当客户端断开连接时
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//当客户端连接请求时
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//当客户端连接响应时

//服务器连接事件
typedef void (CALLBACK* ONSERVERCONNECTED)(CWnd*,HWND);
//服务器断开事件
typedef void (CALLBACK* ONSERVERDISCONNECTED)(CWnd*,HWND);
//服务器接收数据事件
typedef void (CALLBACK* ONSERVERDATAARRIVE)(CWnd*,LPVOID,DWORD,HWND);

class CIPCServer : public CWnd
{
// Construction
public:
	CIPCServer();

// Attributes
public:
	LPCTSTR m_SessionName; //连接会话的名字
	ONSERVERCONNECTED  m_ServerConnected; //服务器连接事件
	ONSERVERDISCONNECTED m_ServerDisConnected; //服务器断开事件
	ONSERVERDATAARRIVE m_ServerDataArrive; //服务器接收数据事件

    //打开服务器，进行监听
    void Open(CWnd* parentWnd);
    //关闭服务器
	void Close(void);
	//发送数据
    void SendMsg(LPVOID MsgPointer, HWND AWinHwnd, DWORD ASize);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCServer)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIPCServer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIPCServer)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool m_Active; //是否激活
	CWnd* m_ParentWnd; //指定创建此组件的类指针
    DWORD m_SessionHandle; //连接会话的消息标识符
    DWORD m_ServerDisConnectHwnd; //IPCServerDisconnecting消息标识符
    DWORD m_ConnectRequestHwnd; //IPCConnectRequest消息标识符
    DWORD m_ConnectResposeHwnd; //IPCConnectRespose消息标识符
    DWORD m_ClientDisConnectHwnd; //IPCClientDisconnecting消息标识符
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCSERVER_H__E3B9D56F_ECCE_413E_9519_9143A50FD136__INCLUDED_)
