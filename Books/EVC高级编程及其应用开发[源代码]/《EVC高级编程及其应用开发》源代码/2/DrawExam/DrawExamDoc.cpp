// DrawExamDoc.cpp : implementation of the CDrawExamDoc class
//

#include "stdafx.h"
#include "DrawExam.h"

#include "DrawExamDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawExamDoc

IMPLEMENT_DYNCREATE(CDrawExamDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawExamDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawExamDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawExamDoc construction/destruction

CDrawExamDoc::CDrawExamDoc()
{
	// TODO: add one-time construction code here

}

CDrawExamDoc::~CDrawExamDoc()
{
}

BOOL CDrawExamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawExamDoc serialization

void CDrawExamDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDrawExamDoc diagnostics

#ifdef _DEBUG
void CDrawExamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawExamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawExamDoc commands
