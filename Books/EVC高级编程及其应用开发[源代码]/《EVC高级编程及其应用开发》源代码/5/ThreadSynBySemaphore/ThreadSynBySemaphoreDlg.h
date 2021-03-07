// ThreadSynBySemaphoreDlg.h : header file
//

#if !defined(AFX_THREADSYNBYSEMAPHOREDLG_H__09885073_155C_4D17_8364_C4EBED23A573__INCLUDED_)
#define AFX_THREADSYNBYSEMAPHOREDLG_H__09885073_155C_4D17_8364_C4EBED23A573__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadSynBySemaphoreDlg dialog

//定义数组大小
const MAXDATASIZE=100;
class CThreadSynBySemaphoreDlg : public CDialog
{
// Construction
public:
	CThreadSynBySemaphoreDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadSynBySemaphoreDlg)
	enum { IDD = IDD_THREADSYNBYSEMAPHORE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynBySemaphoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadSynBySemaphoreDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnexec();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
   int m_incNum; //记数
   int m_aGlobalData[MAXDATASIZE]; //数组
   HANDLE m_hSynSemaphore;//采用信号量同步

private:
   //线程函数
   static DWORD ThreadProc(PVOID pArg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYSEMAPHOREDLG_H__09885073_155C_4D17_8364_C4EBED23A573__INCLUDED_)
