// ADOAccessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOAccess.h"
#include "ADOAccessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADOAccessDlg dialog

CADOAccessDlg::CADOAccessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOAccessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOAccessDlg)
	m_strSql = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADOAccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOAccessDlg)
	DDX_CBString(pDX, IDC_CMB_SQL, m_strSql);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOAccessDlg, CDialog)
	//{{AFX_MSG_MAP(CADOAccessDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTNCREATEDB, OnBtncreatedb)
	ON_BN_CLICKED(IDC_BTNOPENDB, OnBtnopendb)
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOAccessDlg message handlers

BOOL CADOAccessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//初始化COM库
	CoInitializeEx(NULL,COINIT_MULTITHREADED);

	//建立与Access数据库连接
    if (!CreateConnection())
    {
	   AfxMessageBox(_T("建立连接失败"));
	   return FALSE;
    }

   	//设置人列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_VIEW);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("姓名"), LVCFMT_LEFT, rt.Width() * 0.5);
    pListCtrl->InsertColumn(1,_T("年龄"), LVCFMT_LEFT, rt.Width() * 0.5);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOAccessDlg::OnDestroy() 
{
	//关闭连接
	CloseConnection();
	
	//释放COM库
    CoUninitialize();	
	CDialog::OnDestroy();
}



//与ADO数据库建立连接
BOOL CADOAccessDlg::CreateConnection()
{
	CLSID	tClsid;
	HRESULT hr;

	//1,得到ADO连接对象对应ClassID
	hr = CLSIDFromProgID( g_szADOCE30ConnProgID, &tClsid );
	
	if (FAILED(hr))
	{
		return FALSE;
	}
	
    //2,创建ADO连接对象
	hr = CoCreateInstance (tClsid, NULL,
		CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER,
		IID__Connection, (LPVOID *)&m_pADOCEConn);
	
	if((!m_pADOCEConn) || FAILED(hr))
	{
		return FALSE;
	}
		
	//3.设置连接数据库的Provider
	hr = m_pADOCEConn->put_Provider(TEXT("cedb"));
	if FAILED(hr)
	{
		return FALSE;
	}

	//4.得到记录集对象的ClassID
	hr = CLSIDFromProgID( g_szADOCE30RSProgID, &tClsid );
	if FAILED(hr)
	{
		return FALSE;
	}

	//5.创建结果集对象
	hr = CoCreateInstance (tClsid, NULL,
		CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER,
		IID__Recordset,(LPVOID *)&m_pADOCERS);
				
	if((!m_pADOCERS) || FAILED(hr))
	{
		return FALSE;
	}
								
	return TRUE;

}

//关闭与Access数据库连接
void CADOAccessDlg::CloseConnection()
{
	if (m_pADOCEConn != NULL)
	{
		m_pADOCEConn->Close();
		m_pADOCEConn->Release();
		m_pADOCEConn = NULL;
	}

	if (m_pADOCERS != NULL)
	{
		m_pADOCERS->Close();
        m_pADOCERS->Release();
		m_pADOCERS = NULL;
	}
}

/*
函数名称：新建数据库
入口参数：szDbName表示要新建的数据库名称
出口参数：无
返 回 值：TRUE:新建数据库成功;FALSE:新建数据库失败
*/
BOOL CADOAccessDlg::CreateDatabase(LPCTSTR szDbName)
{
	VARIANT varTSQL,varEmpty; 
	HRESULT hr;
    TCHAR szSqlBuf[1024];
	wcscpy(szSqlBuf,_T("CREATE DATABASE '"));
	wcscat(szSqlBuf,szDbName);
	wcscat(szSqlBuf,_T("'"));

	VariantInit(&varTSQL);
	VariantInit(&varEmpty);
	
	varTSQL.bstrVal = SysAllocString(szSqlBuf);
	varTSQL.vt = VT_BSTR;
    
	//创建数据库
    hr=m_pADOCERS->Open(varTSQL,varEmpty,MSADOCE::adOpenDynamic,MSADOCE::adLockOptimistic,MSADOCE::adCmdText);
	if(FAILED(hr))
	{
		return FALSE;
	}
	m_pADOCERS->Close();
	return TRUE;
}


