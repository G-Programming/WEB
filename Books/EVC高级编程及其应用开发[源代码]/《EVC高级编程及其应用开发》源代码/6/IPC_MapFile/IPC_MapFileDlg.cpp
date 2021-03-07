// IPC_MapFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPC_MapFile.h"
#include "IPC_MapFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileDlg dialog

CIPC_MapFileDlg::CIPC_MapFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPC_MapFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIPC_MapFileDlg)
	m_Exist = FALSE;
	m_Open = FALSE;
	m_Syn = FALSE;
	m_MemData = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPC_MapFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIPC_MapFileDlg)
	DDX_Check(pDX, IDC_CKEXIST, m_Exist);
	DDX_Check(pDX, IDC_CKOPEN, m_Open);
	DDX_Check(pDX, IDC_CKSYN, m_Syn);
	DDX_Text(pDX, IDC_EDTDATA, m_MemData);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIPC_MapFileDlg, CDialog)
	//{{AFX_MSG_MAP(CIPC_MapFileDlg)
	ON_BN_CLICKED(IDC_BTNOPEN, OnBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	ON_BN_CLICKED(IDC_BTNREAD, OnBtnread)
	ON_BN_CLICKED(IDC_BTNWRITE, OnBtnwrite)
	ON_BN_CLICKED(IDC_CKSYN, OnCksyn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileDlg message handlers

BOOL CIPC_MapFileDlg::OnInitDialog()
{
	// 禁止全屏显示
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	//初始化m_memFileMap变量
    if (!m_memFileMap.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("创建通讯窗口失败"));
	}
	m_memFileMap.m_OnMemDataChange = OnMemDataChange;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*函数介绍：内存映射文件内容变化事件函数
*入口参数：pWnd指向窗体指针
*出口参数：(无)
*返回值：(无)
*/
void CALLBACK CIPC_MapFileDlg::OnMemDataChange(CWnd *pWnd)
{
	CIPC_MapFileDlg * pDlg;
	pDlg = (CIPC_MapFileDlg*)pWnd;
	pDlg->m_MemData = pDlg->m_memFileMap.ReadBuffer();
	pDlg->UpdateData(FALSE);
}

/*
*函数介绍：打开内存映射按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBtnopen() 
{
   WORD dReturnCode;
   m_memFileMap.m_MapName = _T("IPCMemFile");
   m_memFileMap.m_MaxSize = 1024;
   //打开内存映射文件
   dReturnCode = m_memFileMap.OpenFileMap(this);
   if (dReturnCode <= 0)
   {
	   AfxMessageBox(_T("创建失败"));
   }
   if (dReturnCode >=1)
   {
	   m_Open = true;
   }
   if (dReturnCode == 2) 
   {
	   m_Exist = true;
   }
   UpdateData(false);

}

/*
*函数介绍：关闭内存映射按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBtnclose() 
{
   m_memFileMap.CloseFileMap();
   m_Open = false;
   m_Exist = false;
   UpdateData(false);
}

/*
*函数介绍：读取按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBtnread() 
{
	m_MemData = m_memFileMap.ReadBuffer();
	UpdateData(FALSE);
}

/*
*函数介绍：写入数据按钮单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnBtnwrite() 
{
   UpdateData(TRUE);
   m_memFileMap.WriteBuffer(m_MemData.GetBuffer(m_MemData.GetLength()));
}

/*
*函数介绍：是否同步复选框单击事件
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CIPC_MapFileDlg::OnCksyn() 
{
   UpdateData(TRUE);
   m_memFileMap.m_Syn = m_Syn;
}
	
