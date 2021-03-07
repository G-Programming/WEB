// LedCtrlUse.h : main header file for the LEDCTRLUSE application
//

#if !defined(AFX_LEDCTRLUSE_H__088D3358_4E97_42D1_BF47_9B9E1D422D5F__INCLUDED_)
#define AFX_LEDCTRLUSE_H__088D3358_4E97_42D1_BF47_9B9E1D422D5F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLedCtrlUseApp:
// See LedCtrlUse.cpp for the implementation of this class
//

class CLedCtrlUseApp : public CWinApp
{
public:
	CLedCtrlUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLedCtrlUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLedCtrlUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEDCTRLUSE_H__088D3358_4E97_42D1_BF47_9B9E1D422D5F__INCLUDED_)
