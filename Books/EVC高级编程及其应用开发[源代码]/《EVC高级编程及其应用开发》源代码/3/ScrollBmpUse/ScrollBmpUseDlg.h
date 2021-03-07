// ScrollBmpUseDlg.h : header file
//

#if !defined(AFX_SCROLLBMPUSEDLG_H__1DF1228A_ECBE_4A78_9B53_333AF4B0761B__INCLUDED_)
#define AFX_SCROLLBMPUSEDLG_H__1DF1228A_ECBE_4A78_9B53_333AF4B0761B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CScrollBmpUseDlg dialog
#include "ScrollBmp.h"
class CScrollBmpUseDlg : public CDialog
{
// Construction
public:
	CScrollBmpUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScrollBmpUseDlg)
	enum { IDD = IDD_SCROLLBMPUSE_DIALOG };
	CScrollBmp	m_scrollBmp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBmpUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScrollBmpUseDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLBMPUSEDLG_H__1DF1228A_ECBE_4A78_9B53_333AF4B0761B__INCLUDED_)
