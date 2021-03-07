// DrawExamView.h : interface of the CDrawExamView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWEXAMVIEW_H__56755944_C596_4037_8922_664721B42434__INCLUDED_)
#define AFX_DRAWEXAMVIEW_H__56755944_C596_4037_8922_664721B42434__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDrawExamView : public CView
{
protected: // create from serialization only
	CDrawExamView();
	DECLARE_DYNCREATE(CDrawExamView)

// Attributes
public:
	CDrawExamDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawExamView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawExamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawExamView)
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnLine();
	afx_msg void OnBtnRect();
	afx_msg void OnBtnFilledrect();
	afx_msg void OnBtnEllipse();
	afx_msg void OnBtnFilledellipsed();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBtnFrontcolor1();
	afx_msg void OnBtnFrontcolor2();
	afx_msg void OnBtnFrontcolor3();
	afx_msg void OnBtnFrontcolor4();
	afx_msg void OnBtnFrontcolor5();
	afx_msg void OnBtnFrontcolor6();
	afx_msg void OnBtnFrontcolor7();
	afx_msg void OnBtnFrontcolor8();
	afx_msg void OnBtnBackcolor1();
	afx_msg void OnBtnBackcolor2();
	afx_msg void OnBtnBackcolor3();
	afx_msg void OnBtnBackcolor4();
	afx_msg void OnBtnBackcolor5();
	afx_msg void OnBtnBackcolor6();
	afx_msg void OnBtnBackcolor7();
	afx_msg void OnBtnBackcolor8();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//���ñ�ʶ
	DWORD m_drawID ; 
	//��ͼ��ʼ��
	CPoint m_firstPoint;
	//��ͼ������
	CPoint m_lastPoint;
	//��ʾ��ʼ��ͼ
	bool m_bBeginDraw;
	//����ɫ
	COLORREF m_frontColor; 
	//����ɫ
	COLORREF m_backColor;  

	//���û�ͼ�豸����
	CDC  m_oldDC;
	CBitmap m_oldBmp;

	//���û�ͼ�豸����
	CDC  m_tmpDC;
	CBitmap m_tmpBmp;
private:
	//��ֱ��
	void DrawLine(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint);
    //������
	void DrawRectangle(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint,bool filled);
    //��Բ
	void DrawEllipse(CPoint firstPoint,CPoint lastPoint,CPoint currentPoint,bool filled);
};

#ifndef _DEBUG  // debug version in DrawExamView.cpp
inline CDrawExamDoc* CDrawExamView::GetDocument()
   { return (CDrawExamDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWEXAMVIEW_H__56755944_C596_4037_8922_664721B42434__INCLUDED_)
