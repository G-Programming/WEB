// CESeries.cpp: implementation of the CCESeries class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SeriesSample.h"
#include "CESeries.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//������д�̷߳��͵���Ϣ����
const CM_THREADCOMMWRITE = WM_USER+110;

//��CCESeries���캯��
CCESeries::CCESeries()
{
	m_hComm = INVALID_HANDLE_VALUE;
	
}

//��CCESeries��������
CCESeries::~CCESeries()
{
	
}

/*
*�������ܣ��򿪴���
*��ڲ�����pPortOwner	:ʹ�ô˴�����Ĵ�����
		   portNo		:���ں�
		   baud			:������
		   parity		:��żУ��
		   databits		:����λ
		   stopbits		:ֹͣλ
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ��򿪴���;FALSE:�򿪴���ʧ��
*/
BOOL CCESeries::OpenPort(CWnd* pPortOwner,			/*ʹ�ô����࣬������*/
						 UINT portNo	,			/*���ں�*/
						 UINT baud		,			/*������*/
						 UINT parity	,			/*��żУ��*/
						 UINT databits	,			/*����λ*/
						 UINT stopbits			   /*ֹͣλ*/
						 )
{
	DCB commParam;
	TCHAR szPort[15];	
	
	// �Ѿ��򿪵Ļ���ֱ�ӷ���
	if (m_hComm != INVALID_HANDLE_VALUE)
	{
		return TRUE;
	}
	ASSERT(pPortOwner != NULL);
	ASSERT(portNo > 0 && portNo < 5);
	
	//���ô�����
	wsprintf(szPort, L"COM%d:", portNo);
	//�򿪴���
	m_hComm = CreateFile(
		szPort,
		GENERIC_READ | GENERIC_WRITE,	//�������д
		0,								//��ռ��ʽ������ģʽ��
		NULL,
		OPEN_EXISTING,					//�򿪶����Ǵ�����������ʽ��
		0,
		NULL 
		);
	
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		// ��Ч���,���ء�		
		TRACE(_T("CreateFile ������Ч���"));
		return FALSE;
		
	}
	
	// �õ��򿪴��ڵĵ�ǰ���Բ������޸ĺ����������ô��ڡ�
	// ���ô��ڵĳ�ʱ����Ϊ�������ء�
	
	if (!GetCommState(m_hComm,&commParam))
	{		
		return FALSE;
	}
	
	commParam.BaudRate = baud;					// ���ò����� 
	commParam.fBinary = TRUE;					// ���ö�����ģʽ���˴���������TRUE
	commParam.fParity = TRUE;					// ֧����żУ�� 
	commParam.ByteSize = databits;				// ����λ,��Χ:4-8 
	commParam.Parity = NOPARITY;				// У��ģʽ
	commParam.StopBits = stopbits;				// ֹͣλ 
	
	commParam.fOutxCtsFlow = FALSE;				// No CTS output flow control 
	commParam.fOutxDsrFlow = FALSE;				// No DSR output flow control 
	commParam.fDtrControl = DTR_CONTROL_ENABLE; 
	// DTR flow control type 
	commParam.fDsrSensitivity = FALSE;			// DSR sensitivity 
	commParam.fTXContinueOnXoff = TRUE;			// XOFF continues Tx 
	commParam.fOutX = FALSE;					// No XON/XOFF out flow control 
	commParam.fInX = FALSE;						// No XON/XOFF in flow control 
	commParam.fErrorChar = FALSE;				// Disable error replacement 
	commParam.fNull = FALSE;					// Disable null stripping 
	commParam.fRtsControl = RTS_CONTROL_ENABLE; 
	// RTS flow control 
	commParam.fAbortOnError = FALSE;			// �����ڷ������󣬲�����ֹ���ڶ�д
	
	if (!SetCommState(m_hComm, &commParam))
	{
		TRACE(_T("SetCommState error"));		
		return FALSE;
	}
	
	
    //���ô��ڶ�дʱ��
	COMMTIMEOUTS CommTimeOuts;
	GetCommTimeouts (m_hComm, &CommTimeOuts);
	CommTimeOuts.ReadIntervalTimeout = MAXDWORD;  
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;  
	CommTimeOuts.ReadTotalTimeoutConstant = 0;    
	CommTimeOuts.WriteTotalTimeoutMultiplier = 10;  
	CommTimeOuts.WriteTotalTimeoutConstant = 1000;  
	
	if(!SetCommTimeouts( m_hComm, &CommTimeOuts ))
	{
		TRACE( _T("SetCommTimeouts ���ش���") );
		return FALSE;
	}
	
	m_pPortOwner = pPortOwner;	
	
	//ָ���˿ڼ����¼���
	SetCommMask (m_hComm, EV_RXCHAR);
	
	//�����豸������
	SetupComm(m_hComm,512,512);
	
	//��ʼ���������е���Ϣ
	PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
	
	m_hReadCloseEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	m_hWriteCloseEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	//�����������߳�
	m_hReadThread = CreateThread(NULL,0,ReadThreadFunc,this,0,&m_dwReadThreadID);
	//����д�����߳�
	m_hWriteThread = CreateThread(NULL,0,WriteThreadFunc,this,0,&m_dwWriteThreadID);
	
	TRACE(_T("���ڴ򿪳ɹ�"));
	
	return TRUE;
}

