// PingExampleDlg.h : header file
//

#if !defined(AFX_PINGEXAMPLEDLG_H__2E36A495_B704_4A76_BB6D_D1D5B17549C0__INCLUDED_)
#define AFX_PINGEXAMPLEDLG_H__2E36A495_B704_4A76_BB6D_D1D5B17549C0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CPingExampleDlg dialog
class CPingExampleDlg : public CDialog
{
// Construction
public:
	CPingExampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPingExampleDlg)
	enum { IDD = IDD_PINGEXAMPLE_DIALOG };
	CListBox	m_lstRecv;
	CString	m_ipAddr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingExampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPingExampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnclear();
	afx_msg void OnBtnping();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGEXAMPLEDLG_H__2E36A495_B704_4A76_BB6D_D1D5B17549C0__INCLUDED_)
