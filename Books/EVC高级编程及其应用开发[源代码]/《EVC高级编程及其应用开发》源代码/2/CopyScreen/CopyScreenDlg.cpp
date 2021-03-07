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
函数名称：拷贝屏幕
入口参数：(无)
出口参数：nWidth  : 存储屏幕宽度
          nHeight : 存储屏幕高度
返 回 值：存储屏幕位图
*/
HBITMAP CopyScreenToBitmap(int &nWidth,int &nHeight)
{
	// 屏幕和内存设备描述表
	HDC  hScrDC, hMemDC;      
	// 位图句柄
	HBITMAP  hBitmap, hOldBitmap;    
	// 屏幕分辨率
	int  xScrn, yScrn;         
	
	//为屏幕创建设备描述表
	hScrDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	//为屏幕设备描述表创建兼容的内存设备描述表
	hMemDC = CreateCompatibleDC(hScrDC);
	// 获得屏幕分辨率
	xScrn = GetDeviceCaps(hScrDC, HORZRES);
	yScrn = GetDeviceCaps(hScrDC, VERTRES);

	//存储屏幕的长宽
	nWidth = xScrn;
	nHeight = yScrn;
	
	// 创建一个与屏幕设备描述表兼容的位图
	hBitmap = CreateCompatibleBitmap(hScrDC, xScrn, yScrn);
	// 把新位图选到内存设备描述表中
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// 把屏幕设备描述表拷贝到内存设备描述表中
	BitBlt(hMemDC, 0, 0, xScrn,yScrn,hScrDC, 0, 0, SRCCOPY);
	//得到屏幕位图的句柄
	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);
	//清除 
	DeleteDC(hScrDC);
	DeleteDC(hMemDC);
	// 返回位图句柄
	return hBitmap;
}

void CCopyScreenDlg::OnBtnsnap() 
{
	HBITMAP	bmp;
	int nWidth,nHeight;
	//抓取屏幕
	bmp = CopyScreenToBitmap(nWidth,nHeight);
	//将抓取的屏幕压缩显示到窗体上
	CDC *pDC = new CClientDC(this);
	CDC srcDC;
	CRect rect;
	this->GetClientRect(&rect);
	rect.DeflateRect(0,20);
    //绘制显示区域矩形
	CPen pen;
	pen.CreatePen(PS_SOLID,2,RGB(0,255,255));
	pDC->SelectObject(&pen);
	pDC->Rectangle(rect);
    //显示屏幕
	srcDC.CreateCompatibleDC(pDC);
	srcDC.SelectObject(bmp);
	pDC->StretchBlt(rect.left+2,rect.top+2,rect.right - rect.left - 4 ,rect.bottom - rect.top - 4,&srcDC,0,0,nWidth,nHeight,SRCCOPY);
	DeleteObject(bmp);
}
