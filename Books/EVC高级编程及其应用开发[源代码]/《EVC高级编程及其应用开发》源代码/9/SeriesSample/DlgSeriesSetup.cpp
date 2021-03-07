// DlgSeriesSetup.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "DlgSeriesSetup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSeriesSetup dialog


CDlgSeriesSetup::CDlgSeriesSetup(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSeriesSetup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSeriesSetup)
	//}}AFX_DATA_INIT
}


void CDlgSeriesSetup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSeriesSetup)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSeriesSetup, CDialog)
	//{{AFX_MSG_MAP(CDlgSeriesSetup)
	ON_BN_CLICKED(IDC_BTNOPEN, OnBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSeriesSetup message handlers

void CDlgSeriesSetup::OnBtnopen() 
{
	CComboBox *pCmbName = NULL;
	CComboBox *pCmbBaud = NULL;
	CComboBox *pCmbParity = NULL;
	CComboBox *pCmbDataBits = NULL;
	CComboBox *pCmbStopBits = NULL;
	
	pCmbName = (CComboBox*)GetDlgItem(IDC_CMBNAME);
	pCmbBaud = (CComboBox*)GetDlgItem(IDC_CMBBAUD);
	pCmbParity = (CComboBox*)GetDlgItem(IDC_CMBPARITY);
	pCmbDataBits = (CComboBox*)GetDlgItem(IDC_CMBDATABITS);
	pCmbStopBits = (CComboBox*)GetDlgItem(IDC_CMBSTOPBITS);
	ASSERT(pCmbName != NULL);
	ASSERT(pCmbBaud != NULL);
	ASSERT(pCmbParity != NULL);
	ASSERT(pCmbDataBits != NULL);
	ASSERT(pCmbStopBits != NULL);
	//�õ����ڱ��
	CString tmpCommName;
	pCmbName->GetWindowText(tmpCommName);
	m_portNo = _wtoi(tmpCommName);
	//�õ�������
	CString tmpBaud;
	pCmbBaud->GetWindowText(tmpBaud);
	m_baud = _wtoi(tmpBaud);
	//�õ���żУ��
	m_parity = pCmbParity->GetCurSel();
	//�õ�����λ
	CString tmpDataBits;
	pCmbDataBits->GetWindowText(tmpDataBits);
	m_databits = _wtoi(tmpDataBits);
	//�õ�ֹͣλ
	m_stopbits = pCmbStopBits->GetCurSel();
	
    OnOK();	
}

void CDlgSeriesSetup::OnBtnclose() 
{
   OnClose();	
}
