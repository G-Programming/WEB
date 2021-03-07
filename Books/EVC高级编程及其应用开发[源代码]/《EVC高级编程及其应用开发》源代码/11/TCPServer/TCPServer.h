// TCPServer.h : main header file for the TCPSERVER application
//

#if !defined(AFX_TCPSERVER_H__87B42D9E_A719_47CB_8D07_821BB7EF8817__INCLUDED_)
#define AFX_TCPSERVER_H__87B42D9E_A719_47CB_8D07_821BB7EF8817__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTCPServerApp:
// See TCPServer.cpp for the implementation of this class
//

class CTCPServerApp : public CWinApp
{
public:
	CTCPServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTCPServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPSERVER_H__87B42D9E_A719_47CB_8D07_821BB7EF8817__INCLUDED_)
