// ListCtrlUse.h : main header file for the LISTCTRLUSE application
//

#if !defined(AFX_LISTCTRLUSE_H__981FD2ED_437F_4ECB_9BBB_256841D005C9__INCLUDED_)
#define AFX_LISTCTRLUSE_H__981FD2ED_437F_4ECB_9BBB_256841D005C9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListCtrlUseApp:
// See ListCtrlUse.cpp for the implementation of this class
//

class CListCtrlUseApp : public CWinApp
{
public:
	CListCtrlUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListCtrlUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLUSE_H__981FD2ED_437F_4ECB_9BBB_256841D005C9__INCLUDED_)
