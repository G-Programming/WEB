// IPC_MapFile.h : main header file for the IPC_MAPFILE application
//

#if !defined(AFX_IPC_MAPFILE_H__AE692F5A_A281_43E5_A0D3_C650C856555E__INCLUDED_)
#define AFX_IPC_MAPFILE_H__AE692F5A_A281_43E5_A0D3_C650C856555E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileApp:
// See IPC_MapFile.cpp for the implementation of this class
//

class CIPC_MapFileApp : public CWinApp
{
public:
	CIPC_MapFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPC_MapFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIPC_MapFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPC_MAPFILE_H__AE692F5A_A281_43E5_A0D3_C650C856555E__INCLUDED_)
