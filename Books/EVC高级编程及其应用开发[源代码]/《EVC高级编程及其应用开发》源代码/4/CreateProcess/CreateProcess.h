// CreateProcess.h : main header file for the CREATEPROCESS application
//

#if !defined(AFX_CREATEPROCESS_H__5FAF89F3_CE8E_4648_A307_25D0FD1BAFED__INCLUDED_)
#define AFX_CREATEPROCESS_H__5FAF89F3_CE8E_4648_A307_25D0FD1BAFED__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateProcessApp:
// See CreateProcess.cpp for the implementation of this class
//

class CCreateProcessApp : public CWinApp
{
public:
	CCreateProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEPROCESS_H__5FAF89F3_CE8E_4648_A307_25D0FD1BAFED__INCLUDED_)
