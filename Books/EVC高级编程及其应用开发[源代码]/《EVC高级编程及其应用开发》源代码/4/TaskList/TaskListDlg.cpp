// TaskListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TaskList.h"
#include "TaskListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskListDlg dialog

CTaskListDlg::CTaskListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTaskListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTaskListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTaskListDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTaskListDlg, CDialog)
	//{{AFX_MSG_MAP(CTaskListDlg)
	ON_BN_CLICKED(IDC_BTNACTIVE, OnBtnactive)
	ON_BN_CLICKED(IDC_BTNREFRESH, OnBtnrefresh)
	ON_BN_CLICKED(IDC_BTNTERMINATE, OnBtnterminate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskListDlg message handlers

BOOL CTaskListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	    //���ý����б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("������"), LVCFMT_LEFT, rt.Width() * 0.35);
    pListCtrl->InsertColumn(1,_T("���������"), LVCFMT_LEFT, rt.Width() * 0.35);
    pListCtrl->InsertColumn(2, _T("�߳���"), LVCFMT_LEFT, rt.Width() * 0.30);



	return TRUE;  // return TRUE  unless you set the focus to a control
}


/*
*�������ܣ��õ�CEϵͳ�����е������б�
*��ڲ�����(��)
*���ڲ�����pList ���洢�õ������б���Ϣ
*����ֵ�����صõ���������
*/
DWORD CTaskListDlg::GetTaskListCE( PTASK_LIST pList) { 

  HINSTANCE         hKernel        = NULL; 
  HINSTANCE         hProcessSnap   = NULL; 
  PROCESSENTRY32 pe32           = {0}; 
  DWORD          dwTaskCount    = 0; 
  

  //״̬toolhelp.dll��̬���ӿ�
  hKernel = LoadLibrary(_T("toolhelp.dll")); 
  
  if (!hKernel) {
	  ::MessageBox(NULL, L"Toolhelp.dll����ʧ��", L"�����о�", MB_OK);
    return 0;
  }
  
  //��������ӳ��
  hProcessSnap = (HINSTANCE)CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 
  
  //���ʧ�ܣ����˳�
  if (hProcessSnap == (HANDLE)-1) 
    return 0; 
  
  dwTaskCount = 0; 
  

  //���ñ������������ݵı����Ľṹ��С            
  pe32.dwSize = sizeof(PROCESSENTRY32);
  //��ȡ��һ�����̣������˽�����Ϣд����̽ṹ�ı���pe32��          
  if (Process32First(hProcessSnap, &pe32)) { 
    do { 
      LPTSTR pCurChar; 
 
      if(_tcsstr(pe32.szExeFile, L"\\")) 
        pCurChar = _tcsrchr(pe32.szExeFile, '\\'); 
      else
        pCurChar = pe32.szExeFile;
      
      lstrcpy(pList-> ProcessName, pCurChar); 
      

      pList ->dwProcessId = pe32.th32ProcessID; 
      pList ->cntThreads = pe32.cntThreads;
      
      ++dwTaskCount;   //������Ŀ��1
      ++pList;         //�Ƶ���һ���ṹ�ڴ��
    } 
    while (Process32Next(hProcessSnap, &pe32)); //������һ������
  } 
  else 
    dwTaskCount = 0;    // 
 
  CloseHandle (hProcessSnap); 
  return dwTaskCount; 
}

/*
*�������ܣ��ص���������EnumWindows����
*��ڲ�����hwnd ��������
*          lParam : ������Ϣ�б�ָ��
*���ڲ�����lParam ��������Ϣ�б�ָ��
*����ֵ: True����ɹ���False����ʧ��
*/
BOOL CALLBACK CTaskListDlg::EnumWindowsProc( HWND hwnd, DWORD lParam ) { 
  DWORD             pid = 0; 
  DWORD             i; 
  TCHAR             buf[TITLE_SIZE]; 
  PTASK_LIST_ENUM   te = (PTASK_LIST_ENUM)lParam; 
  PTASK_LIST        tlist = te->tlist; 
  DWORD             numTasks = te->numtasks; 
  
  // ���ݴ��ھ�����õ����̱�ʶ
  if (!GetWindowThreadProcessId( hwnd, &pid )) { 
    return TRUE; 
  } 
  //���ҽ��̱�ʶ���б�����ͬ�Ľ��̱�ʶ
  for (i=0; i<numTasks; i++) { 
    if (tlist[i].dwProcessId == pid) {
	  if (::IsWindowVisible(hwnd)) {
      tlist[i].hwnd = hwnd; 
      int nCnt = ::GetWindowText( hwnd, buf, TITLE_SIZE );
      buf[nCnt] = '\0';
      if (nCnt) { 
        lstrcpy( tlist[i].WindowTitle, buf ); 
      } 
     }
      break; 
    } 
  } 
  //�����оٴ���
  return TRUE; 
}


