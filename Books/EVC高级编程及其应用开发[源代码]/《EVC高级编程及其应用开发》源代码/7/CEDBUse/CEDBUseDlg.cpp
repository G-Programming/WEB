// CEDBUseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CEDBUse.h"
#include "CEDBUseDlg.h"

#include "StudentInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCEDBUseDlg dialog

CCEDBUseDlg::CCEDBUseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCEDBUseDlg::IDD, pParent)
{
	//��ʼ�����ݿ���
	m_hDB = 0;
	//�����ݿ�����ʶ����0
	m_ceOid = 0;     
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCEDBUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCEDBUseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCEDBUseDlg, CDialog)
	//{{AFX_MSG_MAP(CCEDBUseDlg)
	ON_BN_CLICKED(IDC_BTNOPEN, OnBtnopen)
	ON_BN_CLICKED(IDC_BTNCLOSE, OnBtnclose)
	ON_BN_CLICKED(IDC_BTNREFRESH, OnBtnrefresh)
	ON_BN_CLICKED(IDC_BTNADD, OnBtnadd)
	ON_BN_CLICKED(IDC_BTNEDIT, OnBtnedit)
	ON_BN_CLICKED(IDC_BTNDELETE, OnBtndelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCEDBUseDlg message handlers

BOOL CCEDBUseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("���"), LVCFMT_LEFT, rt.Width() * 0.2);
    pListCtrl->InsertColumn(1,_T("����"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(2, _T("��������"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(3, _T("���"), LVCFMT_LEFT, rt.Width() * 0.2);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//�����ݿ�
void CCEDBUseDlg::OnBtnopen() 
{
	//1���������ݿ�����������򿪣������ڣ����½�һ��
	if (!CeMountDBVol(&m_ceGuid,DBFILENAME,OPEN_ALWAYS))
	{
		AfxMessageBox(_T("�򿪻��½����ݾ�ʧ��"));
		return;
	}

	
	//2�����Ŵ����ݿ�
	m_hDB = CeOpenDatabaseEx(&m_ceGuid,&m_ceOid,DBTABLENAME,NULL,CEDB_AUTOINCREMENT,NULL);
	if (m_hDB == INVALID_HANDLE_VALUE)
	{
		//3�� //������ݿⲻ���ڣ����½�֮
		if (GetLastError() == ERROR_FILE_NOT_FOUND) 
		{
			CEDBASEINFO ceDbInfo;

			ceDbInfo.dwFlags = CEDB_VALIDNAME | CEDB_VALIDTYPE | CEDB_VALIDSORTSPEC ;
			wcscpy(ceDbInfo.szDbaseName , DBTABLENAME);
			ceDbInfo.dwDbaseType = 0;
			ceDbInfo.wNumSortOrder = 2 ; //�����ֶ���Ŀ

			ceDbInfo.rgSortSpecs[0].propid = PID_NO;
			ceDbInfo.rgSortSpecs[0].dwFlags = CEDB_SORT_CASEINSENSITIVE; //�����Ҵ�Сд�޹�
			
			ceDbInfo.rgSortSpecs[1].propid = PID_NAME;
			ceDbInfo.rgSortSpecs[1].dwFlags = CEDB_SORT_CASEINSENSITIVE; //�����Ҵ�Сд�޹�
			m_ceOid = CeCreateDatabaseEx(&m_ceGuid,&ceDbInfo);
			if (m_ceOid == 0)
			{
				AfxMessageBox(_T("�������ݿ�ʧ��"));
				//�˴���ж�����ݿ��
				if (!CeUnmountDBVol(&m_ceGuid))
				{
					AfxMessageBox(_T("ж�����ݿ��ļ���ʧ��"));
				}
				return ;
			}
			//4���������ݿ��Ӧ�����Ŵ����ݿ�
			m_hDB = CeOpenDatabaseEx(&m_ceGuid,&m_ceOid,DBTABLENAME,NULL,CEDB_AUTOINCREMENT,NULL);
			if (m_hDB == INVALID_HANDLE_VALUE)
			{
				AfxMessageBox(_T("�����ݿ�ʧ��"));
				//�˴���ж�����ݿ��
				if (!CeUnmountDBVol(&m_ceGuid))
				{
					AfxMessageBox(_T("ж�����ݿ��ļ���ʧ��"));
				}
				return ;
			}
		}
		else
		{
			AfxMessageBox(_T("�����ݿ�ʧ��"));
			//�˴���ж�����ݿ��
			if (!CeUnmountDBVol(&m_ceGuid))
			{
				AfxMessageBox(_T("ж�����ݿ��ļ���ʧ��"));
			}
			return ;
		}
	}
}

//�ر����ݿ�
void CCEDBUseDlg::OnBtnclose() 
{
	//1���ر����ݿ�
	if (!CloseHandle(m_hDB))
	{
		AfxMessageBox(_T("�ر����ݿ�ʧ��"));
		return;
	}
	//2�������ݿ������ݻ��嵽���ô洢������
	if (!CeFlushDBVol(&m_ceGuid))
	{
		AfxMessageBox(_T("�������ʧ��"));
		return ;
	}
	//3��ж�����ݿ��
	if (!CeUnmountDBVol(&m_ceGuid))
	{
		AfxMessageBox(_T("ж�����ݿ��ļ���ʧ��"));
		return ;
	}
	
}

/*
����˵������ȡ���ݿ�ļ�¼��Ŀ
��ڲ�����pCeGuid : ���ݿ��ļ����ʶָ��
		  ceOid   : ���ݿ�����ʶ
���ڲ�����(��)
�� �� ֵ��-1 :����ʧ�ܡ��ɹ��Ļ�������ʵ�ʵļ�¼��
*/
int CCEDBUseDlg::GetRecordCount(CEGUID *pCeGuid,CEOID ceOid)
{
	int iCount;
	CEOIDINFO oidinfo;
	if (!CeOidGetInfoEx(pCeGuid,ceOid,&oidinfo))
	{
		AfxMessageBox(_T("��ȡ��Ϣʧ��"));
		return -1;
	}
	iCount = oidinfo.infDatabase.wNumRecords;
	return iCount;
}

//�����ݿ��л�ȡ���м�¼������ʾ���б���ͼ��
void CCEDBUseDlg::OnBtnrefresh() 
{
	CEOID ceOid;
	WORD wProps;
	DWORD dwRecSize;
	PBYTE pBuff;
	PCEPROPVAL pRecord;

	REC_STUDENT * pStudent;
 
	//�õ����ݿ��¼��
	int iRecordCount = GetRecordCount(&m_ceGuid,m_ceOid);
	DWORD dwIndex;
	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	pListCtrl->DeleteAllItems();
	for (int k=0;k<iRecordCount;k++)
	{
		//�ƶ���¼ָ��
		ceOid = CeSeekDatabase(m_hDB,CEDB_SEEK_BEGINNING,k,&dwIndex);

		ASSERT(ceOid !=0);
		pBuff = 0;	
		//��ȡ�����ֶ�ֵ
		ceOid = CeReadRecordProps(m_hDB,CEDB_ALLOWREALLOC,&wProps,NULL,&(LPBYTE)pBuff,&dwRecSize);
		
		ASSERT(ceOid != 0);
		
		pRecord = (PCEPROPVAL)pBuff;
		pStudent = new REC_STUDENT;
		
		for (int i=0;i<wProps;i++)
		{
			switch(pRecord->propid)
			{
			case PID_NO:
				{
					wcscpy(pStudent->szNo,pRecord->val.lpwstr);
					break;
				}
			case PID_NAME:
				{
					wcscpy(pStudent->szName,pRecord->val.lpwstr);
					break;
				}
			case PID_BIRTHDAY:
				{
					pStudent->ftBirthday = pRecord->val.filetime;
					break;
				}
			case PID_STATURE:
				{
					pStudent->iStature = pRecord->val.lVal;
					break;
				}
			}
			pRecord++;
		}
		LocalFree(pBuff);
		
		//���б�������ѧ����Ϣ
		pListCtrl->InsertItem(k,_T("Test"));
		//���ѧ�����
		pListCtrl->SetItemText(k,0,pStudent->szNo);
		//���ѧ������
		pListCtrl->SetItemText(k,1,pStudent->szName);
		//���ѧ�����գ��˴���Ҫ��Щת��
		SYSTEMTIME systime;
		FileTimeToSystemTime(&(pStudent->ftBirthday),&systime);
		TCHAR szBirthday[11];
		swprintf(szBirthday,_T("%d-%d-%d"),systime.wYear,systime.wMonth,systime.wDay);
		pListCtrl->SetItemText(k,2,szBirthday);
		//���ѧ����ߣ��˴���Ҫ������ת�����ַ���
		TCHAR szStature[5];
		_itow(pStudent->iStature,szStature,10);
		pListCtrl->SetItemText(k,3,szStature);
		delete pStudent;
	}
}

/*
����˵�������һ���¼�¼
��ڲ�����stu : ѧ�����ݿ��ṹ
���ڲ�����(��)
�� �� ֵ��TRUE:��ӳɹ�;FALSE:���ʧ��
*/
bool CCEDBUseDlg::AddNewStudent(REC_STUDENT stu)
{
	CEOID ceOid;
	CEPROPVAL *pProps;
	pProps = new CEPROPVAL[4];
	//ѧ��ѧ��
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NO; 
	pProps->val.lpwstr = stu.szNo;
	//ѧ������
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NAME ; 
	pProps->val.lpwstr = stu.szName;
	//ѧ����������
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_BIRTHDAY;
	pProps->val.filetime  = stu.ftBirthday;
	//ѧ�����
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_STATURE;
	pProps->val.iVal = stu.iStature;
    
    pProps = pProps -3 ;
	ceOid = CeWriteRecordProps(m_hDB,0,4,pProps);

	if (ceOid == 0)
	{
		return false;
	}
	return true;
}

/*
����˵�����༭��¼
��ڲ�����stu : ѧ�����ݿ��ṹ
		  ceOid : ��¼�����ʶ
���ڲ�����(��)
�� �� ֵ��TRUE:�༭�ɹ�;FALSE:�༭ʧ��
*/
bool CCEDBUseDlg::EditStudent(REC_STUDENT stu,CEOID ceOid)
{
	CEOID tmpCeOid;
	CEPROPVAL *pProps;
	pProps = new CEPROPVAL[4];
	//ѧ��ѧ��
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NO; 
	pProps->val.lpwstr = stu.szNo;
	//ѧ������
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NAME ; 
	pProps->val.lpwstr = stu.szName;
	//ѧ����������
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_BIRTHDAY;
	pProps->val.filetime  = stu.ftBirthday;
	//ѧ�����
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_STATURE;
	pProps->val.iVal = stu.iStature;
    
    pProps = pProps -3 ;
	tmpCeOid = CeWriteRecordProps(m_hDB,ceOid,4,pProps);

	if (tmpCeOid == 0)
	{
		return false;
	}
	return true;
}

//��Ӽ�¼��ť����ʵ�ַ���
void CCEDBUseDlg::OnBtnadd() 
{
	REC_STUDENT rec_stu;
	
	CStudentInputDlg inputDlg;
	if (inputDlg.DoModal() == IDOK)
	{
		//�õ����
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//�õ�����
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//�õ���������
		SYSTEMTIME timeDest;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		::SystemTimeToFileTime(&timeDest, &(rec_stu.ftBirthday));
		//�õ����ֵ
		rec_stu.iStature = inputDlg.m_stature;
		AddNewStudent(rec_stu);
	}
	//������֮�󣬵���ˢ�°�ť��������
	OnBtnrefresh();
}

//�༭��¼��ť����ʵ�ַ���
void CCEDBUseDlg::OnBtnedit() 
{
	REC_STUDENT rec_stu;
	CEOID ceOid;
	PBYTE pBuff;
	WORD wProps;
	DWORD dwRecSize;
	PCEPROPVAL pRecord;
	REC_STUDENT *pStudent;


	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	DWORD dwIndex;
	ceOid = CeSeekDatabase(m_hDB,CEDB_SEEK_BEGINNING,iItemIndex,&dwIndex);
	ASSERT(ceOid !=0);

	pBuff = 0;	
	//��ȡ���м�¼ֵ
	ceOid = CeReadRecordProps(m_hDB,CEDB_ALLOWREALLOC,&wProps,NULL,&(LPBYTE)pBuff,&dwRecSize);
	
	ASSERT(ceOid != 0);
	
	pRecord = (PCEPROPVAL)pBuff;
	pStudent = new REC_STUDENT;
	
	for (int i=0;i<wProps;i++)
	{
		switch(pRecord->propid)
		{
		case PID_NO:
			{
				wcscpy(pStudent->szNo,pRecord->val.lpwstr);
				break;
			}
		case PID_NAME:
			{
				wcscpy(pStudent->szName,pRecord->val.lpwstr);
				break;
			}
		case PID_BIRTHDAY:
			{
				pStudent->ftBirthday = pRecord->val.filetime;
				break;
			}
		case PID_STATURE:
			{
				pStudent->iStature = pRecord->val.lVal;
				break;
			}
		}
		pRecord++;
	}
	LocalFree(pBuff);	

	CStudentInputDlg inputDlg;
	//ͬ���༭�Ի��������ֵ
	inputDlg.m_no = pStudent->szNo;
	inputDlg.m_name = pStudent->szName;
	SYSTEMTIME tmpTime;
	FileTimeToSystemTime(&(pStudent->ftBirthday),&tmpTime);
	inputDlg.m_birthday = tmpTime;
	inputDlg.m_stature = pStudent->iStature;
	
	delete pStudent;
	if (inputDlg.DoModal() == IDOK)
	{
		//�õ����
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//�õ�����
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//�õ���������
		SYSTEMTIME timeDest;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		::SystemTimeToFileTime(&timeDest, &(rec_stu.ftBirthday));
		//�õ����ֵ
		rec_stu.iStature = inputDlg.m_stature;
		EditStudent(rec_stu,ceOid);
	}
	//�༭���֮�󣬵���ˢ�°�ť��������
	OnBtnrefresh();	
}

//ɾ����ǰ��¼
void CCEDBUseDlg::OnBtndelete() 
{
	//����ѧ���б�����	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	DWORD dwIndex;
	CEOID ceOid;
	ceOid = CeSeekDatabase(m_hDB,CEDB_SEEK_BEGINNING,iItemIndex,&dwIndex);
	ASSERT(ceOid !=0 );
	if (!CeDeleteRecord(m_hDB,ceOid))
	{
		AfxMessageBox(_T("ɾ��ʧ��"));
	}
}
