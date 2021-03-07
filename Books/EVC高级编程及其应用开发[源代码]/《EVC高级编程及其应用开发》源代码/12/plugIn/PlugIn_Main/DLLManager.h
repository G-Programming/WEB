// DLLManager.h: interface for the CDLLManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLLMANAGER_H__F429BE7C_DC2F_4878_95C4_7182F54D5D27__INCLUDED_)
#define AFX_DLLMANAGER_H__F429BE7C_DC2F_4878_95C4_7182F54D5D27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDLLManager  
{
public:
	CDLLManager();
	virtual ~CDLLManager();
public:
	//加载DLL
	bool LoadDLL(CString szFileName);
	//初始化DLL
	bool InitDLL();
	//释放DLL
	bool FreeDLL();
	//设置ToolBar指针
	void SetToolBarPointer(CToolBar *pWndToolBar);
	//当点击ToolBar上的按钮事件
	bool HandleOnClick();
	//得到插件图标和插件标题
	bool GetPlugInResources(HICON *hIcon, CString *szLabel);
	//得到插件名称
	bool GetDLLName(CString *szName);
 	//得到插件按钮标识
	UINT GetToolBarButtonID(); 
	//设置DLL物理文件名
	void SetDLLFileName(CString szFileName);

private:
    //用于存储工具栏指针
	CToolBar *m_pwndToolBar;
	//用于存储插件按钮的ID
	UINT m_unToolBarID;
public:
	//存储DLL的物理文件名
	CString m_szDLLFileName;
	//存储已记载的DLL句柄
	HINSTANCE m_pDLLhInstance;
	//存储插件名
	CString m_szPlugInName;

};

#endif // !defined(AFX_DLLMANAGER_H__F429BE7C_DC2F_4878_95C4_7182F54D5D27__INCLUDED_)
