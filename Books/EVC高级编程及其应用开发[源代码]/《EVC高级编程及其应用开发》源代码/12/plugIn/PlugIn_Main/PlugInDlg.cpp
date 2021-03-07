// PlugInDlg.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "PlugInDlg.h"
#include "MainFrm.h"
#include "DLLManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlugInDlg dialog


CPlugInDlg::CPlugInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlugInDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlugInDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPlugInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlugInDlg)
	DDX_Control(pDX, IDC_LSTPLUGIN, m_lstPlugIn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlugInDlg, CDialog)
	//{{AFX_MSG_MAP(CPlugInDlg)
	ON_BN_CLICKED(IDC_BTNLOAD, OnBtnload)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlugInDlg message handlers


/*
*函数介绍：将插件信息填充到列表视图
*入口参数：(无)
*出口参数：(无)
*返 回 值：(无)
*/
void CPlugInDlg::FillPlugIns(void)
{
	CRect           rect;
	CString         strItem1= _T("序号");
	CString         strItem2= _T("插件名称");
	CString         strItem3= _T("插件文件名");
	CString         szSerialNo(""), szPlugInName(""), szPlugInPath("");
	LPTSTR          pStrTemp1 = NULL, pStrTemp2 = NULL, pStrTemp3 = NULL;
	CPlugIn_MainApp     *pApp = NULL;
	
	pApp = (CPlugIn_MainApp *)AfxGetApp();
	
	int nNumDLLsFound = FindDLLs(pApp);
	
	//设置列表视图的列标题
	m_lstPlugIn.GetWindowRect(&rect);
	m_lstPlugIn.InsertColumn(0, strItem1, LVCFMT_LEFT, rect.Width() * 4/20);
	m_lstPlugIn.InsertColumn(1, strItem2, LVCFMT_LEFT, rect.Width() * 6/20);
	m_lstPlugIn.InsertColumn(2, strItem3, LVCFMT_LEFT, rect.Width() * 10/20);
	
	POSITION pos1 = m_szListPlugInName.GetHeadPosition();
	POSITION pos2 = m_szListValidFilenames.GetHeadPosition();
	
	//向列表视图中添加插件信息
	for (int nItem = 0; nItem < nNumDLLsFound; nItem++)
	{
		szPlugInName = m_szListPlugInName.GetNext(pos1);
		szPlugInPath = m_szListValidFilenames.GetNext(pos2);
		szSerialNo.Format(_T("%d"), nItem);

			
		pStrTemp1= szSerialNo.GetBuffer(szSerialNo.GetLength());
		pStrTemp2= szPlugInName.GetBuffer(szPlugInName.GetLength());
		pStrTemp3= szPlugInPath.GetBuffer(szPlugInPath.GetLength());

        m_lstPlugIn.InsertItem(nItem,pStrTemp1);
        m_lstPlugIn.SetItemText(nItem,0,pStrTemp1);
	    m_lstPlugIn.SetItemText(nItem,1,pStrTemp2);
	    m_lstPlugIn.SetItemText(nItem,2,pStrTemp3);	 
	
		//判断插件是否已被加载
		if (((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.Find(szPlugInPath) != NULL)
		{
			ListView_SetCheckState(m_lstPlugIn.m_hWnd, nItem, TRUE);
		}
	}
	m_szListPlugInName.RemoveAll();
	m_szListValidFilenames.RemoveAll();
}


/*
*函数介绍：查找同可执行文件相同目录下的.plx插件文件，并将其存储到列表中
*入口参数：pApp:指向CPlugIn_MainApp应用程序对象指针
*出口参数：(无)
*返 回 值：返回找到插件的数量
*/
int CPlugInDlg::FindDLLs(CPlugIn_MainApp *pApp)
{
	//定义查找文件句柄
	HANDLE hFile;
	//定义查找文件结构
	WIN32_FIND_DATA FileData;
	CDLLManager			tmpDLL;
	//设置查找插件路径
	CString				szSearchPath = _T("");
	CString				szCommandLine ;
	int					nNumDlls = 0 ;
    TCHAR exeFullPath[MAX_PATH] ;
    GetModuleFileName(NULL,exeFullPath,MAX_PATH);
    szCommandLine = exeFullPath;
	//去掉Exe文件名
	szCommandLine = szCommandLine.Left(szCommandLine.Find(_T("PlugIn_Main.exe")));
	szCommandLine = szCommandLine.Right(szCommandLine.GetLength() - 1);
	//设置查找文件路径
	szSearchPath = szCommandLine + "*.PLX";
	//查找第一个符合条件的文件
	hFile = FindFirstFile (szSearchPath, &FileData);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			//设置工具栏对象指针
			tmpDLL.SetToolBarPointer(((CMainFrame *)pApp->m_pMainWnd)->GetToolBarObject());
			//设置插件DLL文件名
			tmpDLL.SetDLLFileName(szCommandLine + FileData.cFileName);
			CString szName(_T(""));
			if (tmpDLL.GetDLLName(&szName) == true)
			{
				//将插件名称和文件名存储到列表中
				m_szListPlugInName.AddTail(szName);
				m_szListValidFilenames.AddTail(tmpDLL.m_szDLLFileName);
				nNumDlls++;
			}
		} while (FindNextFile(hFile, &FileData) != 0);
		//关闭查找文件句柄
		FindClose(hFile);
	}
	return nNumDlls;
}

