// DlgPull.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "DlgPull.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPull dialog


CDlgPull::CDlgPull(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPull::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPull)
	m_connectStr = _T("provider=sqloledb; data source=nero; Initial Catalog=dbtest; user id=sa; password=");
	m_errorTableName = _T("tblErrors");
	m_internetPassword = _T("");
	m_internetURL = _T("http://nero/sqlce/sscesa20.dll");
	m_localConnectStr = _T("Provider=microsoft.sqlserver.oledb.ce.2.0;Data Source=\\My Documents\\myDB.sdf");
	m_localTableName = _T("students");
	m_queryStr = _T("select * from students");
	m_internetUsername = _T("");
	m_tracking = _T("");
	//}}AFX_DATA_INIT
}


void CDlgPull::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPull)
	DDX_Text(pDX, IDC_EDTCONNECTSTR, m_connectStr);
	DDX_Text(pDX, IDC_EDTERRORTABLENAME, m_errorTableName);
	DDX_Text(pDX, IDC_EDTINTERNETPASSWORD, m_internetPassword);
	DDX_Text(pDX, IDC_EDTINTERNETURL, m_internetURL);
	DDX_Text(pDX, IDC_EDTLOCALCONNECTSTR, m_localConnectStr);
	DDX_Text(pDX, IDC_EDTLOCALTABLENAME, m_localTableName);
	DDX_Text(pDX, IDC_EDTQUERYSTR, m_queryStr);
	DDX_Text(pDX, IDC_INTERNETUSERNAME, m_internetUsername);
	DDX_CBString(pDX, IDC_CMBTRACKING, m_tracking);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPull, CDialog)
	//{{AFX_MSG_MAP(CDlgPull)
	ON_BN_CLICKED(IDC_BTNOK, OnBtnok)
	ON_BN_CLICKED(IDC_BTNCANCEL, OnBtncancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPull message handlers

void CDlgPull::OnBtnok() 
{
   OnOK();
}

void CDlgPull::OnBtncancel() 
{
  OnCancel();	
}
