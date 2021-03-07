// ThreadSynBySemaphore.h : main header file for the THREADSYNBYSEMAPHORE application
//

#if !defined(AFX_THREADSYNBYSEMAPHORE_H__94AB6C97_8BDB_4A60_BE47_790A2529EC7C__INCLUDED_)
#define AFX_THREADSYNBYSEMAPHORE_H__94AB6C97_8BDB_4A60_BE47_790A2529EC7C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadSynBySemaphoreApp:
// See ThreadSynBySemaphore.cpp for the implementation of this class
//

class CThreadSynBySemaphoreApp : public CWinApp
{
public:
	CThreadSynBySemaphoreApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynBySemaphoreApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadSynBySemaphoreApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYSEMAPHORE_H__94AB6C97_8BDB_4A60_BE47_790A2529EC7C__INCLUDED_)
