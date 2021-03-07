// TreeCtrlUse.h : main header file for the TREECTRLUSE application
//

#if !defined(AFX_TREECTRLUSE_H__98E01FFC_C89E_4401_83C0_68483FC11AAE__INCLUDED_)
#define AFX_TREECTRLUSE_H__98E01FFC_C89E_4401_83C0_68483FC11AAE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlUseApp:
// See TreeCtrlUse.cpp for the implementation of this class
//

class CTreeCtrlUseApp : public CWinApp
{
public:
	CTreeCtrlUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtrlUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTreeCtrlUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREECTRLUSE_H__98E01FFC_C89E_4401_83C0_68483FC11AAE__INCLUDED_)
