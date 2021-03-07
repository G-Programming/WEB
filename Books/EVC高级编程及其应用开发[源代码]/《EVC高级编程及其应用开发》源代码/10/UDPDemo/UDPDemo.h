// UDPDemo.h : main header file for the UDPDEMO application
//

#if !defined(AFX_UDPDEMO_H__F5DB63F3_8309_47F6_AA99_5762EBBDEC7B__INCLUDED_)
#define AFX_UDPDEMO_H__F5DB63F3_8309_47F6_AA99_5762EBBDEC7B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUDPDemoApp:
// See UDPDemo.cpp for the implementation of this class
//

class CUDPDemoApp : public CWinApp
{
public:
	CUDPDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUDPDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPDEMO_H__F5DB63F3_8309_47F6_AA99_5762EBBDEC7B__INCLUDED_)
