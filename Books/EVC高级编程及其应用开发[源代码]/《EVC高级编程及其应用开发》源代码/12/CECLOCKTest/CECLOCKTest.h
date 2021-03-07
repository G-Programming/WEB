// CECLOCKTest.h : main header file for the CECLOCKTEST application
//

#if !defined(AFX_CECLOCKTEST_H__5DC47DBB_5C2B_4E1C_B41A_53CDDB57E08E__INCLUDED_)
#define AFX_CECLOCKTEST_H__5DC47DBB_5C2B_4E1C_B41A_53CDDB57E08E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCECLOCKTestApp:
// See CECLOCKTest.cpp for the implementation of this class
//

class CCECLOCKTestApp : public CWinApp
{
public:
	CCECLOCKTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCECLOCKTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCECLOCKTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CECLOCKTEST_H__5DC47DBB_5C2B_4E1C_B41A_53CDDB57E08E__INCLUDED_)