/*
*�������ܣ��õ���������������;��
*��ڲ�����te ��������Ϣ�б�ָ��
*���ڲ�����te ��������Ϣ�б�ָ��
*����ֵ: (��)
*/
void CTaskListDlg::GetWindowTitles( PTASK_LIST_ENUM te ) { 
  //�о�ϵͳ���д���
  EnumWindows((WNDENUMPROC) EnumWindowsProc, (LPARAM) te ); 
} 

/*
*�������ܣ�������̷���
*��ڲ�����tlist �� ������Ϣ
*���ڲ�����(��)
*����ֵ: True���ɹ���False��ʧ��
*/
bool CTaskListDlg::ActivateProcess(PTASK_LIST tlist)
{
  //�ж��Ƿ���������ڣ�����ھͼ�����
  if (tlist->hwnd && tlist->WindowTitle) 
  {
	::SetForegroundWindow(tlist->hwnd);
	::SetActiveWindow(tlist->hwnd);
    return TRUE; 
  }
  else
  { 
	return FALSE;
  } 
} 

/*
*�������ܣ���ֹ���̷���
*��ڲ�����tlist �� ������Ϣ
*���ڲ�����(��)
*����ֵ: True���ɹ���False��ʧ��
*/
bool CTaskListDlg::KillProcess( PTASK_LIST tlist ) 
{ 
  HANDLE            hProcess; 

  //���û��������,����TerminateProcess��ֹ����
  if (!tlist->hwnd)  
  { 
	//���ݽ��̱�ʶ�����ؽ��̾��
    hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, tlist->dwProcessId ); 
    //�ɹ��Ļ�����ֹ����
	if (hProcess) 
	{ 
      if (!TerminateProcess( hProcess, 1 )) 
	  { 
        CloseHandle( hProcess ); 
        return FALSE; 
      } 
      CloseHandle( hProcess ); 
      return TRUE; 
    }
	else
	{
	  return FALSE;
	}
  }
  //�������壬���������ڹر���Ϣ����ֹ�߳� 
  else
  {
    ::PostMessage( tlist->hwnd, WM_CLOSE, 0, 0 ); 
    return TRUE;
  }
} 



/*
*�������ܣ�ˢ�°�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CTaskListDlg::OnBtnrefresh() 
{
	TASK_LIST_ENUM processList; //�����б���Ϣ
	TCHAR numBuf[10]; //�洢�����е��߳���

	memset(&g_tlist, 0, sizeof(TASK_LIST) * MAX_TASKS);
	//�õ������б���Ϣ
	DWORD nNumTasks = GetTaskListCE(g_tlist);
	processList.numtasks = nNumTasks;
	processList.tlist = g_tlist;
	//���½����б���Ϣ����ȡ�����ھ���ͱ���
	GetWindowTitles(&processList);

    CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);

	//����б��������Ŀ
	pListCtrl->DeleteAllItems();
    memset(&numBuf,0,sizeof(numBuf));

	//���б������ӽ��������Ϣ
	for (int i=0;i<processList.numtasks;i++)
	{
        //����exe�������������߳���
      pListCtrl->InsertItem(i,_T("Test"));
	  pListCtrl->SetItemText(i,0,processList.tlist[i].ProcessName);
	  pListCtrl->SetItemText(i,1,processList.tlist[i].WindowTitle);	 
	  _itow(processList.tlist[i].cntThreads,numBuf,10);
	  pListCtrl->SetItemText(i,2,numBuf);
	}

}



/*
*�������ܣ�������̰�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CTaskListDlg::OnBtnactive() 
{
   CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);
   POSITION	 pos = pListCtrl->GetFirstSelectedItemPosition();
   if (pos)
   {
     int nItemIndex = pListCtrl->GetNextSelectedItem(pos);
	 //�������
	 ActivateProcess(&g_tlist[nItemIndex]);
   }
}

/*
*�������ܣ���ֹ���̰�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ: (��)
*/
void CTaskListDlg::OnBtnterminate() 
{
   CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LISTPROCESS);
   POSITION	 pos = pListCtrl->GetFirstSelectedItemPosition();
   if (pos)
   {
     int nItemIndex = pListCtrl->GetNextSelectedItem(pos);
	 //��ֹ����
	 KillProcess(&g_tlist[nItemIndex]);
   }
   //ˢ�½����б�
   SendMessage(WM_COMMAND, (WPARAM)IDC_BTNREFRESH, 0);
}

