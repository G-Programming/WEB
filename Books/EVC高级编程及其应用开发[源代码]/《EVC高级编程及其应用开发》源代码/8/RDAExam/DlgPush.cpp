// DlgPush.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "DlgPush.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPush dialog


CDlgPush::CDlgPush(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPush::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPush)
	m_connectStr = _T("provider=sqloledb; data source=nero; Initial Catalog=dbtest; user id=sa; password=");
	m_internetPassword = _T("");
	m_internetURL = _T("http://nero/sqlce/sscesa20.dll");
	m_localConnectStr = _T("Provider=microsoft.sqlserver.oledb.ce.2.0;Data Source=\\My Documents\\myDB.sdf");
	m_localTableName = _T("");
	m_internetUsername = _T("");
	//}}AFX_DATA_INIT
}


void CDlgPush::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPush)
	DDX_Text(pDX, IDC_EDTCONNECTSTR, m_connectStr);
	DDX_Text(pDX, IDC_EDTINTERNETPASSWORD, m_internetPassword);
	DDX_Text(pDX, IDC_EDTINTERNETURL, m_internetURL);
	DDX_Text(pDX, IDC_EDTLOCALCONNECTSTR, m_localConnectStr);
	DDX_Text(pDX, IDC_EDTLOCALTABLENAME, m_localTableName);
	DDX_Text(pDX, IDC_INTERNETUSERNAME, m_internetUsername);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPush, CDialog)
	//{{AFX_MSG_MAP(CDlgPush)
	ON_BN_CLICKED(IDC_BTNOK, OnBtnok)
	ON_BN_CLICKED(IDC_BTNCANCEL, OnBtncancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPush message handlers

void CDlgPush::OnBtnok() 
{
	OnOK();	
}

void CDlgPush::OnBtncancel() 
{
	OnCancel();	
}
