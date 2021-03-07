// TCPClientDlg.h : header file
//

#if !defined(AFX_TCPCLIENTDLG_H__F00D36E6_3F71_481D_A6F1_0F41D60CE8C8__INCLUDED_)
#define AFX_TCPCLIENTDLG_H__F00D36E6_3F71_481D_A6F1_0F41D60CE8C8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "TCPClient_CE.h"
/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg dialog

class CTCPClientDlg : public CDialog
{
// Construction
public:
	CTCPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPClientDlg)
	enum { IDD = IDD_TCPCLIENT_DIALOG };
	CString	m_remoteHost;
	int		m_remotePort;
	CString	m_recvData;
	CString	m_sendData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnconn();
	afx_msg void OnBtndisconn();
	afx_msg void OnBtnsenddata();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//����CTCPClient_CE����
	CTCPClient_CE m_tcpClient;
private:
	//���ӶϿ��¼�������
	static void CALLBACK OnDisConnect(CWnd* pWnd);
	//�������ݽ����¼�������
	static void CALLBACK OnRead(CWnd* pWnd,const char * buf,int len );
	//Socket�����¼�������
	static void CALLBACK OnError(CWnd* pWnd,int nErrorCode);
private:
	//�õ����ص�IP��ַ
	CString GetLocalIP();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPCLIENTDLG_H__F00D36E6_3F71_481D_A6F1_0F41D60CE8C8__INCLUDED_)
