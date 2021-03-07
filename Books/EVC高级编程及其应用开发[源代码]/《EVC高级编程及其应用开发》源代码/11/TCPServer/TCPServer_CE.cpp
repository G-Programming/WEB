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
//存储客户端Socket句柄
CList<CTCPCustom_CE,CTCPCustom_CE&> m_ListClientSocket;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//构造函数
CTCPServer_CE::CTCPServer_CE()
{
	//创建线程退出事件句柄
	m_exitThreadEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
}
//析构函数
CTCPServer_CE::~CTCPServer_CE()
{
	//关闭线程退出事件句柄
	CloseHandle(m_exitThreadEvent);
}

/*--------------------------------------------------------------------
【函数介绍】:  此线程用于检测监听套接字事件。
【入口参数】:  lparam:无类型指针，可以通过此参数，向线程中传入需要用到的资源。
			   在这里我们将CTCPServer_CE类实例指针传进来
【出口参数】:  (无)
【返回  值】:  返回值没有特别的意义，在此我们将返回值设为0。
---------------------------------------------------------------------*/
DWORD CTCPServer_CE::SocketThreadFunc(PVOID lparam)
{
	CTCPServer_CE *pSocket;
	//得到CTCPServer_CE实例指针
	pSocket = (CTCPServer_CE*)lparam;
	//定义读事件集合
	fd_set fdRead;
	int ret;
	TIMEVAL	aTime;
	aTime.tv_sec = 1;
	aTime.tv_usec = 1;
	while (TRUE)
	{
        //收到退出事件，结束线程
		if (WaitForSingleObject(pSocket->m_exitThreadEvent,0) == WAIT_OBJECT_0)
		{
			break;
		}
		
		FD_ZERO(&fdRead);
		FD_SET(pSocket->m_ServerSocket,&fdRead);
		
		ret = select(0,&fdRead,NULL,NULL,&aTime);
		
		if (ret == SOCKET_ERROR)
		{
			//触发错误事件
			int iErrorCode = WSAGetLastError();
			//触发服务器socket的错误事件
			pSocket->OnServerError(pSocket->m_pOwnerWnd,pSocket,iErrorCode);
			//关闭服务器套接字 
			closesocket(pSocket->m_ServerSocket);
			break;
		}
		
		if (ret > 0)
		{
			//判断是否读事件
			if (FD_ISSET(pSocket->m_ServerSocket,&fdRead))
			{
				//如果调用了Listen，则表示触发了OnAccept事件
				
				SOCKADDR_IN clientAddr;
				CTCPCustom_CE * pClientSocket = new CTCPCustom_CE();
				int namelen = sizeof(clientAddr);
				//等待，创建与客户端连接的套接字
				pClientSocket->m_socket = accept(pSocket->m_ServerSocket, (struct sockaddr *)&clientAddr, &namelen);
				//接收到客户端连接
				if (pClientSocket->m_socket)
				{
					pClientSocket->m_RemoteHost = inet_ntoa(clientAddr.sin_addr);
					pClientSocket->m_RemotePort = ntohs(clientAddr.sin_port);
					
					//触发与客户端建立连接事件
					pSocket->OnClientConnect(pSocket->m_pOwnerWnd,pClientSocket);
					//打开pClientSocket服务线程
					pClientSocket->Open(pSocket);
					//添加到客户端连接队列中
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
【函数介绍】:  打开TCP服务
【入口参数】:  (无)
【出口参数】:  (无)
【返回  值】:  <=0:打开TCP服务失败; =1:打开TCP服务成功
---------------------------------------------------------------------*/
int CTCPServer_CE::Open()
{
	WSADATA wsa;
	
	//1.初始化socket资源
	if (WSAStartup(MAKEWORD(1,1),&wsa) != 0)
	{
		return -1;//代表失败
	}
	
	//2.创建监听套接字
	if ((m_ServerSocket=socket(AF_INET, SOCK_STREAM, 0))<0)
	{
		return -2;
	}
	
    SOCKADDR_IN  serverAddr;
	ZeroMemory((char *)&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(m_LocalPort);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//3.绑定监听套接字
	if (bind(m_ServerSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr))<0)
	{
		
		return -3 ;
	}
	//4.监听套接字开始监听
	if (listen(m_ServerSocket,8)!=0)
	{
		return -3;
	}
	
	//4.设置监听套接字通讯模式为异步模式
	DWORD ul= 1;
	ioctlsocket(m_ServerSocket,FIONBIO,&ul);

	ResetEvent(m_exitThreadEvent);
	//5.创建通讯线程，在线程里，等待客户端接入
	m_serverThreadHandle = CreateThread(NULL,0,SocketThreadFunc,this,0,NULL);
	if (m_serverThreadHandle == NULL)
	{
		closesocket(m_ServerSocket);
		return -1;
	}

	return 1;
}


/*--------------------------------------------------------------------
【函数介绍】:  关闭TCP服务
【入口参数】:  (无)
【出口参数】:  (无)
【返回  值】:  <=0:关闭TCP服务失败; =1:关闭TCP服务成功
---------------------------------------------------------------------*/
int CTCPServer_CE::Close()
{
	//结束通讯线程
	SetEvent(m_exitThreadEvent);
	Sleep(1000);
	//关闭Socket，释放资源
	int err = closesocket(m_ServerSocket);
	if (err == SOCKET_ERROR)
	{
		return -1;
	}
	m_ServerSocket = NULL;

	//首先，关闭与所有客户端连接
	POSITION pos = m_ListClientSocket.GetHeadPosition();
	while (pos != NULL)
	{
        CTCPCustom_CE &tmpTcpCustom = m_ListClientSocket.GetAt(pos);
		if (!tmpTcpCustom.Close())
		{
			AfxMessageBox(L"关闭客户端socket错误");
		}
		m_ListClientSocket.RemoveHead();
		pos = m_ListClientSocket.GetHeadPosition();
	}
	
	WSACleanup();
	return 1;
}  
