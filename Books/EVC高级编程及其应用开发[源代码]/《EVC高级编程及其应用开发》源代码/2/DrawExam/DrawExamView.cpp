// DrawExamView.cpp : implementation of the CDrawExamView class
//

#include "stdafx.h"
#include "DrawExam.h"

#include "DrawExamDoc.h"
#include "DrawExamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawExamView

IMPLEMENT_DYNCREATE(CDrawExamView, CView)

BEGIN_MESSAGE_MAP(CDrawExamView, CView)
	//{{AFX_MSG_MAP(CDrawExamView)
	ON_COMMAND(ID_BTN_SELECT, OnBtnSelect)
	ON_COMMAND(ID_BTN_LINE, OnBtnLine)
	ON_COMMAND(ID_BTN_RECT, OnBtnRect)
	ON_COMMAND(ID_BTN_FILLEDRECT, OnBtnFilledrect)
	ON_COMMAND(ID_BTN_ELLIPSE, OnBtnEllipse)
	ON_COMMAND(ID_BTN_FILLEDELLIPSED, OnBtnFilledellipsed)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_BTN_FRONTCOLOR1, OnBtnFrontcolor1)
	ON_COMMAND(ID_BTN_FRONTCOLOR2, OnBtnFrontcolor2)
	ON_COMMAND(ID_BTN_FRONTCOLOR3, OnBtnFrontcolor3)
	ON_COMMAND(ID_BTN_FRONTCOLOR4, OnBtnFrontcolor4)
	ON_COMMAND(ID_BTN_FRONTCOLOR5, OnBtnFrontcolor5)
	ON_COMMAND(ID_BTN_FRONTCOLOR6, OnBtnFrontcolor6)
	ON_COMMAND(ID_BTN_FRONTCOLOR7, OnBtnFrontcolor7)
	ON_COMMAND(ID_BTN_FRONTCOLOR8, OnBtnFrontcolor8)
	ON_COMMAND(ID_BTN_BACKCOLOR1, OnBtnBackcolor1)
	ON_COMMAND(ID_BTN_BACKCOLOR2, OnBtnBackcolor2)
	ON_COMMAND(ID_BTN_BACKCOLOR3, OnBtnBackcolor3)
	ON_COMMAND(ID_BTN_BACKCOLOR4, OnBtnBackcolor4)
	ON_COMMAND(ID_BTN_BACKCOLOR5, OnBtnBackcolor5)
	ON_COMMAND(ID_BTN_BACKCOLOR6, OnBtnBackcolor6)
	ON_COMMAND(ID_BTN_BACKCOLOR7, OnBtnBackcolor7)
	ON_COMMAND(ID_BTN_BACKCOLOR8, OnBtnBackcolor8)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawExamView construction/destruction

CDrawExamView::CDrawExamView()
{
	// TODO: add construction code here

}

CDrawExamView::~CDrawExamView()
{
}

BOOL CDrawExamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawExamView drawing

