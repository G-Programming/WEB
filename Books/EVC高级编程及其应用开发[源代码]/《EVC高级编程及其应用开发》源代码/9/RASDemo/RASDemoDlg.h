// RASDemoDlg.h : header file
//

#if !defined(AFX_RASDEMODLG_H__FE87934C_D2D7_458D_B46E_1B705D0E912E__INCLUDED_)
#define AFX_RASDEMODLG_H__FE87934C_D2D7_458D_B46E_1B705D0E912E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CERas.h"

/////////////////////////////////////////////////////////////////////////////
// CRASDemoDlg dialog

class CRASDemoDlg : public CDialog
{
// Construction
public:
	CRASDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRASDemoDlg)
	enum { IDD = IDD_RASDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRASDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRASDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtndial();
	afx_msg void OnBtnhangup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCERAS m_ceRas;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RASDEMODLG_H__FE87934C_D2D7_458D_B46E_1B705D0E912E__INCLUDED_)
