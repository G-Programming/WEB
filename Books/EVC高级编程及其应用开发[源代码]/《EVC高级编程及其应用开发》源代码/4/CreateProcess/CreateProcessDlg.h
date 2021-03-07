// CreateProcessDlg.h : header file
//

#if !defined(AFX_CREATEPROCESSDLG_H__A6CECDCA_7F9E_44C3_8F80_266138574278__INCLUDED_)
#define AFX_CREATEPROCESSDLG_H__A6CECDCA_7F9E_44C3_8F80_266138574278__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateProcessDlg dialog

class CCreateProcessDlg : public CDialog
{
// Construction
public:
	CCreateProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateProcessDlg)
	enum { IDD = IDD_CREATEPROCESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnexec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool WinExec(LPCTSTR FileName);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEPROCESSDLG_H__A6CECDCA_7F9E_44C3_8F80_266138574278__INCLUDED_)
