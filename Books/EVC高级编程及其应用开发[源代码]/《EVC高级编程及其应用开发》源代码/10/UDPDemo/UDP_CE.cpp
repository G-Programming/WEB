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
*函数介绍：打开UDP通讯端口
*入口参数：pWnd: 指定父窗体指针 
           localPort: 指定远程UDP端口
           romoteHost:指定远程IP地址
           remotePort:指定远程UDP端口
*出口参数：(无)
*返回值：1代表成功；-1，-2，-3等都代表失败
*/
DWORD CUDP_CE::Open(CWnd* pWnd,int localPort,LPCTSTR remoteHost,int remotePort)
{
	
	WSADATA wsa;
	
	m_pOwnerWnd = pWnd;
	
	//加载winsock动态链接库
	if (WSAStartup(MAKEWORD(1,1),&wsa) != 0)
	{
		return -1;//代表失败
	}
	
	//创建UDP套接字
	m_UDPSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (m_UDPSocket == INVALID_SOCKET)
	{
		return -2;
	}
	
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(localPort);
	localAddr.sin_addr.s_addr=INADDR_ANY;
	
	//绑定地址
	if(bind(m_UDPSocket,(sockaddr*)&localAddr,sizeof(localAddr))!=0)
	{
		return -3;
	}
	
	
	//设置非堵塞通讯
	DWORD ul= 1;
	ioctlsocket(m_UDPSocket,FIONBIO,&ul);

	//创建一个线程退出事件
	m_ExitThreadEvent	= CreateEvent(NULL,TRUE,FALSE,NULL);
	
	//创建通讯线程
	AfxBeginThread(RecvThread,this);
	
	m_RemoteAddr.sin_family = AF_INET;
	m_RemoteAddr.sin_port = htons(remotePort);
	//此处要将双字节转换成单字节
	char ansiRemoteHost[255];
	ZeroMemory(ansiRemoteHost,255);
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK,remoteHost,wcslen(remoteHost)
		,ansiRemoteHost,wcslen(remoteHost),NULL,NULL);
	m_RemoteAddr.sin_addr.s_addr=inet_addr(ansiRemoteHost);
	return 1;
}

/*
*函数介绍：关闭UDP通讯端口
*入口参数：(无)
*出口参数：(无)
*返 回 值：1代表成功；-1，-2等都代表失败
*/
DWORD CUDP_CE::Close(void)
{
	//设置通讯线程退出事件，通知线程退出
	SetEvent(m_ExitThreadEvent);
	Sleep(2000);
	//关闭线程句柄
	CloseHandle(m_ExitThreadEvent);
	//关闭socket
	if (closesocket(m_UDPSocket) == SOCKET_ERROR)
	{
		return -1;
	}
	
	//释放socket资源
	if (WSACleanup() == SOCKET_ERROR)
	{
		return -2;
	}
	return 1;
}

/*
*函数介绍：发送数据
*入口参数：dataPriority: 数据优先级 
           dataType: 数据类型
           buf:缓冲区数据
           len:缓冲数据长度
*出口参数：(无)
*返回值：发送成功代表实际发送的字节数，否则返回-1
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
	
	//发送数据
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
*函数介绍：接收线程函数
*入口参数：lparam : 指传进线程的参数
*出口参数：(无)
*返 回 值：无意义。
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
		
        //收到退出事件，结束线程
		if (WaitForSingleObject(pSocket->m_ExitThreadEvent,0) == WAIT_OBJECT_0)
		{
			break;
		}

		//将set初始化空集合
		FD_ZERO(&fdRead);
		
		//将pSocket->m_UDPSocket套接字添加到集合中
		FD_SET(pSocket->m_UDPSocket,&fdRead);
		
		//调用select函数，判断套接字I/O状态
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
					//此处添加解析程序，将接收到的数据解析后，
                    
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
*函数介绍：处理接收到的数据包
*入口参数：inBuf: 待处理的缓冲区
           inBufLen:待处理的缓冲区长度
*出口参数：dataPriority:数据优先级
           dataType:数据类型
           outBuf:处理后的缓冲区数据
           outBufLen:处理后的缓冲区数据长度
*返 回 值：合法则返回true,否则，返回false;
*/
bool CUDP_CE::HandlePackage(const char *inBuf,int inBufLen
							,char *outBuf,int &outBufLen)
{
	CString csBuf;
	csBuf = inBuf;
	int iPosHead = pos(FRAMEHEAD,inBuf,inBufLen);
	int iPosTail = pos(FRAMETAIL,inBuf,inBufLen);
	//没有查到包头或包尾
	if ((iPosHead == -1) || (iPosTail == -1))
	{
		return FALSE;
	}
	//如果包头位置大于等于包尾位置，就退出
	if (iPosHead >= iPosTail)
	{
		return FALSE;
	}
	//得到数据包长度
	int iPackLen;
	CopyMemory(&iPackLen,inBuf+iPosHead+4,4);
	//判断包长度是否正确
	if (iPackLen != iPosTail - iPosHead - 8)
	{
		return FALSE;
	}
	
	CopyMemory(outBuf,inBuf+8,iPackLen);
	outBufLen = iPackLen;
	return TRUE;
}

/*
*函数介绍：查找一个字符串的位置
*入口参数：aSubStr: 待查找的子串
           aBuf:待查找的缓冲区
           len:待查找的缓冲区长度
*出口参数：(无)
*返回值：找到的话，返回在父串中的位置，否则返回-1.
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