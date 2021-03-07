// DlgSubmit.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "DlgSubmit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSubmit dialog


CDlgSubmit::CDlgSubmit(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSubmit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSubmit)
	m_internetURL = _T("http://nero/sqlce/sscesa20.dll");
	m_internetPassword = _T("");
	m_queryStr = _T("UPDATE SERVERTIME SET CurTime=Getdate()");
	m_internetUsername = _T("");
	m_connectStr = _T("provider=sqloledb; data source=nero; Initial Catalog=dbtest; user id=sa; password=");
	//}}AFX_DATA_INIT
}

void CDlgSubmit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSubmit)
	DDX_Text(pDX, IDC_EDTINTERNETURL, m_internetURL);
	DDX_Text(pDX, IDC_EDTINTERNETPASSWORD, m_internetPassword);
	DDX_Text(pDX, IDC_EDTQUERYSTR, m_queryStr);
	DDX_Text(pDX, IDC_INTERNETUSERNAME, m_internetUsername);
	DDX_Text(pDX, IDC_EDTCONNECTSTR, m_connectStr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSubmit, CDialog)
	//{{AFX_MSG_MAP(CDlgSubmit)
	ON_BN_CLICKED(IDC_BTNOK, OnBtnok)
	ON_BN_CLICKED(IDC_BTNCANCEL, OnBtncancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSubmit message handlers

void CDlgSubmit::OnBtnok() 
{
	OnOK();	
}

void CDlgSubmit::OnBtncancel() 
{
   OnCancel();	
}
