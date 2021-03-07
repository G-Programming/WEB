#if !defined(AFX_LISTCTRLATTR_H__36B132DA_3AC8_4F81_93B8_C831D8BDEFC9__INCLUDED_)
#define AFX_LISTCTRLATTR_H__36B132DA_3AC8_4F81_93B8_C831D8BDEFC9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ListCtrlAttr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListCtrlAttr dialog

class CListCtrlAttr : public CDialog
{
// Construction
public:
	CListCtrlAttr(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CListCtrlAttr)
	enum { IDD = IDD_LISTCTRLATTR_DIALOG };
	BOOL	m_bNoColumnHeader;
	BOOL	m_bEditLabels;
	BOOL	m_bSingleSel;
	CString	m_cstrViewMode;
	CString	m_cstrSort;
	CString	m_cstrAlignMode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlAttr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListCtrlAttr)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLATTR_H__36B132DA_3AC8_4F81_93B8_C831D8BDEFC9__INCLUDED_)
