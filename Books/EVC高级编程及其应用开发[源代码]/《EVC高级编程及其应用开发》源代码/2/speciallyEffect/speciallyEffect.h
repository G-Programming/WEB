// speciallyEffect.h : main header file for the SPECIALLYEFFECT application
//

#if !defined(AFX_SPECIALLYEFFECT_H__F378D5BE_F478_496B_8F2A_358BEA46C91F__INCLUDED_)
#define AFX_SPECIALLYEFFECT_H__F378D5BE_F478_496B_8F2A_358BEA46C91F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpeciallyEffectApp:
// See speciallyEffect.cpp for the implementation of this class
//

class CSpeciallyEffectApp : public CWinApp
{
public:
	CSpeciallyEffectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeciallyEffectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpeciallyEffectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALLYEFFECT_H__F378D5BE_F478_496B_8F2A_358BEA46C91F__INCLUDED_)
