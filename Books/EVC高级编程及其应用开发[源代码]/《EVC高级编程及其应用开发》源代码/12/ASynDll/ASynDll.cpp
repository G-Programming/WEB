// ASynDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ASynDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CASynDllApp

BEGIN_MESSAGE_MAP(CASynDllApp, CWinApp)
	//{{AFX_MSG_MAP(CASynDllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CASynDllApp construction

CASynDllApp::CASynDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CASynDllApp object

CASynDllApp theApp;

//����ص�����
TDataReadNotify DataReadNotify;

//�̴߳�����
DWORD DoTheWork(LPVOID lpParameter)
{
  long lDBData;

  Sleep(5000);
  lDBData = Random();
  

  //֪ͨ�û�������ִ�����
  if (DataReadNotify != NULL) 
  {
	  //ִ�лص�����
	  DataReadNotify(lDBData);
  }

  return 0;
};

//��ѯ����
long ASynDLL_API QueryData(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HANDLE hThread;
	DWORD pThreadId;
	long lProcAdr;
	
	//�����̺߳���
	lProcAdr = (long)(&DoTheWork);
	//�����̣߳���ִ���߳�
	hThread = CreateThread(NULL, 
		0,
		(LPTHREAD_START_ROUTINE)lProcAdr,
		NULL,
		0,
		&pThreadId);
	
	
	return 0;
};

//���ûص�����ָ��
long ASynDLL_API SetCallbackProcAddr(long lProcAddress)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	long Result = 0;
	
	//���ûص�����
	DataReadNotify = (TDataReadNotify)lProcAddress;
	
	if (DataReadNotify != NULL) 
	{
		Result = 1;
	}
	return Result;
};
