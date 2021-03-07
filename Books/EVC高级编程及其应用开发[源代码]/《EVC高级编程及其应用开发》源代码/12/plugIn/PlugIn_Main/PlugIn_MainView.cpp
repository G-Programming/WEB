// PlugIn_MainView.cpp : implementation of the CPlugIn_MainView class
//

#include "stdafx.h"
#include "PlugIn_Main.h"

#include "PlugIn_MainDoc.h"
#include "PlugIn_MainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainView

IMPLEMENT_DYNCREATE(CPlugIn_MainView, CView)

BEGIN_MESSAGE_MAP(CPlugIn_MainView, CView)
	//{{AFX_MSG_MAP(CPlugIn_MainView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainView construction/destruction

CPlugIn_MainView::CPlugIn_MainView()
{
	// TODO: add construction code here

}

CPlugIn_MainView::~CPlugIn_MainView()
{
}

BOOL CPlugIn_MainView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainView drawing

void CPlugIn_MainView::OnDraw(CDC* pDC)
{
	CPlugIn_MainDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainView diagnostics

#ifdef _DEBUG
void CPlugIn_MainView::AssertValid() const
{
	CView::AssertValid();
}

void CPlugIn_MainView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlugIn_MainDoc* CPlugIn_MainView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlugIn_MainDoc)));
	return (CPlugIn_MainDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainView message handlers
