// AnimateDrawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AnimateDraw.h"
#include "AnimateDrawDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimateDrawDlg dialog

CAnimateDrawDlg::CAnimateDrawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimateDrawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnimateDrawDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimateDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimateDrawDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnimateDrawDlg, CDialog)
	//{{AFX_MSG_MAP(CAnimateDrawDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateDrawDlg message handlers

BOOL CAnimateDrawDlg::OnInitDialog()
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



void CAnimateDrawDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
//�õ����ڻ�ͼ����
//	CClientDC dc(this);
	//����������ͼ����
	CDC offDC;
	//��������λͼ
	CBitmap offBitmap;

	//������������
	offDC.CreateCompatibleDC(&dc);
	offBitmap.CreateCompatibleBitmap(&dc,240,320);
	offDC.SelectObject(&offBitmap);

	//����λͼ���ƻ���
	CDC bmpDC;
	CBitmap aniBmp;
	//����λͼ
	aniBmp.LoadBitmap(IDB_BMP_ANIMATE);
	bmpDC.CreateCompatibleDC(&offDC);
    bmpDC.SelectObject(aniBmp);

	//ѭ����ʾλͼ���γɶ���Ч��
    for(int nCnt=0; nCnt<4; nCnt++)
    {
	  //������������Ϊ����ɫ
      offDC.PatBlt(0, 0, 240, 320, WHITENESS);
	  //����λͼ��������ͼ������
      TransparentImage(offDC.m_hDC,nCnt*4,0,46,57,bmpDC.m_hDC,nCnt*46,0,46,57, RGB(255,0,255));
      //��������ͼ�������Ƶ�ʵ�ʴ��ڻ�ͼ����
      dc.BitBlt(0,0,240,320,&offDC,0,0,SRCCOPY);
	  Sleep(100);
    }
	//ɾ��λͼGDI����
	aniBmp.DeleteObject();
	//ɾ��λͼ���ƻ���
	bmpDC.DeleteDC();
	//ɾ������λͼGDI����
	offBitmap.DeleteObject();
	//ɾ��������ͼ����
	offDC.DeleteDC();
	
	Invalidate();
}
