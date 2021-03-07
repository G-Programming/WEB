// StudentInputDlg.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "StudentInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentInputDlg dialog


CStudentInputDlg::CStudentInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentInputDlg)
	m_birthday = 0;
	m_name = _T("");
	m_no = _T("");
	m_stature = 0;
	//}}AFX_DATA_INIT
}


void CStudentInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentInputDlg)
	DDX_DateTimeCtrl(pDX, IDC_DT_BIRTHDAY, m_birthday);
	DDX_Text(pDX, IDC_EDT_NAME, m_name);
	DDX_Text(pDX, IDC_EDT_NO, m_no);
	DDX_Text(pDX, IDC_EDT_STATURE, m_stature);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentInputDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentInputDlg)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentInputDlg message handlers

//确定按钮单击事件方法
void CStudentInputDlg::OnBtnOk() 
{
	this->OnOK();
}

//取消按钮单击事件方法
void CStudentInputDlg::OnBtnCancel() 
{	
	OnCancel();
}
