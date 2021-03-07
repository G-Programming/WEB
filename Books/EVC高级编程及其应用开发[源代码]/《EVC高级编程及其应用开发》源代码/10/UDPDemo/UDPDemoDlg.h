// UDPDemoDlg.h : header file
//

#if !defined(AFX_UDPDEMODLG_H__E689F99C_5356_4BBF_A1DE_FD5DC12724CA__INCLUDED_)
#define AFX_UDPDEMODLG_H__E689F99C_5356_4BBF_A1DE_FD5DC12724CA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "udp_ce.h"
/////////////////////////////////////////////////////////////////////////////
// CUDPDemoDlg dialog

class CUDPDemoDlg : public CDialog
{
// Construction
public:
	CUDPDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPDemoDlg)
	enum { IDD = IDD_UDPDEMO_DIALOG };
	int		m_LocalPort;
	int		m_RecvNum;
	CString	m_RecvStr;
	CString	m_RemoteHost;
	int		m_RemotePort;
	int		m_SendNum;
	CString	m_SendStr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUDPDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnopen();
	afx_msg void OnBtnclose();
	afx_msg void OnBtnsend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//定义UDP通讯类变量
	CUDP_CE m_CEUdp;
	//UDP接收数据事件
	static void CALLBACK OnUdpCERecv(CWnd * pWnd,char* buf,int nLen,sockaddr * addr);
	//UDP通讯错误事件
	static void CALLBACK OnUdpCEError(CWnd * pWnd,int nError);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPDEMODLG_H__E689F99C_5356_4BBF_A1DE_FD5DC12724CA__INCLUDED_)
