// ThreadSynByEvent.h : main header file for the THREADSYNBYEVENT application
//

#if !defined(AFX_THREADSYNBYEVENT_H__7D1FFA6E_D3C7_4FF9_ADDA_7406F2FCF888__INCLUDED_)
#define AFX_THREADSYNBYEVENT_H__7D1FFA6E_D3C7_4FF9_ADDA_7406F2FCF888__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadSynByEventApp:
// See ThreadSynByEvent.cpp for the implementation of this class
//

class CThreadSynByEventApp : public CWinApp
{
public:
	CThreadSynByEventApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadSynByEventApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadSynByEventApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADSYNBYEVENT_H__7D1FFA6E_D3C7_4FF9_ADDA_7406F2FCF888__INCLUDED_)
