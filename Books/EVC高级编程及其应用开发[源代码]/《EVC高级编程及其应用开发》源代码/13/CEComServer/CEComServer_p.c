/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.02.88 */
/* at Wed Mar 10 21:35:10 2004
 */
/* Compiler settings for CEComServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY

#include "rpcproxy.h"
#include "CEComServer.h"

#define TYPE_FORMAT_STRING_SIZE   37                                
#define PROC_FORMAT_STRING_SIZE   55                                

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISimple, ver. 0.0,
   GUID={0xA35A0BE3,0xE599,0x40CF,{0x81,0x23,0x5D,0x6B,0x08,0xDA,0xD8,0x43}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISimple_ServerInfo;

#pragma code_seg(".orpc")

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x3020058, /* MIDL Version 3.2.88 */
    0,
    0,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short ISimple_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    18
    };

static const MIDL_SERVER_INFO ISimple_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISimple_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISimple_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISimple_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _ISimpleProxyVtbl = 
{
    &ISimple_ProxyInfo,
    &IID_ISimple,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ISimple::ShowSvrMsg */ ,
    (void *)-1 /* ISimple::_com_issue_errorex */
};


static const PRPC_STUB_FUNCTION ISimple_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISimpleStubVtbl =
{
    &IID_ISimple,
    &ISimple_ServerInfo,
    9,
    &ISimple_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure ShowSvrMsg */

			0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/*  2 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  4 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x4,		/* 4 */
			0x1,		/* 1 */

	/* Return value */

/* 12 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
/* 14 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 16 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure _com_issue_errorex */

/* 18 */	0x33,		/* FC_AUTO_HANDLE */
			0x64,		/* 100 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
#if !defined(_MIPS_)
#ifndef _PPC_
/* 22 */	NdrFcShort( 0x20 ),	/* x86, MIPS Stack size/offset = 32 */
#else
			NdrFcShort( 0x24 ),	/* PPC Stack size/offset = 36 */
#endif
#else
			NdrFcShort( 0x20 ),	/* MIPS Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 24 */	NdrFcShort( 0x28 ),	/* 40 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
/* 28 */	0x6,		/* 6 */
			0x4,		/* 4 */

	/* Parameter _hr1 */

/* 30 */	NdrFcShort( 0x48 ),	/* 72 */
#ifndef _ALPHA_
/* 32 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pthis1 */

/* 36 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 38 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 40 */	NdrFcShort( 0x0 ),	/* Type Offset=0 */

	/* Parameter refiid1 */

/* 42 */	NdrFcShort( 0x8a ),	/* 138 */
#ifndef _ALPHA_
#if !defined(_MIPS_)
#ifndef _PPC_
/* 44 */	NdrFcShort( 0xc ),	/* x86, MIPS Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0xc ),	/* MIPS Stack size/offset = 12 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 46 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */

/* 48 */	NdrFcShort( 0x70 ),	/* 112 */
#ifndef _ALPHA_
#if !defined(_MIPS_)
#ifndef _PPC_
/* 50 */	NdrFcShort( 0x1c ),	/* x86, MIPS Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/* PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x1c ),	/* MIPS Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 52 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 12 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 18 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 24 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 26 */	NdrFcShort( 0x10 ),	/* 16 */
/* 28 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 30 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 32 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (18) */
			0x5b,		/* FC_END */

			0x0
        }
    };

const CInterfaceProxyVtbl * _CEComServer_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISimpleProxyVtbl,
    0
};

const CInterfaceStubVtbl * _CEComServer_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISimpleStubVtbl,
    0
};

PCInterfaceName const _CEComServer_InterfaceNamesList[] = 
{
    "ISimple",
    0
};

const IID *  _CEComServer_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _CEComServer_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _CEComServer, pIID, n)

int __stdcall _CEComServer_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_CEComServer_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo CEComServer_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _CEComServer_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _CEComServer_StubVtblList,
    (const PCInterfaceName * ) & _CEComServer_InterfaceNamesList,
    (const IID ** ) & _CEComServer_BaseIIDList,
    & _CEComServer_IID_Lookup, 
    1,
    2
};
