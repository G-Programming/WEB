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

	//�����������Ĭ��״̬Ϊ��δ���߳�ӵ�С�
	m_hSynMutex = CreateMutex(NULL,FALSE,NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*�������ܣ��߳�ִ�й���
*��ڲ�����pArg�������߳�ʱ���������Ĳ���������ָ���б��ؼ�ָ��
*���ڲ�����(��)
*����ֵ������ֻ����1��
*/
DWORD  CThreadSynByMutexDlg::ThreadProc(PVOID pArg)
{
	CThreadSynByMutexDlg * pDlg;
	
	CListBox * pLstBox;
	pLstBox = (CListBox*)pArg;
	pDlg = (CThreadSynByMutexDlg*)AfxGetMainWnd();
	TCHAR buffer[10];
	//���󻥳����
	if (WaitForSingleObject(pDlg->m_hSynMutex,INFINITE) == WAIT_OBJECT_0)
	{
		//�����鸳ֵ
		for (int i=0;i<MAXDATASIZE;i++)
		{
			pDlg->m_incNum++;
			pDlg->m_aGlobalData[i] = pDlg->m_incNum;
			Sleep(5);
		}
		
		//��ʾ�Ѿ���ֵ������
		for(i = 0 ; i < MAXDATASIZE ; i++)
		{
			_itow(pDlg->m_aGlobalData[i],buffer,10);
			pLstBox->AddString(buffer);
		}
	}
	//�ͷŶԻ�������ӵ��Ȩ
	ReleaseMutex(pDlg->m_hSynMutex);
	return 1;
}

/*
ִ�а�ť�����¼������ڴ��������߳�
*/
void CThreadSynByMutexDlg::OnBtnexec() 
{
   DWORD dwThreadId1,dwThreadId2;
   HANDLE handle1,handle2;
	
   CListBox * pLstOne;
   CListBox * pLstTwo;
   pLstOne = (CListBox*)GetDlgItem(IDC_LISTONE);
   pLstTwo = (CListBox*)GetDlgItem(IDC_LISTTWO);

   //��ʼ������ֵ
   m_incNum = 0;

   //���������߳�
   handle1 = CreateThread(NULL,0,ThreadProc,pLstOne,0,&dwThreadId1);
   handle2 = CreateThread(NULL,0,ThreadProc,pLstTwo,0,&dwThreadId2);

   if (!handle1)
   {
	   AfxMessageBox(_T("�߳�1����ʧ��"));
   }
	
   if (!handle2)
   {
	   AfxMessageBox(_T("�߳�2����ʧ��"));
   }

   CloseHandle(handle1);
   CloseHandle(handle2);
}

void CThreadSynByMutexDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	//�رջ������
	CloseHandle(m_hSynMutex);	
}
