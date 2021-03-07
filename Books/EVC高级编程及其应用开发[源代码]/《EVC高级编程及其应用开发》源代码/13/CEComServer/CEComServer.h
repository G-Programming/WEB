/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.02.88 */
/* at Wed Mar 10 21:35:10 2004
 */
/* Compiler settings for CEComServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CEComServer_h__
#define __CEComServer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISimple_FWD_DEFINED__
#define __ISimple_FWD_DEFINED__
typedef interface ISimple ISimple;
#endif 	/* __ISimple_FWD_DEFINED__ */


#ifndef __Simple_FWD_DEFINED__
#define __Simple_FWD_DEFINED__

#ifdef __cplusplus
typedef class Simple Simple;
#else
typedef struct Simple Simple;
#endif /* __cplusplus */

#endif 	/* __Simple_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ISimple_INTERFACE_DEFINED__
#define __ISimple_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISimple
 * at Wed Mar 10 21:35:10 2004
 * using MIDL 3.02.88
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_ISimple;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("A35A0BE3-E599-40CF-8123-5D6B08DAD843")
    ISimple : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowSvrMsg( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE _com_issue_errorex( 
            HRESULT _hr1,
            IUnknown __RPC_FAR *pthis1,
            const GUID refiid1) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISimple __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISimple __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISimple __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISimple __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISimple __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISimple __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISimple __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowSvrMsg )( 
            ISimple __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_com_issue_errorex )( 
            ISimple __RPC_FAR * This,
            HRESULT _hr1,
            IUnknown __RPC_FAR *pthis1,
            const GUID refiid1);
        
        END_INTERFACE
    } ISimpleVtbl;

    interface ISimple
    {
        CONST_VTBL struct ISimpleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimple_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISimple_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISimple_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISimple_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISimple_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISimple_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISimple_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISimple_ShowSvrMsg(This)	\
    (This)->lpVtbl -> ShowSvrMsg(This)

#define ISimple__com_issue_errorex(This,_hr1,pthis1,refiid1)	\
    (This)->lpVtbl -> _com_issue_errorex(This,_hr1,pthis1,refiid1)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimple_ShowSvrMsg_Proxy( 
    ISimple __RPC_FAR * This);


void __RPC_STUB ISimple_ShowSvrMsg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISimple__com_issue_errorex_Proxy( 
    ISimple __RPC_FAR * This,
    HRESULT _hr1,
    IUnknown __RPC_FAR *pthis1,
    const GUID refiid1);


void __RPC_STUB ISimple__com_issue_errorex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISimple_INTERFACE_DEFINED__ */



#ifndef __CECOMSERVERLib_LIBRARY_DEFINED__
#define __CECOMSERVERLib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: CECOMSERVERLib
 * at Wed Mar 10 21:35:10 2004
 * using MIDL 3.02.88
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_CECOMSERVERLib;

EXTERN_C const CLSID CLSID_Simple;

#ifdef __cplusplus

class DECLSPEC_UUID("04056CF6-5A52-498E-A751-8066C206AED1")
Simple;
#endif
#endif /* __CECOMSERVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
