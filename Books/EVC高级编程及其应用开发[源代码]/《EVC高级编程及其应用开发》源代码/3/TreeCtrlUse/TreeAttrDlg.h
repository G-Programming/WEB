#if !defined(AFX_TREEATTRDLG_H__26492005_5BA1_485A_9167_2AE13C2F964C__INCLUDED_)
#define AFX_TREEATTRDLG_H__26492005_5BA1_485A_9167_2AE13C2F964C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TreeAttrDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTreeAttrDlg dialog

class CTreeAttrDlg : public CDialog
{
// Construction
public:
	CTreeAttrDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeAttrDlg)
	enum { IDD = IDD_TREEATTRDLG_DIALOG };
	BOOL	m_bEditLabels;
	BOOL	m_bHasButtons;
	BOOL	m_bHasLines;
	BOOL	m_bLinesAtRoot;
	BOOL	m_bShowSelAlways;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeAttrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTreeAttrDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEATTRDLG_H__26492005_5BA1_485A_9167_2AE13C2F964C__INCLUDED_)
