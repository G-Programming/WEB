#if !defined(AFX_DLGPULL_H__346AF370_7584_4EAA_B538_3029B5916BCC__INCLUDED_)
#define AFX_DLGPULL_H__346AF370_7584_4EAA_B538_3029B5916BCC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgPull.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPull dialog

class CDlgPull : public CDialog
{
// Construction
public:
	CDlgPull(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPull)
	enum { IDD = IDD_DLGPULL_DIALOG };
	CString	m_connectStr;
	CString	m_errorTableName;
	CString	m_internetPassword;
	CString	m_internetURL;
	CString	m_localConnectStr;
	CString	m_localTableName;
	CString	m_queryStr;
	CString	m_internetUsername;
	CString	m_tracking;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPull)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPull)
	afx_msg void OnBtnok();
	afx_msg void OnBtncancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPULL_H__346AF370_7584_4EAA_B538_3029B5916BCC__INCLUDED_)
