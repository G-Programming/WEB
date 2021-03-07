#if !defined(AFX_CLOCKST_H__83406643_5A4E_4DE4_A8A7_D9CE93A75D49__INCLUDED_)
#define AFX_CLOCKST_H__83406643_5A4E_4DE4_A8A7_D9CE93A75D49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ClockST.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClockST window

class AFX_EXT_CLASS CClockST : public CWnd
{
// Construction
public:
	CClockST();

// Attributes
protected:
	//ª≠±Ì≈Ã
	void DrawDial(CDC *pDC,CRect rect);

	//ª≠ ±’Î
	void DrawHourHand(CDC *pDC,CRect rect ,int nHour);

	//ª≠∑÷’Î
	void DrawMinuteHand(CDC *pDC,CRect rect ,int nMinute);

	//ª≠√Î’Î
	void DrawSecondHand(CDC *pDC ,CRect rect ,int nSecond);
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockST)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClockST();

	// Generated message map functions
protected:
	//{{AFX_MSG(CClockST)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKST_H__83406643_5A4E_4DE4_A8A7_D9CE93A75D49__INCLUDED_)
