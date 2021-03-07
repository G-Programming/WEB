// speciallyEffectDlg.h : header file
//

#if !defined(AFX_SPECIALLYEFFECTDLG_H__7F8B7BA0_4EF8_46A3_8733_CFB9471705DD__INCLUDED_)
#define AFX_SPECIALLYEFFECTDLG_H__7F8B7BA0_4EF8_46A3_8733_CFB9471705DD__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSpeciallyEffectDlg dialog

class CSpeciallyEffectDlg : public CDialog
{
// Construction
public:
	CSpeciallyEffectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpeciallyEffectDlg)
	enum { IDD = IDD_SPECIALLYEFFECT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeciallyEffectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpeciallyEffectDlg)
	virtual BOOL OnInitDialog();

	afx_msg void OnSelchangeList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALLYEFFECTDLG_H__7F8B7BA0_4EF8_46A3_8733_CFB9471705DD__INCLUDED_)
