// RASDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RASDemo.h"
#include "RASDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRASDemoDlg dialog

CRASDemoDlg::CRASDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRASDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRASDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRASDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRASDemoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRASDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CRASDemoDlg)
	ON_BN_CLICKED(IDC_BTNDIAL, OnBtndial)
	ON_BN_CLICKED(IDC_BTNHANGUP, OnBtnhangup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRASDemoDlg message handlers

BOOL CRASDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CRASDemoDlg::OnBtndial() 
{
	if (m_ceRas.CERasDial(_T("GPRS"),_T("*99***1#"),_T("*"),_T(""),_T(""),_T("")))
	{
		AfxMessageBox(_T("≤¶∫≈≥…π¶"));
	}
	else
	{
		AfxMessageBox(_T("≤¶∫≈ ß∞‹"));
	}
	
}

void CRASDemoDlg::OnBtnhangup() 
{
	if (m_ceRas.CERasHangup())
	{
		AfxMessageBox(_T("π“∂œ≥…π¶"));
	}
	else
	{
		AfxMessageBox(_T("π“∂œ ß∞‹"));
	}
	
}
