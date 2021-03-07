// ThreadSynBySemaphoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadSynBySemaphore.h"
#include "ThreadSynBySemaphoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadSynBySemaphoreDlg dialog

CThreadSynBySemaphoreDlg::CThreadSynBySemaphoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynBySemaphoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadSynBySemaphoreDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynBySemaphoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadSynBySemaphoreDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadSynBySemaphoreDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadSynBySemaphoreDlg)
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadSynBySemaphoreDlg message handlers

BOOL CThreadSynBySemaphoreDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//创建信号量对象,初始化信号量计数为1，最大信号量计数也为1
	m_hSynSemaphore = CreateSemaphore(NULL,1,1,NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*函数介绍：线程执行过程
*入口参数：pArg：创建线程时，传进来的参数，这里指的列表框控件指针
*出口参数：(无)
*返回值：这里只返回1。
*/
DWORD  CThreadSynBySemaphoreDlg::ThreadProc(PVOID pArg)
{
	CThreadSynBySemaphoreDlg * pDlg;

	CListBox * pLstBox;
	pLstBox = (CListBox*)pArg;
	pDlg = (CThreadSynBySemaphoreDlg*)AfxGetMainWnd();
	TCHAR buffer[10];
	//等待信号量可用，当信号量计数大于0时，可用
	if (WaitForSingleObject(pDlg->m_hSynSemaphore,INFINITE) == WAIT_OBJECT_0)
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
	
	//因为等待函数自动给信号量计数减1
	//所以给信号量计数加1，使信号量继续可用
	ReleaseSemaphore(pDlg->m_hSynSemaphore,1,NULL);

	return 1;
}


/*
执行按钮单击事件，用于创建两个线程
*/
void CThreadSynBySemaphoreDlg::OnBtnexec() 
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


void CThreadSynBySemaphoreDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	//关闭信号量对象
	CloseHandle(m_hSynSemaphore);
}
