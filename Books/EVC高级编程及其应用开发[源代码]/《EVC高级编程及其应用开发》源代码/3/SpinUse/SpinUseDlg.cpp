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

	//���ú�ɫֵ΢����ť
	CSpinButtonCtrl *pSpinRed = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_RED);
	ASSERT(pSpinRed!=NULL);
	//���û�鴰��
	pSpinRed->SetBuddy(GetDlgItem(IDC_EDT_RED));
	pSpinRed->SetRange(0,255);
	pSpinRed->SetPos(128);

	//������ɫֵ΢����ť
	CSpinButtonCtrl *pSpinGreen = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_GREEN);
	ASSERT(pSpinGreen!=NULL);
	//���û�鴰��
	pSpinGreen->SetBuddy(GetDlgItem(IDC_EDT_GREEN));
	pSpinGreen->SetRange(0,255);
	pSpinGreen->SetPos(128);

	//������ɫֵ΢����ť
	CSpinButtonCtrl *pSpinBlue = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_BLUE);
	ASSERT(pSpinBlue!=NULL);
	//���û�鴰��
	pSpinBlue->SetBuddy(GetDlgItem(IDC_EDT_BLUE));
	pSpinBlue->SetRange(0,255);
	pSpinBlue->SetPos(128);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//����ɫֵ�ı�ʱ��������ɫֵ
void CSpinUseDlg::OnColorChange() 
{
	UpdateData(TRUE);
	CBrush colorBrush;
	COLORREF clRGB;
	//�õ�RGB��ɫֵ
    clRGB = RGB(m_red,m_green,m_blue);
	CClientDC * pClientDC;
	//�õ���ͼ����
	pClientDC = new CClientDC(this);
	colorBrush.CreateSolidBrush(clRGB);
	CRect rect(80,120,160,200);
	//��ʾ��ɫ
	pClientDC->FillRect(rect,&colorBrush);
	delete pClientDC;
}
