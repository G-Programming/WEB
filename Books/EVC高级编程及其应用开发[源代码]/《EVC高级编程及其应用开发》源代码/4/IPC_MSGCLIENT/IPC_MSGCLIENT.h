// IPC_MSGCLIENT.h : main header file for the IPC_MSGCLIENT application
//

#if !defined(AFX_IPC_MSGCLIENT_H__231C2C4D_3346_4CDA_BEBD_A985CB676631__INCLUDED_)
#define AFX_IPC_MSGCLIENT_H__231C2C4D_3346_4CDA_BEBD_A985CB676631__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGCLIENTApp:
// See IPC_MSGCLIENT.cpp for the implementation of this class
//

class CIPC_MSGCLIENTApp : public CWinApp
{
public:
	CIPC_MSGCLIENTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPC_MSGCLIENTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIPC_MSGCLIENTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPC_MSGCLIENT_H__231C2C4D_3346_4CDA_BEBD_A985CB676631__INCLUDED_)
