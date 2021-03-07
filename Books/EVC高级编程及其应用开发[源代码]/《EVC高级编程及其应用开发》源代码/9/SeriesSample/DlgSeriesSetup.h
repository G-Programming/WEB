#if !defined(AFX_DLGSERIESSETUP_H__20E607A1_7927_4133_B1A6_08A935FFC2EF__INCLUDED_)
#define AFX_DLGSERIESSETUP_H__20E607A1_7927_4133_B1A6_08A935FFC2EF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DlgSeriesSetup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSeriesSetup dialog

class CDlgSeriesSetup : public CDialog
{
// Construction
public:
	CDlgSeriesSetup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSeriesSetup)
	enum { IDD = IDD_DIALOG_SETUPSERIES };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSeriesSetup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSeriesSetup)
	afx_msg void OnBtnopen();
	afx_msg void OnBtnclose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	UINT m_portNo; /*串口号*/
	UINT m_baud;	/*波特率*/
	UINT m_parity; /*奇偶校验*/
	UINT m_databits;/*数据位*/
	UINT m_stopbits;/*停止位*/
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERIESSETUP_H__20E607A1_7927_4133_B1A6_08A935FFC2EF__INCLUDED_)
