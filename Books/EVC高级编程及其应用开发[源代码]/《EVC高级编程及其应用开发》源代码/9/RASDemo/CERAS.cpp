// CERAS.cpp: implementation of the CCERAS class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RASDemo.h"
#include "CERAS.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCERAS::CCERAS()
{

}

CCERAS::~CCERAS()
{

}


/*
*函数介绍：用于建立拨号连接
*入口参数：szEntry : 拨号连接名; 
szPhoneNumber : 拨号的号码;
szCallbackNumber : 回叫号码; 
szUserName : 拨号用户名;
szPassword : 拨号密码;
szDomain : 域; 
*出口参数：(无)
*返 回 值：TRUE : 成功拨号，建立拨号连接 , FALSE : 拨号失败
*/
boolean CCERAS::CERasDial(LPCTSTR szEntry, LPCTSTR szPhoneNumber,
						  LPCTSTR szCallbackNumber,LPCTSTR szUserName, LPCTSTR szPassword, LPCTSTR szDomain)
{
    RASDIALPARAMS rdParams;
	m_hRasConn = NULL;
	//初始化变量
	rdParams.dwSize = sizeof(RASDIALPARAMS);
	wcscpy(rdParams.szEntryName,szEntry);
	wcscpy(rdParams.szPhoneNumber,szPhoneNumber);
	wcscpy(rdParams.szCallbackNumber,szCallbackNumber);
	wcscpy(rdParams.szUserName,szUserName);
	wcscpy(rdParams.szPassword,szPassword);
	wcscpy(rdParams.szDomain,szDomain);
	
	//以下是同步拨号模式
	DWORD dwRet;
	
	dwRet = RasDial(NULL,NULL,&rdParams,0,NULL,&m_hRasConn);
	if ( dwRet != 0 )
	{
		
		RasHangUp(m_hRasConn);
		return FALSE;
	}
	
	return TRUE;
	
}

/*
*函数介绍：挂断由本类建立的连接
*入口参数：(无)
*出口参数：(无)
*返 回 值：TRUE : 成功挂断,FALSE : 挂断失败
*/
boolean CCERAS::CERasHangup()
{
	RASCONNSTATUS status;
	status.dwSize = sizeof(RASCONNSTATUS);
	
	//关闭Ras拨号连接
	DWORD result = RasHangUp(m_hRasConn);
	if (result == 0)
	{   
		//延时,判断连接是否关闭
		while (RasGetConnectStatus(m_hRasConn, &status) == 0 )
		{
			Sleep(10);
		}
		m_hRasConn = NULL;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}

/*
*函数介绍：挂断所有已建立的拨号连接
*入口参数：(无)
*出口参数：(无)
*返 回 值：TRUE : 成功挂断所有已建立的拨号连接,FALSE : 挂断所有建立的拨号连接失败
*/
boolean CCERAS::CERasHangupAll()
{
	
	RASCONN entries[25];
	DWORD bufsize;
	DWORD numEntries;
	bufsize = 25*sizeof(RASCONN);
	entries[0].dwSize = sizeof(RASCONN);
	
	RASCONNSTATUS status;
	status.dwSize = sizeof(RASCONNSTATUS);
	
	if (RasEnumConnections(&entries[0],&bufsize, &numEntries) == 0 )
	{
        for(DWORD i=0;i<numEntries;i++)
		{
			if (RasHangUp(entries[i].hrasconn) == 0)
			{
				while (RasGetConnectStatus(entries[i].hrasconn, &status) == 0 )
				{
					Sleep(0);
				}
			}
		}
		 n
	}   
	return TRUE;
}


/*
*函数介绍：得到由本类建立的连接是否还存在连接
*入口参数：(无)
*出口参数：(无)
*返 回 值：TRUE : 代表连接存在,FALSE : 代表连接不存在
*/
boolean CCERAS::IsConnected()
{
	
	RASCONNSTATUS status;
	status.dwSize = sizeof(RASCONNSTATUS);
	
	if (!RasGetConnectStatus(m_hRasConn, &status))
	{
		if (status.rasconnstate == RASCS_Connected)
		{
			return TRUE;
		}
		else
		{
			m_hRasConn = NULL;
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*
*函数介绍：得到系统建立拨号连接的个数
*入口参数：(无)
*出口参数：(无)
*返 回 值：返回系统存在拨号连接的个数
*/
int CCERAS::GetConnectedCount()
{
	DWORD dwSize = sizeof(RASCONN) * 20, dwCount = 20;
	HRASCONN hConnection = NULL;
	RASCONN  connections[20];
	connections[0].dwSize = sizeof(RASCONN);
	if (!RasEnumConnections(connections, &dwSize, &dwCount))
	{
		return dwCount;
	}
	else
	{
		return 0;
	}
	
}



