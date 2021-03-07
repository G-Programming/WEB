// Draw2DGraphDlg.h : header file
//

#if !defined(AFX_DRAW2DGRAPHDLG_H__935A4636_1422_4BF9_8D2B_22A3C5923B77__INCLUDED_)
#define AFX_DRAW2DGRAPHDLG_H__935A4636_1422_4BF9_8D2B_22A3C5923B77__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "2DGraph.h"
/////////////////////////////////////////////////////////////////////////////
// CDraw2DGraphDlg dialog

class CDraw2DGraphDlg : public CDialog
{
// Construction
public:
	CDraw2DGraphDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDraw2DGraphDlg)
	enum { IDD = IDD_DRAW2DGRAPH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw2DGraphDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDraw2DGraphDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	C2DGraph m_2DGraph;
	int m_pointCount;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW2DGRAPHDLG_H__935A4636_1422_4BF9_8D2B_22A3C5923B77__INCLUDED_)
