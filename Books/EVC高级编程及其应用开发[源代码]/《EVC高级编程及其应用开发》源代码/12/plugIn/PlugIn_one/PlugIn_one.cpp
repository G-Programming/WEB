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
//定义按钮标识
#define  ID_BUTTON_PLUGIN_CALC 12001
//定义插件名称
const TCHAR szPlugName[] = _T("计算器");

#define PLUG_EXPORT __declspec(dllexport)
//初始化插件，这里主要设置主程序ToolBar指针
extern "C" PLUG_EXPORT UINT InitPlugIn(CToolBar *pWndToolbar);
//释放插件，主要是删除掉ToolBar上的按钮
extern "C" PLUG_EXPORT void DestroyPlugIn();
//当点击ToolBar上的按钮事件
extern "C" PLUG_EXPORT void HandleOnClick(); 
//得到插件图标和插件标题
extern "C" PLUG_EXPORT void GetPlugInResources(HICON *hIcon, CString *szLabel);
//得到插件名
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
*函数介绍：初始化插件，这里主要设置主程序ToolBar指针
*入口参数：pWndToolBar : 指向主程序的ToolBar指针
*出口参数：无
*返回值：  无
*/
PLUG_EXPORT UINT InitPlugIn(CToolBar *pWndToolBar)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	theApp.SetToolBarPointer(pWndToolBar);
	theApp.AddButtonToToolBar();

	return ID_BUTTON_PLUGIN_CALC;
}

/*
*函数介绍：释放插件，主要是删除掉ToolBar上的按钮
*入口参数：无
*出口参数：无
*返回值：  无
*/
PLUG_EXPORT void DestroyPlugIn()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	theApp.RemoveButtonFromToolBar();
}


/*
*函数介绍：当点击ToolBar上的按钮事件
*入口参数：无
*出口参数：无
*返回值：  无
*/
PLUG_EXPORT void HandleOnClick()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
    if (!theApp.WinExec(_T("calc")))
	{
		AfxMessageBox(_T("计算器程序未被执行"));
	}
}

/*
*函数介绍：得到插件图标和插件标题
*入口参数：无
*出口参数：hIcon : 插件图标句柄
           szLabel : 插件标题
*返回值：  无
*/
PLUG_EXPORT void GetPlugInResources(HICON *hIcon, CString *szLabel)
{
	hIcon = theApp.GetPlugInIcon();
	*szLabel = _T("计算器插件");
}

/*
*函数介绍：得到插件名
*入口参数：无
*出口参数：szPlugInName : 插件名
*返回值：  无
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
*函数介绍：用于设置主窗体工具栏指针
*入口参数：pWndToolBar : 指向主程序的ToolBar指针
*出口参数：无
*返回值：  无
*/
void CPlugIn_oneApp::SetToolBarPointer(CToolBar *pwndToolBar)
{
	m_pwndToolBar = pwndToolBar;
}

/*
*函数介绍：用于添加按钮到主窗体工具栏上
*入口参数：无
*出口参数：无
*返回值：  无
*/
void CPlugIn_oneApp::AddButtonToToolBar()
{

	CToolBarCtrl& pToolbarCtrl = m_pwndToolBar->GetToolBarCtrl();

	//得到工具栏已有的按钮数
	int nButCount = pToolbarCtrl.GetButtonCount();

	//将插件按钮位图添加到工具栏上
	int nImageCount = pToolbarCtrl.AddBitmap(1, IDB_PLUGIN_CALC);

	//定义一个新按钮
	TBBUTTON tb;
	//设置按钮按钮图片
	tb.iBitmap = nImageCount;
	//设置按钮标识
	tb.idCommand = ID_BUTTON_PLUGIN_CALC;
	//设置按钮状态
	tb.fsState = TBSTATE_ENABLED;
	//设置按钮演示
	tb.fsStyle = TBSTYLE_BUTTON;
	tb.dwData = 0;
	tb.iString = NULL;

	//将按钮添加到工具栏上
	pToolbarCtrl.InsertButton(nImageCount, &tb);
}

/*
*函数介绍：用于从主窗体上删除掉添加的按钮
*入口参数：无
*出口参数：无
*返回值：  无
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
			//当按钮是本插件按钮时，则删除之。
			if (tbButton.idCommand == ID_BUTTON_PLUGIN_CALC)
			{
				pToolbarCtrl.DeleteButton(i);
				break;
			}
		}
	}
}

/*
*函数介绍：用于得到插件按钮的标识
*入口参数：无
*出口参数：无
*返回值：  插件按钮标识
*/
UINT CPlugIn_oneApp::GetToolBarButtonInfo(void)
{
	return ID_BUTTON_PLUGIN_CALC;
}

/*
*函数介绍：用于得到插件的图标
*入口参数：pWndToolBar : 指向主程序的ToolBar指针
*出口参数：无
*返回值：  图标句柄
*/
HICON *CPlugIn_oneApp::GetPlugInIcon(void)
{
	return (HICON *)LoadIcon(IDI_PLUGIN_CALC);
}
/*
*函数介绍：用于执行外部程序
*入口参数：FileName : 表示可执行文件名
*出口参数：无
*返回值：  TRUE:执行成功，FALSE:执行失败
*/
bool CPlugIn_oneApp::WinExec(LPCTSTR FileName)
{
    PROCESS_INFORMATION processInfo; //进程相关信息
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


