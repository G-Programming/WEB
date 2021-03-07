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

	//存储线中的点
	CList<CPoint,CPoint&> m_lstPoints;   

	//画表格边框设备环境
	CDC m_dcGrid;  
	//表格边框设备环境缓冲位图
	CBitmap m_bitmapGrid ; 

	//用来画线的设备环境
	CDC m_dcLine;  
	//画线设备环境缓冲位图
	CBitmap m_bitmapLine; 
public:
	COLORREF m_crBackColor; //控件背景色
	COLORREF m_crGridColor; //表格边框颜色
	COLORREF m_crLineColor; //曲线颜色
	COLORREF m_crTextColor; //输出文本颜色

	double m_dXMaxValue ; //X轴最大值
	double m_dXMinValue ; //X轴最小值
	double m_dYMaxValue ; //Y轴最大值
	double m_dYMinValue ; //Y轴最小值

    LPCTSTR m_strXCaption ; //X轴标题
	LPCTSTR m_strYCaption ; //Y轴标题
private:
	//用于刷新控件显示
	void InvalidateCtrl();
    //将用户添加的点值转换成屏幕坐标
    CPoint GpToSp(CPoint& point);
public:
	//在曲线末尾添加一个点
	void AppendPoint(double dPointX, double dPointY);
	//删除曲线第一点
	void DeleteFirstPoint();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_2DGRAPH_H__65719FC0_F152_460E_9897_BA4E53FF956B__INCLUDED_)
