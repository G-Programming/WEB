// PlugIn_MainDoc.cpp : implementation of the CPlugIn_MainDoc class
//

#include "stdafx.h"
#include "PlugIn_Main.h"

#include "PlugIn_MainDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainDoc

IMPLEMENT_DYNCREATE(CPlugIn_MainDoc, CDocument)

BEGIN_MESSAGE_MAP(CPlugIn_MainDoc, CDocument)
	//{{AFX_MSG_MAP(CPlugIn_MainDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainDoc construction/destruction

CPlugIn_MainDoc::CPlugIn_MainDoc()
{
	// TODO: add one-time construction code here

}

CPlugIn_MainDoc::~CPlugIn_MainDoc()
{
}

BOOL CPlugIn_MainDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainDoc serialization

void CPlugIn_MainDoc::Serialize(CArchive& ar)
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
// CPlugIn_MainDoc diagnostics

#ifdef _DEBUG
void CPlugIn_MainDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPlugIn_MainDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainDoc commands
