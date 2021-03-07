// SpinUseDlg.h : header file
//

#if !defined(AFX_SPINUSEDLG_H__83ED59C9_B7FB_42A7_8BC6_9F8A89C409C5__INCLUDED_)
#define AFX_SPINUSEDLG_H__83ED59C9_B7FB_42A7_8BC6_9F8A89C409C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSpinUseDlg dialog

class CSpinUseDlg : public CDialog
{
// Construction
public:
	CSpinUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpinUseDlg)
	enum { IDD = IDD_SPINUSE_DIALOG };
	int		m_blue;
	int		m_green;
	int		m_red;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpinUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnColorChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINUSEDLG_H__83ED59C9_B7FB_42A7_8BC6_9F8A89C409C5__INCLUDED_)
