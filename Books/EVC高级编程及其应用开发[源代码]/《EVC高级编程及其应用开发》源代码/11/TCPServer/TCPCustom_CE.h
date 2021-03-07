// TCPCustom_CE.h: interface for the CTCPCustom_CE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPCUSTOM_CE_H__0E8B4A18_8A99_438E_B5F6_B5985FFC117D__INCLUDED_)
#define AFX_TCPCUSTOM_CE_H__0E8B4A18_8A99_438E_B5F6_B5985FFC117D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <winsock.h>
#include "TCPServer_CE.h"

class CTCPCustom_CE  
{
public:
	CTCPCustom_CE();
	virtual ~CTCPCustom_CE();
public:
	CTCPServer_CE * m_pTCPServer_CE; //引用TCP服务端监听Socket

	CString m_RemoteHost; //远程主机IP地址
	DWORD m_RemotePort; //远程主机端口号
	SOCKET m_socket;      //通讯Socket句柄
private:
	HANDLE m_exitThreadEvent;  //通讯线程退出事件句柄
	HANDLE m_tcpThreadHandle;  //通讯线程句柄
private:
    //通讯线程函数
	static DWORD SocketThreadFunc(PVOID lparam);
public:
	//打开socket，创建通讯线程
	bool Open(CTCPServer_CE *pTCPServer);
    
	//关闭socket，关闭线程，释放Socket资源
	bool Close();

	//向客户端发送数据
	bool  SendData(const char * buf , int len);

};

#endif // !defined(AFX_TCPCUSTOM_CE_H__0E8B4A18_8A99_438E_B5F6_B5985FFC117D__INCLUDED_)
