// PlugIn_MainView.h : interface of the CPlugIn_MainView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLUGIN_MAINVIEW_H__4985C205_545A_4F60_B204_541991B88F6B__INCLUDED_)
#define AFX_PLUGIN_MAINVIEW_H__4985C205_545A_4F60_B204_541991B88F6B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPlugIn_MainView : public CView
{
protected: // create from serialization only
	CPlugIn_MainView();
	DECLARE_DYNCREATE(CPlugIn_MainView)

// Attributes
public:
	CPlugIn_MainDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlugIn_MainView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlugIn_MainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlugIn_MainView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PlugIn_MainView.cpp
inline CPlugIn_MainDoc* CPlugIn_MainView::GetDocument()
   { return (CPlugIn_MainDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGIN_MAINVIEW_H__4985C205_545A_4F60_B204_541991B88F6B__INCLUDED_)
