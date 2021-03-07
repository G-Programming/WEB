// CEComClient.h : main header file for the CECOMCLIENT application
//

#if !defined(AFX_CECOMCLIENT_H__666D5792_0155_4C64_997E_4A0501034BAC__INCLUDED_)
#define AFX_CECOMCLIENT_H__666D5792_0155_4C64_997E_4A0501034BAC__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCEComClientApp:
// See CEComClient.cpp for the implementation of this class
//

class CCEComClientApp : public CWinApp
{
public:
	CCEComClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCEComClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCEComClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CECOMCLIENT_H__666D5792_0155_4C64_997E_4A0501034BAC__INCLUDED_)
