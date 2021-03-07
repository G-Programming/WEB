// IPC_MSGServer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "IPC_MSGServer.h"
#include "IPC_MSGServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerApp

BEGIN_MESSAGE_MAP(CIPC_MSGServerApp, CWinApp)
	//{{AFX_MSG_MAP(CIPC_MSGServerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerApp construction

CIPC_MSGServerApp::CIPC_MSGServerApp()
	: CWinApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIPC_MSGServerApp object

CIPC_MSGServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CIPC_MSGServerApp initialization

BOOL CIPC_MSGServerApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CIPC_MSGServerDlg dlg;
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
