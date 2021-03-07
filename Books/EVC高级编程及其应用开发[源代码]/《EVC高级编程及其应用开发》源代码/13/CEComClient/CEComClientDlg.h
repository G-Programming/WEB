// CEComClientDlg.h : header file
//

#if !defined(AFX_CECOMCLIENTDLG_H__64E5775C_2A2D_45C0_9B93_D57B30D1AAB5__INCLUDED_)
#define AFX_CECOMCLIENTDLG_H__64E5775C_2A2D_45C0_9B93_D57B30D1AAB5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CCEComClientDlg dialog

class CCEComClientDlg : public CDialog
{
// Construction
public:
	CCEComClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCEComClientDlg)
	enum { IDD = IDD_CECOMCLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCEComClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCEComClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtncall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CLSID clsid;
	ISimple *m_pSimple;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CECOMCLIENTDLG_H__64E5775C_2A2D_45C0_9B93_D57B30D1AAB5__INCLUDED_)
