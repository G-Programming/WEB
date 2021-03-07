// TreeAttrDlg.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "TreeAttrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeAttrDlg dialog


CTreeAttrDlg::CTreeAttrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeAttrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeAttrDlg)
	m_bEditLabels = FALSE;
	m_bHasButtons = FALSE;
	m_bHasLines = FALSE;
	m_bLinesAtRoot = FALSE;
	m_bShowSelAlways = FALSE;
	//}}AFX_DATA_INIT
}


void CTreeAttrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeAttrDlg)
	DDX_Check(pDX, IDC_CHK_EDITLABELS, m_bEditLabels);
	DDX_Check(pDX, IDC_CHK_HASBUTTONS, m_bHasButtons);
	DDX_Check(pDX, IDC_CHK_HASLINES, m_bHasLines);
	DDX_Check(pDX, IDC_CHK_LINESATROOT, m_bLinesAtRoot);
	DDX_Check(pDX, IDC_SHOWSELALWAYS, m_bShowSelAlways);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTreeAttrDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeAttrDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeAttrDlg message handlers
