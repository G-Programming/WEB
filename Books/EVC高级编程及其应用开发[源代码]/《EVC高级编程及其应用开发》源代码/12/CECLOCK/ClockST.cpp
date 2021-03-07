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
��������: �����̣�Ҳ����ʱ���Բ��
��ڲ���: pDC   : ��ʾ��ͼ����
		  rect  : ��ʾ��ͼ����
���ڲ���: pDC   : ��ʾ��ͼ����
�� �� ֵ: (��)
*****************************************************************************/
void CClockST::DrawDial(CDC *pDC,CRect rect)
{
	CBrush backBrush;
	CBrush *pOldBrush;
	backBrush.CreateSolidBrush(RGB(86,86,209));
	
	pDC->FillRect(&rect,&backBrush);
	backBrush.DeleteObject();

	//�Ȼ�һ��Բ
	pDC->Ellipse(&rect);

	//Ȼ�󣬻������ϵ�12����
	//����Բ�뾶
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	int iMinRadius = iMaxRadius - 5;
	//�ȼ��������������Ϊ0,0
	CPoint pointFace[12];
	CPoint minPointFace[12];
	//����12��������
	for (int i=0;i<12;i++)
	{
		pointFace[i].x = iMaxRadius * cos(0.017453292*i*30);
		pointFace[i].y = iMaxRadius * sin(0.017453292*i*30);

		minPointFace[i].x = iMinRadius * cos(0.017453292*i*30);
		minPointFace[i].y = iMinRadius * sin(0.017453292*i*30);
	}

	//����12������
	for (i=0;i<12;i++)
	{
		pointFace[i].x = pointFace[i].x + iMaxRadius;
		pointFace[i].y = pointFace[i].y + iMaxRadius;

		minPointFace[i].x = minPointFace[i].x + iMaxRadius;
		minPointFace[i].y = minPointFace[i].y + iMaxRadius;
	}

	//���Ʊ����ϵ�12����
	CString strClock;
	for (i=0;i<12;i++)
	{
		strClock.Format(L"%d",i+1);
		pDC->MoveTo(minPointFace[i]);
		pDC->LineTo(pointFace[i]);
	}
}

/****************************************************************************
��������: ��ʱ��
��ڲ���: pDC   : ��ʾ��ͼ����
		  rect  : ��ʾ��ͼ����
		  nHour : ��ʾ��ǰСʱ��
���ڲ���: pDC   : ��ʾ��ͼ����
�� �� ֵ: (��)
*****************************************************************************/
void CClockST::DrawHourHand(CDC *pDC,CRect rect ,int nHour)
{
	ASSERT(nHour>=0 && nHour <24);
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	//����ʱ�볤��
	int iHourHandLen = (iMaxRadius * 3) /5;
	CPoint points[2];
	//����ԭ������
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
��������: ������
��ڲ���: pDC     : ��ʾ��ͼ����
		  rect    : ��ʾ��ͼ����
		  nMinute : ��ʾ��ǰ����
���ڲ���: pDC     : ��ʾ��ͼ����
�� �� ֵ: (��)
*****************************************************************************/
void CClockST::DrawMinuteHand(CDC *pDC,CRect rect ,int nMinute)
{
	ASSERT(nMinute>=0 && nMinute < 60);
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	//����ʱ�볤��
	int iMinuteHandLen = (iMaxRadius * 4) /5;
	CPoint points[2];
	//����ԭ������
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
��������: ������
��ڲ���: pDC     : ��ʾ��ͼ����
		  rect    : ��ʾ��ͼ����
		  nSecond : ��ʾ��ǰ����
���ڲ���: pDC     : ��ʾ��ͼ����
�� �� ֵ: (��)
*****************************************************************************/
void CClockST::DrawSecondHand(CDC *pDC ,CRect rect ,int nSecond)
{
	ASSERT(nSecond>=0 && nSecond <60);
	int iMaxRadius = (rect.bottom - rect.top) / 2;
	//����ʱ�볤��
	int iSecondHandLen = (iMaxRadius * 9) /10;
	CPoint points[2];
	//����ԭ������
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

	//�����ڴ��ͼ����
	CDC memDC;
	CBitmap memBitmap;
	CBitmap *pOldBitmap;
	memDC.CreateCompatibleDC(&dc) ;
	memBitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height()) ;
	pOldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap) ;

	//�õ�ϵͳ��ǰʱ��
	CTime curTime = CTime::GetCurrentTime();
	//������
	DrawDial(&memDC,rect);	
	//��ʱ��
	DrawHourHand(&memDC,&rect,curTime.GetHour());
	//������
	DrawMinuteHand(&memDC,&rect,curTime.GetMinute());	
	//������
	DrawSecondHand(&memDC,&rect,curTime.GetSecond());

	//���ڴ��ͼ�������Ƶ��ؼ���ǰ��ͼ������
	dc.BitBlt(rect.left,rect.top ,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
	
	//�ͷ���Դ
	memBitmap.DeleteObject();
	memDC.DeleteDC();
}

BOOL CClockST::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL result ;
	//ע�ᴰ����
	static CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW) ;
	//����������
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
