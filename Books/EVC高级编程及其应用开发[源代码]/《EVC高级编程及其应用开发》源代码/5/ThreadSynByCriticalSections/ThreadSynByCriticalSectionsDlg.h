// ThreadSynByCriticalSectionsDlg.h : header file
//

#if !defined(AFX_THREADSYNBYCRITICALSECTIONSDLG_H__945CE3C5_82F6_4EA3_BEAD_211A0C7A0A83__INCLUDED_)
#define AFX_THREADSYNBYCRITICALSECTIONSDLG_H__945CE3C5_82F6_4EA3_BEAD_211A0C7A0A83__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByCriticalSectionsDlg dialog
//定义数组大小
const MAXDATASIZE=100;
class CThreadSynByCriticalSectionsDlg : public CDialog
{
// Construction
public:
	CThreadSynByCriticalSectionsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadSynByCriticalSectionsDlg)
	enum { IDD = IDD_THREADSYNBYCRITICALSECTIONS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynByCriticalSectionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadSynByCriticalSectionsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnexec();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
   int m_incNum; //记数
   int m_aGlobalData[MAXDATASIZE]; //数组
   //线程同步临界区对象
   CRITICAL_SECTION m_critical_Section; 

private:
   //线程函数
   static DWORD ThreadProc(PVOID pArg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYCRITICALSECTIONSDLG_H__945CE3C5_82F6_4EA3_BEAD_211A0C7A0A83__INCLUDED_)
