#if !defined(AFX_IPCCLIENT_H__B21E172B_AD88_480B_8B11_0EFDF78405B0__INCLUDED_)
#define AFX_IPCCLIENT_H__B21E172B_AD88_480B_8B11_0EFDF78405B0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// IPCClient.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIPCClient window
//������Ϣ����
const LPCTSTR IPCServerDisconnecting = _T("IPCServerDisconnecting");//���������Ͽ�����ʱ
const LPCTSTR IPCClientDisconnecting = _T("IPCClientDisconnecting");//���ͻ��˶Ͽ�����ʱ
const LPCTSTR IPCConnectRequest = _T("IPCConnectRequest");//���ͻ�����������ʱ
const LPCTSTR IPCConnectRespose = _T("IPCConnectRespose");//���ͻ���������Ӧʱ

//�ͻ��������¼�
typedef void (CALLBACK* ONCLIENTCONNECTED)(CWnd*,HWND);
//�ͻ��˶Ͽ��¼�
typedef void (CALLBACK* ONCLIENTDISCONNECTED)(CWnd*,HWND);
//�ͻ��˽��������¼�
typedef void (CALLBACK* ONCLIENTDATAARRIVE)(CWnd*,LPVOID,DWORD);


class CIPCClient : public CWnd
{
// Construction
public:
	CIPCClient();

// Attributes
public:
    LPCTSTR m_SessionName; // ���ӻỰ������
	ONCLIENTCONNECTED  m_ClientConnected; //�ͻ��������¼�
	ONCLIENTDISCONNECTED m_ClientDisConnected; //�ͻ��˶Ͽ������¼�
	ONCLIENTDATAARRIVE m_ClientDataArrive; //�ͻ��˽��������¼�

    //ͬ��������������
	void Open(CWnd *parentWnd);
    //�ر�ͬ����������
	void Close(void);
	//��������
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
	HWND m_ServerWinHwnd; //����˴�����
	CWnd* m_ParentWnd; ////ָ������������Ĵ���ָ��
	bool m_Active; //�Ƿ񼤻�
    DWORD m_SessionHandle; //���ӻỰ����Ϣ��ʶ��
    DWORD m_ServerDisconnectHwnd; //IPCServerDisconnecting��Ϣ��ʶ��
    DWORD m_ConnectRequestHwnd; //IPCConnectRequest��Ϣ��ʶ��
    DWORD m_ConnectResposeHwnd; //IPCConnectRespose��Ϣ��ʶ��
    DWORD m_ClientDisconnectHwnd; //IPCClientDisconnecting��Ϣ��ʶ��
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCCLIENT_H__B21E172B_AD88_480B_8B11_0EFDF78405B0__INCLUDED_)
