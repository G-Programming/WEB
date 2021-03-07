// ThreadSynByMutexDlg.h : header file
//

#if !defined(AFX_THREADSYNBYMUTEXDLG_H__0F5B9D7D_3FEF_4939_A099_2A4E10259444__INCLUDED_)
#define AFX_THREADSYNBYMUTEXDLG_H__0F5B9D7D_3FEF_4939_A099_2A4E10259444__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByMutexDlg dialog
//定义数组大小
const MAXDATASIZE=100;

class CThreadSynByMutexDlg : public CDialog
{
// Construction
public:
	CThreadSynByMutexDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadSynByMutexDlg)
	enum { IDD = IDD_THREADSYNBYMUTEX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynByMutexDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadSynByMutexDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnexec();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
   int m_incNum; //记数
   int m_aGlobalData[MAXDATASIZE]; //数组

   HANDLE m_hSynMutex; //同步互斥句柄
private:
	//线程过程函数
	static DWORD  ThreadProc(PVOID pArg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYMUTEXDLG_H__0F5B9D7D_3FEF_4939_A099_2A4E10259444__INCLUDED_)
