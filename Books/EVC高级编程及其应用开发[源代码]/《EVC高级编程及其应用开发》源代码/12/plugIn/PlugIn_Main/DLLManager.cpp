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

//定义插件DLL中初始化函数类型
typedef UINT (*PINITFUNC)(CToolBar *m_wndToolbar);
//定义插件DLL中释放插件函数类型
typedef void (*PDESTROYFUNC)();
//定义插件DLL中得到插件名函数类型
typedef UINT (*PPLUGINNAMEFUNC)(CString *szPlugInName);
//定义插件DLL中插件按钮点击事件函数类型
typedef VOID (*PLUGINMSGHANDLER) ();
//定义插件DLL中得到插件资源函数类型
typedef VOID (*PLUGINRESOURCE) (HICON*, CString*);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//构造函数
CDLLManager::CDLLManager()
{
	m_szDLLFileName = _T("");
	m_unToolBarID = 0;
	m_szPlugInName = _T("");
	m_pDLLhInstance = NULL;
	m_pwndToolBar = NULL;
}

//析构函数
CDLLManager::~CDLLManager()
{
	FreeDLL();
	m_pDLLhInstance = NULL;
	m_pwndToolBar = NULL;
}


/*
*函数介绍：装载插件DLL
*入口参数：szFileName : 表示被装载的插件DLL文件名
*出口参数：(无)
*返 回 值：TRUE:表示装载成功; FALSE:表示装载失败
*/
bool CDLLManager::LoadDLL(CString szFileName)
{
    //设置DLL文件名
	m_szDLLFileName = szFileName;
	//装载DLL
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
*函数介绍：释放加载的插件DLL
*入口参数：(无)
*出口参数：(无)
*返 回 值：TRUE:释放成功 ; FALSE: 释放失败
*/
bool CDLLManager::FreeDLL()
{

	bool bFuncCalled = false;

	if (m_pDLLhInstance != NULL)
	{   
		//先调用插件DLL中DestroyPlugIn函数释放插件
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

		//释放插件DLL
		FreeLibrary(m_pDLLhInstance);

		//设置默认参数
		m_pDLLhInstance = NULL;
		m_szDLLFileName = "" ;

	}

	return bFuncCalled;
}


/*
*函数介绍：调用插件中InitPlugIn方法，来初始化插件
*入口参数：(无)
*出口参数：(无)
*返 回 值：TRUE:初始化插件成功 ; FALSE: 初始化插件失败
*/
bool CDLLManager::InitDLL()
{
	bool bFuncCalled = false;
	//判断DLL是否被装载，如果未装载，则调用LoadDLL函数来加载dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
    
	//得到插件中InitPlugIn函数地址
	PINITFUNC pInitFunc = (PINITFUNC)GetProcAddress(m_pDLLhInstance, _T("InitPlugIn"));
	//成功得到InitPlugIn函数地址的话，则执行此函数
	if (pInitFunc != NULL)
	{
		m_unToolBarID = pInitFunc(m_pwndToolBar);

		bFuncCalled = true;
	}
	else
	{
		//得到InitPlugIn函数地址失败的话，则调用FreeDLL释放dll
		FreeDLL();
		bFuncCalled = false;
	}

	return bFuncCalled;
}


/*
*函数介绍：得到插件名称
*入口参数：(无)
*出口参数：szName : 用来存储得到的插件名称
*返 回 值：TRUE:得到插件名称成功 ; FALSE:得到插件名称失败
*/
bool CDLLManager::GetDLLName(CString *szName)
{
	//判断DLL是否被装载，如果未装载，则调用LoadDLL函数来加载dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
	//得到插件中GetPlugInName函数地址
	PPLUGINNAMEFUNC pFunc = (PPLUGINNAMEFUNC)GetProcAddress(m_pDLLhInstance, _T("GetPlugInName"));
	if (pFunc == NULL)
	{

		//得到GetPlugInName函数地址失败的话，则调用FreeDLL释放dll
		FreeDLL();
		return false;
	}
	//成功的话，执行此函数
	pFunc(szName);
	
	return true;
}


/*
*函数介绍：点击ToolBar上的按钮事件
*入口参数：(无)
*出口参数：(无)
*返 回 值：TRUE:成功执行 ; FALSE: 执行失败
*/
bool  CDLLManager::HandleOnClick()
{
	//判断DLL是否被装载，如果未装载，则调用LoadDLL函数来加载dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
	//得到插件中HandleOnClick函数地址
	PLUGINMSGHANDLER pFunc = (PLUGINMSGHANDLER)GetProcAddress(m_pDLLhInstance, _T("HandleOnClick"));
	if (pFunc == NULL)
	{
		//得到HandleOnClick函数地址失败的话，则调用FreeDLL释放dll
		FreeDLL();
		return false;
	}
	//成功的话，执行此函数
	pFunc();
	
	return true;
}

/*
*函数介绍：得到插件图标和插件标题
*入口参数：(无)
*出口参数： hIcon   : 存储得到图标句柄 
            szLabel : 存储插件标题
*返 回 值： TRUE:执行成功 ; FALSE: 执行失败
*/
bool CDLLManager::GetPlugInResources(HICON *hIcon, CString *szLabel)
{
	//判断DLL是否被装载，如果未装载，则调用LoadDLL函数来加载dll
	if ( m_pDLLhInstance == NULL )
	{
		if (!LoadDLL(m_szDLLFileName))
		{
			return false;
		}
	}
	//得到插件中GetPlugInResources函数地址
	PLUGINRESOURCE pFunc = (PLUGINRESOURCE)GetProcAddress(m_pDLLhInstance, _T("GetPlugInResources"));
	if (pFunc == NULL)
	{
		//得到GetPlugInResources函数地址失败的话，则调用FreeDLL释放dll
		FreeDLL();	
		return false;
	}
	//成功的话，执行此函数
	pFunc(hIcon,szLabel);
	
	return true;
}

/*
*函数介绍：设置工具栏对象指针
*入口参数：pWndToolBar : 工具栏对象指针
*出口参数：(无)
*返 回 值：(无)
*/
void CDLLManager::SetToolBarPointer(CToolBar *pWndToolBar)
{
	m_pwndToolBar = pWndToolBar;
}

/*
*函数介绍：得到插件按钮标识
*入口参数：(无)
*出口参数：(无)
*返 回 值：返回插件按钮标识
*/
UINT CDLLManager::GetToolBarButtonID()
{

	return m_unToolBarID;
}

/*
*函数介绍：设置插件DLL物理文件名
*入口参数：szFileName : 插件DLL物理文件名
*出口参数：(无)
*返 回 值：(无)
*/
void CDLLManager::SetDLLFileName(CString szFileName)
{
	m_szDLLFileName = szFileName;
}

