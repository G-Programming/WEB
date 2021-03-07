// MyCEActiveX_TestDlg.h : header file
//
//{{AFX_INCLUDES()
#include "myceactivex.h"
//}}AFX_INCLUDES

#if !defined(AFX_MYCEACTIVEX_TESTDLG_H__90508C91_8D56_43FF_8551_9EED607D2EF0__INCLUDED_)
#define AFX_MYCEACTIVEX_TESTDLG_H__90508C91_8D56_43FF_8551_9EED607D2EF0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveX_TestDlg dialog

class CMyCEActiveX_TestDlg : public CDialog
{
// Construction
public:
	CMyCEActiveX_TestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyCEActiveX_TestDlg)
	enum { IDD = IDD_MYCEACTIVEX_TEST_DIALOG };
	CMyCEActiveX	m_myCEActiveX;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCEActiveX_TestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyCEActiveX_TestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnOnMsgChangeMyceactivexctrl1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCEACTIVEX_TESTDLG_H__90508C91_8D56_43FF_8551_9EED607D2EF0__INCLUDED_)
