// SpinUse.h : main header file for the SPINUSE application
//

#if !defined(AFX_SPINUSE_H__A3E09C9C_C57E_4A09_BEE9_CBF1B83D945B__INCLUDED_)
#define AFX_SPINUSE_H__A3E09C9C_C57E_4A09_BEE9_CBF1B83D945B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpinUseApp:
// See SpinUse.cpp for the implementation of this class
//

class CSpinUseApp : public CWinApp
{
public:
	CSpinUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpinUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINUSE_H__A3E09C9C_C57E_4A09_BEE9_CBF1B83D945B__INCLUDED_)
