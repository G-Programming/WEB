// AnimateDrawDlg.h : header file
//

#if !defined(AFX_ANIMATEDRAWDLG_H__FDE1DF39_D1B5_4361_8B4E_C97AE6E0C7DD__INCLUDED_)
#define AFX_ANIMATEDRAWDLG_H__FDE1DF39_D1B5_4361_8B4E_C97AE6E0C7DD__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CAnimateDrawDlg dialog

class CAnimateDrawDlg : public CDialog
{
// Construction
public:
	CAnimateDrawDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAnimateDrawDlg)
	enum { IDD = IDD_ANIMATEDRAW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateDrawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAnimateDrawDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATEDRAWDLG_H__FDE1DF39_D1B5_4361_8B4E_C97AE6E0C7DD__INCLUDED_)
