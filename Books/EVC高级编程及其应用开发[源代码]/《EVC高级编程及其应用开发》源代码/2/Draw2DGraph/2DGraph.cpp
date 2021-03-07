// 2DGraph.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "2DGraph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C2DGraph

C2DGraph::C2DGraph()
{
    //��ʼ���ؼ�����
	m_crBackColor = RGB(0,0,0);
	m_crGridColor = RGB(0,255,255);
	m_crLineColor = RGB(255,0,255);
	m_crTextColor = RGB(255,0,255);
	
	m_strXCaption = _T("X��");
	m_strYCaption = _T("Y��");
	m_dXMaxValue = 10;
	m_dXMinValue = 0;
	m_dYMaxValue = 10;
	m_dYMinValue = 0; 
}

C2DGraph::~C2DGraph()
{
}


BEGIN_MESSAGE_MAP(C2DGraph, CWnd)
//{{AFX_MSG_MAP(C2DGraph)
ON_WM_PAINT()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// C2DGraph message handlers

BOOL C2DGraph::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	BOOL result ;
	//ע�ᴰ����
	static CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW) ;
	//����������
	result = CWnd::CreateEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 
		className, NULL, dwStyle, 
		rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top,
		pParentWnd->GetSafeHwnd(), (HMENU)nID) ;
	//���´�����ʾ
	if (result != 0)
		InvalidateCtrl() ;	
	return TRUE;
}

void C2DGraph::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rectClient;
	GetClientRect(rectClient) ;
	
	CDC memDC ;
	CBitmap memBitmap ;
	CBitmap* oldBitmap ; 
	
	memDC.CreateCompatibleDC(&dc) ;
	memBitmap.CreateCompatibleBitmap(&dc, rectClient.Width(), rectClient.Height()) ;
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap) ;
	
	//��m_dcGrid��m_dcLine���Ƶ��ؼ���
	if (memDC.GetSafeHdc() != NULL)
	{
		memDC.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
			         &m_dcGrid, 0, 0, SRCCOPY) ;
		memDC.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
			         &m_dcLine, 0, 0, SRCPAINT) ;
		
		dc.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
			&memDC, 0, 0, SRCCOPY) ;
	}
	
	memDC.SelectObject(oldBitmap) ;		
	
	//ɾ���ڴ�λͼGDI����
	memBitmap.DeleteObject();
	//ɾ���ڴ��ͼ����
	memDC.DeleteDC();
}

//���û���ӵĵ�ֵת������Ļ����
CPoint C2DGraph::GpToSp(CPoint& point)
{
	CPoint rPoint;
   	CRect rectClient;
	CRect rectLine;
	
	GetClientRect(rectClient) ;
	rectLine.left = rectClient.left + 20;
	rectLine.right = rectClient.right - 10;
	rectLine.top = rectClient.top + 10;
	rectLine.bottom = rectClient.bottom - 20;
	rPoint.x = rectLine.left + (point.x / (m_dXMaxValue - m_dXMinValue))*rectLine.Width();
	rPoint.y = rectLine.top + (1 - point.y / (m_dYMaxValue - m_dYMinValue))*rectLine.Height(); 
	return rPoint;
}

