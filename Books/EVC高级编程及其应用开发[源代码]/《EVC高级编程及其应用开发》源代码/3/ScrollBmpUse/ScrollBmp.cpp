// ScrollBmp.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ScrollBmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollBmp

CScrollBmp::CScrollBmp()
{
}

CScrollBmp::~CScrollBmp()
{
}


BEGIN_MESSAGE_MAP(CScrollBmp, CWnd)
	//{{AFX_MSG_MAP(CScrollBmp)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CScrollBmp message handlers

//初始化滚动位图显示控件
void CScrollBmp::InitBmpCtrl()
{
	CClientDC dc(this);
	//创建位图显示内存环境变量
	m_dcMem.CreateCompatibleDC( &dc );
   
	CRect tmpRect;
	GetClientRect(tmpRect);
	//创建位图显示控件底部滚动条
	m_hbar.Create(SBS_HORZ | WS_CHILD | WS_VISIBLE, 
      CRect(tmpRect.left,tmpRect.bottom-10,tmpRect.right, tmpRect.bottom), this, 100);
    //创建位图显示控件右边滚动条
	m_vbar.Create(SBS_VERT  | WS_CHILD | WS_VISIBLE, 
      CRect(tmpRect.right-10,tmpRect.top,tmpRect.right, tmpRect.bottom-10), this, 101);
	
	m_hbar.ShowWindow(false);  
	m_vbar.ShowWindow(false);
}

//根据位图名加载位图
BOOL CScrollBmp::LoadBmp(LPTSTR lpszResourceName)
{
	if(m_hBmpNew != NULL )
	DeleteObject(m_hBmpNew);
	
	m_hBmpNew = SHLoadDIBitmap(lpszResourceName);
	if( m_hBmpNew == NULL )
	{
		AfxMessageBox(_T("加载位图失败"));
		return FALSE;
	}
	LoadBmpToCtrl();
	return TRUE;
}

//根据位图资源ID加载位图
BOOL CScrollBmp::LoadBmp(UINT nIDResource)
{
	if(m_hBmpNew != NULL )
	DeleteObject(m_hBmpNew);
	
	m_hBmpNew = LoadBitmap(AfxGetResourceHandle(),MAKEINTRESOURCE(nIDResource));
	if( m_hBmpNew == NULL )
	{
		AfxMessageBox(_T("加载位图失败"));
		return FALSE;
	}
	LoadBmpToCtrl();
	return TRUE;
}

//将位图加载到控件上显示
void CScrollBmp::LoadBmpToCtrl()
{
	BITMAP bmInfo;        // bmp位图信息结构
	CPoint pt; 
	SCROLLINFO horz,vert;
	
	m_sourceX=m_sourceY=0;
	
	//得到滚动位图显示控件大小
	GetClientRect( &m_rectStaticClient );
	m_rectStaticClient.NormalizeRect();
	
	pt.x = m_rectStaticClient.left;
	pt.y = m_rectStaticClient.top;

	//得到位图信息，存储到bmInfo
	GetObject(m_hBmpNew , sizeof(BITMAP), &bmInfo );
	VERIFY(m_hBmpOld = (HBITMAP)SelectObject(m_dcMem, m_hBmpNew )  );

	m_offsetX= pt.x;
	m_offsetY=pt.y;

	horz.cbSize = sizeof(SCROLLINFO);
	horz.fMask = SIF_ALL;
	horz.nMin = 0;
	horz.nMax = bmInfo.bmWidth-m_rectStaticClient.Width();
	horz.nPage =0;
	horz.nPos = 0;
	horz.nTrackPos=0;
	
	//设置底部和右边滚动条
	if(bmInfo.bmWidth<=m_rectStaticClient.Width())
	{
		if((m_rectStaticClient.Width()-bmInfo.bmWidth)==0)
			m_offsetX= pt.x;
		else
			m_offsetX= pt.x+((m_rectStaticClient.Width()-bmInfo.bmWidth)/2);
		m_vbar.MoveWindow(m_offsetX+bmInfo.bmWidth,m_offsetY,18,m_rectStaticClient.Height());
		m_hbar.ShowWindow(false);
	}
	else
		m_hbar.ShowWindow(true);
	m_hbar.SetScrollInfo(&horz);

	vert.cbSize = sizeof(SCROLLINFO);
	vert.fMask = SIF_ALL;
	vert.nMin = 0;
	vert.nMax = bmInfo.bmHeight-(m_rectStaticClient.Height());
	vert.nPage = 0;
	vert.nPos = 0;
	vert.nTrackPos= 0;
	if(bmInfo.bmHeight<=m_rectStaticClient.Height())
	{
		if((m_rectStaticClient.Height()-bmInfo.bmHeight)==0)
			m_offsetY= pt.y;
		else
			m_offsetY= pt.y+((m_rectStaticClient.Height()-bmInfo.bmHeight)/2);
		m_hbar.MoveWindow(m_offsetX,m_offsetY+bmInfo.bmHeight,m_rectStaticClient.Width(),18);
		m_vbar.ShowWindow(false);
	}
	else
		m_vbar.ShowWindow(true);
	m_vbar.SetScrollInfo(&vert);
	
	//更新显示
	InvalidateRect(&m_rectStaticClient);
}

//水平滚动事件
void CScrollBmp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
	case SB_TOP:
		m_sourceX = 0;
		break;
	case SB_BOTTOM:
		m_sourceX = INT_MAX;
		break;
	case SB_THUMBTRACK:
		m_sourceX= nPos;
		break;
	}	
	m_hbar.SetScrollPos(m_sourceX);
	m_erase=true;
	InvalidateRect(&m_rectStaticClient);

	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

//竖直滚动事件
void CScrollBmp::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	switch (nSBCode)
	{
	case SB_TOP:
		m_sourceY = 0;
		break;
	case SB_BOTTOM:
		m_sourceY = INT_MAX;
		break;
	case SB_THUMBTRACK:
		m_sourceY = nPos;
		break;
	}
	m_vbar.SetScrollPos(m_sourceY);
    m_erase=true;
    InvalidateRect(&m_rectStaticClient);
	
	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CScrollBmp::OnPaint() 
{
	CPaintDC dc(this); // device context for painting


	//显示指定位置的图片
	dc.BitBlt(m_offsetX,m_offsetY,m_rectStaticClient.Width()-10,m_rectStaticClient.Height()-10, 
                   &m_dcMem, m_sourceX, m_sourceY,SRCCOPY);

	m_erase=false;	
}

BOOL CScrollBmp::OnEraseBkgnd(CDC* pDC) 
{
	if(m_erase)
		return false;
	else	
	return CWnd::OnEraseBkgnd(pDC);	
}
