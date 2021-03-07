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
*函数介绍：画直线 
*入口参数：firstPoint    : 表示开始点
           lastPoint     : 表示上一个点
		   currentPoint  : 表示当前点
*出口参数：(无)
*返回值：(无)
*/
void CDrawExamView::DrawLine(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint)
{
	CDC *pDC = new CClientDC(this);

	//擦去旧线
	pDC->SetROP2(R2_NOT);
	pDC->MoveTo(m_firstPoint);
	pDC->LineTo(m_lastPoint);
	
	//画新线
	pDC->MoveTo(m_firstPoint);
	pDC->LineTo(currentPoint);
	
	delete pDC;
}

/*
*函数介绍：画矩形
*入口参数：firstPoint    : 表示开始点
           lastPoint     : 表示上一个点
		   currentPoint  : 表示当前点
		   filled		 : 表示矩形是否填充
*出口参数：(无)
*返回值：(无)
*/
void CDrawExamView::DrawRectangle(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint,bool filled)
{
	CDC *pDC = new CClientDC(this);

	//创建背景色刷子
	CBrush brush(m_backColor);

	//如果是实心矩形
	if (filled) 
	{
		pDC->SelectObject(brush);
	}
	else
	{
		//创建空刷子
        pDC->SelectStockObject(NULL_BRUSH);
	}
	//擦去旧矩形
	pDC->SetROP2(R2_NOT);
	pDC->Rectangle(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
	
	//画新矩形
	pDC->Rectangle(m_firstPoint.x,m_firstPoint.y,currentPoint.x,currentPoint.y);
	
	//释放刷子GDI对象
	brush.DeleteObject();
	delete pDC;
}

/*
*函数介绍：画圆
*入口参数：firstPoint    : 表示开始点
           lastPoint     : 表示上一个点
		   currentPoint  : 表示当前点
		   filled		 : 表示圆是否填充
*出口参数：(无)
*返回值：(无)
*/
void CDrawExamView::DrawEllipse(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint,bool filled)
 {
	CDC *pDC = new CClientDC(this);

	//创建背景刷子
	CBrush brush(m_backColor);
	
	//如果实心圆
	if (filled) 
	{
		pDC->SelectObject(brush);
	}
	else
	{
		//创建空刷子
        pDC->SelectStockObject(NULL_BRUSH);
	}
	//擦去旧圆
	pDC->SetROP2(R2_NOT);
	pDC->Ellipse(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
	
	//画新圆
	pDC->Ellipse(m_firstPoint.x,m_firstPoint.y,currentPoint.x,currentPoint.y);
	
	//释放刷子GDI对象
	brush.DeleteObject();
	delete pDC;
 }


void CDrawExamView::OnPaint() 
{
	CPaintDC dc(this); 
	CRect rectClient;
	GetClientRect(rectClient);

	//创建m_oldDC设备环境
	if (m_oldDC.GetSafeHdc() == NULL)
	{
		m_oldDC.CreateCompatibleDC(&dc);
		m_oldBmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
		m_oldDC.SelectObject(m_oldBmp);

		CBrush brushBack(RGB(255,255,255));
		m_oldDC.FillRect(rectClient,&brushBack);
		brushBack.DeleteObject();
	}
	
	//创建m_tmpDC设备环境
	if (m_tmpDC.GetSafeHdc() == NULL)
	{
		m_tmpDC.CreateCompatibleDC(&dc);
		m_tmpBmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
		m_tmpDC.SelectObject(m_tmpBmp);
		m_tmpDC.PatBlt(0,0,rectClient.Width(),rectClient.Height(),WHITENESS);
	}
	
	//将m_oldDC设备环境绘制到窗体上
	dc.BitBlt(0,0,rectClient.Width(),rectClient.Height(),&m_oldDC,0,0,SRCCOPY);

}


//鼠标按下左键事件
void CDrawExamView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//标识开始绘图
	m_bBeginDraw = TRUE;
    //设置开始点坐标
	m_firstPoint = point;
	//设置结束点坐标
	m_lastPoint = point;
	//设置鼠标为捕捉状态
	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}

//鼠标移动事件
void CDrawExamView::OnMouseMove(UINT nFlags, CPoint point) 
{
    if (m_bBeginDraw)
	{
		switch (m_drawID)
		{
			//表示处于选择状态
		case 0:
			
			break;
			//表示划直线
		case 1 :
			{
				DrawLine(m_firstPoint,m_lastPoint,point);
				//设置末尾节点
				m_lastPoint = point;
				break;
			}
			//表示画空心矩形
		case 2 :
			{
                DrawRectangle(m_firstPoint,m_lastPoint,point,false);
				m_lastPoint = point;	
				break;
			}
			//表示画实心矩形
		case 3:
			{
                DrawRectangle(m_firstPoint,m_lastPoint,point,true);
				m_lastPoint = point;
				break;
			}
			//表示空心圆
		case 4:
			{
                DrawEllipse(m_firstPoint,m_lastPoint,point,false);
				m_lastPoint = point;
			}
			//表示画实心圆
		case 5:
			{
                DrawEllipse(m_firstPoint,m_lastPoint,point,false);
				m_lastPoint = point;
			}
		}
		
	}
	CView::OnMouseMove(nFlags, point);
}

//鼠标松开事件
void CDrawExamView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    //释放鼠标捕捉
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
	case 1://画新线
		{
			pOldPen = m_tmpDC.SelectObject(&newPen);
			m_tmpDC.MoveTo(m_firstPoint);
			m_tmpDC.LineTo(m_lastPoint);
			
			m_tmpDC.SelectObject(pOldPen);
			break;
		}
	case 2://画空心矩形
		{
			m_tmpDC.SelectStockObject(NULL_BRUSH);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			
			m_tmpDC.Rectangle(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			m_tmpDC.SelectObject(pOldPen);

			break;
		}
	case 3://画实心矩形
		{
			pOldBrush = m_tmpDC.SelectObject(&newBrush);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			
			m_tmpDC.Rectangle(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			m_tmpDC.SelectObject(pOldPen);
			m_tmpDC.SelectObject(pOldBrush);
			break;
		}
	case 4://画空心圆
		{
			m_tmpDC.SelectStockObject(NULL_BRUSH);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			m_tmpDC.Ellipse(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			
			m_tmpDC.SelectObject(pOldPen);
			break;
		}
	case 5://画实心圆
		{			
			pOldBrush = m_tmpDC.SelectObject(&newBrush);
			pOldPen = m_tmpDC.SelectObject(&newPen);
			m_tmpDC.Ellipse(m_firstPoint.x,m_firstPoint.y,m_lastPoint.x,m_lastPoint.y);
			
			m_tmpDC.SelectObject(pOldPen);
			m_tmpDC.SelectObject(pOldBrush);
			break;
		}
	}
	//将m_tmpDC内容绘制到m_oldDC上
	m_oldDC.BitBlt(0, 0, rectClient.Width(), rectClient.Height(), 
		&m_tmpDC, 0, 0, SRCCOPY) ;
	//删除画笔GDI对象
	newPen.DeleteObject();
	//删除画刷GDI对象
	newBrush.DeleteObject();
	//触发窗体重画
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


//设置绘图为选择状态
void CDrawExamView::OnBtnSelect() 
{
   m_drawID = 0 ;
}

//设置绘图为画直线
void CDrawExamView::OnBtnLine() 
{
   m_drawID = 1;
}

//设置绘图为画空心矩形
void CDrawExamView::OnBtnRect() 
{
   m_drawID = 2;	
}

//设置绘图为画实心矩形
void CDrawExamView::OnBtnFilledrect() 
{
	m_drawID = 3;
}

//设置绘图为画空心矩形
void CDrawExamView::OnBtnEllipse() 
{
	m_drawID = 4;
}

//设置绘图为画实心矩形
void CDrawExamView::OnBtnFilledellipsed() 
{
	m_drawID = 5;
}

//设置前景色
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

//设置背景色
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

