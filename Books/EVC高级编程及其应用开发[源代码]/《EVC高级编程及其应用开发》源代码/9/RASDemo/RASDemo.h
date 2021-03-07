// RASDemo.h : main header file for the RASDEMO application
//

#if !defined(AFX_RASDEMO_H__5C328164_5E73_4168_94B6_7A72F2FF6B25__INCLUDED_)
#define AFX_RASDEMO_H__5C328164_5E73_4168_94B6_7A72F2FF6B25__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRASDemoApp:
// See RASDemo.cpp for the implementation of this class
//

class CRASDemoApp : public CWinApp
{
public:
	CRASDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRASDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRASDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RASDEMO_H__5C328164_5E73_4168_94B6_7A72F2FF6B25__INCLUDED_)
