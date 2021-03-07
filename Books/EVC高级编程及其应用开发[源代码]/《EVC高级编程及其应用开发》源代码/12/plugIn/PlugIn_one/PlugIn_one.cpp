// PlugIn_one.cpp : Defines the initialization routines for the DLL.
//


#include "stdafx.h"
#include "PlugIn_one.h"

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
// CPlugIn_oneApp
//���尴ť��ʶ
#define  ID_BUTTON_PLUGIN_CALC 12001
//����������
const TCHAR szPlugName[] = _T("������");

#define PLUG_EXPORT __declspec(dllexport)
//��ʼ�������������Ҫ����������ToolBarָ��
extern "C" PLUG_EXPORT UINT InitPlugIn(CToolBar *pWndToolbar);
//�ͷŲ������Ҫ��ɾ����ToolBar�ϵİ�ť
extern "C" PLUG_EXPORT void DestroyPlugIn();
//�����ToolBar�ϵİ�ť�¼�
extern "C" PLUG_EXPORT void HandleOnClick(); 
//�õ����ͼ��Ͳ������
extern "C" PLUG_EXPORT void GetPlugInResources(HICON *hIcon, CString *szLabel);
//�õ������
extern "C" PLUG_EXPORT void GetPlugInName(CString *szPlugInName);


BEGIN_MESSAGE_MAP(CPlugIn_oneApp, CWinApp)
	//{{AFX_MSG_MAP(CPlugIn_oneApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// The one and only CPlugIn_oneApp object

CPlugIn_oneApp theApp;
/*
*�������ܣ���ʼ�������������Ҫ����������ToolBarָ��
*��ڲ�����pWndToolBar : ָ���������ToolBarָ��
*���ڲ�������
*����ֵ��  ��
*/
PLUG_EXPORT UINT InitPlugIn(CToolBar *pWndToolBar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	theApp.SetToolBarPointer(pWndToolBar);
	theApp.AddButtonToToolBar();

	return ID_BUTTON_PLUGIN_CALC;
}

/*
*�������ܣ��ͷŲ������Ҫ��ɾ����ToolBar�ϵİ�ť
*��ڲ�������
*���ڲ�������
*����ֵ��  ��
*/
PLUG_EXPORT void DestroyPlugIn()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	theApp.RemoveButtonFromToolBar();
}


/*
*�������ܣ������ToolBar�ϵİ�ť�¼�
*��ڲ�������
*���ڲ�������
*����ֵ��  ��
*/
PLUG_EXPORT void HandleOnClick()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
    if (!theApp.WinExec(_T("calc")))
	{
		AfxMessageBox(_T("����������δ��ִ��"));
	}
}

/*
*�������ܣ��õ����ͼ��Ͳ������
*��ڲ�������
*���ڲ�����hIcon : ���ͼ����
           szLabel : �������
*����ֵ��  ��
*/
PLUG_EXPORT void GetPlugInResources(HICON *hIcon, CString *szLabel)
{
	hIcon = theApp.GetPlugInIcon();
	*szLabel = _T("���������");
}

/*
*�������ܣ��õ������
*��ڲ�������
*���ڲ�����szPlugInName : �����
*����ֵ��  ��
*/
PLUG_EXPORT void GetPlugInName(CString *szPlugInName)
{
	*szPlugInName = szPlugName;
}

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_oneApp construction
CPlugIn_oneApp::CPlugIn_oneApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}



/*
*�������ܣ��������������幤����ָ��
*��ڲ�����pWndToolBar : ָ���������ToolBarָ��
*���ڲ�������
*����ֵ��  ��
*/
void CPlugIn_oneApp::SetToolBarPointer(CToolBar *pwndToolBar)
{
	m_pwndToolBar = pwndToolBar;
}

/*
*�������ܣ�������Ӱ�ť�������幤������
*��ڲ�������
*���ڲ�������
*����ֵ��  ��
*/
void CPlugIn_oneApp::AddButtonToToolBar()
{

	CToolBarCtrl& pToolbarCtrl = m_pwndToolBar->GetToolBarCtrl();

	//�õ����������еİ�ť��
	int nButCount = pToolbarCtrl.GetButtonCount();

	//�������ťλͼ��ӵ���������
	int nImageCount = pToolbarCtrl.AddBitmap(1, IDB_PLUGIN_CALC);

	//����һ���°�ť
	TBBUTTON tb;
	//���ð�ť��ťͼƬ
	tb.iBitmap = nImageCount;
	//���ð�ť��ʶ
	tb.idCommand = ID_BUTTON_PLUGIN_CALC;
	//���ð�ť״̬
	tb.fsState = TBSTATE_ENABLED;
	//���ð�ť��ʾ
	tb.fsStyle = TBSTYLE_BUTTON;
	tb.dwData = 0;
	tb.iString = NULL;

	//����ť��ӵ���������
	pToolbarCtrl.InsertButton(nImageCount, &tb);
}

/*
*�������ܣ����ڴ���������ɾ������ӵİ�ť
*��ڲ�������
*���ڲ�������
*����ֵ��  ��
*/
void CPlugIn_oneApp::RemoveButtonFromToolBar()
{
	if (m_pwndToolBar != NULL)
	{
		CToolBarCtrl& pToolbarCtrl = m_pwndToolBar->GetToolBarCtrl();
		
		TBBUTTON tbButton;
		
		int nButtonCount = pToolbarCtrl.GetButtonCount();
		for (int i=0; i<nButtonCount; ++i)
		{
			pToolbarCtrl.GetButton(i, &tbButton);
			//����ť�Ǳ������ťʱ����ɾ��֮��
			if (tbButton.idCommand == ID_BUTTON_PLUGIN_CALC)
			{
				pToolbarCtrl.DeleteButton(i);
				break;
			}
		}
	}
}

/*
*�������ܣ����ڵõ������ť�ı�ʶ
*��ڲ�������
*���ڲ�������
*����ֵ��  �����ť��ʶ
*/
UINT CPlugIn_oneApp::GetToolBarButtonInfo(void)
{
	return ID_BUTTON_PLUGIN_CALC;
}

/*
*�������ܣ����ڵõ������ͼ��
*��ڲ�����pWndToolBar : ָ���������ToolBarָ��
*���ڲ�������
*����ֵ��  ͼ����
*/
HICON *CPlugIn_oneApp::GetPlugInIcon(void)
{
	return (HICON *)LoadIcon(IDI_PLUGIN_CALC);
}
/*
*�������ܣ�����ִ���ⲿ����
*��ڲ�����FileName : ��ʾ��ִ���ļ���
*���ڲ�������
*����ֵ��  TRUE:ִ�гɹ���FALSE:ִ��ʧ��
*/
bool CPlugIn_oneApp::WinExec(LPCTSTR FileName)
{
    PROCESS_INFORMATION processInfo; //���������Ϣ
    if (!CreateProcess(FileName, NULL, NULL, NULL, NULL
      , CREATE_NEW_CONSOLE
      , NULL, NULL, NULL, &processInfo))
    {
		return false;
	}
    CloseHandle(processInfo.hThread);
	CloseHandle(processInfo.hProcess);
	return true ;
}


