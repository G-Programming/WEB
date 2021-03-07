// CEDBUse.h : main header file for the CEDBUSE application
//

#if !defined(AFX_CEDBUSE_H__5D7A0921_A841_4A0B_B381_A30CBED82836__INCLUDED_)
#define AFX_CEDBUSE_H__5D7A0921_A841_4A0B_B381_A30CBED82836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCEDBUseApp:
// See CEDBUse.cpp for the implementation of this class
//

class CCEDBUseApp : public CWinApp
{
public:
	CCEDBUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCEDBUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCEDBUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEDBUSE_H__5D7A0921_A841_4A0B_B381_A30CBED82836__INCLUDED_)
