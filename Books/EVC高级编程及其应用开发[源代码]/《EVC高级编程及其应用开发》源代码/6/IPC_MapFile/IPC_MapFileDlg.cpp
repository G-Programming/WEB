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
	// ��ֹȫ����ʾ
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	//��ʼ��m_memFileMap����
    if (!m_memFileMap.CreateEx(WS_EX_CLIENTEDGE,
    _T("STATIC"), _T("Hi"),WS_POPUP, 5, 5, 30, 30, m_hWnd, NULL))
 	{
	   AfxMessageBox(_T("����ͨѶ����ʧ��"));
	}
	m_memFileMap.m_OnMemDataChange = OnMemDataChange;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*�������ܣ��ڴ�ӳ���ļ����ݱ仯�¼�����
*��ڲ�����pWndָ����ָ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CALLBACK CIPC_MapFileDlg::OnMemDataChange(CWnd *pWnd)
{
	CIPC_MapFileDlg * pDlg;
	pDlg = (CIPC_MapFileDlg*)pWnd;
	pDlg->m_MemData = pDlg->m_memFileMap.ReadBuffer();
	pDlg->UpdateData(FALSE);
}

/*
*�������ܣ����ڴ�ӳ�䰴ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBtnopen() 
{
   WORD dReturnCode;
   m_memFileMap.m_MapName = _T("IPCMemFile");
   m_memFileMap.m_MaxSize = 1024;
   //���ڴ�ӳ���ļ�
   dReturnCode = m_memFileMap.OpenFileMap(this);
   if (dReturnCode <= 0)
   {
	   AfxMessageBox(_T("����ʧ��"));
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
*�������ܣ��ر��ڴ�ӳ�䰴ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBtnclose() 
{
   m_memFileMap.CloseFileMap();
   m_Open = false;
   m_Exist = false;
   UpdateData(false);
}

/*
*�������ܣ���ȡ��ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBtnread() 
{
	m_MemData = m_memFileMap.ReadBuffer();
	UpdateData(FALSE);
}

/*
*�������ܣ�д�����ݰ�ť�����¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnBtnwrite() 
{
   UpdateData(TRUE);
   m_memFileMap.WriteBuffer(m_MemData.GetBuffer(m_MemData.GetLength()));
}

/*
*�������ܣ��Ƿ�ͬ����ѡ�򵥻��¼�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CIPC_MapFileDlg::OnCksyn() 
{
   UpdateData(TRUE);
   m_memFileMap.m_Syn = m_Syn;
}
	
