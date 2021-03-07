// PingExample.h : main header file for the PINGEXAMPLE application
//

#if !defined(AFX_PINGEXAMPLE_H__1739FC74_C3E9_47D3_B040_3A5FD4FA8EAC__INCLUDED_)
#define AFX_PINGEXAMPLE_H__1739FC74_C3E9_47D3_B040_3A5FD4FA8EAC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPingExampleApp:
// See PingExample.cpp for the implementation of this class
//

class CPingExampleApp : public CWinApp
{
public:
	CPingExampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPingExampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPingExampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINGEXAMPLE_H__1739FC74_C3E9_47D3_B040_3A5FD4FA8EAC__INCLUDED_)
