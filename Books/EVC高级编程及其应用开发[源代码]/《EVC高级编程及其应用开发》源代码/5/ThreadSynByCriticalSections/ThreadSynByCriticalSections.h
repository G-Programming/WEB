// ThreadSynByCriticalSections.h : main header file for the THREADSYNBYCRITICALSECTIONS application
//

#if !defined(AFX_THREADSYNBYCRITICALSECTIONS_H__5F1276C7_638C_452A_8A08_210F971963FF__INCLUDED_)
#define AFX_THREADSYNBYCRITICALSECTIONS_H__5F1276C7_638C_452A_8A08_210F971963FF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByCriticalSectionsApp:
// See ThreadSynByCriticalSections.cpp for the implementation of this class
//

class CThreadSynByCriticalSectionsApp : public CWinApp
{
public:
	CThreadSynByCriticalSectionsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynByCriticalSectionsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadSynByCriticalSectionsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYCRITICALSECTIONS_H__5F1276C7_638C_452A_8A08_210F971963FF__INCLUDED_)
