// Simple.h : Declaration of the CSimple

#ifndef __SIMPLE_H_
#define __SIMPLE_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimple
class ATL_NO_VTABLE CSimple : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSimple, &CLSID_Simple>,
	public IDispatchImpl<ISimple, &IID_ISimple, &LIBID_CECOMSERVERLib>
{
public:
	CSimple()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SIMPLE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSimple)
	COM_INTERFACE_ENTRY(ISimple)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ISimple
public:
	STDMETHOD(_com_issue_errorex)(HRESULT _hr1, IUnknown  *pthis1,const GUID  refiid1);
	STDMETHOD(ShowSvrMsg)();
};

#endif //__SIMPLE_H_
