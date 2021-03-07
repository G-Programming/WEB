// UDP_CE.cpp: implementation of the CUDP_CE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UDPDemo.h"
#include "UDP_CE.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUDP_CE::CUDP_CE()
{
	
}

CUDP_CE::~CUDP_CE()
{
	
}


/*
*�������ܣ���UDPͨѶ�˿�
*��ڲ�����pWnd: ָ��������ָ�� 
           localPort: ָ��Զ��UDP�˿�
           romoteHost:ָ��Զ��IP��ַ
           remotePort:ָ��Զ��UDP�˿�
*���ڲ�����(��)
*����ֵ��1����ɹ���-1��-2��-3�ȶ�����ʧ��
*/
DWORD CUDP_CE::Open(CWnd* pWnd,int localPort,LPCTSTR remoteHost,int remotePort)
{
	
	WSADATA wsa;
	
	m_pOwnerWnd = pWnd;
	
	//����winsock��̬���ӿ�
	if (WSAStartup(MAKEWORD(1,1),&wsa) != 0)
	{
		return -1;//����ʧ��
	}
	
	//����UDP�׽���
	m_UDPSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (m_UDPSocket == INVALID_SOCKET)
	{
		return -2;
	}
	
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(localPort);
	localAddr.sin_addr.s_addr=INADDR_ANY;
	
	//�󶨵�ַ
	if(bind(m_UDPSocket,(sockaddr*)&localAddr,sizeof(localAddr))!=0)
	{
		return -3;
	}
	
	
	//���÷Ƕ���ͨѶ
	DWORD ul= 1;
	ioctlsocket(m_UDPSocket,FIONBIO,&ul);

	//����һ���߳��˳��¼�
	m_ExitThreadEvent	= CreateEvent(NULL,TRUE,FALSE,NULL);
	
	//����ͨѶ�߳�
	AfxBeginThread(RecvThread,this);
	
	m_RemoteAddr.sin_family = AF_INET;
	m_RemoteAddr.sin_port = htons(remotePort);
	//�˴�Ҫ��˫�ֽ�ת���ɵ��ֽ�
	char ansiRemoteHost[255];
	ZeroMemory(ansiRemoteHost,255);
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,remoteHost,wcslen(remoteHost)
		,ansiRemoteHost,wcslen(remoteHost),NULL,NULL);
	m_RemoteAddr.sin_addr.s_addr=inet_addr(ansiRemoteHost);
	return 1;
}

/*
*�������ܣ��ر�UDPͨѶ�˿�
*��ڲ�����(��)
*���ڲ�����(��)
*�� �� ֵ��1����ɹ���-1��-2�ȶ�����ʧ��
*/
DWORD CUDP_CE::Close(void)
{
	//����ͨѶ�߳��˳��¼���֪ͨ�߳��˳�
	SetEvent(m_ExitThreadEvent);
	Sleep(2000);
	//�ر��߳̾��
	CloseHandle(m_ExitThreadEvent);
	//�ر�socket
	if (closesocket(m_UDPSocket) == SOCKET_ERROR)
	{
		return -1;
	}
	
	//�ͷ�socket��Դ
	if (WSACleanup() == SOCKET_ERROR)
	{
		return -2;
	}
	return 1;
}

/*
*�������ܣ���������
*��ڲ�����dataPriority: �������ȼ� 
           dataType: ��������
           buf:����������
           len:�������ݳ���
*���ڲ�����(��)
*����ֵ�����ͳɹ�����ʵ�ʷ��͵��ֽ��������򷵻�-1
*/
DWORD CUDP_CE::SendData(const char *buf, int len)
{
	int nBytes = 0;
	int nSendBytes=0;
	int nSumBytes =0; 
	int nErrorCode;
	
	UDPData sendData;
	CopyMemory(sendData.FrameHead,FRAMEHEAD,4);
	sendData.DataPackageLen = len;
	CopyMemory(sendData.FrameTail,FRAMETAIL,4);
	
	nSumBytes = len + 12;	
	
	char * sendBuf;
	sendBuf = new char[nSumBytes];
	CopyMemory(sendBuf,sendData.FrameHead,4);
	CopyMemory(sendBuf+4,&(sendData.DataPackageLen),4);
	CopyMemory(sendBuf+8,buf,len);
	CopyMemory(sendBuf+8+len,sendData.FrameTail,4);
	
	//��������
	while (nSendBytes < nSumBytes)
	{
		nBytes = sendto(m_UDPSocket,sendBuf+nSendBytes,nSumBytes-nSendBytes,0,(sockaddr*)&m_RemoteAddr,sizeof(m_RemoteAddr));
		if (nBytes==SOCKET_ERROR )
		{
			nErrorCode = WSAGetLastError();
			m_OnUdpError(m_pOwnerWnd,nErrorCode);
			return -1;
		}
		if (nSendBytes == nSumBytes)
		{
			break;
		}
		Sleep(1000);
		nSendBytes = nSendBytes + nBytes;
	}
	delete[] sendBuf;
	return nSendBytes;
}


