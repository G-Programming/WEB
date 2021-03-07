// Draw2DGraph.h : main header file for the DRAW2DGRAPH application
//

#if !defined(AFX_DRAW2DGRAPH_H__22319C1A_E412_4BF7_A47A_8D3F2E4BB75B__INCLUDED_)
#define AFX_DRAW2DGRAPH_H__22319C1A_E412_4BF7_A47A_8D3F2E4BB75B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDraw2DGraphApp:
// See Draw2DGraph.cpp for the implementation of this class
//

class CDraw2DGraphApp : public CWinApp
{
public:
	CDraw2DGraphApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraw2DGraphApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDraw2DGraphApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAW2DGRAPH_H__22319C1A_E412_4BF7_A47A_8D3F2E4BB75B__INCLUDED_)
