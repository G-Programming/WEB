// IPC_MSGServerDlg.h : header file
//

#if !defined(AFX_IPC_MSGSERVERDLG_H__1013437D_C9D7_4E9B_90C0_CF941B69D324__INCLUDED_)
#define AFX_IPC_MSGSERVERDLG_H__1013437D_C9D7_4E9B_90C0_CF941B69D324__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerDlg dialog
#include "IPCServer.h"
class CIPC_MSGServerDlg : public CDialog
{
// Construction
public:
	CIPC_MSGServerDlg(CWnd* pParent = NULL);	// standard constructor
	//存储客户端窗口句柄
	HWND m_ClientWnd;
// Dialog Data
	//{{AFX_DATA(CIPC_MSGServerDlg)
	enum { IDD = IDD_IPC_MSGSERVER_DIALOG };
	CString	m_RecvData;
	CString	m_SendData;
	CString	m_SessionName;
	CString	m_Status;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPC_MSGServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIPC_MSGServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnopen();
	afx_msg void OnBtnclose();
	afx_msg void OnBtnsenddata();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	//定义进程通讯类变量
	CIPCServer m_IPCServer;
    //回调函数，服务器连接事件
	static void CALLBACK OnServerConnected(CWnd* parentWnd,HWND hWnd);
    //回调函数，服务器断开连接事件
	static void CALLBACK OnServerDisConnected(CWnd* parentWnd,HWND hWnd);
    //回调函数，服务器接收数据事件
	static void CALLBACK OnServerDataArrive(CWnd* parentWnd,LPVOID pData,DWORD bufLen,HWND hWnd);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPC_MSGSERVERDLG_H__1013437D_C9D7_4E9B_90C0_CF941B69D324__INCLUDED_)
