// ThreadSynByEventDlg.h : header file
//

#if !defined(AFX_THREADSYNBYEVENTDLG_H__317B1012_C4AC_4111_8195_D62AE09049B0__INCLUDED_)
#define AFX_THREADSYNBYEVENTDLG_H__317B1012_C4AC_4111_8195_D62AE09049B0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByEventDlg dialog

//定义数组大小
const MAXDATASIZE=100;

class CThreadSynByEventDlg : public CDialog
{
// Construction
public:
	CThreadSynByEventDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadSynByEventDlg)
	enum { IDD = IDD_THREADSYNBYEVENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynByEventDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadSynByEventDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBtnexec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
   int m_incNum; //记数
   int m_aGlobalData[MAXDATASIZE]; //数组

   HANDLE m_hSynEvent; //线程同步事件句柄
private:
   //线程函数
   static DWORD  ThreadProc(PVOID pArg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYEVENTDLG_H__317B1012_C4AC_4111_8195_D62AE09049B0__INCLUDED_)
