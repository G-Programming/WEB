// CERAS.h: interface for the CCERAS class.
//
//////////////////////////////////////////////////////////////////////
//********************************************************************
//文件标识:CERAS.h
//********************************************************************
#if !defined(AFX_CERAS_H__40A8D118_57B5_4E9D_B924_3CC5F3B0FEE4__INCLUDED_)
#define AFX_CERAS_H__40A8D118_57B5_4E9D_B924_3CC5F3B0FEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ras.h>

class CCERAS  
{
private:
	HRASCONN m_hRasConn; //RAS拨号句柄
public:
	CCERAS();
	virtual ~CCERAS();
	
    boolean CERasDial(LPCTSTR szEntry, LPCTSTR szPhoneNumber,
		LPCTSTR szCallbackNumber,LPCTSTR szUserName, 
		LPCTSTR szPassword, LPCTSTR szDomain);
	boolean CERasHangup();
	boolean IsConnected();
	int GetConnectedCount();
	boolean CERasHangupAll();
	
};

#endif // !defined(AFX_CERAS_H__40A8D118_57B5_4E9D_B924_3CC5F3B0FEE4__INCLUDED_)
