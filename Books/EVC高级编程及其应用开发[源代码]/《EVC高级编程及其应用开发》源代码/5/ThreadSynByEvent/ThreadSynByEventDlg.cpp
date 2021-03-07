// ThreadSynByEventDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadSynByEvent.h"
#include "ThreadSynByEventDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByEventDlg dialog

CThreadSynByEventDlg::CThreadSynByEventDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadSynByEventDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadSynByEventDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynByEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadSynByEventDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadSynByEventDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadSynByEventDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByEventDlg message handlers

BOOL CThreadSynByEventDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here

     
	//创建线程同步事件句柄
	m_hSynEvent = CreateEvent(NULL,false,true,NULL);
	m_incNum = 0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*函数介绍：线程执行过程
*入口参数：pArg：创建线程时，传进来的参数,这里指的列表框控件指针
*出口参数：(无)
*返回值：这里只返回1。
*/
DWORD  CThreadSynByEventDlg::ThreadProc(PVOID pArg)
{
	CThreadSynByEventDlg * pDlg;

	CListBox * pLstBox;
	pLstBox = (CListBox*)pArg;
	pDlg = (CThreadSynByEventDlg*)AfxGetMainWnd();
	TCHAR buffer[10];
	//等待同步事件信号
	if (WaitForSingleObject(pDlg->m_hSynEvent,INFINITE) == WAIT_OBJECT_0)
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
	//打开同步事件信号
	SetEvent(pDlg->m_hSynEvent);
	return 1;
}



void CThreadSynByEventDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	//关闭线程同步事件对象
    CloseHandle(m_hSynEvent);	
}


/*
执行按钮单击事件，用于创建两个线程
*/
void CThreadSynByEventDlg::OnBtnexec() 
{
   DWORD dwThreadId1,dwThreadId2;
   HANDLE handle1,handle2;

   CListBox * pLstOne;
   CListBox * pLstTwo;
   pLstOne = (CListBox*)GetDlgItem(IDC_LISTONE);
   pLstTwo = (CListBox*)GetDlgItem(IDC_LISTTWO);

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

