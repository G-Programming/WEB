// ADOAccess.h : main header file for the ADOACCESS application
//

#if !defined(AFX_ADOACCESS_H__EF91C1E6_D401_436D_B048_0D5098C1E76E__INCLUDED_)
#define AFX_ADOACCESS_H__EF91C1E6_D401_436D_B048_0D5098C1E76E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADOAccessApp:
// See ADOAccess.cpp for the implementation of this class
//

class CADOAccessApp : public CWinApp
{
public:
	CADOAccessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOAccessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOAccessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOACCESS_H__EF91C1E6_D401_436D_B048_0D5098C1E76E__INCLUDED_)
