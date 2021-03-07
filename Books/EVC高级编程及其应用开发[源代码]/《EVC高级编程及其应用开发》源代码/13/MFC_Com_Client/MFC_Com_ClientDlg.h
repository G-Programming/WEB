// MFC_Com_ClientDlg.h : header file
//

#if !defined(AFX_MFC_COM_CLIENTDLG_H__95F4622E_ECD6_4CB8_BEE5_981639ACF646__INCLUDED_)
#define AFX_MFC_COM_CLIENTDLG_H__95F4622E_ECD6_4CB8_BEE5_981639ACF646__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_Com_ClientDlg dialog

class CMFC_Com_ClientDlg : public CDialog
{
// Construction
public:
	CMFC_Com_ClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_Com_ClientDlg)
	enum { IDD = IDD_MFC_COM_CLIENT_DIALOG };
	CString	m_log;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_Com_ClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_Com_ClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnExec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_COM_CLIENTDLG_H__95F4622E_ECD6_4CB8_BEE5_981639ACF646__INCLUDED_)
