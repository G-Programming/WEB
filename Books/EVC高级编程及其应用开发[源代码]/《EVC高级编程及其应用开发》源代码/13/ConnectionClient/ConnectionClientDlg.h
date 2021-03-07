// ConnectionClientDlg.h : header file
//

#if !defined(AFX_CONNECTIONCLIENTDLG_H__978481D4_1DA1_4C79_8893_C4784E949C4B__INCLUDED_)
#define AFX_CONNECTIONCLIENTDLG_H__978481D4_1DA1_4C79_8893_C4784E949C4B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CConnectionClientDlg dialog

class CConnectionClientDlg : public CDialog
{
// Construction
public:
	CConnectionClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CConnectionClientDlg)
	enum { IDD = IDD_CONNECTIONCLIENT_DIALOG };
	int		m_number1;
	int		m_number2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectionClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConnectionClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnExec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTIONCLIENTDLG_H__978481D4_1DA1_4C79_8893_C4784E949C4B__INCLUDED_)
