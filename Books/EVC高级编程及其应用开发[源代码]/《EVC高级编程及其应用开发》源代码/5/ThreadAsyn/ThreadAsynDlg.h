// ThreadAsynDlg.h : header file
//

#if !defined(AFX_THREADASYNDLG_H__71EAFB43_A687_40C3_8DE0_8715EE73C2C4__INCLUDED_)
#define AFX_THREADASYNDLG_H__71EAFB43_A687_40C3_8DE0_8715EE73C2C4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadAsynDlg dialog

//定义数组大小
const MAXDATASIZE=100;

class CThreadAsynDlg : public CDialog
{
// Construction
public:
	CThreadAsynDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadAsynDlg)
	enum { IDD = IDD_THREADASYN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadAsynDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadAsynDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBtnexec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
   int m_incNum; //记数
   int m_aGlobalData[MAXDATASIZE]; //数组


private:
   //线程函数
   static DWORD ThreadProc(PVOID pArg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADASYNDLG_H__71EAFB43_A687_40C3_8DE0_8715EE73C2C4__INCLUDED_)
