// AnimateDraw.h : main header file for the ANIMATEDRAW application
//

#if !defined(AFX_ANIMATEDRAW_H__7720B831_7F3D_4DB1_B58A_8ABDD85E9B76__INCLUDED_)
#define AFX_ANIMATEDRAW_H__7720B831_7F3D_4DB1_B58A_8ABDD85E9B76__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnimateDrawApp:
// See AnimateDraw.cpp for the implementation of this class
//

class CAnimateDrawApp : public CWinApp
{
public:
	CAnimateDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnimateDrawApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATEDRAW_H__7720B831_7F3D_4DB1_B58A_8ABDD85E9B76__INCLUDED_)