/*
*�������ܣ��رմ���
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��  (��)
*/
void CCESeries::ClosePort()
{	
	//��ʾ���ڻ�û�д�
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return ;
	}
	
	//�رն��߳�
	CloseReadThread();
	//�ر�д�߳�
	CloseWriteThread();
	
	//�رմ���
	if (!CloseHandle (m_hComm))
	{
		m_hComm = INVALID_HANDLE_VALUE;
		return ;
	}
}


/*
*�������ܣ��򴮿ڷ�������
*��ڲ�����buf		: ��Ҫ������д������ݵĻ�����
		   bufLen	: ��Ҫ������д������ݵĻ���������
*���ڲ�����(��)
*����ֵ��TRUE:��ʾ�ɹ��ؽ�Ҫ���͵����ݴ��ݵ�д�߳���Ϣ���С�
		 FALSE:��ʾ��Ҫ���͵����ݴ��ݵ�д�߳���Ϣ����ʧ�ܡ�
		 ע�ӣ��˴���TRUE,��ֱ�Ӵ�������һ���ɹ�д�뵽�����ˡ�
*/
BOOL CCESeries::WritePort(const BYTE *buf,DWORD bufLen)
{
	//��Ҫ���͵����ݴ��ݵ�д�߳���Ϣ����
	if (PostThreadMessage(m_dwWriteThreadID,CM_THREADCOMMWRITE,
		WPARAM(bufLen), LPARAM(buf)))
	{
		return TRUE;
	}
	
	return FALSE;
}

/*
*�������ܣ����ô��ڶ�ȡ��д�볬ʱ
*��ڲ�����CommTimeOuts : ָ��COMMTIMEOUTS�ṹ
*���ڲ�����(��)
*����ֵ��TRUE:���óɹ�;FALSE:����ʧ��
*/
BOOL CCESeries::SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);
	return SetCommTimeouts(m_hComm,&CommTimeOuts);
}


