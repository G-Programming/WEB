// PingExampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PingExample.h"
#include "PingExampleDlg.h"
#include <icmpapi.h>
#include <winsock.h>
#include <ipExport.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPingExampleDlg dialog

CPingExampleDlg::CPingExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPingExampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPingExampleDlg)
	m_ipAddr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPingExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPingExampleDlg)
	DDX_Control(pDX, IDC_LIST_RECV, m_lstRecv);
	DDX_Text(pDX, IDC_EDIT_IP, m_ipAddr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPingExampleDlg, CDialog)
	//{{AFX_MSG_MAP(CPingExampleDlg)
	ON_BN_CLICKED(IDC_BTNCLEAR, OnBtnclear)
	ON_BN_CLICKED(IDC_BTNPING, OnBtnping)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPingExampleDlg message handlers

BOOL CPingExampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*�������ܣ�CE��Ping����
*��ڲ�����cIPAddr  : IP��ַ
		   pWnd     : CWnd��������ָ���������    
*���ڲ�����pListBox : CListBox����������ʾPing��Ϣ
*����ֵ��(��)
*/
void CEPing(CString cIPAddr,CListBox * pListBox,CWnd * pWnd)
{
   	WSAData wsaData;
	//��ʼ��Socket��̬���ӿ�
    if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0) {
        return ;
    }
	
	/*��IP��ַת���ɵ��ֽ�*/
    char szDestIPAddr[255];
	ZeroMemory(szDestIPAddr,255);
	WideCharToMultiByte(CP_ACP,WC_COMPOSITECHECK
		,cIPAddr.GetBuffer(cIPAddr.GetLength()),cIPAddr.GetLength()
		,szDestIPAddr,cIPAddr.GetLength(),NULL,NULL);
	
	IPAddr ipAddr;
	//��Ŀ���ַ���IP��ַת����IPAddr�ṹ
    ipAddr = inet_addr(szDestIPAddr);      
	
	if (ipAddr == INADDR_NONE) 
	{
		AfxMessageBox(_T("��ַ��Ч"));
		return ;
	}
	
	// ��ping����
    HANDLE hIP = IcmpCreateFile();
    if (hIP == INVALID_HANDLE_VALUE) {
        AfxMessageBox(_T("���ܴ�Ping����"));
        return ;
    }
	
	
	// ����ping���ݰ�
    char acPingBuffer[64];
    memset(acPingBuffer, '*', sizeof(acPingBuffer));
    PICMP_ECHO_REPLY pIpe = (PICMP_ECHO_REPLY)GlobalAlloc( GMEM_FIXED | GMEM_ZEROINIT,
		sizeof(ICMP_ECHO_REPLY) + sizeof(acPingBuffer)); 
    if (pIpe == 0) {
		AfxMessageBox(_T("����ping��������ʧ��"));
        return ;
    }
    
	CString m_recv;
    // ����ping���ݰ�
	m_recv = "ping "+cIPAddr+" with 64 Bytes";
	pListBox->AddString(m_recv);
    for (int i=0;i<4;i++)
	{
		//����ping��������ȴ�����ʱ��Ϊ1��
		DWORD dwStatus = IcmpSendEcho(hIP,ipAddr, 
            acPingBuffer, sizeof(acPingBuffer), NULL, pIpe, 
            sizeof(ICMP_ECHO_REPLY) + sizeof(acPingBuffer), 1000);
		//��dwStatus������0��������յ���Ӧ
		if (dwStatus != 0) {
			m_recv.Format(_T("Reply From %d.%d.%d.%d :bytes=%d time=%d TTL")
				,int(LOBYTE(LOWORD(pIpe->Address)))
				,int(HIBYTE(LOWORD(pIpe->Address)))
				,int(LOBYTE(HIWORD(pIpe->Address)))
				,int(HIBYTE(HIWORD(pIpe->Address)))
				,int(pIpe->DataSize)
				,int(pIpe->RoundTripTime)
				,int(pIpe->Options.Ttl));
			pListBox->AddString(m_recv);
			Sleep(500);
		}
		else 
		{
			pListBox->AddString(_T("Error obtaining info from ping packet."));
		}
		pWnd->UpdateWindow();
	}
	
    //�ͷ��ѷ�����ڴ�
    GlobalFree(pIpe);
	//�ر�Ping����
    IcmpCloseHandle(hIP);
    //�ͷ�Socket��Դ
	WSACleanup();
}






void CPingExampleDlg::OnBtnclear() 
{
	int nCount = m_lstRecv.GetCount();
	
	for (int i=0;i < nCount;i++)
	{
		m_lstRecv.DeleteString(0);
	}

}


void CPingExampleDlg::OnBtnping() 
{
  UpdateData(TRUE);
  CEPing(m_ipAddr,&m_lstRecv,this);
  UpdateWindow();	
}
