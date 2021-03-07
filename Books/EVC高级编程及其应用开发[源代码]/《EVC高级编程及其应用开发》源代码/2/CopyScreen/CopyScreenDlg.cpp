// CopyScreenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CopyScreen.h"
#include "CopyScreenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCopyScreenDlg dialog

CCopyScreenDlg::CCopyScreenDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCopyScreenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCopyScreenDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCopyScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCopyScreenDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCopyScreenDlg, CDialog)
//{{AFX_MSG_MAP(CCopyScreenDlg)
ON_BN_CLICKED(IDC_BTNSNAP, OnBtnsnap)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCopyScreenDlg message handlers

BOOL CCopyScreenDlg::OnInitDialog()
{
	
	m_bFullScreen = FALSE;
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
�������ƣ�������Ļ
��ڲ�����(��)
���ڲ�����nWidth  : �洢��Ļ���
          nHeight : �洢��Ļ�߶�
�� �� ֵ���洢��Ļλͼ
*/
HBITMAP CopyScreenToBitmap(int &nWidth,int &nHeight)
{
	// ��Ļ���ڴ��豸������
	HDC  hScrDC, hMemDC;      
	// λͼ���
	HBITMAP  hBitmap, hOldBitmap;    
	// ��Ļ�ֱ���
	int  xScrn, yScrn;         
	
	//Ϊ��Ļ�����豸������
	hScrDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	//Ϊ��Ļ�豸�����������ݵ��ڴ��豸������
	hMemDC = CreateCompatibleDC(hScrDC);
	// �����Ļ�ֱ���
	xScrn = GetDeviceCaps(hScrDC, HORZRES);
	yScrn = GetDeviceCaps(hScrDC, VERTRES);

	//�洢��Ļ�ĳ���
	nWidth = xScrn;
	nHeight = yScrn;
	
	// ����һ������Ļ�豸��������ݵ�λͼ
	hBitmap = CreateCompatibleBitmap(hScrDC, xScrn, yScrn);
	// ����λͼѡ���ڴ��豸��������
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// ����Ļ�豸�����������ڴ��豸��������
	BitBlt(hMemDC, 0, 0, xScrn,yScrn,hScrDC, 0, 0, SRCCOPY);
	//�õ���Ļλͼ�ľ��
	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);
	//��� 
	DeleteDC(hScrDC);
	DeleteDC(hMemDC);
	// ����λͼ���
	return hBitmap;
}

void CCopyScreenDlg::OnBtnsnap() 
{
	HBITMAP	bmp;
	int nWidth,nHeight;
	//ץȡ��Ļ
	bmp = CopyScreenToBitmap(nWidth,nHeight);
	//��ץȡ����Ļѹ����ʾ��������
	CDC *pDC = new CClientDC(this);
	CDC srcDC;
	CRect rect;
	this->GetClientRect(&rect);
	rect.DeflateRect(0,20);
    //������ʾ�������
	CPen pen;
	pen.CreatePen(PS_SOLID,2,RGB(0,255,255));
	pDC->SelectObject(&pen);
	pDC->Rectangle(rect);
    //��ʾ��Ļ
	srcDC.CreateCompatibleDC(pDC);
	srcDC.SelectObject(bmp);
	pDC->StretchBlt(rect.left+2,rect.top+2,rect.right - rect.left - 4 ,rect.bottom - rect.top - 4,&srcDC,0,0,nWidth,nHeight,SRCCOPY);
	DeleteObject(bmp);
}
