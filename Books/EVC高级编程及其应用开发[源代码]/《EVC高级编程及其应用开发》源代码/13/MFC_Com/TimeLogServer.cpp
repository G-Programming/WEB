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

//实现类厂
IMPLEMENT_OLECREATE(CTimeLogServer,"TimeLogServer",
           0x50AF86CD,0xAAF2,0x43B8,0x88,0x02,0x48,0x3C,0xFF,0x78,0xEF,0x38);
//映射接口到相应的嵌套类
BEGIN_INTERFACE_MAP(CTimeLogServer,CCmdTarget)
  INTERFACE_PART(CTimeLogServer,IID_ITimeLog,TimeLog)
END_INTERFACE_MAP()

//构造函数
CTimeLogServer::CTimeLogServer()
{
	
	//增加全局对象计数
	::AfxOleLockApp();
	//得到系统当前时间
	CTime TimeStamp = CTime::GetCurrentTime();
	//设置日志文件名，用当前日期来给日志文件命名
	CString FileName;
	CString strTmp;
	strTmp.Format(_T("%d-%d-%d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay());
	FileName.Format(_T("%s.log"),strTmp);
	//打开日志文件，参数a表示，打开文件后，在文件尾部追加写入信息
	//，同时如果指定的文件不存在，就新建一个文件。
	m_logfile = _wfopen(FileName,_T("a"));
	//如果打开日志文件成功的话，记录初始化日志信息
	if(m_logfile)
	{
		fwprintf(m_logfile,_T("# # # # # # # # # # # # # # # # # \n"));
		strTmp.Format(_T("%d年%d月%d日%d:%d %d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay(),
			TimeStamp.GetHour(),TimeStamp.GetMinute(),TimeStamp.GetSecond());
		fwprintf(m_logfile,_T("开始于:%s"),strTmp);
		fwprintf(m_logfile,_T("\n"));
	}
}

//析构函数
CTimeLogServer::~CTimeLogServer()
{
	//减少全局对象计数
	::AfxOleUnlockApp();

	//关闭已打开的日志文件
	CString strTmp;
	if(m_logfile)
	{
		//写入日志结束信息
		CTime TimeStamp = CTime::GetCurrentTime();
		fwprintf(m_logfile,_T("\n"));
		strTmp.Format(_T("%d年%d月%d日%d:%d %d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay(),
			TimeStamp.GetHour(),TimeStamp.GetMinute(),TimeStamp.GetSecond());
		fwprintf(m_logfile,_T("结束于:%s"),strTmp);
        fwprintf(m_logfile,_T("\n"));
		fwprintf(m_logfile,_T("# # # # # # # # # # # # # # # # #\n"));
		//关闭日志文件
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


//为XTimeLog嵌套类实现IUnknown接口

//实现IUnknown接口的AddRef方法
STDMETHODIMP_(ULONG) 
CTimeLogServer::XTimeLog::AddRef()
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	return pThis->ExternalAddRef();
}

//实现IUnknown接口的Release()方法
STDMETHODIMP_(ULONG)
CTimeLogServer::XTimeLog::Release()
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	return pThis->ExternalRelease();
}

//实现IUnknown接口的QueryInterface方法
STDMETHODIMP
CTimeLogServer::XTimeLog::QueryInterface(REFIID riid,void**ppvObj)
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	return pThis->ExternalQueryInterface(&riid,ppvObj);
}

//实现ITimeLog接口的写日志方法OutputLog
STDMETHODIMP
CTimeLogServer::XTimeLog::OutputLog(BSTR* varLogText)
{
	METHOD_PROLOGUE(CTimeLogServer,TimeLog)
	if(pThis->m_logfile)
	{
		CTime TimeStamp = CTime::GetCurrentTime();

		CString NowTime;
		NowTime.Format(_T("%d年%d月%d日%d:%d %d"),TimeStamp.GetYear(),TimeStamp.GetMonth(),TimeStamp.GetDay(),
			TimeStamp.GetHour(),TimeStamp.GetMinute(),TimeStamp.GetSecond());

		CString LogText((LPCWSTR)*varLogText);
		fwprintf(pThis->m_logfile,L"\n%s\n%s\n%",NowTime,LogText);
		return NOERROR;
	}
	else
	{
		AfxMessageBox(L"没有日志文件!");
		return S_FALSE;
	}
}
