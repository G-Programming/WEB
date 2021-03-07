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

//��ͷ
const LPCSTR FRAMEHEAD = "!@#$";
//��β
const LPCSTR FRAMETAIL = ")(*&";
//UDP�������ݰ��ṹ
typedef struct CUDPData
{
	char  FrameHead[4]; //֡ͷ
	DWORD DataPackageLen;  //֡����
	char * Buf;     //����������
    char FrameTail[4];   //֡β
}UDPData;

//UDP�ͻ��˷��ʹ���ص�����
typedef void (CALLBACK* ONUDPERROR)(CWnd*,int);
//UDP�ͻ��˽������ݻص�����
typedef void (CALLBACK* ONUDPRECV)(CWnd*,char* buf,int bufLen,sockaddr*);


class CUDP_CE  
{
public:
	CUDP_CE();
	virtual ~CUDP_CE();
public:
	//��UDPͨѶ
    DWORD Open(CWnd* pWnd,int localPort, LPCTSTR remoteHost ,int remotePort);
	//�ر�UDPͨѶ
	DWORD Close(void);

	//��������
	DWORD SendData(const char *buf, int len);
public:
    //UDP���������¼�
    ONUDPERROR m_OnUdpError;
	//UDP���������¼�
    ONUDPRECV  m_OnUdpRecv;

private:
	SOCKET m_UDPSocket;                   //UDP SocketͨѶ�׽���
    struct sockaddr_in m_RemoteAddr;      //�洢Զ��ͨѶ��ַ
    HANDLE m_ExitThreadEvent;             //�߳��˳��¼�
	CWnd * m_pOwnerWnd;                   //�洢��������


private:
	//ͨѶ�̺߳���
    static UINT RecvThread(LPVOID lparam);

	//�������
	bool HandlePackage(const char *inBuf,int inBufLen
					   ,char *outBuf,int &outBufLen);
	//�����Ӵ�
    int pos(LPCSTR aSubStr, const char *aBuf, int len);

};

#pragma pack(pop)
#endif // !defined(AFX_UDP_CE_H__9D1E867E_58EC_45C5_B886_3BC0E163A375__INCLUDED_)
