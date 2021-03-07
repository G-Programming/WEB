// DLLManager.cpp: implementation of the CDLLManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlugIn_Main.h"
#include "DLLManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//������DLL�г�ʼ����������
typedef UINT (*PINITFUNC)(CToolBar *m_wndToolbar);
//������DLL���ͷŲ����������
typedef void (*PDESTROYFUNC)();
//������DLL�еõ��������������
typedef UINT (*PPLUGINNAMEFUNC)(CString *szPlugInName);
//������DLL�в����ť����¼���������
typedef VOID (*PLUGINMSGHANDLER) ();
//������DLL�еõ������Դ��������
typedef VOID (*PLUGINRESOURCE) (HICON*, CString*);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//���캯��
CDLLManager::CDLLManager()
{
	m_szDLLFileName = _T("");
	m_unToolBarID = 0;
	m_szPlugInName = _T("");
	m_pDLLhInstance = NULL;
	m_pwndToolBar = NULL;
}

//��������
CDLLManager::~CDLLManager()
{
	FreeDLL();
	m_pDLLhInstance = NULL;
	m_pwndToolBar = NULL;
}


/*
*�������ܣ�װ�ز��DLL
*��ڲ�����szFileName : ��ʾ��װ�صĲ��DLL�ļ���
*���ڲ�����(��)
*�� �� ֵ��TRUE:��ʾװ�سɹ�; FALSE:��ʾװ��ʧ��
*/
bool CDLLManager::LoadDLL(CString szFileName)
{
    //����DLL�ļ���
	m_szDLLFileName = szFileName;
	//װ��DLL
	HMODULE hModule = LoadLibrary(szFileName);

	if (!hModule)
	{
        m_pDLLhInstance = NULL;
		return false;
	} 
	else
	{
		m_pDLLhInstance = hModule;
	}
	return true;
}


/*
*�������ܣ��ͷż��صĲ��DLL
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��TRUE:�ͷųɹ� ; FALSE: �ͷ�ʧ��
*/
bool CDLLManager::FreeDLL()
{

	bool bFuncCalled = false;

	if (m_pDLLhInstance != NULL)
	{   
		//�ȵ��ò��DLL��DestroyPlugIn�����ͷŲ��
		PDESTROYFUNC pDestroyFunc = (PDESTROYFUNC)GetProcAddress(m_pDLLhInstance, _T("DestroyPlugIn"));
		if (pDestroyFunc != NULL)
		{
			pDestroyFunc();

			bFuncCalled = true;
		}
		else
		{
			bFuncCalled = false;
		}

		//�ͷŲ��DLL
		FreeLibrary(m_pDLLhInstance);

		//����Ĭ�ϲ���
		m_pDLLhInstance = NULL;
		m_szDLLFileName = "" ;

	}

	return bFuncCalled;
}


/*
*�������ܣ����ò����InitPlugIn����������ʼ�����
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��TRUE:��ʼ������ɹ� ; FALSE: ��ʼ�����ʧ��
*/
bool CDLLManager::InitDLL()
{
	bool bFuncCalled = false;
	//�ж�DLL�Ƿ�װ�أ����δװ�أ������LoadDLL����������dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
    
	//�õ������InitPlugIn������ַ
	PINITFUNC pInitFunc = (PINITFUNC)GetProcAddress(m_pDLLhInstance, _T("InitPlugIn"));
	//�ɹ��õ�InitPlugIn������ַ�Ļ�����ִ�д˺���
	if (pInitFunc != NULL)
	{
		m_unToolBarID = pInitFunc(m_pwndToolBar);

		bFuncCalled = true;
	}
	else
	{
		//�õ�InitPlugIn������ַʧ�ܵĻ��������FreeDLL�ͷ�dll
		FreeDLL();
		bFuncCalled = false;
	}

	return bFuncCalled;
}


/*
*�������ܣ��õ��������
*��ڲ�����(��)
*���ڲ�����szName : �����洢�õ��Ĳ������
*�� �� ֵ��TRUE:�õ�������Ƴɹ� ; FALSE:�õ��������ʧ��
*/
bool CDLLManager::GetDLLName(CString *szName)
{
	//�ж�DLL�Ƿ�װ�أ����δװ�أ������LoadDLL����������dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
	//�õ������GetPlugInName������ַ
	PPLUGINNAMEFUNC pFunc = (PPLUGINNAMEFUNC)GetProcAddress(m_pDLLhInstance, _T("GetPlugInName"));
	if (pFunc == NULL)
	{

		//�õ�GetPlugInName������ַʧ�ܵĻ��������FreeDLL�ͷ�dll
		FreeDLL();
		return false;
	}
	//�ɹ��Ļ���ִ�д˺���
	pFunc(szName);
	
	return true;
}


/*
*�������ܣ����ToolBar�ϵİ�ť�¼�
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��TRUE:�ɹ�ִ�� ; FALSE: ִ��ʧ��
*/
bool  CDLLManager::HandleOnClick()
{
	//�ж�DLL�Ƿ�װ�أ����δװ�أ������LoadDLL����������dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
	//�õ������HandleOnClick������ַ
	PLUGINMSGHANDLER pFunc = (PLUGINMSGHANDLER)GetProcAddress(m_pDLLhInstance, _T("HandleOnClick"));
	if (pFunc == NULL)
	{
		//�õ�HandleOnClick������ַʧ�ܵĻ��������FreeDLL�ͷ�dll
		FreeDLL();
		return false;
	}
	//�ɹ��Ļ���ִ�д˺���
	pFunc();
	
	return true;
}

/*
*�������ܣ��õ����ͼ��Ͳ������
*��ڲ�����(��)
*���ڲ����� hIcon   : �洢�õ�ͼ���� 
            szLabel : �洢�������
*�� �� ֵ�� TRUE:ִ�гɹ� ; FALSE: ִ��ʧ��
*/
bool CDLLManager::GetPlugInResources(HICON *hIcon, CString *szLabel)
{
	//�ж�DLL�Ƿ�װ�أ����δװ�أ������LoadDLL����������dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
	//�õ������GetPlugInResources������ַ
	PLUGINRESOURCE pFunc = (PLUGINRESOURCE)GetProcAddress(m_pDLLhInstance, _T("GetPlugInResources"));
	if (pFunc == NULL)
	{
		//�õ�GetPlugInResources������ַʧ�ܵĻ��������FreeDLL�ͷ�dll
		FreeDLL();	
		return false;
	}
	//�ɹ��Ļ���ִ�д˺���
	pFunc(hIcon,szLabel);
	
	return true;
}

/*
*�������ܣ����ù���������ָ��
*��ڲ�����pWndToolBar : ����������ָ��
*���ڲ�����(��)
*�� �� ֵ��(��)
*/
void CDLLManager::SetToolBarPointer(CToolBar *pWndToolBar)
{
	m_pwndToolBar = pWndToolBar;
}

/*
*�������ܣ��õ������ť��ʶ
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ�����ز����ť��ʶ
*/
UINT CDLLManager::GetToolBarButtonID()
{

	return m_unToolBarID;
}

/*
*�������ܣ����ò��DLL�����ļ���
*��ڲ�����szFileName : ���DLL�����ļ���
*���ڲ�����(��)
*�� �� ֵ��(��)
*/
void CDLLManager::SetDLLFileName(CString szFileName)
{
	m_szDLLFileName = szFileName;
}

