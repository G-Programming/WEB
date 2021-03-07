// ListCtrlAttr.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ListCtrlAttr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlAttr dialog


CListCtrlAttr::CListCtrlAttr(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlAttr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListCtrlAttr)
	m_bNoColumnHeader = FALSE;
	m_bEditLabels = FALSE;
	m_bSingleSel = FALSE;
	m_cstrViewMode = _T("");
	m_cstrSort = _T("");
	m_cstrAlignMode = _T("");
	//}}AFX_DATA_INIT
}


void CListCtrlAttr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListCtrlAttr)
	DDX_Check(pDX, IDC_CHK_COLUMNHEADER, m_bNoColumnHeader);
	DDX_Check(pDX, IDC_CHK_EDITLABEL, m_bEditLabels);
	DDX_Check(pDX, IDC_CHK_SINGLESELECT, m_bSingleSel);
	DDX_CBString(pDX, IDC_CMB_VIEWMODE, m_cstrViewMode);
	DDX_CBString(pDX, IDC_CMB_SORT, m_cstrSort);
	DDX_CBString(pDX, IDC_CMB_ALIGN, m_cstrAlignMode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListCtrlAttr, CDialog)
	//{{AFX_MSG_MAP(CListCtrlAttr)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlAttr message handlers

