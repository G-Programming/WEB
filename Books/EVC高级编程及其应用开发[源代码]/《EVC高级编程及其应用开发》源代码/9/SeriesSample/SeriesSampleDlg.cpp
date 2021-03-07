// SeriesSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SeriesSample.h"
#include "SeriesSampleDlg.h"
#include "DlgSeriesSetup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CSeriesSampleDlg dialog

CSeriesSampleDlg::CSeriesSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeriesSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeriesSampleDlg)
	m_strRecv = _T("");
	m_strSend = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSeriesSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeriesSampleDlg)
	DDX_Text(pDX, IDC_EDTRECV, m_strRecv);
	DDX_Text(pDX, IDC_EDTSEND, m_strSend);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSeriesSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSeriesSampleDlg)
	ON_BN_CLICKED(IDC_BTNCONN, OnBtnconn)
	ON_BN_CLICKED(IDC_BTNDISCONN, OnBtndisconn)
	ON_BN_CLICKED(IDC_BTNSEND, OnBtnsend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeriesSampleDlg message handlers

BOOL CSeriesSampleDlg::OnInitDialog()
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


//建立连接
void CSeriesSampleDlg::OnBtnconn() 
{
	m_ceSeries.m_OnSeriesRead = OnSeriesRead;
	CDlgSeriesSetup dlgSeries;
	if (dlgSeries.DoModal() == IDOK)
	{
		if (!m_ceSeries.OpenPort(this,dlgSeries.m_portNo,dlgSeries.m_baud,dlgSeries.m_parity,dlgSeries.m_databits,dlgSeries.m_stopbits))
		{
			AfxMessageBox(L"打开串口失败");
		}
		else  //打开成功的话，将关闭按钮和发送按钮置为可用
		{
			CButton *pBtnConn = (CButton*)GetDlgItem(IDC_BTNCONN);
			CButton *pBtnDisConn = (CButton*)GetDlgItem(IDC_BTNDISCONN);
			CButton *pBtnSend = (CButton*)GetDlgItem(IDC_BTNSEND);
			
			ASSERT(pBtnConn != NULL);
			ASSERT(pBtnDisConn != NULL);
			ASSERT(pBtnSend != NULL);

			pBtnConn->EnableWindow(FALSE);
			pBtnDisConn->EnableWindow(TRUE);
			pBtnSend->EnableWindow(TRUE);
		}
	}
}

//断开连接按钮
void CSeriesSampleDlg::OnBtndisconn() 
{
	m_ceSeries.ClosePort();
	CButton *pBtnConn = (CButton*)GetDlgItem(IDC_BTNCONN);
	CButton *pBtnDisConn = (CButton*)GetDlgItem(IDC_BTNDISCONN);
	CButton *pBtnSend = (CButton*)GetDlgItem(IDC_BTNSEND);
	
	ASSERT(pBtnConn != NULL);
	ASSERT(pBtnDisConn != NULL);
	ASSERT(pBtnSend != NULL);
	
	pBtnConn->EnableWindow(TRUE);
	pBtnDisConn->EnableWindow(FALSE);
	pBtnSend->EnableWindow(FALSE);

}

void CSeriesSampleDlg::OnBtnsend() 
{
	UpdateData(TRUE);
    BYTE * buf;
	int bufLen = m_strSend.GetLength()*2;
	buf = new BYTE(bufLen);
	CopyMemory(buf,m_strSend.GetBuffer(m_strSend.GetLength()),bufLen);
	if (!m_ceSeries.WritePort(buf,bufLen))
	{
		AfxMessageBox(L"写入失败");
	}
}

void CSeriesSampleDlg::OnSeriesRead(CWnd* pWnd,BYTE* buf,int bufLen)
{
	CSeriesSampleDlg *pDlg = (CSeriesSampleDlg *)pWnd;
	CEdit * pEdit;
	pEdit = (CEdit*)pDlg->GetDlgItem(IDC_EDTRECV);

	CString strRecv = (char*)buf;
	CString strOld;
	pEdit->GetWindowText(strOld);
	pEdit->SetWindowText(strOld + strRecv);
    
	delete[] buf;
}