//����ˢ�¿ؼ���ʾ
void C2DGraph::InvalidateCtrl()
{
    CPen *oldPen;
	CPen solidPen(PS_SOLID,0,m_crGridColor);
    CFont xFont,yFont,*oldFont;
	CBrush brushBack;
	brushBack.CreateSolidBrush(m_crBackColor) ;
	
	CRect rectClient;
	GetClientRect(rectClient);
	
	CClientDC dc(this);
	
	//��������豸�����Լ�������Ӧ������
	if (m_dcGrid.GetSafeHdc() == NULL)
	{
		m_dcGrid.CreateCompatibleDC(&dc);
		m_bitmapGrid.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
		m_dcGrid.SelectObject(&m_bitmapGrid);
	}
	
	//���ñ�����ɫ
	m_dcGrid.SetBkColor(m_crBackColor);
	m_dcGrid.FillRect(rectClient,&brushBack);
	
	//���߿�
	oldPen = m_dcGrid.SelectObject(&solidPen);
	m_dcGrid.MoveTo(rectClient.left + 20,rectClient.top + 10);
	m_dcGrid.LineTo(rectClient.right - 10,rectClient.top + 10);
	m_dcGrid.LineTo (rectClient.right - 10,rectClient.bottom - 20) ;
	m_dcGrid.LineTo (rectClient.left + 20 , rectClient.bottom - 20) ;
	m_dcGrid.LineTo (rectClient.left + 20 , rectClient.top  + 10) ;
	
	m_dcGrid.SelectObject(oldPen);
	
	//����Y������
	yFont.CreateFont (14, 0, 900, 0, 300,
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, _T("����")) ;
	
	//����X������
	xFont.CreateFont (14, 0, 0, 0, 300,
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, _T("����")) ;
	
	//��Y�������
	m_dcGrid.SetTextColor(m_crTextColor);
	oldFont = m_dcGrid.SelectObject(&yFont);
	m_dcGrid.ExtTextOut (rectClient.left + 2, 
		(rectClient.top + rectClient.bottom ) / 2 + 5, ETO_CLIPPED,NULL,m_strYCaption,wcslen(m_strYCaption),NULL) ;
	
	//��Y�������ֵ
	CString strTmp;
	strTmp.Format(_T("%.2f"),m_dYMaxValue);
	m_dcGrid.ExtTextOut (rectClient.left+5  , 
		rectClient.top + 40 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��Y������Сֵ
	strTmp.Format(_T("%.2f"),m_dYMinValue);
	m_dcGrid.ExtTextOut (rectClient.left+5 , 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��X�������
	oldFont = m_dcGrid.SelectObject(&xFont);
	m_dcGrid.ExtTextOut ((rectClient.left+ rectClient.right)/2 - 5, 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL,m_strXCaption,wcslen(m_strXCaption) ,NULL) ;
	
	//��X�������ֵ
	strTmp.Format(_T("%.2f"),m_dXMaxValue);
	m_dcGrid.ExtTextOut (rectClient.right - 40, 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	//��X������Сֵ
	strTmp.Format(_T("%.2f"),m_dXMinValue);
	m_dcGrid.ExtTextOut (rectClient.left + 20, 
		rectClient.bottom - 18 , ETO_CLIPPED,NULL
		,strTmp,strTmp.GetLength(),NULL) ;
	
	
	m_dcGrid.SelectObject(oldFont);
	
	//���������豸�����Լ�������Ӧ������
	if (m_dcLine.GetSafeHdc() == NULL)
	{
		m_dcLine.CreateCompatibleDC(&dc) ;
		m_bitmapLine.CreateCompatibleBitmap(&dc, rectClient.Width(), rectClient.Height()) ;
		m_dcLine.SelectObject(&m_bitmapLine) ;
	}
	
	m_dcLine.SetBkColor (m_crBackColor) ;
	m_dcLine.FillRect(rectClient, &brushBack) ;

	//ɾ��������GDI����
	solidPen.DeleteObject();
	xFont.DeleteObject();
	yFont.DeleteObject();
	brushBack.DeleteObject();
}

//������ĩβ���һ����
void C2DGraph::AppendPoint(double dPointX, double dPointY)
{
	CPen *oldPen;
	CRect rectCleanUp;
	CPoint points[2];
	CPen penLine;
	penLine.CreatePen(PS_SOLID, 0, m_crLineColor) ;
	
    m_lstPoints.AddTail(CPoint(dPointX,dPointY));	
	oldPen = m_dcLine.SelectObject(&penLine) ;
	if (m_dcLine.GetSafeHdc() != NULL)
	{
		if (m_lstPoints.GetCount() == 0 )
		{
			
		}
		//����ǵ�1����
		else if (m_lstPoints.GetCount() == 1) 
		{
			POSITION pos = m_lstPoints.GetHeadPosition();
			points[0] = m_lstPoints.GetAt(pos);
            points[0] = GpToSp(points[0]);
			m_dcLine.SetPixel(points[0],m_crLineColor);
		}
		//������ڻ����2����
		else
		{
			POSITION pos = m_lstPoints.GetTailPosition();
			points[0] = m_lstPoints.GetPrev(pos);
			points[1] = m_lstPoints.GetPrev(pos);
			points[0] = GpToSp(points[0]);
			points[1] = GpToSp(points[1]);
			
			m_dcLine.MoveTo (points[0].x, points[0].y) ;	
			m_dcLine.LineTo (points[1].x,points[1].y) ;
		}
	}
	m_dcLine.SelectObject(oldPen) ;
	//ɾ������GDI����
	penLine.DeleteObject();
	//������ʾ
	Invalidate();
}

//ɾ�����ߵ�һ��
void C2DGraph::DeleteFirstPoint()
{
	CPen *oldPen ;
	CPoint points[2];
	CPen deletePen(PS_SOLID,1,m_crBackColor);
	
	if (m_dcLine.GetSafeHdc() != NULL)
	{
		//���������ֻ��һ����
		if (m_lstPoints.GetCount() == 1)
		{
			POSITION pos = m_lstPoints.GetHeadPosition();
			points[0] = m_lstPoints.GetNext(pos);
			points[0] = GpToSp(points[0]);
			
			m_dcLine.SetPixel(points[0],m_crBackColor);
			m_lstPoints.RemoveHead();
		}
		//��������к��д��ڻ����2����
		else if (m_lstPoints.GetCount() >= 2)
		{
			POSITION pos = m_lstPoints.GetHeadPosition();
			points[0] = m_lstPoints.GetNext(pos);
			points[1] = m_lstPoints.GetNext(pos);
			points[0] = GpToSp(points[0]);
			points[1] = GpToSp(points[1]);
			
			oldPen = m_dcLine.SelectObject(&deletePen);
			m_dcLine.MoveTo (points[0].x, points[0].y) ;	
			m_dcLine.LineTo (points[1].x, points[1].y) ;
			m_dcLine.SelectObject(oldPen);
			m_lstPoints.RemoveHead();
		}
	}
	//ɾ������GDI����
	deletePen.DeleteObject();
	//������ʾ
	Invalidate();		
}



