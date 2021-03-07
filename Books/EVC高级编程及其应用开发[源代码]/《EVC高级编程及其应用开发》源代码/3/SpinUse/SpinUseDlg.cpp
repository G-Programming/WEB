// SpinUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpinUse.h"
#include "SpinUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpinUseDlg dialog

CSpinUseDlg::CSpinUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpinUseDlg)
	m_blue = 0;
	m_green = 0;
	m_red = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpinUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpinUseDlg)
	DDX_Text(pDX, IDC_EDT_BLUE, m_blue);
	DDX_Text(pDX, IDC_EDT_GREEN, m_green);
	DDX_Text(pDX, IDC_EDT_RED, m_red);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpinUseDlg, CDialog)
	//{{AFX_MSG_MAP(CSpinUseDlg)
	ON_EN_CHANGE(IDC_EDT_BLUE, OnColorChange)
	ON_EN_CHANGE(IDC_EDT_GREEN, OnColorChange)
	ON_EN_CHANGE(IDC_EDT_RED, OnColorChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinUseDlg message handlers

BOOL CSpinUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//设置红色值微调按钮
	CSpinButtonCtrl *pSpinRed = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_RED);
	ASSERT(pSpinRed!=NULL);
	//设置伙伴窗口
	pSpinRed->SetBuddy(GetDlgItem(IDC_EDT_RED));
	pSpinRed->SetRange(0,255);
	pSpinRed->SetPos(128);

	//设置绿色值微调按钮
	CSpinButtonCtrl *pSpinGreen = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_GREEN);
	ASSERT(pSpinGreen!=NULL);
	//设置伙伴窗口
	pSpinGreen->SetBuddy(GetDlgItem(IDC_EDT_GREEN));
	pSpinGreen->SetRange(0,255);
	pSpinGreen->SetPos(128);

	//设置蓝色值微调按钮
	CSpinButtonCtrl *pSpinBlue = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_BLUE);
	ASSERT(pSpinBlue!=NULL);
	//设置伙伴窗口
	pSpinBlue->SetBuddy(GetDlgItem(IDC_EDT_BLUE));
	pSpinBlue->SetRange(0,255);
	pSpinBlue->SetPos(128);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//当颜色值改变时，重显颜色值
void CSpinUseDlg::OnColorChange() 
{
	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//得到RGB颜色值
    clRGB = RGB(m_red,m_green,m_blue);
	CClientDC * pClientDC;
	//得到绘图环境
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//显示颜色
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;
}
