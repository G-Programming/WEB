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
	CTCPServer_CE * m_pTCPServer_CE; //����TCP����˼���Socket

	CString m_RemoteHost; //Զ������IP��ַ
	DWORD m_RemotePort; //Զ�������˿ں�
	SOCKET m_socket;      //ͨѶSocket���
private:
	HANDLE m_exitThreadEvent;  //ͨѶ�߳��˳��¼����
	HANDLE m_tcpThreadHandle;  //ͨѶ�߳̾��
private:
    //ͨѶ�̺߳���
	static DWORD SocketThreadFunc(PVOID lparam);
public:
	//��socket������ͨѶ�߳�
	bool Open(CTCPServer_CE *pTCPServer);
    
	//�ر�socket���ر��̣߳��ͷ�Socket��Դ
	bool Close();

	//��ͻ��˷�������
	bool  SendData(const char * buf , int len);

};

#endif // !defined(AFX_TCPCUSTOM_CE_H__0E8B4A18_8A99_438E_B5F6_B5985FFC117D__INCLUDED_)
