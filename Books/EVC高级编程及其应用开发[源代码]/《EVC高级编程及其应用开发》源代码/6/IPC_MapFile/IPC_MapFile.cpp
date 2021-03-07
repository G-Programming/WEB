// IPC_MapFile.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "IPC_MapFile.h"
#include "IPC_MapFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileApp

BEGIN_MESSAGE_MAP(CIPC_MapFileApp, CWinApp)
	//{{AFX_MSG_MAP(CIPC_MapFileApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileApp construction

CIPC_MapFileApp::CIPC_MapFileApp()
	: CWinApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIPC_MapFileApp object

CIPC_MapFileApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileApp initialization

BOOL CIPC_MapFileApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CIPC_MapFileDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