/*
函数名称：打开数据库
入口参数：szDbName表示要打开的数据库名称
出口参数：无
返 回 值：TRUE:打开数据库成功;FALSE:打开数据库失败
*/
BOOL CADOAccessDlg::OpenDatabase(LPCTSTR szDbName)
{
	HRESULT hr;
	VARIANT varConn1;


    //与指定的数据库建立连接
	hr = m_pADOCEConn->Open(LPTSTR(szDbName),TEXT(""), TEXT(""),MSADOCE::adOpenUnspecified);
	if FAILED(hr)
	{
		return FALSE;
	}

	VariantInit(&varConn1);
	varConn1.pdispVal=m_pADOCEConn;
	varConn1.vt=VT_DISPATCH;
	//设置结果集对象到已建立的连接上
	hr=m_pADOCERS->put_ActiveConnection(varConn1);
	if (FAILED(hr))
	{
		return FALSE;
	}

	return TRUE;
}

//新建数据库按钮单击事件代码
void CADOAccessDlg::OnBtncreatedb() 
{
   CString dbFileName;

   TCHAR szFilters[]=_T("Access File (*.cdb)|*.cdb||");
   
   //打开文件保存对话框
   CFileDialog fileDlg (FALSE, _T("cdb"),NULL,OFN_PATHMUSTEXIST,szFilters,this);
   if (fileDlg.DoModal() == IDOK)
   {
	   dbFileName = fileDlg.GetPathName();
   }
   else
   {
	   return;
   }

   //
   if (!CreateDatabase(dbFileName))
   {
	   AfxMessageBox(_T("创建数据库失败"));
	   return;
   }	
}

//打开数据库按钮单击事件代码
void CADOAccessDlg::OnBtnopendb() 
{
   CString dbFileName;

   TCHAR szFilters[]=_T("Access File (*.cdb)|*.cdb||");
 
   //调用，打开文件对话框，选择Access数据库文件
   CFileDialog fileDlg (TRUE, _T("cdb"),_T("*.cdb"),OFN_FILEMUSTEXIST,szFilters,this);
   if (fileDlg.DoModal() == IDOK)
   {
	   dbFileName = fileDlg.GetPathName();
   }
   else
   {
	   return;
   }

   //打开数据库
   if (!OpenDatabase(dbFileName))
   {
	   AfxMessageBox(_T("打开数据库失败"));
	   return;
   }	
}

//将表中的记录在列表视图上显示
void CADOAccessDlg::AddRecordToView()
{
	HRESULT hr;
	short iEndOfFile;
	VARIANT			varData,varFieldSelect;
	TCHAR*			pszName;
	TCHAR*			pszAge;	
	pszName = (TCHAR*)malloc(40);
	pszAge = (TCHAR*)malloc(40);
    hr = m_pADOCERS->MoveFirst();
	//判断记录集指针是否到达尾部
	hr = m_pADOCERS->get_EOF(&iEndOfFile);
	int k=0;
	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_VIEW);
	while(!iEndOfFile)
	{
			//得到表中字段集对象
			hr = m_pADOCERS->get_Fields(&m_pADOCEFields);
			varFieldSelect.uiVal = 0;
			varFieldSelect.vt = VT_UI2;
			hr = m_pADOCEFields->get_Item(varFieldSelect, &m_pADOCEField);
			hr = m_pADOCEField->get_Value(&varData);
			lstrcpy(pszName, varData.bstrVal);
			
			//得到字段对象
			varFieldSelect.uiVal = 1;
			varFieldSelect.vt = VT_I4;
			hr = m_pADOCEFields->get_Item(varFieldSelect, &m_pADOCEField);
			hr = m_pADOCEField->get_Value(&varData);
		    _itow(varData.lVal,pszAge,10);
			
			//向列表框中添加人信息
			pListCtrl->InsertItem(k,_T("Test"));
			//添加人名
			pListCtrl->SetItemText(k,0,pszName);
			//添加人年龄
			pListCtrl->SetItemText(k,1,pszAge);
			
			//将记录集指针向后移动一个
			m_pADOCERS->MoveNext();
			m_pADOCERS->get_EOF(&iEndOfFile);
			k++;
	}
	free(pszName);
	free(pszAge);
}

//执行按钮单击事件代码
void CADOAccessDlg::OnBtnexec() 
{
	HRESULT hr;
	VARIANT varStrSql,varEmpty;
	VariantInit(&varStrSql);
	VariantInit(&varEmpty);
	UpdateData(TRUE);
	varStrSql.bstrVal = SysAllocString(m_strSql);
	varStrSql.vt = VT_BSTR;
	hr = m_pADOCERS->Open(varStrSql,varEmpty,MSADOCE::adOpenDynamic,MSADOCE::adLockOptimistic,MSADOCE::adCmdText);
	SysFreeString(varStrSql.bstrVal);
						
	if (FAILED(hr))
	{
		AfxMessageBox(_T("执行失败"));
	}
	long iCount = 0;
	hr = m_pADOCERS->get_RecordCount(&iCount);
	AddRecordToView();
	m_pADOCERS->Close();
}
