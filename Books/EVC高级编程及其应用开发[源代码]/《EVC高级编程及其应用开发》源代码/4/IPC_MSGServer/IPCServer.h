#if !defined(AFX_IPCSERVER_H__E3B9D56F_ECCE_413E_9519_9143A50FD136__INCLUDED_)
#define AFX_IPCSERVER_H__E3B9D56F_ECCE_413E_9519_9143A50FD136__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IPCServer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIPCServer window

//������Ϣ����
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//���������Ͽ�����ʱ
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//���ͻ��˶Ͽ�����ʱ
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//���ͻ�����������ʱ
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//���ͻ���������Ӧʱ

//�����������¼�
typedef void (CALLBACK* ONSERVERCONNECTED)(CWnd*,HWND);
//�������Ͽ��¼�
typedef void (CALLBACK* ONSERVERDISCONNECTED)(CWnd*,HWND);
//���������������¼�
typedef void (CALLBACK* ONSERVERDATAARRIVE)(CWnd*,LPVOID,DWORD,HWND);

class CIPCServer : public CWnd
{
// Construction
public:
	CIPCServer();

// Attributes
public:
	LPCTSTR m_SessionName; //���ӻỰ������
	ONSERVERCONNECTED  m_ServerConnected; //�����������¼�
	ONSERVERDISCONNECTED m_ServerDisConnected; //�������Ͽ��¼�
	ONSERVERDATAARRIVE m_ServerDataArrive; //���������������¼�

    //�򿪷����������м���
    void Open(CWnd* parentWnd);
    //�رշ�����
	void Close(void);
	//��������
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
	bool m_Active; //�Ƿ񼤻�
	CWnd* m_ParentWnd; //ָ���������������ָ��
    DWORD m_SessionHandle; //���ӻỰ����Ϣ��ʶ��
    DWORD m_ServerDisConnectHwnd; //IPCServerDisconnecting��Ϣ��ʶ��
    DWORD m_ConnectRequestHwnd; //IPCConnectRequest��Ϣ��ʶ��
    DWORD m_ConnectResposeHwnd; //IPCConnectRespose��Ϣ��ʶ��
    DWORD m_ClientDisConnectHwnd; //IPCClientDisconnecting��Ϣ��ʶ��
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCSERVER_H__E3B9D56F_ECCE_413E_9519_9143A50FD136__INCLUDED_)
