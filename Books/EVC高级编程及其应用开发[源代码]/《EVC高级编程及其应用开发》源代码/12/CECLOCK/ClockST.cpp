// ClockST.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ClockST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockST

CClockST::CClockST()
{
}

CClockST::~CClockST()
{
}


BEGIN_MESSAGE_MAP(CClockST, CWnd)
	//{{AFX_MSG_MAP(CClockST)
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CClockST message handlers

/****************************************************************************
函数名称: 画表盘，也就是时针的圆盘
入口参数: pDC   : 表示绘图环境
		  rect  : 表示绘图区域
出口参数: pDC   : 表示绘图环境
返 回 值: (无)
*****************************************************************************/
void CClockST::DrawDial(CDC *pDC,CRect rect)
{
	CBrush backBrush;
	CBrush *pOldBrush;
	backBrush.CreateSolidBrush(RGB(86,86,209));
	
	pDC->FillRect(&rect,&backBrush);
	backBrush.DeleteObject();

	//先画一个圆
	pDC->Ellipse(&rect);

	//然后，画表盘上的12个点
	//定义圆半径
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	int iMinRadius = iMaxRadius - 5;
	//先假设表盘中心坐标为0,0
	CPoint pointFace[12];
	CPoint minPointFace[12];
	//设置12个点坐标
	for (int i=0;i<12;i++)
	{
		pointFace[i].x = iMaxRadius * cos(0.017453292*i*30);
		pointFace[i].y = iMaxRadius * sin(0.017453292*i*30);

		minPointFace[i].x = iMinRadius * cos(0.017453292*i*30);
		minPointFace[i].y = iMinRadius * sin(0.017453292*i*30);
	}

	//修正12点坐标
	for (i=0;i<12;i++)
	{
		pointFace[i].x = pointFace[i].x + iMaxRadius;
		pointFace[i].y = pointFace[i].y + iMaxRadius;

		minPointFace[i].x = minPointFace[i].x + iMaxRadius;
		minPointFace[i].y = minPointFace[i].y + iMaxRadius;
	}

	//绘制表盘上的12个点
	CString strClock;
	for (i=0;i<12;i++)
	{
		strClock.Format(L"%d",i+1);
		pDC->MoveTo(minPointFace[i]);
		pDC->LineTo(pointFace[i]);
	}
}

/****************************************************************************
函数名称: 画时针
入口参数: pDC   : 表示绘图环境
		  rect  : 表示绘图区域
		  nHour : 表示当前小时数
出口参数: pDC   : 表示绘图环境
返 回 值: (无)
*****************************************************************************/
void CClockST::DrawHourHand(CDC *pDC,CRect rect ,int nHour)
{
	ASSERT(nHour>=0 && nHour <24);
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	//定义时针长度
	int iHourHandLen = (iMaxRadius * 3) /5;
	CPoint points[2];
	//定义原点坐标
	points[0].x = iMaxRadius; 
	points[0].y = iMaxRadius;

	int iTmpHour;
	if (nHour >= 12)
	{
		iTmpHour = nHour - 12;
	}
	else
	{
		iTmpHour = nHour;
	}

	points[1].x = iMaxRadius + iHourHandLen * cos(0.017453292*30*iTmpHour);
	points[1].y = iMaxRadius + iHourHandLen * sin(0.017453292*30*iTmpHour);

	CPen newPen;
	CPen * pOldPen;
	newPen.CreatePen(PS_SOLID,3,RGB(255,0,0));
	pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(points[0]);
	pDC->LineTo(points[1]);
	pDC->SelectObject(pOldPen);
	newPen.DeleteObject();
}

/****************************************************************************
函数名称: 画分针
入口参数: pDC     : 表示绘图环境
		  rect    : 表示绘图区域
		  nMinute : 表示当前分数
出口参数: pDC     : 表示绘图环境
返 回 值: (无)
*****************************************************************************/
void CClockST::DrawMinuteHand(CDC *pDC,CRect rect ,int nMinute)
{
	ASSERT(nMinute>=0 && nMinute < 60);
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	//定义时针长度
	int iMinuteHandLen = (iMaxRadius * 4) /5;
	CPoint points[2];
	//定义原点坐标
	points[0].x = iMaxRadius; 
	points[0].y = iMaxRadius;

	points[1].x = iMaxRadius + iMinuteHandLen * cos(0.017453292*6*nMinute);
	points[1].y = iMaxRadius + iMinuteHandLen * sin(0.017453292*6*nMinute);

	CPen newPen;
	CPen * pOldPen;
	newPen.CreatePen(PS_SOLID,2,RGB(0,255,0));
	pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(points[0]);
	pDC->LineTo(points[1]);
	pDC->SelectObject(pOldPen);
	newPen.DeleteObject();
}

/****************************************************************************
函数名称: 画秒针
入口参数: pDC     : 表示绘图环境
		  rect    : 表示绘图区域
		  nSecond : 表示当前秒数
出口参数: pDC     : 表示绘图环境
返 回 值: (无)
*****************************************************************************/
void CClockST::DrawSecondHand(CDC *pDC ,CRect rect ,int nSecond)
{
	ASSERT(nSecond>=0 && nSecond <60);
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	//定义时针长度
	int iSecondHandLen = (iMaxRadius * 9) /10;
	CPoint points[2];
	//定义原点坐标
	points[0].x = iMaxRadius; 
	points[0].y = iMaxRadius;

	points[1].x = iMaxRadius + iSecondHandLen * cos(0.017453292*6*nSecond);
	points[1].y = iMaxRadius + iSecondHandLen * sin(0.017453292*6*nSecond);

	CPen newPen;
	CPen * pOldPen;
	newPen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(points[0]);
	pDC->LineTo(points[1]);
	pDC->SelectObject(pOldPen);
	newPen.DeleteObject();
}

void CClockST::OnPaint() 
{
	CPaintDC dc(this); 
	
	CRect rect;
	GetClientRect(&rect);

	//创建内存绘图环境
	CDC memDC;
	CBitmap memBitmap;
	CBitmap *pOldBitmap;
	memDC.CreateCompatibleDC(&dc) ;
	memBitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height()) ;
	pOldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap) ;

	//得到系统当前时间
	CTime curTime = CTime::GetCurrentTime();
	//画表盘
	DrawDial(&memDC,rect);	
	//画时针
	DrawHourHand(&memDC,&rect,curTime.GetHour());
	//画分钟
	DrawMinuteHand(&memDC,&rect,curTime.GetMinute());	
	//画秒针
	DrawSecondHand(&memDC,&rect,curTime.GetSecond());

	//将内存绘图环境复制到控件当前绘图环境上
	dc.BitBlt(rect.left,rect.top ,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
	
	//释放资源
	memBitmap.DeleteObject();
	memDC.DeleteDC();
}

BOOL CClockST::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL result ;
	//注册窗体类
	static CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW) ;
	//创建窗体类
	result = CWnd::CreateEx(WS_EX_STATICEDGE, 
		className, NULL, dwStyle, 
		rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
		pParentWnd->GetSafeHwnd(), (HMENU)nID) ;

	SetTimer(1,100,NULL);
	return TRUE;	
}	

void CClockST::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(FALSE);
	CWnd::OnTimer(nIDEvent);
}
