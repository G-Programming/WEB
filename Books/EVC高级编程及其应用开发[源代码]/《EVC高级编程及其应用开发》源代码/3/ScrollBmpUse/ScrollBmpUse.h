// ScrollBmpUse.h : main header file for the SCROLLBMPUSE application
//

#if !defined(AFX_SCROLLBMPUSE_H__778FB7A7_3759_4F53_880C_118171336205__INCLUDED_)
#define AFX_SCROLLBMPUSE_H__778FB7A7_3759_4F53_880C_118171336205__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScrollBmpUseApp:
// See ScrollBmpUse.cpp for the implementation of this class
//

class CScrollBmpUseApp : public CWinApp
{
public:
	CScrollBmpUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBmpUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScrollBmpUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLBMPUSE_H__778FB7A7_3759_4F53_880C_118171336205__INCLUDED_)
