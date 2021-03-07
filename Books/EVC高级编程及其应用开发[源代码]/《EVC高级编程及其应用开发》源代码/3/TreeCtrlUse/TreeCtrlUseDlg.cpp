// TreeCtrlUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TreeCtrlUse.h"
#include "TreeCtrlUseDlg.h"
#include "TreeAttrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlUseDlg dialog

CTreeCtrlUseDlg::CTreeCtrlUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeCtrlUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeCtrlUseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeCtrlUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeCtrlUseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTreeCtrlUseDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeCtrlUseDlg)
	ON_WM_DESTROY()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_BN_CLICKED(IDC_BTNSET, OnBtnset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlUseDlg message handlers

BOOL CTreeCtrlUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//����ͼƬ�б����
	m_pImgList = new CImageList();
	m_pImgList->Create(24,16,TRUE,12,4);
    //��Ԥ�ȶ���õ�����λͼ���ص�ͼƬ�б���
	CBitmap bmp;
    bmp.LoadBitmap(IDB_BMPTREE);
	m_pImgList->Add(&bmp, (COLORREF)0xFFFFFF);
	bmp.DeleteObject();

    bmp.LoadBitmap(IDB_BMPTREESELECTED);
	m_pImgList->Add(&bmp, (COLORREF)0xFFFFFF);
	bmp.DeleteObject();

    //��ʼ����
    InitTree();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}




void CTreeCtrlUseDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	//�ͷŴ�����ͼƬ�б���ͼ
	delete m_pImgList;	
}

//��ʼ������������Ҫ����������
void CTreeCtrlUseDlg::InitTree()
{
	TCHAR *szTree[4][3]={{_T("����"),_T("�Ͼ�"),_T("����")}
	,{_T("����"),_T("֣��"),_T("����")}
	,{_T("�㽭"),_T("����"),_T("����")}
	,{_T("�㶫"),_T("����"),_T("����")}};

	CTreeCtrl* pCtrl = (CTreeCtrl*) GetDlgItem(IDC_TREE);
	ASSERT(pCtrl != NULL);
	
	pCtrl->SetImageList(m_pImgList,TVSIL_NORMAL);
	//����������ĸ��ڵ�
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.iImage = 0;
	tvInsert.item.iSelectedImage = 1;
	tvInsert.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT;
	
	tvInsert.item.pszText = _T("�й�");
	
	HTREEITEM hCountry = pCtrl->InsertItem(&tvInsert);

	HTREEITEM hSecItem;
	//���ʡ�Լ����У��ڡ��й����ڵ���
	for (int i=0;i<4;i++)
	{
		hSecItem = pCtrl->InsertItem( TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT,
			szTree[i][0], 0, 1, 0, 0, 0, hCountry, NULL);
		pCtrl->InsertItem( TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT,
			szTree[i][1], 0, 1, 0, 0, 0, hSecItem, NULL);
		pCtrl->InsertItem( TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT,
			szTree[i][2], 0, 1, 0, 0, 0, hSecItem, NULL);
	}
}

void CTreeCtrlUseDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	CTreeCtrl* pCtrl = (CTreeCtrl*) GetDlgItem(IDC_TREE);
	ASSERT(pCtrl != NULL);
	
	//��״̬������ʾ��ѡ����Ҷ�ı���
	CStatic *pLblStatus = (CStatic*)GetDlgItem(IDC_STATUS);
	pLblStatus->SetWindowText(pCtrl->GetItemText(pCtrl->GetSelectedItem()));

	*pResult = 0;
}

//��������ĳ������
void CTreeCtrlUseDlg::SetNewStyle(long lStyleMask, BOOL bSetBits)
{
	CTreeCtrl* pCtrl = (CTreeCtrl*) GetDlgItem(IDC_TREE);
	ASSERT(pCtrl != NULL);

	long		lStyleOld;

	lStyleOld = GetWindowLong(pCtrl->m_hWnd, GWL_STYLE);
	lStyleOld &= ~lStyleMask;
	if (bSetBits)
		lStyleOld |= lStyleMask;

	SetWindowLong(pCtrl->m_hWnd, GWL_STYLE, lStyleOld);
	pCtrl->SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

//��������ʽ
void CTreeCtrlUseDlg::SetTreeCtrlStyle()
{
	CTreeCtrl* pCtrl = (CTreeCtrl*) GetDlgItem(IDC_TREE);
	ASSERT(pCtrl != NULL);

	SetNewStyle(TVS_EDITLABELS, m_bEditLabels);
	SetNewStyle(TVS_HASBUTTONS, m_bHasButtons);
	SetNewStyle(TVS_HASLINES, m_bHasLines);
	SetNewStyle(TVS_LINESATROOT, m_bLinesAtRoot);
	SetNewStyle(TVS_SHOWSELALWAYS, m_bShowSelAlways);
}

void CTreeCtrlUseDlg::OnBtnset() 
{
	CTreeAttrDlg *g_ptreeCtrlDlg = new CTreeAttrDlg;

	g_ptreeCtrlDlg->m_bEditLabels = m_bEditLabels;
	g_ptreeCtrlDlg->m_bHasButtons = m_bHasButtons;
	g_ptreeCtrlDlg->m_bHasLines = m_bHasLines;
	g_ptreeCtrlDlg->m_bLinesAtRoot = m_bLinesAtRoot;
	g_ptreeCtrlDlg->m_bShowSelAlways = m_bShowSelAlways;

	//���������ô���
	if(g_ptreeCtrlDlg->DoModal() == IDOK)
	{
		m_bEditLabels = g_ptreeCtrlDlg->m_bEditLabels;
		m_bHasButtons = g_ptreeCtrlDlg->m_bHasButtons;
		m_bHasLines = g_ptreeCtrlDlg->m_bHasLines;
		m_bLinesAtRoot = g_ptreeCtrlDlg->m_bLinesAtRoot;
		m_bShowSelAlways = g_ptreeCtrlDlg->m_bShowSelAlways;
		SetTreeCtrlStyle();
	}
	
	delete g_ptreeCtrlDlg;
	g_ptreeCtrlDlg=NULL;	
}