/*
*函数介绍：加载选中的插件列表
*入口参数：pApp:指向CPlugIn_MainApp应用程序对象指针
		   szListSelectedDLLs : 选中的插件列表
*出口参数：(无)
*返 回 值：TRUE:加载成功 ; FALSE: 加载失败
*/
bool CPlugInDlg::LoadDLLs(CPlugIn_MainApp *pApp, CStringList *szListSelectedDLLs)
{
	//判断加载dll的数量
	if (((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs > 0)
	{
		POSITION pos = szListSelectedDLLs->GetHeadPosition();
		((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs = new CDLLManager[((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs];
		for (int nNumDlls = 0 ;	nNumDlls < ((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs ; nNumDlls++)
		{
			((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].SetToolBarPointer(((CMainFrame *)pApp->m_pMainWnd)->GetToolBarObject());
            if (((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].LoadDLL(szListSelectedDLLs->GetNext(pos)) != false)
			{
				if (((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].InitDLL() == false)
				{
					AfxMessageBox(_T("错误: 初始化 " + ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].m_szDLLFileName + "失败!!!"));
					return false;
				}
			}
			else
			{
				AfxMessageBox(_T("错误: 加载 " + ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs[nNumDlls].m_szDLLFileName + "失败!!!"));
				
				return false;
			}
		}
	}
	else
	{
		AfxMessageBox(_T("错误，没有被加载的DLL"));
		return false;
	}
	
	//重新布置界面显示
	((CMainFrame *)pApp->m_pMainWnd)->RecalcLayout();
	
	//设置标识，标识插件已被加载
	((CMainFrame *)pApp->m_pMainWnd)->m_bIsPlugInLoaded = TRUE;
	
	return true;
}


BOOL CPlugInDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//设置列表视图样式
	m_lstPlugIn.SetExtendedStyle(m_lstPlugIn.GetExtendedStyle()
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_GRIDLINES
		| 0x00004000 // LVS_EX_LABELTIP
		| LVS_EX_FULLROWSELECT
		| LVS_EX_CHECKBOXES);
	//填充插件
	FillPlugIns();
	
	m_lstPlugIn.SetFocus();
	if (m_lstPlugIn.GetItemCount() > 0)
        m_lstPlugIn.SetSelectionMark(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//加载按钮单击方法
void CPlugInDlg::OnBtnload() 
{
	int nCount = m_lstPlugIn.GetItemCount();
	int nNumDLLsSelected = 0;
	
	if (nCount <= 0)
	{
		AfxMessageBox(_T("没有插件被发现"));
		return;
	}
	
	CStringList szList;
	
	for (int i=0; i<m_lstPlugIn.GetItemCount(); i++)
	{
		if (ListView_GetCheckState(m_lstPlugIn.m_hWnd, i) != 0)
		{
			szList.AddTail(m_lstPlugIn.GetItemText(i, 2));
			++nNumDLLsSelected;
		}
	}
	
	if (nNumDLLsSelected == 0)
	{
		if (AfxMessageBox(_T("错误: 没有选中插件，您打算卸载插件吗"),MB_YESNO) == IDYES)
		{
			CPlugIn_MainApp *pApp = (CPlugIn_MainApp *) AfxGetApp();
			
			if (((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs > 0)
			{
				//删除曾经被加载的插件
				delete [] ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs;
				((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs = NULL;
				((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = 0;
				((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.RemoveAll();
				
				//重新布置界面显示
				((CMainFrame *)pApp->m_pMainWnd)->RecalcLayout();
			}
			
			((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = 0;
		}
		return;
	}
	else
	{
		CPlugIn_MainApp *pApp = (CPlugIn_MainApp *) AfxGetApp();
		
		if (((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs > 0)
		{
			//删除曾经被加载的插件
			delete [] ((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs;
			((CMainFrame *)pApp->m_pMainWnd)->m_pLoadedDLLs = NULL;
			((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = 0;
			
			// Recalculate layout due to GUI changes
			((CMainFrame *)pApp->m_pMainWnd)->RecalcLayout();
		}
		
		//重新布置界面显示
		((CMainFrame *)pApp->m_pMainWnd)->m_nNumberOfDLLs = nNumDLLsSelected;
		
		//重新加载插件DLL
		LoadDLLs(pApp, &szList);
		
		((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.RemoveAll();
		((CMainFrame *)pApp->m_pMainWnd)->m_szListDLLsCurrentlyLoaded.AddTail(&szList);
		szList.RemoveAll();
	}	
}

//关闭对话框
void CPlugInDlg::OnBtnclose() 
{
	OnCancel();
}
