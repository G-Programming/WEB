// ThreadAsynDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadAsyn.h"
#include "ThreadAsynDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadAsynDlg dialog

CThreadAsynDlg::CThreadAsynDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadAsynDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadAsynDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadAsynDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadAsynDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadAsynDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadAsynDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadAsynDlg message handlers

BOOL CThreadAsynDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*�������ܣ��߳�ִ�й���
*��ڲ�����pArg�������߳�ʱ���������Ĳ���������ָ���б��ؼ�ָ��
*���ڲ�����(��)
*����ֵ������ֻ����1��
*/
DWORD  CThreadAsynDlg::ThreadProc(PVOID pArg)
{
	CThreadAsynDlg * pDlg;

	CListBox * pLstBox;
	pLstBox = (CListBox*)pArg;
	pDlg = (CThreadAsynDlg*)AfxGetMainWnd();
	TCHAR buffer[10];
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

	return 1;
}

void CThreadAsynDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
}

/*
ִ�а�ť�����¼������ڴ��������߳�
*/
void CThreadAsynDlg::OnBtnexec() 
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


