/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.02.88 */
/* at Wed Mar 10 21:35:10 2004
 */
/* Compiler settings for CEComServer.idl:
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

const IID IID_ISimple = {0xA35A0BE3,0xE599,0x40CF,{0x81,0x23,0x5D,0x6B,0x08,0xDA,0xD8,0x43}};


const IID LIBID_CECOMSERVERLib = {0xE6098AB7,0x79F3,0x4B73,{0x8E,0xE5,0xDC,0xB4,0xCB,0xD5,0xDD,0x0A}};


const CLSID CLSID_Simple = {0x04056CF6,0x5A52,0x498E,{0xA7,0x51,0x80,0x66,0xC2,0x06,0xAE,0xD1}};


#ifdef __cplusplus
}
#endif

