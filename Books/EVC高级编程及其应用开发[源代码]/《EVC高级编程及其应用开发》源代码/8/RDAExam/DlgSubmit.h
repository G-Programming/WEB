#if !defined(AFX_DLGSUBMIT_H__365857C0_9696_4B68_80BA_19910FC5AF8A__INCLUDED_)
#define AFX_DLGSUBMIT_H__365857C0_9696_4B68_80BA_19910FC5AF8A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSubmit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSubmit dialog

class CDlgSubmit : public CDialog
{
// Construction
public:
	CDlgSubmit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSubmit)
	enum { IDD = IDD_DLGSUBMIT_DIALOG };
	CString	m_internetURL;
	CString	m_internetPassword;
	CString	m_queryStr;
	CString	m_internetUsername;
	CString	m_connectStr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSubmit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSubmit)
	afx_msg void OnBtnok();
	afx_msg void OnBtncancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSUBMIT_H__365857C0_9696_4B68_80BA_19910FC5AF8A__INCLUDED_)
