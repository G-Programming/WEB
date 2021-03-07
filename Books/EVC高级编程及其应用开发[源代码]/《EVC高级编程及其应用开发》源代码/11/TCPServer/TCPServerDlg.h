// TCPServerDlg.h : header file
//

#if !defined(AFX_TCPSERVERDLG_H__608CC623_E942_418A_9836_1905480EBF12__INCLUDED_)
#define AFX_TCPSERVERDLG_H__608CC623_E942_418A_9836_1905480EBF12__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPServerDlg dialog
#include "TCPServer_CE.h"
#include "TCPCustom_CE.h"
class CTCPServerDlg : public CDialog
{
// Construction
public:
	CTCPServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPServerDlg)
	enum { IDD = IDD_TCPSERVER_DIALOG };
	int		m_localPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnlisten();
	afx_msg void OnBtnclose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//����CTCPServer_CE����
	CTCPServer_CE m_tcpServer;
private:
	//�ͻ������ӽ����¼�������
	static void CALLBACK	OnClientConnect(CWnd* pWnd,CTCPCustom_CE *pTcpCustom);
	//�ͻ���SOCKET�ر��¼�������
	static void  CALLBACK OnClientClose(CWnd* pWnd,CTCPCustom_CE*pTcpCustom);
	//���������յ����Կͻ��˵�����
	static  void CALLBACK OnClientRead(CWnd* pWnd,CTCPCustom_CE* pTcpCustom,const char * buf,int len );
	//�ͻ���Socket�����¼�������
	static  void CALLBACK OnClientError(CWnd* pWnd,CTCPCustom_CE* pTcpCustom,int nErrorCode);
	
	//��������Socket�����¼�������
	static void CALLBACK OnServerError(CWnd* pWnd,CTCPServer_CE* pTcpServer_CE,int nErrorCode);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPSERVERDLG_H__608CC623_E942_418A_9836_1905480EBF12__INCLUDED_)
