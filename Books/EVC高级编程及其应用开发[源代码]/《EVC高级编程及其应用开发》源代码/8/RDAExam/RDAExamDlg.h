// RDAExamDlg.h : header file
//

#if !defined(AFX_RDAEXAMDLG_H__24131E39_9065_4D13_BC51_F3438CFA219F__INCLUDED_)
#define AFX_RDAEXAMDLG_H__24131E39_9065_4D13_BC51_F3438CFA219F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ca_mergex20.h"

/////////////////////////////////////////////////////////////////////////////
// CRDAExamDlg dialog

class CRDAExamDlg : public CDialog
{
// Construction
public:
	CRDAExamDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRDAExamDlg)
	enum { IDD = IDD_RDAEXAM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRDAExamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRDAExamDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnsubmit();
	afx_msg void OnBtnpull();
	afx_msg void OnBtnpush();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//显示远程数据访问时的错误
	void    ShowErrors(ISSCEErrors* pISSCEErrors);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RDAEXAMDLG_H__24131E39_9065_4D13_BC51_F3438CFA219F__INCLUDED_)
