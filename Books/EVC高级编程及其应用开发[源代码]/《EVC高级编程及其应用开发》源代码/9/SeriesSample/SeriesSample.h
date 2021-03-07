// SeriesSample.h : main header file for the SERIESSAMPLE application
//

#if !defined(AFX_SERIESSAMPLE_H__5B23BD6B_8462_496A_B8FC_7FA974D998B1__INCLUDED_)
#define AFX_SERIESSAMPLE_H__5B23BD6B_8462_496A_B8FC_7FA974D998B1__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSeriesSampleApp:
// See SeriesSample.cpp for the implementation of this class
//

class CSeriesSampleApp : public CWinApp
{
public:
	CSeriesSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriesSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSeriesSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIESSAMPLE_H__5B23BD6B_8462_496A_B8FC_7FA974D998B1__INCLUDED_)
