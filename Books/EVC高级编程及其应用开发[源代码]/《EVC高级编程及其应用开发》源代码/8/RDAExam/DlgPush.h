#if !defined(AFX_DLGPUSH_H__6D00CE06_747C_4CDF_8DF0_6FD763BEBF82__INCLUDED_)
#define AFX_DLGPUSH_H__6D00CE06_747C_4CDF_8DF0_6FD763BEBF82__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgPush.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPush dialog

class CDlgPush : public CDialog
{
// Construction
public:
	CDlgPush(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPush)
	enum { IDD = IDD_DLGPUSH_DIALOG };
	CString	m_connectStr;
	CString	m_internetPassword;
	CString	m_internetURL;
	CString	m_localConnectStr;
	CString	m_localTableName;
	CString	m_internetUsername;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPush)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPush)
	afx_msg void OnBtnok();
	afx_msg void OnBtncancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPUSH_H__6D00CE06_747C_4CDF_8DF0_6FD763BEBF82__INCLUDED_)
