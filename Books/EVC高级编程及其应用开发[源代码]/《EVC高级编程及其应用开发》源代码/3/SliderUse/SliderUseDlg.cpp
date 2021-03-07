// SliderUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SliderUse.h"
#include "SliderUseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSliderUseDlg dialog

CSliderUseDlg::CSliderUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderUseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSliderUseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSliderUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSliderUseDlg)
	DDX_Control(pDX, IDC_SLIDER_RED, m_slider_red);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_slider_green);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_slider_blue);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSliderUseDlg, CDialog)
	//{{AFX_MSG_MAP(CSliderUseDlg)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSliderUseDlg message handlers

BOOL CSliderUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//设置红色值滑动条
	CSliderCtrl *pSliderRed = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED);
	ASSERT(pSliderRed!=NULL);
	//设置滑动条取值范围
	pSliderRed->SetRange(0,255);
	pSliderRed->SetPos(128);

	//设置绿色值滑动条
	CSliderCtrl *pSliderGreen = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN);
	ASSERT(pSliderGreen!=NULL);
	//设置滑动条取值范围
	pSliderGreen->SetRange(0,255);
	pSliderGreen->SetPos(128);

	//设置蓝色值滑动条
	CSliderCtrl *pSliderBlue = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE);
	ASSERT(pSliderBlue!=NULL);
	//设置滑动条取值范围
	pSliderBlue->SetRange(0,255);
	pSliderBlue->SetPos(128);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//水平滚动事件
void CSliderUseDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int iRed,iGreen,iBlue;
	//得到红色、绿色和蓝色滑动条滚动事件
	if ((pScrollBar->GetDlgCtrlID() == IDC_SLIDER_RED) 
		|| (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_GREEN)
		|| (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_BLUE))
	{
		CSliderCtrl *pSliderRed = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED);
		CSliderCtrl *pSliderGreen = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN);
		CSliderCtrl *pSliderBlue = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE);

		iRed = pSliderRed->GetPos();
		iGreen = pSliderGreen->GetPos();
		iBlue = pSliderBlue->GetPos();

	}

	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//得到RGB颜色值
    clRGB = RGB(iRed,iGreen,iBlue);
	CClientDC * pClientDC;
	//得到绘图环境
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//显示颜色
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;

	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CSliderUseDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
