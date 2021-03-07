/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.02.88 */
/* at Tue Mar 09 21:14:57 2004
 */
/* Compiler settings for ConnectionCom.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IAdd = {0x681C5A5C,0xCF18,0x452A,{0xBC,0x70,0x65,0xE0,0x52,0xAF,0xAC,0x09}};


const IID LIBID_CONNECTIONCOMLib = {0x03CFA5DA,0xFD47,0x4ADF,{0x8B,0x96,0xBF,0xEE,0x4F,0x64,0x6B,0x5C}};


const IID IID__IAddEvents = {0x04CF9885,0x43F3,0x406D,{0x82,0x3D,0x0A,0x0C,0x44,0x88,0x3E,0xF4}};


const CLSID CLSID_Add = {0x630B3CD3,0xDDB1,0x43CE,{0xAD,0x2F,0x4F,0x57,0xDC,0x54,0xD5,0xD0}};


#ifdef __cplusplus
}
#endif

