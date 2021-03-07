// IPC_MSGServer.h : main header file for the IPC_MSGSERVER application
//

#if !defined(AFX_IPC_MSGSERVER_H__B673189C_DF0D_4DB9_8608_67041B8AF29E__INCLUDED_)
#define AFX_IPC_MSGSERVER_H__B673189C_DF0D_4DB9_8608_67041B8AF29E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerApp:
// See IPC_MSGServer.cpp for the implementation of this class
//

class CIPC_MSGServerApp : public CWinApp
{
public:
	CIPC_MSGServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPC_MSGServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIPC_MSGServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPC_MSGSERVER_H__B673189C_DF0D_4DB9_8608_67041B8AF29E__INCLUDED_)
