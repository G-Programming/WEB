// Simple.cpp : Implementation of CSimple
#include "stdafx.h"
#include "CEComServer.h"
#include "Simple.h"

/////////////////////////////////////////////////////////////////////////////
// CSimple


STDMETHODIMP CSimple::ShowSvrMsg()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	::MessageBox(NULL,_T("此消息来自COM"),_T("COM测试"),MB_OK);

	return S_OK;
}

STDMETHODIMP CSimple::_com_issue_errorex(HRESULT _hr1, IUnknown *pthis1, const GUID refiid1)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// TODO: Add your implementation code here

	return S_OK;
}
