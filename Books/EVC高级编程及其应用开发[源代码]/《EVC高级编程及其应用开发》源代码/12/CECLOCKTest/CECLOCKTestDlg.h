// CECLOCKTestDlg.h : header file
//

#if !defined(AFX_CECLOCKTESTDLG_H__04BDC7F5_BE7C_4F92_9B08_96567F00AF83__INCLUDED_)
#define AFX_CECLOCKTESTDLG_H__04BDC7F5_BE7C_4F92_9B08_96567F00AF83__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CCECLOCKTestDlg dialog
#include "ClockST.h"

class CCECLOCKTestDlg : public CDialog
{
// Construction
public:
	CCECLOCKTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCECLOCKTestDlg)
	enum { IDD = IDD_CECLOCKTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCECLOCKTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCECLOCKTestDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CClockST m_clock;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CECLOCKTESTDLG_H__04BDC7F5_BE7C_4F92_9B08_96567F00AF83__INCLUDED_)
