// ResDllTest.h : main header file for the RESDLLTEST application
//

#if !defined(AFX_RESDLLTEST_H__F9ED1640_05A0_4A19_AFE6_B3C7FEA65BC2__INCLUDED_)
#define AFX_RESDLLTEST_H__F9ED1640_05A0_4A19_AFE6_B3C7FEA65BC2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CResDllTestApp:
// See ResDllTest.cpp for the implementation of this class
//

class CResDllTestApp : public CWinApp
{
public:
	CResDllTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResDllTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CResDllTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESDLLTEST_H__F9ED1640_05A0_4A19_AFE6_B3C7FEA65BC2__INCLUDED_)