/*
*�������ܣ������̺߳���
*��ڲ�����lparam : ָ�����̵߳Ĳ���
*���ڲ�����(��)
*�� �� ֵ�������塣
*/
UINT CUDP_CE::RecvThread(LPVOID lparam)
{
	CUDP_CE *pSocket;
	pSocket = (CUDP_CE*)lparam;
	fd_set fdRead;
	int ret;
	TIMEVAL	aTime;
	char * recvBuf=NULL;
	aTime.tv_sec = 1;
	aTime.tv_usec = 0;
	SOCKADDR_IN tmpAddr;
	int tmpRecvLen;
	int recvLen;
	int iErrorCode;
	
	char * recvedBuf = NULL;
	int recvedBufLen;
	
	while (TRUE)
	{
		
        //�յ��˳��¼��������߳�
		if (WaitForSingleObject(pSocket->m_ExitThreadEvent,0) == WAIT_OBJECT_0)
		{
			break;
		}

		//��set��ʼ���ռ���
		FD_ZERO(&fdRead);
		
		//��pSocket->m_UDPSocket�׽�����ӵ�������
		FD_SET(pSocket->m_UDPSocket,&fdRead);
		
		//����select�������ж��׽���I/O״̬
		ret = select(0,&fdRead,NULL,NULL,&aTime);
		
		if (ret == SOCKET_ERROR)
		{
			iErrorCode = WSAGetLastError();
			pSocket->m_OnUdpError(pSocket->m_pOwnerWnd,iErrorCode);
			break;
		}
		
		if (ret > 0)
		{
			if (FD_ISSET(pSocket->m_UDPSocket,&fdRead))
			{
				
                tmpAddr.sin_family=AF_INET;             
                tmpAddr.sin_port = htons(pSocket->m_RemoteAddr.sin_port);
				tmpAddr.sin_addr.s_addr =INADDR_ANY;
                tmpRecvLen = sizeof(tmpAddr);
				
				
				recvBuf = new char[1024];
				recvedBuf = new char[1024];
				ZeroMemory(recvBuf,1024);
				ZeroMemory(recvedBuf,1024);
				recvLen = recvfrom(pSocket->m_UDPSocket,recvBuf, 1024,0,(SOCKADDR*)&tmpAddr,&tmpRecvLen); 
				if (recvLen == SOCKET_ERROR)
				{
					iErrorCode = WSAGetLastError();
					pSocket->m_OnUdpError(pSocket->m_pOwnerWnd,iErrorCode);
					break;
				}
				else if (recvLen == 0)
				{
					iErrorCode = WSAGetLastError();
					pSocket->m_OnUdpError(pSocket->m_pOwnerWnd,iErrorCode);	
					break;
				}
				else
				{
					//�˴���ӽ������򣬽����յ������ݽ�����
                    
					if (pSocket->HandlePackage(recvBuf,recvLen,recvedBuf,recvedBufLen))
					{
						pSocket->m_OnUdpRecv(pSocket->m_pOwnerWnd,recvedBuf,recvedBufLen,(SOCKADDR*)&tmpAddr);
					}
					delete []recvBuf;
					recvBuf = NULL;
					delete []recvedBuf;
					recvedBuf = NULL;
				}
				
			}
		}
	}
	return 0;
}

/*
*�������ܣ�������յ������ݰ�
*��ڲ�����inBuf: ������Ļ�����
           inBufLen:������Ļ���������
*���ڲ�����dataPriority:�������ȼ�
           dataType:��������
           outBuf:�����Ļ���������
           outBufLen:�����Ļ��������ݳ���
*�� �� ֵ���Ϸ��򷵻�true,���򣬷���false;
*/
bool CUDP_CE::HandlePackage(const char *inBuf,int inBufLen
							,char *outBuf,int &outBufLen)
{
	CString csBuf;
	csBuf = inBuf;
	int iPosHead = pos(FRAMEHEAD,inBuf,inBufLen);
	int iPosTail = pos(FRAMETAIL,inBuf,inBufLen);
	//û�в鵽��ͷ���β
	if ((iPosHead == -1) || (iPosTail == -1))
	{
		return FALSE;
	}
	//�����ͷλ�ô��ڵ��ڰ�βλ�ã����˳�
	if (iPosHead >= iPosTail)
	{
		return FALSE;
	}
	//�õ����ݰ�����
	int iPackLen;
	CopyMemory(&iPackLen,inBuf+iPosHead+4,4);
	//�жϰ������Ƿ���ȷ
	if (iPackLen != iPosTail - iPosHead - 8)
	{
		return FALSE;
	}
	
	CopyMemory(outBuf,inBuf+8,iPackLen);
	outBufLen = iPackLen;
	return TRUE;
}

/*
*�������ܣ�����һ���ַ�����λ��
*��ڲ�����aSubStr: �����ҵ��Ӵ�
           aBuf:�����ҵĻ�����
           len:�����ҵĻ���������
*���ڲ�����(��)
*����ֵ���ҵ��Ļ��������ڸ����е�λ�ã����򷵻�-1.
*/
int CUDP_CE::pos(LPCSTR aSubStr, const char *aBuf, int len)
{
	bool aResult = TRUE;
	int subLen = strlen(aSubStr);
    for ( int i=0;i<len-subLen+1;i++)
	{
		aResult = TRUE;
		for (int j=0;j<subLen;j++)
		{
			if (*(aBuf+i+j) != aSubStr[j])
			{
				aResult = FALSE;
				break;
			}
			int k = 0;
		}
		if (aResult)
		{
			return i;
		}
	}
	return -1;
}