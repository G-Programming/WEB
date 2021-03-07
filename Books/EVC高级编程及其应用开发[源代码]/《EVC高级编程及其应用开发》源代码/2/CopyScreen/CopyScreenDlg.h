// CopyScreenDlg.h : header file
//

#if !defined(AFX_COPYSCREENDLG_H__F5033DA1_5F46_4FB2_B947_5945C95B909A__INCLUDED_)
#define AFX_COPYSCREENDLG_H__F5033DA1_5F46_4FB2_B947_5945C95B909A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CCopyScreenDlg dialog

class CCopyScreenDlg : public CDialog
{

// Construction
public:
	CCopyScreenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCopyScreenDlg)
	enum { IDD = IDD_COPYSCREEN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopyScreenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCopyScreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnsnap();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYSCREENDLG_H__F5033DA1_5F46_4FB2_B947_5945C95B909A__INCLUDED_)
