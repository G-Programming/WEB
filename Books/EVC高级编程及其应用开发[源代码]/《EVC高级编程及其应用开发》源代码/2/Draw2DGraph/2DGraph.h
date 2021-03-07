#if !defined(AFX_2DGRAPH_H__65719FC0_F152_460E_9897_BA4E53FF956B__INCLUDED_)
#define AFX_2DGRAPH_H__65719FC0_F152_460E_9897_BA4E53FF956B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// 2DGraph.h : header file
//
#include <Afxtempl.h>;
/////////////////////////////////////////////////////////////////////////////
// C2DGraph window

class C2DGraph : public CWnd
{
// Construction
public:
	C2DGraph();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C2DGraph)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~C2DGraph();

	// Generated message map functions
protected:
	//{{AFX_MSG(C2DGraph)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

	//�洢���еĵ�
	CList<CPoint,CPoint&> m_lstPoints;   

	//�����߿��豸����
	CDC m_dcGrid;  
	//���߿��豸��������λͼ
	CBitmap m_bitmapGrid ; 

	//�������ߵ��豸����
	CDC m_dcLine;  
	//�����豸��������λͼ
	CBitmap m_bitmapLine; 
public:
	COLORREF m_crBackColor; //�ؼ�����ɫ
	COLORREF m_crGridColor; //���߿���ɫ
	COLORREF m_crLineColor; //������ɫ
	COLORREF m_crTextColor; //����ı���ɫ

	double m_dXMaxValue ; //X�����ֵ
	double m_dXMinValue ; //X����Сֵ
	double m_dYMaxValue ; //Y�����ֵ
	double m_dYMinValue ; //Y����Сֵ

    LPCTSTR m_strXCaption ; //X�����
	LPCTSTR m_strYCaption ; //Y�����
private:
	//����ˢ�¿ؼ���ʾ
	void InvalidateCtrl();
    //���û���ӵĵ�ֵת������Ļ����
    CPoint GpToSp(CPoint& point);
public:
	//������ĩβ���һ����
	void AppendPoint(double dPointX, double dPointY);
	//ɾ�����ߵ�һ��
	void DeleteFirstPoint();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2DGRAPH_H__65719FC0_F152_460E_9897_BA4E53FF956B__INCLUDED_)
