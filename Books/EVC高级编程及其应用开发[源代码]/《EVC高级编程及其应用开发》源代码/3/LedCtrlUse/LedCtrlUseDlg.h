// LedCtrlUseDlg.h : header file
//

#if !defined(AFX_LEDCTRLUSEDLG_H__6DE50F35_F62F_4C6A_8A19_E01BBCDD00DB__INCLUDED_)
#define AFX_LEDCTRLUSEDLG_H__6DE50F35_F62F_4C6A_8A19_E01BBCDD00DB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "LedCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CLedCtrlUseDlg dialog

class CLedCtrlUseDlg : public CDialog
{
// Construction
public:
	CLedCtrlUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLedCtrlUseDlg)
	enum { IDD = IDD_LEDCTRLUSE_DIALOG };
	CLedCtrl	m_led;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLedCtrlUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLedCtrlUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEDCTRLUSEDLG_H__6DE50F35_F62F_4C6A_8A19_E01BBCDD00DB__INCLUDED_)
