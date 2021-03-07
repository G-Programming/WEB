// ThreadAsyn.h : main header file for the THREADASYN application
//

#if !defined(AFX_THREADASYN_H__A3CAD1BF_652D_4EE6_AB68_F25EEFFD0FDA__INCLUDED_)
#define AFX_THREADASYN_H__A3CAD1BF_652D_4EE6_AB68_F25EEFFD0FDA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadAsynApp:
// See ThreadAsyn.cpp for the implementation of this class
//

class CThreadAsynApp : public CWinApp
{
public:
	CThreadAsynApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadAsynApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadAsynApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADASYN_H__A3CAD1BF_652D_4EE6_AB68_F25EEFFD0FDA__INCLUDED_)
