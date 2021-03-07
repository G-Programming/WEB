#if !defined(AFX_MYCEACTIVEX_H__6B4D8885_E81A_4EE1_A1DB_99A8AA0BF5DF__INCLUDED_)
#define AFX_MYCEACTIVEX_H__6B4D8885_E81A_4EE1_A1DB_99A8AA0BF5DF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// MyCEActiveX.h : main header file for MYCEACTIVEX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXApp : See MyCEActiveX.cpp for implementation.

class CMyCEActiveXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCEACTIVEX_H__6B4D8885_E81A_4EE1_A1DB_99A8AA0BF5DF__INCLUDED)
