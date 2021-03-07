// PlugIn_Main.h : main header file for the PLUGIN_MAIN application
//

#if !defined(AFX_PLUGIN_MAIN_H__AD3B446F_656F_4F2A_980F_5B5BF50B62E0__INCLUDED_)
#define AFX_PLUGIN_MAIN_H__AD3B446F_656F_4F2A_980F_5B5BF50B62E0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_MainApp:
// See PlugIn_Main.cpp for the implementation of this class
//

class CPlugIn_MainApp : public CWinApp
{
public:
	CPlugIn_MainApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlugIn_MainApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlugIn_MainApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGIN_MAIN_H__AD3B446F_656F_4F2A_980F_5B5BF50B62E0__INCLUDED_)
