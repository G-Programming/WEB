#if !defined(AFX_STUDENTINPUTDLG_H__7D227A67_3186_4633_8E6C_3056373124BD__INCLUDED_)
#define AFX_STUDENTINPUTDLG_H__7D227A67_3186_4633_8E6C_3056373124BD__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// StudentInputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentInputDlg dialog

class CStudentInputDlg : public CDialog
{
// Construction
public:
	CStudentInputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentInputDlg)
	enum { IDD = IDD_STUDENTINPUTDLG_DIALOG };
	CTime	m_birthday;
	CString	m_name;
	CString	m_no;
	int		m_stature;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentInputDlg)
	afx_msg void OnBtnOk();
	afx_msg void OnBtnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTINPUTDLG_H__7D227A67_3186_4633_8E6C_3056373124BD__INCLUDED_)
