// ResDllTestDlg.h : header file
//

#if !defined(AFX_RESDLLTESTDLG_H__5CDE9DF6_8032_492F_85CA_2A9F85AC3910__INCLUDED_)
#define AFX_RESDLLTESTDLG_H__5CDE9DF6_8032_492F_85CA_2A9F85AC3910__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CResDllTestDlg dialog
//添加资源定义标识
#define IDB_RESBMP                      101
#define IDC_RESCUR                      102
#define IDI_RESICON                     103


class CResDllTestDlg : public CDialog
{
// Construction
public:
	CResDllTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CResDllTestDlg)
	enum { IDD = IDD_RESDLLTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResDllTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CResDllTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnload();
	afx_msg void OnBtnfree();
	afx_msg void OnBtnbmp();
	afx_msg void OnBtnicon();
	afx_msg void OnBtncur();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//DLL句柄
	HINSTANCE m_hDll;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESDLLTESTDLG_H__5CDE9DF6_8032_492F_85CA_2A9F85AC3910__INCLUDED_)
