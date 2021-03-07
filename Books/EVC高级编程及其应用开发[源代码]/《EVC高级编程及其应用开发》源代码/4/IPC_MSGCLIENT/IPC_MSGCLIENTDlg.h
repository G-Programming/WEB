// IPC_MSGCLIENTDlg.h : header file
//

#if !defined(AFX_IPC_MSGCLIENTDLG_H__3DC0AED7_E2AE_4002_A7BE_5DCA0F7835F2__INCLUDED_)
#define AFX_IPC_MSGCLIENTDLG_H__3DC0AED7_E2AE_4002_A7BE_5DCA0F7835F2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "IPCClient.h"
/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGCLIENTDlg dialog

class CIPC_MSGCLIENTDlg : public CDialog
{
// Construction
public:
	CIPC_MSGCLIENTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIPC_MSGCLIENTDlg)
	enum { IDD = IDD_IPC_MSGCLIENT_DIALOG };
	CString	m_SessionName;
	CString	m_Status;
	CString	m_RecvData;
	CString	m_SendData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPC_MSGCLIENTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIPC_MSGCLIENTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnconnect();
	afx_msg void OnBtndisconnect();
	afx_msg void OnBtnsenddata();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CIPCClient m_IPCClient;
	//回调函数，客户端建立连接事件函数
	static void CALLBACK OnClientConnected(CWnd *parentWnd,HWND hWnd);
	//回调函数，客户端断开连接事件函数
	static void CALLBACK OnClientDisConnected(CWnd *parentWnd,HWND hWnd);
	//回调函数，客户端接收数据事件函数
	static void CALLBACK OnClientDataArrive(CWnd *parentWnd,LPVOID pData,DWORD bufLen);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPC_MSGCLIENTDLG_H__3DC0AED7_E2AE_4002_A7BE_5DCA0F7835F2__INCLUDED_)
