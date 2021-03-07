// MyCEActiveX_Test.h : main header file for the MYCEACTIVEX_TEST application
//

#if !defined(AFX_MYCEACTIVEX_TEST_H__235A0FA8_C987_46D9_B4D6_260F5F477DE5__INCLUDED_)
#define AFX_MYCEACTIVEX_TEST_H__235A0FA8_C987_46D9_B4D6_260F5F477DE5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveX_TestApp:
// See MyCEActiveX_Test.cpp for the implementation of this class
//

class CMyCEActiveX_TestApp : public CWinApp
{
public:
	CMyCEActiveX_TestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCEActiveX_TestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyCEActiveX_TestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCEACTIVEX_TEST_H__235A0FA8_C987_46D9_B4D6_260F5F477DE5__INCLUDED_)
