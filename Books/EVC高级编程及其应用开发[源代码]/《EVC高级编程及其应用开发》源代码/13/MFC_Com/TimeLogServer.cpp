// TimeLogServer.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "TimeLogServer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeLogServer

IMPLEMENT_DYNCREATE(CTimeLogServer, CCmdTarget)

//ʵ���೧
IMPLEMENT_OLECREATE(CTimeLogServer,"TimeLogServer",
           0x50AF86CD,0xAAF2,0x43B8,0x88,0x02,0x48,0x3C,0xFF,0x78,0xEF,0x38);
//ӳ��ӿڵ���Ӧ��Ƕ����
BEGIN_INTERFACE_MAP(CTimeLogServer,CCmdTarget)
  INTERFACE_PART(CTimeLogServer,IID_ITimeLog,TimeLog)
END_INTERFACE_MAP()

//���캯��
CTimeLogServer::CTimeLogServer()
{
	
	//����ȫ�ֶ������
	::AfxOleLockApp();
	//�õ�ϵͳ��ǰʱ��
	CTime TimeStamp = CTime::GetCurrentTime();
	//������־�ļ������õ�ǰ����������־�ļ�����
	CString FileName;
	CString strTmp;
	strTmp.Format(_T("%d-%d-%d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay());
	FileName.Format(_T("%s.log"),strTmp);
	//����־�ļ�������a��ʾ�����ļ������ļ�β��׷��д����Ϣ
	//��ͬʱ���ָ�����ļ������ڣ����½�һ���ļ���
	m_logfile = _wfopen(FileName,_T("a"));
	//�������־�ļ��ɹ��Ļ�����¼��ʼ����־��Ϣ
	if(m_logfile)
	{
		fwprintf(m_logfile,_T("# # # # # # # # # # # # # # # # # \n"));
		strTmp.Format(_T("%d��%d��%d��%d:%d %d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay(),
			TimeStamp.GetHour(),TimeStamp.GetMinute(),TimeStamp.GetSecond());
		fwprintf(m_logfile,_T("��ʼ��:%s"),strTmp);
		fwprintf(m_logfile,_T("\n"));
	}
}

//��������
CTimeLogServer::~CTimeLogServer()
{
	//����ȫ�ֶ������
	::AfxOleUnlockApp();

	//�ر��Ѵ򿪵���־�ļ�
	CString strTmp;
	if(m_logfile)
	{
		//д����־������Ϣ
		CTime TimeStamp = CTime::GetCurrentTime();
		fwprintf(m_logfile,_T("\n"));
		strTmp.Format(_T("%d��%d��%d��%d:%d %d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay(),
			TimeStamp.GetHour(),TimeStamp.GetMinute(),TimeStamp.GetSecond());
		fwprintf(m_logfile,_T("������:%s"),strTmp);
        fwprintf(m_logfile,_T("\n"));
		fwprintf(m_logfile,_T("# # # # # # # # # # # # # # # # #\n"));
		//�ر���־�ļ�
		fclose(m_logfile);
	}
}


BEGIN_MESSAGE_MAP(CTimeLogServer, CCmdTarget)
	//{{AFX_MSG_MAP(CTimeLogServer)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeLogServer message handlers


//ΪXTimeLogǶ����ʵ��IUnknown�ӿ�

//ʵ��IUnknown�ӿڵ�AddRef����
STDMETHODIMP_(ULONG) 
CTimeLogServer::XTimeLog::AddRef()
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	return pThis->ExternalAddRef();
}

//ʵ��IUnknown�ӿڵ�Release()����
STDMETHODIMP_(ULONG)
CTimeLogServer::XTimeLog::Release()
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	return pThis->ExternalRelease();
}

//ʵ��IUnknown�ӿڵ�QueryInterface����
STDMETHODIMP
CTimeLogServer::XTimeLog::QueryInterface(REFIID riid,void**ppvObj)
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	return pThis->ExternalQueryInterface(&riid,ppvObj);
}

//ʵ��ITimeLog�ӿڵ�д��־����OutputLog
STDMETHODIMP
CTimeLogServer::XTimeLog::OutputLog(BSTR* varLogText)
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	if(pThis->m_logfile)
	{
		CTime TimeStamp = CTime::GetCurrentTime();

		CString NowTime;
		NowTime.Format(_T("%d��%d��%d��%d:%d %d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay(),
			TimeStamp.GetHour(),TimeStamp.GetMinute(),TimeStamp.GetSecond());

		CString LogText((LPCWSTR)*varLogText);
		fwprintf(pThis->m_logfile,L"\n%s\n%s\n%",NowTime,LogText);
		return NOERROR;
	}
	else
	{
		AfxMessageBox(L"û����־�ļ�!");
		return S_FALSE;
	}
}
