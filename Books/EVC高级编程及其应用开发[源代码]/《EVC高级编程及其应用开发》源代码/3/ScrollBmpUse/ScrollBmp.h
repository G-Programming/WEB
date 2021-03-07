#if !defined(AFX_SCROLLBMP_H__EFA04A27_BC09_4D9D_BEEE_BBC11197695E__INCLUDED_)
#define AFX_SCROLLBMP_H__EFA04A27_BC09_4D9D_BEEE_BBC11197695E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ScrollBmp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScrollBmp window

class CScrollBmp : public CWnd
{
// Construction
public:
	CScrollBmp();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBmp)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScrollBmp();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScrollBmp)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CScrollBar	m_vbar;			//竖直滚动条
	CScrollBar	m_hbar;			//水平滚动条

	CDC m_dcMem;				//内存设备环境，用于绘制位图
	
	HBITMAP m_hBmpOld;			// 保存旧的Bitmap对象句柄
	HBITMAP m_hBmpNew;			// 保存新的Bitmap对象句柄
   
	CRect m_rectStaticClient;	//存储bmp显示控件的大小

	BOOL m_erase;				//代表是否擦除

	int m_offsetX,m_offsetY;	//代表显示位图的偏移量
	int m_sourceX, m_sourceY;	//代表显示位图时，源位图的开始点
public:
	//初始化滚动位图显示控件
	void InitBmpCtrl(); 
	//根据文件名加载图片
	BOOL LoadBmp(LPTSTR lpszResourceName);
	//根据位图资源ID加载图片
	BOOL LoadBmp(UINT nIDResource);
private:
	void LoadBmpToCtrl();

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLBMP_H__EFA04A27_BC09_4D9D_BEEE_BBC11197695E__INCLUDED_)
