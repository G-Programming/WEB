// ADOAccessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOAccess.h"
#include "ADOAccessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADOAccessDlg dialog

CADOAccessDlg::CADOAccessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOAccessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOAccessDlg)
	m_strSql = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADOAccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOAccessDlg)
	DDX_CBString(pDX, IDC_CMB_SQL, m_strSql);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOAccessDlg, CDialog)
	//{{AFX_MSG_MAP(CADOAccessDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTNCREATEDB, OnBtncreatedb)
	ON_BN_CLICKED(IDC_BTNOPENDB, OnBtnopendb)
	ON_BN_CLICKED(IDC_BTNEXEC, OnBtnexec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOAccessDlg message handlers

BOOL CADOAccessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//��ʼ��COM��
	CoInitializeEx(NULL,COINIT_MULTITHREADED);

	//������Access���ݿ�����
    if (!CreateConnection())
    {
	   AfxMessageBox(_T("��������ʧ��"));
	   return FALSE;
    }

   	//�������б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_VIEW);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("����"), LVCFMT_LEFT, rt.Width() * 0.5);
    pListCtrl->InsertColumn(1,_T("����"), LVCFMT_LEFT, rt.Width() * 0.5);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOAccessDlg::OnDestroy() 
{
	//�ر�����
	CloseConnection();
	
	//�ͷ�COM��
    CoUninitialize();	
	CDialog::OnDestroy();
}



//��ADO���ݿ⽨������
BOOL CADOAccessDlg::CreateConnection()
{
	CLSID	tClsid;
	HRESULT hr;

	//1,�õ�ADO���Ӷ����ӦClassID
	hr = CLSIDFromProgID( g_szADOCE30ConnProgID, &tClsid );
	
	if (FAILED(hr))
	{
		return FALSE;
	}
	
    //2,����ADO���Ӷ���
	hr = CoCreateInstance (tClsid, NULL,
		CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER,
		IID__Connection, (LPVOID *)&m_pADOCEConn);
	
	if((!m_pADOCEConn) || FAILED(hr))
	{
		return FALSE;
	}
		
	//3.�����������ݿ��Provider
	hr = m_pADOCEConn->put_Provider(TEXT("cedb"));
	if FAILED(hr)
	{
		return FALSE;
	}

	//4.�õ���¼�������ClassID
	hr = CLSIDFromProgID( g_szADOCE30RSProgID, &tClsid );
	if FAILED(hr)
	{
		return FALSE;
	}

	//5.�������������
	hr = CoCreateInstance (tClsid, NULL,
		CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER,
		IID__Recordset,(LPVOID *)&m_pADOCERS);
				
	if((!m_pADOCERS) || FAILED(hr))
	{
		return FALSE;
	}
								
	return TRUE;

}

//�ر���Access���ݿ�����
void CADOAccessDlg::CloseConnection()
{
	if (m_pADOCEConn != NULL)
	{
		m_pADOCEConn->Close();
		m_pADOCEConn->Release();
		m_pADOCEConn = NULL;
	}

	if (m_pADOCERS != NULL)
	{
		m_pADOCERS->Close();
        m_pADOCERS->Release();
		m_pADOCERS = NULL;
	}
}

/*
�������ƣ��½����ݿ�
��ڲ�����szDbName��ʾҪ�½������ݿ�����
���ڲ�������
�� �� ֵ��TRUE:�½����ݿ�ɹ�;FALSE:�½����ݿ�ʧ��
*/
BOOL CADOAccessDlg::CreateDatabase(LPCTSTR szDbName)
{
	VARIANT varTSQL,varEmpty; 
	HRESULT hr;
    TCHAR szSqlBuf[1024];
	wcscpy(szSqlBuf,_T("CREATE DATABASE '"));
	wcscat(szSqlBuf,szDbName);
	wcscat(szSqlBuf,_T("'"));

	VariantInit(&varTSQL);
	VariantInit(&varEmpty);
	
	varTSQL.bstrVal = SysAllocString(szSqlBuf);
	varTSQL.vt = VT_BSTR;
    
	//�������ݿ�
    hr=m_pADOCERS->Open(varTSQL,varEmpty,MSADOCE::adOpenDynamic,MSADOCE::adLockOptimistic,MSADOCE::adCmdText);
	if(FAILED(hr))
	{
		return FALSE;
	}
	m_pADOCERS->Close();
	return TRUE;
}


/*
�������ƣ������ݿ�
��ڲ�����szDbName��ʾҪ�򿪵����ݿ�����
���ڲ�������
�� �� ֵ��TRUE:�����ݿ�ɹ�;FALSE:�����ݿ�ʧ��
*/
BOOL CADOAccessDlg::OpenDatabase(LPCTSTR szDbName)
{
	HRESULT hr;
	VARIANT varConn1;


    //��ָ�������ݿ⽨������
	hr = m_pADOCEConn->Open(LPTSTR(szDbName),TEXT(""), TEXT(""),MSADOCE::adOpenUnspecified);
	if FAILED(hr)
	{
		return FALSE;
	}

	VariantInit(&varConn1);
	varConn1.pdispVal=m_pADOCEConn;
	varConn1.vt=VT_DISPATCH;
	//���ý���������ѽ�����������
	hr=m_pADOCERS->put_ActiveConnection(varConn1);
	if (FAILED(hr))
	{
		return FALSE;
	}

	return TRUE;
}

//�½����ݿⰴť�����¼�����
void CADOAccessDlg::OnBtncreatedb() 
{
   CString dbFileName;

   TCHAR szFilters[]=_T("Access File (*.cdb)|*.cdb||");
   
   //���ļ�����Ի���
   CFileDialog fileDlg (FALSE, _T("cdb"),NULL,OFN_PATHMUSTEXIST,szFilters,this);
   if (fileDlg.DoModal() == IDOK)
   {
	   dbFileName = fileDlg.GetPathName();
   }
   else
   {
	   return;
   }

   //
   if (!CreateDatabase(dbFileName))
   {
	   AfxMessageBox(_T("�������ݿ�ʧ��"));
	   return;
   }	
}

//�����ݿⰴť�����¼�����
void CADOAccessDlg::OnBtnopendb() 
{
   CString dbFileName;

   TCHAR szFilters[]=_T("Access File (*.cdb)|*.cdb||");
 
   //���ã����ļ��Ի���ѡ��Access���ݿ��ļ�
   CFileDialog fileDlg (TRUE, _T("cdb"),_T("*.cdb"),OFN_FILEMUSTEXIST,szFilters,this);
   if (fileDlg.DoModal() == IDOK)
   {
	   dbFileName = fileDlg.GetPathName();
   }
   else
   {
	   return;
   }

   //�����ݿ�
   if (!OpenDatabase(dbFileName))
   {
	   AfxMessageBox(_T("�����ݿ�ʧ��"));
	   return;
   }	
}

//�����еļ�¼���б���ͼ����ʾ
void CADOAccessDlg::AddRecordToView()
{
	HRESULT hr;
	short iEndOfFile;
	VARIANT			varData,varFieldSelect;
	TCHAR*			pszName;
	TCHAR*			pszAge;	
	pszName = (TCHAR*)malloc(40);
	pszAge = (TCHAR*)malloc(40);
    hr = m_pADOCERS->MoveFirst();
	//�жϼ�¼��ָ���Ƿ񵽴�β��
	hr = m_pADOCERS->get_EOF(&iEndOfFile);
	int k=0;
	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_VIEW);
	while(!iEndOfFile)
	{
			//�õ������ֶμ�����
			hr = m_pADOCERS->get_Fields(&m_pADOCEFields);
			varFieldSelect.uiVal = 0;
			varFieldSelect.vt = VT_UI2;
			hr = m_pADOCEFields->get_Item(varFieldSelect, &m_pADOCEField);
			hr = m_pADOCEField->get_Value(&varData);
			lstrcpy(pszName, varData.bstrVal);
			
			//�õ��ֶζ���
			varFieldSelect.uiVal = 1;
			varFieldSelect.vt = VT_I4;
			hr = m_pADOCEFields->get_Item(varFieldSelect, &m_pADOCEField);
			hr = m_pADOCEField->get_Value(&varData);
		    _itow(varData.lVal,pszAge,10);
			
			//���б�����������Ϣ
			pListCtrl->InsertItem(k,_T("Test"));
			//�������
			pListCtrl->SetItemText(k,0,pszName);
			//���������
			pListCtrl->SetItemText(k,1,pszAge);
			
			//����¼��ָ������ƶ�һ��
			m_pADOCERS->MoveNext();
			m_pADOCERS->get_EOF(&iEndOfFile);
			k++;
	}
	free(pszName);
	free(pszAge);
}

//ִ�а�ť�����¼�����
void CADOAccessDlg::OnBtnexec() 
{
	HRESULT hr;
	VARIANT varStrSql,varEmpty;
	VariantInit(&varStrSql);
	VariantInit(&varEmpty);
	UpdateData(TRUE);
	varStrSql.bstrVal = SysAllocString(m_strSql);
	varStrSql.vt = VT_BSTR;
	hr = m_pADOCERS->Open(varStrSql,varEmpty,MSADOCE::adOpenDynamic,MSADOCE::adLockOptimistic,MSADOCE::adCmdText);
	SysFreeString(varStrSql.bstrVal);
						
	if (FAILED(hr))
	{
		AfxMessageBox(_T("ִ��ʧ��"));
	}
	long iCount = 0;
	hr = m_pADOCERS->get_RecordCount(&iCount);
	AddRecordToView();
	m_pADOCERS->Close();
}
