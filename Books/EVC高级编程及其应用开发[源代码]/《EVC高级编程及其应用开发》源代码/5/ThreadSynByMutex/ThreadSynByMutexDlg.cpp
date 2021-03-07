// ThreadSynByMutexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadSynByMutex.h"
#include "ThreadSynByMutexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByMutexDlg dialog

CThreadSynByMutexDlg::CThreadSynByMutexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynByMutexDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadSynByMutexDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynByMutexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadSynByMutexDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadSynByMutexDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadSynByMutexDlg)
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByMutexDlg message handlers

BOOL CThreadSynByMutexDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//创建互斥对象，默认状态为“未被线程拥有”
	m_hSynMutex = CreateMutex(NULL,FALSE,NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*函数介绍：线程执行过程
*入口参数：pArg：创建线程时，传进来的参数，这里指的列表框控件指针
*出口参数：(无)
*返回值：这里只返回1。
*/
DWORD  CThreadSynByMutexDlg::ThreadProc(PVOID pArg)
{
	CThreadSynByMutexDlg * pDlg;
	
	CListBox * pLstBox;
	pLstBox = (CListBox*)pArg;
	pDlg = (CThreadSynByMutexDlg*)AfxGetMainWnd();
	TCHAR buffer[10];
	//请求互斥对象
	if (WaitForSingleObject(pDlg->m_hSynMutex,INFINITE) == WAIT_OBJECT_0)
	{
		//给数组赋值
		for (int i=0;i<MAXDATASIZE;i++)
		{
			pDlg->m_incNum++;
			pDlg->m_aGlobalData[i] = pDlg->m_incNum;
			Sleep(5);
		}
		
		//显示已经赋值的数组
		for(i = 0 ; i < MAXDATASIZE ; i++)
		{
			_itow(pDlg->m_aGlobalData[i],buffer,10);
			pLstBox->AddString(buffer);
		}
	}
	//释放对互斥对象的拥有权
	ReleaseMutex(pDlg->m_hSynMutex);
	return 1;
}

/*
执行按钮单击事件，用于创建两个线程
*/
void CThreadSynByMutexDlg::OnBtnexec() 
{
   DWORD dwThreadId1,dwThreadId2;
   HANDLE handle1,handle2;
	
   CListBox * pLstOne;
   CListBox * pLstTwo;
   pLstOne = (CListBox*)GetDlgItem(IDC_LISTONE);
   pLstTwo = (CListBox*)GetDlgItem(IDC_LISTTWO);

   //初始化计数值
   m_incNum = 0;

   //创建两个线程
   handle1 = CreateThread(NULL,0,ThreadProc,pLstOne,0,&dwThreadId1);
   handle2 = CreateThread(NULL,0,ThreadProc,pLstTwo,0,&dwThreadId2);

   if (!handle1)
   {
	   AfxMessageBox(_T("线程1创建失败"));
   }
	
   if (!handle2)
   {
	   AfxMessageBox(_T("线程2创建失败"));
   }

   CloseHandle(handle1);
   CloseHandle(handle2);
}

void CThreadSynByMutexDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	//关闭互斥对象
	CloseHandle(m_hSynMutex);	
}
