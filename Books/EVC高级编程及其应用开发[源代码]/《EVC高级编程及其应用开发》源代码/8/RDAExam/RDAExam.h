// RDAExam.h : main header file for the RDAEXAM application
//

#if !defined(AFX_RDAEXAM_H__3F69705E_5C3C_41EA_BFB4_D76A868F69D4__INCLUDED_)
#define AFX_RDAEXAM_H__3F69705E_5C3C_41EA_BFB4_D76A868F69D4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRDAExamApp:
// See RDAExam.cpp for the implementation of this class
//

class CRDAExamApp : public CWinApp
{
public:
	CRDAExamApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRDAExamApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRDAExamApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RDAEXAM_H__3F69705E_5C3C_41EA_BFB4_D76A868F69D4__INCLUDED_)
