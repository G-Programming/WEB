// TaskListDlg.h : header file
//

#if !defined(AFX_TASKLISTDLG_H__C1BE7221_F09D_470B_956B_17C80E8EB0BE__INCLUDED_)
#define AFX_TASKLISTDLG_H__C1BE7221_F09D_470B_956B_17C80E8EB0BE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTaskListDlg dialog
//�����õ��ĳ���
#define TITLE_SIZE          64        //�����ַ����Ĵ�С 
#define PROCESS_SIZE        MAX_PATH  //�������ַ����Ĵ�С
#define MAX_TASKS           25        //��������


//���������Ϣ�ṹ
typedef struct _TASK_LIST {  
  DWORD dwProcessId;// ���̱�ʶ 
  DWORD cntThreads; // �˽����е��߳���
  HWND        hwnd; // ���������ھ��
  TCHAR       ProcessName[PROCESS_SIZE]; //����Exe�ļ��� 
  TCHAR       WindowTitle[TITLE_SIZE]; //�����ڱ�����
} TASK_LIST, *PTASK_LIST; 

//���������Ϣ�б�ṹ
typedef struct _TASK_LIST_ENUM { 
  PTASK_LIST  tlist; //������Ϣ�б�
  DWORD       numtasks; //������
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
	//����洢������Ϣ����������
	TASK_LIST g_tlist[MAX_TASKS];

	bool ActivateProcess(PTASK_LIST tlist);
    bool KillProcess( PTASK_LIST tlist );

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKLISTDLG_H__C1BE7221_F09D_470B_956B_17C80E8EB0BE__INCLUDED_)
