// SliderUse.h : main header file for the SLIDERUSE application
//

#if !defined(AFX_SLIDERUSE_H__71E88161_5FF0_456A_B6D1_288B25EB0864__INCLUDED_)
#define AFX_SLIDERUSE_H__71E88161_5FF0_456A_B6D1_288B25EB0864__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSliderUseApp:
// See SliderUse.cpp for the implementation of this class
//

class CSliderUseApp : public CWinApp
{
public:
	CSliderUseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSliderUseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSliderUseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERUSE_H__71E88161_5FF0_456A_B6D1_288B25EB0864__INCLUDED_)
