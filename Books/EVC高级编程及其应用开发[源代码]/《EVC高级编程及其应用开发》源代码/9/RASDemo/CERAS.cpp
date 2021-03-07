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
*�������ܣ����ڽ�����������
*��ڲ�����szEntry : ����������; 
szPhoneNumber : ���ŵĺ���;
szCallbackNumber : �ؽк���; 
szUserName : �����û���;
szPassword : ��������;
szDomain : ��; 
*���ڲ�����(��)
*�� �� ֵ��TRUE : �ɹ����ţ������������� , FALSE : ����ʧ��
*/
boolean CCERAS::CERasDial(LPCTSTR szEntry, LPCTSTR szPhoneNumber,
						  LPCTSTR szCallbackNumber,LPCTSTR szUserName, LPCTSTR szPassword, LPCTSTR szDomain)
{
    RASDIALPARAMS rdParams;
	m_hRasConn = NULL;
	//��ʼ������
	rdParams.dwSize = sizeof(RASDIALPARAMS);
	wcscpy(rdParams.szEntryName,szEntry);
	wcscpy(rdParams.szPhoneNumber,szPhoneNumber);
	wcscpy(rdParams.szCallbackNumber,szCallbackNumber);
	wcscpy(rdParams.szUserName,szUserName);
	wcscpy(rdParams.szPassword,szPassword);
	wcscpy(rdParams.szDomain,szDomain);
	
	//������ͬ������ģʽ
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
*�������ܣ��Ҷ��ɱ��ཨ��������
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��TRUE : �ɹ��Ҷ�,FALSE : �Ҷ�ʧ��
*/
boolean CCERAS::CERasHangup()
{
	RASCONNSTATUS status;
	status.dwSize = sizeof(RASCONNSTATUS);
	
	//�ر�Ras��������
	DWORD result = RasHangUp(m_hRasConn);
	if (result == 0)
	{   
		//��ʱ,�ж������Ƿ�ر�
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
*�������ܣ��Ҷ������ѽ����Ĳ�������
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��TRUE : �ɹ��Ҷ������ѽ����Ĳ�������,FALSE : �Ҷ����н����Ĳ�������ʧ��
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
*�������ܣ��õ��ɱ��ཨ���������Ƿ񻹴�������
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��TRUE : �������Ӵ���,FALSE : �������Ӳ�����
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
*�������ܣ��õ�ϵͳ�����������ӵĸ���
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ������ϵͳ���ڲ������ӵĸ���
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