//���ڶ��̺߳���
DWORD CCESeries::ReadThreadFunc(LPVOID lparam)
{
	CCESeries *ceSeries = (CCESeries*)lparam;
	
	DWORD	evtMask;
	BYTE * readBuf = NULL;//��ȡ���ֽ�
	DWORD actualReadLen=0;//ʵ�ʶ�ȡ���ֽ���
	DWORD willReadLen;
	
	DWORD dwReadErrors;
	COMSTAT	cmState;
	
	// ��ջ��壬����鴮���Ƿ�򿪡�
	ASSERT(ceSeries->m_hComm !=INVALID_HANDLE_VALUE); 
	
	
	//��մ���
	PurgeComm(ceSeries->m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR );
	
	SetCommMask (ceSeries->m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
	while (TRUE)
	{   	
		if (WaitCommEvent(ceSeries->m_hComm,&evtMask,0))
		{			
			SetCommMask (ceSeries->m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
			//��ʾ�����յ��ַ�		
			if (evtMask & EV_RXCHAR) 
			{
				
				ClearCommError(ceSeries->m_hComm,&dwReadErrors,&cmState);
				willReadLen = cmState.cbInQue ;
				if (willReadLen <= 0)
				{
					continue;
				}
				
				readBuf = new BYTE[willReadLen];
				ReadFile(ceSeries->m_hComm, readBuf, willReadLen, &actualReadLen,0);
				
				//�����ȡ�����ݴ���0��
				if (actualReadLen>0)
				{
					//������ȡ�ص�����
					ceSeries->m_OnSeriesRead(ceSeries->m_pPortOwner,readBuf,actualReadLen);
				}
			}
		}
		//����յ����߳��˳��źţ����˳��߳�
		if (WaitForSingleObject(ceSeries->m_hReadCloseEvent,500) == WAIT_OBJECT_0)
		{
			break;
		}
	}
	return 0;
}

//����д�̺߳���
DWORD CCESeries::WriteThreadFunc(LPVOID lparam)
{
	CCESeries *ceSeries = (CCESeries*)lparam;
	MSG msg;
	DWORD dwWriteLen = 0;
	BYTE * buf = NULL;
	
	while (TRUE)
	{
		//�����׽���߳���Ϣ
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.hwnd != 0 )
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				continue;
			}
			if (msg.message == CM_THREADCOMMWRITE)
			{
				//�򴮿�д
				buf = (BYTE*)msg.lParam;
				dwWriteLen = msg.wParam;
				//�򴮿�д
				WritePort(ceSeries->m_hComm,buf,dwWriteLen);
				//ɾ����̬������ڴ�
				delete[] buf;
			}
		}
		//����յ�д�߳��˳��źţ����˳��߳�
		if (WaitForSingleObject(ceSeries->m_hWriteCloseEvent,500) == WAIT_OBJECT_0)
		{
			break;
		}
		ceSeries->m_hWriteThread = NULL;
	}
	
	return 0;
}


//˽�÷����������򴮿�д���ݣ���д�̵߳���
BOOL CCESeries::WritePort(HANDLE hComm,const BYTE *buf,DWORD bufLen)
{
	DWORD dwNumBytesWritten;
	DWORD dwHaveNumWritten =0 ; //�Ѿ�д�����
	
	ASSERT(hComm != INVALID_HANDLE_VALUE);
	do
	{
		if (WriteFile (hComm,					//���ھ�� 
			buf+dwHaveNumWritten,				//��д���ݻ����� 
			bufLen - dwHaveNumWritten,          //��д���ݻ�������С
			&dwNumBytesWritten,					//����ִ�гɹ��󣬷���ʵ���򴮿�д�ĸ���	
			NULL))								//�˴���������NULL
		{
			dwHaveNumWritten = dwHaveNumWritten + dwNumBytesWritten;
			//д�����
			if (dwHaveNumWritten == bufLen)
			{
				break;
			}
			Sleep(10);
		}
		else
		{
			return FALSE;
		}
	}while (TRUE);
	
	return TRUE;	
}



//�رն��߳�
void CCESeries::CloseReadThread()
{
	SetEvent(m_hReadCloseEvent);
	//���������¼���Ч��Ч
	SetCommMask(m_hComm, 0);
	//������н�Ҫ��������
    PurgeComm( m_hComm,  PURGE_RXCLEAR );
    //�ȴ�10�룬������߳�û���˳�����ǿ���˳�
    if (WaitForSingleObject(m_hReadThread,10000) == WAIT_TIMEOUT)
	{
		TerminateThread(m_hReadThread,0);
	}
	m_hReadThread = NULL;
}

//�ر�д�߳�
void CCESeries::CloseWriteThread()
{
	SetEvent(m_hWriteCloseEvent);
	
	//������н�Ҫд������
    PurgeComm( m_hComm,  PURGE_TXCLEAR );
	
    //�ȴ�10�룬������߳�û���˳�����ǿ���˳�
    if (WaitForSingleObject(m_hWriteThread,10000) == WAIT_TIMEOUT)
	{
		TerminateThread(m_hWriteThread,0);
	}
	m_hWriteThread = NULL;
}