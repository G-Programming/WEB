// TaskList.h : main header file for the TASKLIST application
//

#if !defined(AFX_TASKLIST_H__BA9B74F2_3E5C_4E02_8D15_C2634F70EBA6__INCLUDED_)
#define AFX_TASKLIST_H__BA9B74F2_3E5C_4E02_8D15_C2634F70EBA6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaskListApp:
// See TaskList.cpp for the implementation of this class
//

class CTaskListApp : public CWinApp
{
public:
	CTaskListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTaskListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKLIST_H__BA9B74F2_3E5C_4E02_8D15_C2634F70EBA6__INCLUDED_)
