// TaskListDlg.h : header file
//

#if !defined(AFX_TASKLISTDLG_H__C1BE7221_F09D_470B_956B_17C80E8EB0BE__INCLUDED_)
#define AFX_TASKLISTDLG_H__C1BE7221_F09D_470B_956B_17C80E8EB0BE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTaskListDlg dialog
//定义用到的常量
#define TITLE_SIZE          64        //标题字符串的大小 
#define PROCESS_SIZE        MAX_PATH  //进程名字符串的大小
#define MAX_TASKS           25        //最大进程数


//定义进程信息结构
typedef struct _TASK_LIST {  
  DWORD dwProcessId;// 进程标识 
  DWORD cntThreads; // 此进程中的线程数
  HWND        hwnd; // 进程主窗口句柄
  TCHAR       ProcessName[PROCESS_SIZE]; //进程Exe文件名 
  TCHAR       WindowTitle[TITLE_SIZE]; //主窗口标题名
} TASK_LIST, *PTASK_LIST; 

//定义进程信息列表结构
typedef struct _TASK_LIST_ENUM { 
  PTASK_LIST  tlist; //进程信息列表
  DWORD       numtasks; //进程数
} TASK_LIST_ENUM, *PTASK_LIST_ENUM; 


class CTaskListDlg : public CDialog
{
// Construction
public:
	CTaskListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTaskListDlg)
	enum { IDD = IDD_TASKLIST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
  static DWORD GetTaskListCE(PTASK_LIST pList);
  static void  GetWindowTitles( PTASK_LIST_ENUM pe );
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTaskListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnactive();
	afx_msg void OnBtnrefresh();
	afx_msg void OnBtnterminate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
  static BOOL CALLBACK EnumWindowsProc( HWND hwnd, DWORD lParam );
private:
	//定义存储进程信息机构体数组
	TASK_LIST g_tlist[MAX_TASKS];

	bool ActivateProcess(PTASK_LIST tlist);
    bool KillProcess( PTASK_LIST tlist );

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKLISTDLG_H__C1BE7221_F09D_470B_956B_17C80E8EB0BE__INCLUDED_)
