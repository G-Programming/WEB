// TCPServer_CE.cpp: implementation of the CTCPServer_CE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPServer.h"
#include "TCPServer_CE.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "TCPCustom_CE.h" 
#include <afxtempl.h>
//�洢�ͻ���Socket���
CList<CTCPCustom_CE,CTCPCustom_CE&> m_ListClientSocket;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//���캯��
CTCPServer_CE::CTCPServer_CE()
{
	//�����߳��˳��¼����
	m_exitThreadEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
}
//��������
CTCPServer_CE::~CTCPServer_CE()
{
	//�ر��߳��˳��¼����
	CloseHandle(m_exitThreadEvent);
}

/*--------------------------------------------------------------------
���������ܡ�:  ���߳����ڼ������׽����¼���
����ڲ�����:  lparam:������ָ�룬����ͨ���˲��������߳��д�����Ҫ�õ�����Դ��
			   ���������ǽ�CTCPServer_CE��ʵ��ָ�봫����
�����ڲ�����:  (��)
������  ֵ��:  ����ֵû���ر�����壬�ڴ����ǽ�����ֵ��Ϊ0��
---------------------------------------------------------------------*/
DWORD CTCPServer_CE::SocketThreadFunc(PVOID lparam)
{
	CTCPServer_CE *pSocket;
	//�õ�CTCPServer_CEʵ��ָ��
	pSocket = (CTCPServer_CE*)lparam;
	//������¼�����
	fd_set fdRead;
	int ret;
	TIMEVAL	aTime;
	aTime.tv_sec = 1;
	aTime.tv_usec = 1;
	while (TRUE)
	{
        //�յ��˳��¼��������߳�
		if (WaitForSingleObject(pSocket->m_exitThreadEvent,0) == WAIT_OBJECT_0)
		{
			break;
		}
		
		FD_ZERO(&fdRead);
		FD_SET(pSocket->m_ServerSocket,&fdRead);
		
		ret = select(0,&fdRead,NULL,NULL,&aTime);
		
		if (ret == SOCKET_ERROR)
		{
			//���������¼�
			int iErrorCode = WSAGetLastError();
			//����������socket�Ĵ����¼�
			pSocket->OnServerError(pSocket->m_pOwnerWnd,pSocket,iErrorCode);
			//�رշ������׽��� 
			closesocket(pSocket->m_ServerSocket);
			break;
		}
		
		if (ret > 0)
		{
			//�ж��Ƿ���¼�
			if (FD_ISSET(pSocket->m_ServerSocket,&fdRead))
			{
				//���������Listen�����ʾ������OnAccept�¼�
				
				SOCKADDR_IN clientAddr;
				CTCPCustom_CE * pClientSocket = new CTCPCustom_CE();
				int namelen = sizeof(clientAddr);
				//�ȴ���������ͻ������ӵ��׽���
				pClientSocket->m_socket = accept(pSocket->m_ServerSocket, (struct sockaddr *)&clientAddr, &namelen);
				//���յ��ͻ�������
				if (pClientSocket->m_socket)
				{
					pClientSocket->m_RemoteHost = inet_ntoa(clientAddr.sin_addr);
					pClientSocket->m_RemotePort = ntohs(clientAddr.sin_port);
					
					//������ͻ��˽��������¼�
					pSocket->OnClientConnect(pSocket->m_pOwnerWnd,pClientSocket);
					//��pClientSocket�����߳�
					pClientSocket->Open(pSocket);
					//��ӵ��ͻ������Ӷ�����
					m_ListClientSocket.AddTail(*pClientSocket);
				}
				else
				{
					delete pClientSocket;
				}	
			}
		}
	}
	return 0;
}



/*--------------------------------------------------------------------
���������ܡ�:  ��TCP����
����ڲ�����:  (��)
�����ڲ�����:  (��)
������  ֵ��:  <=0:��TCP����ʧ��; =1:��TCP����ɹ�
---------------------------------------------------------------------*/
int CTCPServer_CE::Open()
{
	WSADATA wsa;
	
	//1.��ʼ��socket��Դ
	if (WSAStartup(MAKEWORD(1,1),&wsa) != 0)
	{
		return -1;//����ʧ��
	}
	
	//2.���������׽���
	if ((m_ServerSocket=socket(AF_INET, SOCK_STREAM, 0))<0)
	{
		return -2;
	}
	
    SOCKADDR_IN  serverAddr;
	ZeroMemory((char *)&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(m_LocalPort);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//3.�󶨼����׽���
	if (bind(m_ServerSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr))<0)
	{
		
		return -3 ;
	}
	//4.�����׽��ֿ�ʼ����
	if (listen(m_ServerSocket,8)!=0)
	{
		return -3;
	}
	
	//4.���ü����׽���ͨѶģʽΪ�첽ģʽ
	DWORD ul= 1;
	ioctlsocket(m_ServerSocket,FIONBIO,&ul);

	ResetEvent(m_exitThreadEvent);
	//5.����ͨѶ�̣߳����߳���ȴ��ͻ��˽���
	m_serverThreadHandle = CreateThread(NULL,0,SocketThreadFunc,this,0,NULL);
	if (m_serverThreadHandle == NULL)
	{
		closesocket(m_ServerSocket);
		return -1;
	}

	return 1;
}


/*--------------------------------------------------------------------
���������ܡ�:  �ر�TCP����
����ڲ�����:  (��)
�����ڲ�����:  (��)
������  ֵ��:  <=0:�ر�TCP����ʧ��; =1:�ر�TCP����ɹ�
---------------------------------------------------------------------*/
int CTCPServer_CE::Close()
{
	//����ͨѶ�߳�
	SetEvent(m_exitThreadEvent);
	Sleep(1000);
	//�ر�Socket���ͷ���Դ
	int err = closesocket(m_ServerSocket);
	if (err == SOCKET_ERROR)
	{
		return -1;
	}
	m_ServerSocket = NULL;

	//���ȣ��ر������пͻ�������
	POSITION pos = m_ListClientSocket.GetHeadPosition();
	while (pos != NULL)
	{
        CTCPCustom_CE &tmpTcpCustom = m_ListClientSocket.GetAt(pos);
		if (!tmpTcpCustom.Close())
		{
			AfxMessageBox(L"�رտͻ���socket����");
		}
		m_ListClientSocket.RemoveHead();
		pos = m_ListClientSocket.GetHeadPosition();
	}
	
	WSACleanup();
	return 1;
}  
