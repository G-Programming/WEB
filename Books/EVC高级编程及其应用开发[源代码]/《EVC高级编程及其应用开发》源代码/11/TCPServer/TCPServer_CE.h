// TCPServer_CE.h: interface for the CTCPServer_CE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPSERVER_CE_H__711FE909_4A87_4123_95F8_45160691659D__INCLUDED_)
#define AFX_TCPSERVER_CE_H__711FE909_4A87_4123_95F8_45160691659D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <winsock.h>

class CTCPCustom_CE;
class CTCPServer_CE;

//定义客户端连接建立事件
typedef void (CALLBACK* ONCLIENTCONNECT)(CWnd*,CTCPCustom_CE*);
//定义客户端SOCKET关闭事件
typedef void (CALLBACK* ONCLIENTCLOSE)(CWnd*,CTCPCustom_CE*);
//定义客户端当有数据接收事件
typedef void (CALLBACK* ONCLIENTREAD)(CWnd*,CTCPCustom_CE*,const char * buf,int len );
//定义客户端Socket错误事件
typedef void (CALLBACK* ONCLIENTERROR)(CWnd*,CTCPCustom_CE*,int nErrorCode);

//定义服务器端Socket错误事件
typedef void (CALLBACK* ONSERVERERROR)(CWnd*,CTCPServer_CE*,int nErrorCode);

class CTCPServer_CE  
{
public:
	CTCPServer_CE();
	virtual ~CTCPServer_CE();
public:
  int Open(); //打开TCP服务
  int Close(); //关闭TCP服务 
private:
	//线程处理函数
	static DWORD SocketThreadFunc(PVOID lparam);
public:
	int m_LocalPort; //设置服务端口号
	CWnd * m_pOwnerWnd;   //父窗口句柄
private:
	SOCKET m_ServerSocket;     //TCP服务监听socket
	HANDLE m_serverThreadHandle;  //通讯线程句柄
	HANDLE m_exitThreadEvent;  //通讯线程退出事件句柄
public:  //定义事件
	//客户端连接建立事件，回调函数
	ONCLIENTCONNECT    OnClientConnect;
	//客户端连接断开事件，回调函数
	ONCLIENTCLOSE OnClientClose;
	//客户端接收数据事件，回调函数
	ONCLIENTREAD       OnClientRead;
	//客户端发生错误事件，回调函数
	ONCLIENTERROR      OnClientError;
	//服务器端发生错误事件,回调函数
	ONSERVERERROR	   OnServerError;

};

#endif // !defined(AFX_TCPSERVER_CE_H__711FE909_4A87_4123_95F8_45160691659D__INCLUDED_)
