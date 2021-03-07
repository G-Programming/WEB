// UDP_CE.h: interface for the CUDP_CE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDP_CE_H__9D1E867E_58EC_45C5_B886_3BC0E163A375__INCLUDED_)
#define AFX_UDP_CE_H__9D1E867E_58EC_45C5_B886_3BC0E163A375__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WinSock.h"

#pragma pack(push,1)

//包头
const LPCSTR FRAMEHEAD = "!@#$";
//包尾
const LPCSTR FRAMETAIL = ")(*&";
//UDP传输数据包结构
typedef struct CUDPData
{
	char  FrameHead[4]; //帧头
	DWORD DataPackageLen;  //帧长度
	char * Buf;     //缓冲区数据
    char FrameTail[4];   //帧尾
}UDPData;

//UDP客户端发送错误回调函数
typedef void (CALLBACK* ONUDPERROR)(CWnd*,int);
//UDP客户端接收数据回调函数
typedef void (CALLBACK* ONUDPRECV)(CWnd*,char* buf,int bufLen,sockaddr*);


class CUDP_CE  
{
public:
	CUDP_CE();
	virtual ~CUDP_CE();
public:
	//打开UDP通讯
    DWORD Open(CWnd* pWnd,int localPort, LPCTSTR remoteHost ,int remotePort);
	//关闭UDP通讯
	DWORD Close(void);

	//发送数据
	DWORD SendData(const char *buf, int len);
public:
    //UDP发生错误事件
    ONUDPERROR m_OnUdpError;
	//UDP接收数据事件
    ONUDPRECV  m_OnUdpRecv;

private:
	SOCKET m_UDPSocket;                   //UDP Socket通讯套接字
    struct sockaddr_in m_RemoteAddr;      //存储远程通讯地址
    HANDLE m_ExitThreadEvent;             //线程退出事件
	CWnd * m_pOwnerWnd;                   //存储父窗体句柄


private:
	//通讯线程函数
    static UINT RecvThread(LPVOID lparam);

	//拆包函数
	bool HandlePackage(const char *inBuf,int inBufLen
					   ,char *outBuf,int &outBufLen);
	//查找子串
    int pos(LPCSTR aSubStr, const char *aBuf, int len);

};

#pragma pack(pop)
#endif // !defined(AFX_UDP_CE_H__9D1E867E_58EC_45C5_B886_3BC0E163A375__INCLUDED_)