void CDrawExamView::OnDraw(CDC* pDC)
{
	CDrawExamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawExamView diagnostics

#ifdef _DEBUG
void CDrawExamView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawExamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawExamDoc* CDrawExamView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawExamDoc)));
	return (CDrawExamDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawExamView message handlers

/*
*�������ܣ���ֱ�� 
*��ڲ�����firstPoint    : ��ʾ��ʼ��
           lastPoint     : ��ʾ��һ����
		   currentPoint  : ��ʾ��ǰ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CDrawExamView::DrawLine(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint)
{
	CDC *pDC = new CClientDC(this);

	//��ȥ����
	pDC->SetROP2(R2_NOT);
	pDC->MoveTo(m_firstPoint);
	pDC->LineTo(m_lastPoint);
	
	//������
	pDC->MoveTo(m_firstPoint);
	pDC->LineTo(currentPoint);
	
	delete pDC;
}

/*
*�������ܣ�������
*��ڲ�����firstPoint    : ��ʾ��ʼ��
           lastPoint     : ��ʾ��һ����
		   currentPoint  : ��ʾ��ǰ��
		   filled		 : ��ʾ�����Ƿ����
*���ڲ�����(��)
*����ֵ��(��)
*/
void CDrawExamView::DrawRectangle(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint,bool filled)
{
	CDC *pDC = new CClientDC(this);

	//��������ɫˢ��
	CBrush brush(m_backColor);

	//�����ʵ�ľ���
	if (filled) 
	{
		pDC->SelectObject(brush);
	}
	else
	{
		//������ˢ��
        pDC->SelectStockObject(NULL_BRUSH);
	}
	//��ȥ�ɾ���
	pDC->SetROP2(R2_NOT);
	pDC->Rectangle(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
	
	//���¾���
	pDC->Rectangle(m_firstPoint.x,m_firstPoint.y,currentPoint.x,currentPoint.y);
	
	//�ͷ�ˢ��GDI����
	brush.DeleteObject();
	delete pDC;
}

/*
*�������ܣ���Բ
*��ڲ�����firstPoint    : ��ʾ��ʼ��
           lastPoint     : ��ʾ��һ����
		   currentPoint  : ��ʾ��ǰ��
		   filled		 : ��ʾԲ�Ƿ����
*���ڲ�����(��)
*����ֵ��(��)
*/
void CDrawExamView::DrawEllipse(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint,bool filled)
 {
	CDC *pDC = new CClientDC(this);

	//��������ˢ��
	CBrush brush(m_backColor);
	
	//���ʵ��Բ
	if (filled) 
	{
		pDC->SelectObject(brush);
	}
	else
	{
		//������ˢ��
        pDC->SelectStockObject(NULL_BRUSH);
	}
	//��ȥ��Բ
	pDC->SetROP2(R2_NOT);
	pDC->Ellipse(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
	
	//����Բ
	pDC->Ellipse(m_firstPoint.x,m_firstPoint.y,currentPoint.x,currentPoint.y);
	
	//�ͷ�ˢ��GDI����
	brush.DeleteObject();
	delete pDC;
 }


void CDrawExamView::OnPaint() 
{
	CPaintDC dc(this); 
	CRect rectClient;
	GetClientRect(rectClient);

	//����m_oldDC�豸����
	if (m_oldDC.GetSafeHdc() == NULL)
	{
		m_oldDC.CreateCompatibleDC(&dc);
		m_oldBmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
		m_oldDC.SelectObject(m_oldBmp);

		CBrush brushBack(RGB(255,255,255));
		m_oldDC.FillRect(rectClient,&brushBack);
		brushBack.DeleteObject();
	}
	
	//����m_tmpDC�豸����
	if (m_tmpDC.GetSafeHdc() == NULL)
	{
		m_tmpDC.CreateCompatibleDC(&dc);
		m_tmpBmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
		m_tmpDC.SelectObject(m_tmpBmp);
		m_tmpDC.PatBlt(0,0,rectClient.Width(),rectClient.Height(),WHITENESS);
	}
	
	//��m_oldDC�豸�������Ƶ�������
	dc.BitBlt(0,0,rectClient.Width(),rectClient.Height(),&m_oldDC,0,0,SRCCOPY);

}


//��갴������¼�
void CDrawExamView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//��ʶ��ʼ��ͼ
	m_bBeginDraw = TRUE;
    //���ÿ�ʼ������
	m_firstPoint = point;
	//���ý���������
	m_lastPoint = point;
	//�������Ϊ��׽״̬
	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}

//����ƶ��¼�
void CDrawExamView::OnMouseMove(UINT nFlags, CPoint point) 
{
    if (m_bBeginDraw)
	{
		switch (m_drawID)
		{
			//��ʾ����ѡ��״̬
		case 0:
			
			break;
			//��ʾ��ֱ��
		case 1 :
			{
				DrawLine(m_firstPoint,m_lastPoint,point);
				//����ĩβ�ڵ�
				m_lastPoint = point;
				break;
			}
			//��ʾ�����ľ���
		case 2 :
			{
                DrawRectangle(m_firstPoint,m_lastPoint,point,false);
				m_lastPoint = point;	
				break;
			}
			//��ʾ��ʵ�ľ���
		case 3:
			{
                DrawRectangle(m_firstPoint,m_lastPoint,point,true);
				m_lastPoint = point;
				break;
			}
			//��ʾ����Բ
		case 4:
			{
                DrawEllipse(m_firstPoint,m_lastPoint,point,false);
				m_lastPoint = point;
			}
			//��ʾ��ʵ��Բ
		case 5:
			{
                DrawEllipse(m_firstPoint,m_lastPoint,point,false);
				m_lastPoint = point;
			}
		}
		
	}
	CView::OnMouseMove(nFlags, point);
}

//����ɿ��¼�
void CDrawExamView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    //�ͷ���겶׽
	ReleaseCapture();
	m_bBeginDraw = false;
	CRect rectClient;
	GetClientRect(&rectClient);
	CPen newPen(PS_SOLID,1,m_frontColor);
	CBrush newBrush(m_backColor);	
	CPen *pOldPen;
	CBrush *pOldBrush;
	switch(m_drawID)
	{
	case 1://������
		{
			pOldPen = m_tmpDC.SelectObject(&newPen);
			m_tmpDC.MoveTo(m_firstPoint);
			m_tmpDC.LineTo(m_lastPoint);
			
			m_tmpDC.SelectObject(pOldPen);
			break;
		}
	case 2://�����ľ���
		{
			m_tmpDC.SelectStockObject(NULL_BRUSH);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			
			m_tmpDC.Rectangle(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			m_tmpDC.SelectObject(pOldPen);

			break;
		}
	case 3://��ʵ�ľ���
		{
			pOldBrush = m_tmpDC.SelectObject(&newBrush);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			
			m_tmpDC.Rectangle(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			m_tmpDC.SelectObject(pOldPen);
			m_tmpDC.SelectObject(pOldBrush);
			break;
		}
	case 4://������Բ
		{
			m_tmpDC.SelectStockObject(NULL_BRUSH);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			m_tmpDC.Ellipse(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			
			m_tmpDC.SelectObject(pOldPen);
			break;
		}
	case 5://��ʵ��Բ
		{			
			pOldBrush = m_tmpDC.SelectObject(&newBrush);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			m_tmpDC.Ellipse(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			
			m_tmpDC.SelectObject(pOldPen);
			m_tmpDC.SelectObject(pOldBrush);
			break;
		}
	}
	//��m_tmpDC���ݻ��Ƶ�m_oldDC��
	m_oldDC.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
		&m_tmpDC, 0, 0, SRCCOPY) ;
	//ɾ������GDI����
	newPen.DeleteObject();
	//ɾ����ˢGDI����
	newBrush.DeleteObject();
	//���������ػ�
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


//���û�ͼΪѡ��״̬
void CDrawExamView::OnBtnSelect() 
{
   m_drawID = 0 ;
}

//���û�ͼΪ��ֱ��
void CDrawExamView::OnBtnLine() 
{
   m_drawID = 1;
}

//���û�ͼΪ�����ľ���
void CDrawExamView::OnBtnRect() 
{
   m_drawID = 2;	
}

//���û�ͼΪ��ʵ�ľ���
void CDrawExamView::OnBtnFilledrect() 
{
	m_drawID = 3;
}

//���û�ͼΪ�����ľ���
void CDrawExamView::OnBtnEllipse() 
{
	m_drawID = 4;
}

//���û�ͼΪ��ʵ�ľ���
void CDrawExamView::OnBtnFilledellipsed() 
{
	m_drawID = 5;
}

//����ǰ��ɫ
void CDrawExamView::OnBtnFrontcolor1() 
{
	m_frontColor  = RGB(0,0,0);
}

void CDrawExamView::OnBtnFrontcolor2() 
{
	m_frontColor  = RGB(255,255,255);
}

void CDrawExamView::OnBtnFrontcolor3() 
{
	m_frontColor  = RGB(255,0,0);
}

void CDrawExamView::OnBtnFrontcolor4() 
{
	m_frontColor  = RGB(0,255,0);
	
}

void CDrawExamView::OnBtnFrontcolor5() 
{
	m_frontColor  = RGB(0,0,255);
	
}

void CDrawExamView::OnBtnFrontcolor6() 
{
	m_frontColor  = RGB(0,255,255);
}

void CDrawExamView::OnBtnFrontcolor7() 
{
	m_frontColor  = RGB(255,0,255);
}

void CDrawExamView::OnBtnFrontcolor8() 
{
	m_frontColor  = RGB(255,255,0);
}

//���ñ���ɫ
void CDrawExamView::OnBtnBackcolor1() 
{
	m_backColor  = RGB(0,0,0);
}

void CDrawExamView::OnBtnBackcolor2() 
{
	m_backColor  = RGB(255,255,255);
}

void CDrawExamView::OnBtnBackcolor3() 
{
	m_backColor  = RGB(255,0,0);
}

void CDrawExamView::OnBtnBackcolor4() 
{
	m_backColor  = RGB(0,255,0);
	
}

void CDrawExamView::OnBtnBackcolor5() 
{
	m_backColor  = RGB(0,0,255);
	
}

void CDrawExamView::OnBtnBackcolor6() 
{
	m_backColor  = RGB(0,255,255);
}

void CDrawExamView::OnBtnBackcolor7() 
{
	m_backColor  = RGB(255,0,255);
}

void CDrawExamView::OnBtnBackcolor8() 
{
	m_backColor  = RGB(255,255,0);
}

