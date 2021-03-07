// SeriesSampleDlg.h : header file
//

#if !defined(AFX_SERIESSAMPLEDLG_H__A5DD9DD7_F6AA_4933_AF62_CCCC36CB4280__INCLUDED_)
#define AFX_SERIESSAMPLEDLG_H__A5DD9DD7_F6AA_4933_AF62_CCCC36CB4280__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "CESeries.h"
/////////////////////////////////////////////////////////////////////////////
// CSeriesSampleDlg dialog

class CSeriesSampleDlg : public CDialog
{
// Construction
public:
	CSeriesSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSeriesSampleDlg)
	enum { IDD = IDD_SERIESSAMPLE_DIALOG };
	CString	m_strRecv;
	CString	m_strSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriesSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSeriesSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnconn();
	afx_msg void OnBtndisconn();
	afx_msg void OnBtnsend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCESeries m_ceSeries; //定义串口类
private:
	static void OnSeriesRead(CWnd* pWnd,BYTE* buf,int bufLen);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIESSAMPLEDLG_H__A5DD9DD7_F6AA_4933_AF62_CCCC36CB4280__INCLUDED_)
