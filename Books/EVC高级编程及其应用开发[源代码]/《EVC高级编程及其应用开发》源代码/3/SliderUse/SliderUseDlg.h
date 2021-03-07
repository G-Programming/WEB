// SliderUseDlg.h : header file
//

#if !defined(AFX_SLIDERUSEDLG_H__4FE474ED_F010_44F1_A2BB_54F3194FCC49__INCLUDED_)
#define AFX_SLIDERUSEDLG_H__4FE474ED_F010_44F1_A2BB_54F3194FCC49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSliderUseDlg dialog

class CSliderUseDlg : public CDialog
{
// Construction
public:
	CSliderUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSliderUseDlg)
	enum { IDD = IDD_SLIDERUSE_DIALOG };
	CSliderCtrl	m_slider_red;
	CSliderCtrl	m_slider_green;
	CSliderCtrl	m_slider_blue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSliderUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSliderUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERUSEDLG_H__4FE474ED_F010_44F1_A2BB_54F3194FCC49__INCLUDED_)
