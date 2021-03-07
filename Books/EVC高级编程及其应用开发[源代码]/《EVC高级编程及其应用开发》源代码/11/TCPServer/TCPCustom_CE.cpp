// TCPCustom_CE.cpp: implementation of the CTCPCustom_CE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPServer.h"
#include "TCPCustom_CE.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//���캯��
CTCPCustom_CE::CTCPCustom_CE()
{
   //�����߳��˳��¼�
   m_exitThreadEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
}

//��������
CTCPCustom_CE::~CTCPCustom_CE()
{
   //�ر��߳��˳��¼�
   CloseHandle(m_exitThreadEvent);
}

/*--------------------------------------------------------------------
���������ܡ�:  ���߳����ڼ�����ͻ������ӵ�socketͨѶ���¼������統���յ����ݡ�
			   ���ӶϿ���ͨѶ���̷���������¼�
����ڲ�����:  lparam:������ָ�룬����ͨ���˲��������߳��д�����Ҫ�õ�����Դ��
			   ���������ǽ�CTCPCustom_CE��ʵ��ָ�봫����
�����ڲ�����:  (��)
������  ֵ��:  ����ֵû���ر�����壬�ڴ����ǽ�����ֵ��Ϊ0��
---------------------------------------------------------------------*/
DWORD CTCPCustom_CE::SocketThreadFunc(PVOID lparam)
{
	CTCPCustom_CE *pSocket;
	//�õ�CTCPCustom��ʵ��ָ��
	pSocket = (CTCPCustom_CE*)lparam;
	//������¼�����
	fd_set fdRead;  
	int ret;
	TIMEVAL	aTime;
	aTime.tv_sec = 1;
	aTime.tv_usec = 0;
	while (TRUE)
	{
        //�յ��˳��¼��������߳�
		if (WaitForSingleObject(pSocket->m_exitThreadEvent,0) == WAIT_OBJECT_0)
		{
			break;
		}
		//�ÿն��¼�����
		FD_ZERO(&fdRead);
		//��pSocket���ö��¼�
		FD_SET(pSocket->m_socket,&fdRead);
		//����select�������ж��Ƿ��ж��¼�����
		ret = select(0,&fdRead,NULL,NULL,&aTime);
		
		if (ret == SOCKET_ERROR)
		{
			//���������¼�
			pSocket->m_pTCPServer_CE->OnClientError(pSocket->m_pTCPServer_CE->m_pOwnerWnd,pSocket,1);
			//�ر�socket
			closesocket(pSocket->m_socket);
			break;
		}
		
		if (ret > 0)
		{
			//�ж��Ƿ���¼�
			if (FD_ISSET(pSocket->m_socket,&fdRead))
			{
				char recvBuf[1024];
				int recvLen;
				ZeroMemory(recvBuf,1024);
				recvLen = recv(pSocket->m_socket,recvBuf, 1024,0); 
				if (recvLen == SOCKET_ERROR)
				{
					int nErrorCode = WSAGetLastError();
					//������ͻ��˶����ӵ�Socket����
					pSocket->m_pTCPServer_CE->OnClientError(pSocket->m_pTCPServer_CE->m_pOwnerWnd,pSocket,nErrorCode);
					//������ͻ��˶����ӵ�Socket�ر��¼�
					pSocket->m_pTCPServer_CE->OnClientClose(pSocket->m_pTCPServer_CE->m_pOwnerWnd,pSocket);
					//�ر�socket
					closesocket(pSocket->m_socket);
					break;

				}
				//��ʾ�����Ѿ����ݹر�
				else if (recvLen == 0)
				{
					pSocket->m_pTCPServer_CE->OnClientClose(pSocket->m_pTCPServer_CE->m_pOwnerWnd,pSocket);
					//�ر�socket
					closesocket(pSocket->m_socket);
					break;
				}
				else
				{
				   //������ͻ��˶����ӵ�Socket���¼�
                   pSocket->m_pTCPServer_CE->OnClientRead(pSocket->m_pTCPServer_CE->m_pOwnerWnd,pSocket,recvBuf,recvLen);
				}
			}
		}
	}
	return 0;
}

/*--------------------------------------------------------------------
���������ܡ�: ��socket������ͨѶ�߳�
����ڲ�����:  pTCPServerָ��������˼���socket
�����ڲ�����:  (��)
������  ֵ��:  TRUE:�򿪳ɹ�;FALSE:��ʧ��
---------------------------------------------------------------------*/
bool CTCPCustom_CE::Open(CTCPServer_CE *pTCPServer)
{
   //����ͨѶ�߳�
   m_tcpThreadHandle = CreateThread(NULL,0,SocketThreadFunc,this,0,NULL);
   if (m_tcpThreadHandle == NULL)
   {
	   closesocket(m_socket);
	   return FALSE;
   }
   //����ͨѶģʽΪ�첽ģʽ
   DWORD ul= 1;
   ioctlsocket(m_socket,FIONBIO,&ul);
   m_pTCPServer_CE = pTCPServer;
   return TRUE;
}

/*--------------------------------------------------------------------
���������ܡ�: �ر�socket���ر��̣߳��ͷ�Socket��Դ
����ڲ�����:  (��)
�����ڲ�����:  (��)
������  ֵ��:  TRUE:�ɹ��ر�;FALSE:�ر�ʧ��
---------------------------------------------------------------------*/
bool CTCPCustom_CE::Close()
{
   //����ͨѶ�߳̽����¼�
   SetEvent(m_exitThreadEvent);
   Sleep(1000);
   //�ر�Socket���ͷ���Դ
   int err = closesocket(m_socket);
   if (err == SOCKET_ERROR)
   {
	   return FALSE;
   }
   return TRUE;
}


/*-----------------------------------------------------------------
���������ܡ�: ��ͻ��˷�������
����ڲ�����: buf:�����͵�����
              len:�����͵����ݳ���
�����ڲ�����: (��)
������  ֵ��: TRUE:�������ݳɹ�;FALSE:��������ʧ��
------------------------------------------------------------------*/
bool CTCPCustom_CE::SendData(const char * buf , int len)
{
	int nBytes = 0;
	int nSendBytes=0;
			
	while (nSendBytes < len)
	{
	    nBytes = send(m_socket,buf+nSendBytes,len-nSendBytes,0);
		if (nBytes==SOCKET_ERROR )
		{
			int iErrorCode = WSAGetLastError();
			//����socket��Error�¼�
			m_pTCPServer_CE->OnClientError(m_pTCPServer_CE->m_pOwnerWnd,this,iErrorCode);
			//������������˶Ͽ������¼�
			m_pTCPServer_CE->OnClientClose(m_pTCPServer_CE->m_pOwnerWnd,this);
			//�ر�socket
			Close();
			return FALSE;
		}

		nSendBytes = nSendBytes + nBytes;
		
		if (nSendBytes < len)
		{
		    Sleep(1000);
		}
	} 
	return TRUE; 
}
