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

//����ͻ������ӽ����¼�
typedef void (CALLBACK* ONCLIENTCONNECT)(CWnd*,CTCPCustom_CE*);
//����ͻ���SOCKET�ر��¼�
typedef void (CALLBACK* ONCLIENTCLOSE)(CWnd*,CTCPCustom_CE*);
//����ͻ��˵������ݽ����¼�
typedef void (CALLBACK* ONCLIENTREAD)(CWnd*,CTCPCustom_CE*,const char * buf,int len );
//����ͻ���Socket�����¼�
typedef void (CALLBACK* ONCLIENTERROR)(CWnd*,CTCPCustom_CE*,int nErrorCode);

//�����������Socket�����¼�
typedef void (CALLBACK* ONSERVERERROR)(CWnd*,CTCPServer_CE*,int nErrorCode);

class CTCPServer_CE  
{
public:
	CTCPServer_CE();
	virtual ~CTCPServer_CE();
public:
  int Open(); //��TCP����
  int Close(); //�ر�TCP���� 
private:
	//�̴߳�����
	static DWORD SocketThreadFunc(PVOID lparam);
public:
	int m_LocalPort; //���÷���˿ں�
	CWnd * m_pOwnerWnd;   //�����ھ��
private:
	SOCKET m_ServerSocket;     //TCP�������socket
	HANDLE m_serverThreadHandle;  //ͨѶ�߳̾��
	HANDLE m_exitThreadEvent;  //ͨѶ�߳��˳��¼����
public:  //�����¼�
	//�ͻ������ӽ����¼����ص�����
	ONCLIENTCONNECT    OnClientConnect;
	//�ͻ������ӶϿ��¼����ص�����
	ONCLIENTCLOSE OnClientClose;
	//�ͻ��˽��������¼����ص�����
	ONCLIENTREAD       OnClientRead;
	//�ͻ��˷��������¼����ص�����
	ONCLIENTERROR      OnClientError;
	//�������˷��������¼�,�ص�����
	ONSERVERERROR	   OnServerError;

};

#endif // !defined(AFX_TCPSERVER_CE_H__711FE909_4A87_4123_95F8_45160691659D__INCLUDED_)
