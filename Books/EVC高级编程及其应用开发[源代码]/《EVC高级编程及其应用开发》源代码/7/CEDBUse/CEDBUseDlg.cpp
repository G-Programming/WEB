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
	//初始化数据库句柄
	m_hDB = 0;
	//将数据库对象标识设置0
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

	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);

	CRect rt;
    pListCtrl->GetClientRect(&rt);
	pListCtrl->InsertColumn(0,_T("编号"), LVCFMT_LEFT, rt.Width() * 0.2);
    pListCtrl->InsertColumn(1,_T("姓名"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(2, _T("出生日期"), LVCFMT_LEFT, rt.Width() * 0.3);
    pListCtrl->InsertColumn(3, _T("身高"), LVCFMT_LEFT, rt.Width() * 0.2);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}


//打开数据库
void CCEDBUseDlg::OnBtnopen() 
{
	//1、挂载数据库卷，如果存在则打开，不存在，就新建一个
	if (!CeMountDBVol(&m_ceGuid,DBFILENAME,OPEN_ALWAYS))
	{
		AfxMessageBox(_T("打开或新建数据卷失败"));
		return;
	}

	
	//2、接着打开数据库
	m_hDB = CeOpenDatabaseEx(&m_ceGuid,&m_ceOid,DBTABLENAME,NULL,CEDB_AUTOINCREMENT,NULL);
	if (m_hDB == INVALID_HANDLE_VALUE)
	{
		//3、 //如果数据库不存在，就新建之
		if (GetLastError() == ERROR_FILE_NOT_FOUND) 
		{
			CEDBASEINFO ceDbInfo;

			ceDbInfo.dwFlags = CEDB_VALIDNAME | CEDB_VALIDTYPE | CEDB_VALIDSORTSPEC ;
			wcscpy(ceDbInfo.szDbaseName , DBTABLENAME);
			ceDbInfo.dwDbaseType = 0;
			ceDbInfo.wNumSortOrder = 2 ; //排序字段数目

			ceDbInfo.rgSortSpecs[0].propid = PID_NO;
			ceDbInfo.rgSortSpecs[0].dwFlags = CEDB_SORT_CASEINSENSITIVE; //升序，且大小写无关
			
			ceDbInfo.rgSortSpecs[1].propid = PID_NAME;
			ceDbInfo.rgSortSpecs[1].dwFlags = CEDB_SORT_CASEINSENSITIVE; //升序，且大小写无关
			m_ceOid = CeCreateDatabaseEx(&m_ceGuid,&ceDbInfo);
			if (m_ceOid == 0)
			{
				AfxMessageBox(_T("创建数据库失败"));
				//此处得卸载数据库卷
				if (!CeUnmountDBVol(&m_ceGuid))
				{
					AfxMessageBox(_T("卸载数据库文件卷失败"));
				}
				return ;
			}
			//4、创建数据库后，应紧接着打开数据库
			m_hDB = CeOpenDatabaseEx(&m_ceGuid,&m_ceOid,DBTABLENAME,NULL,CEDB_AUTOINCREMENT,NULL);
			if (m_hDB == INVALID_HANDLE_VALUE)
			{
				AfxMessageBox(_T("打开数据库失败"));
				//此处得卸载数据库卷
				if (!CeUnmountDBVol(&m_ceGuid))
				{
					AfxMessageBox(_T("卸载数据库文件卷失败"));
				}
				return ;
			}
		}
		else
		{
			AfxMessageBox(_T("打开数据库失败"));
			//此处得卸载数据库卷
			if (!CeUnmountDBVol(&m_ceGuid))
			{
				AfxMessageBox(_T("卸载数据库文件卷失败"));
			}
			return ;
		}
	}
}

//关闭数据库
void CCEDBUseDlg::OnBtnclose() 
{
	//1、关闭数据库
	if (!CloseHandle(m_hDB))
	{
		AfxMessageBox(_T("关闭数据库失败"));
		return;
	}
	//2、将数据库卷的数据缓冲到永久存储介质上
	if (!CeFlushDBVol(&m_ceGuid))
	{
		AfxMessageBox(_T("缓冲介质失败"));
		return ;
	}
	//3、卸载数据库卷
	if (!CeUnmountDBVol(&m_ceGuid))
	{
		AfxMessageBox(_T("卸载数据库文件卷失败"));
		return ;
	}
	
}

/*
函数说明：获取数据库的记录数目
入口参数：pCeGuid : 数据库文件卷标识指针
		  ceOid   : 数据库对象标识
出口参数：(无)
返 回 值：-1 :代表失败。成功的话，返回实际的记录数
*/
int CCEDBUseDlg::GetRecordCount(CEGUID *pCeGuid,CEOID ceOid)
{
	int iCount;
	CEOIDINFO oidinfo;
	if (!CeOidGetInfoEx(pCeGuid,ceOid,&oidinfo))
	{
		AfxMessageBox(_T("获取信息失败"));
		return -1;
	}
	iCount = oidinfo.infDatabase.wNumRecords;
	return iCount;
}

//从数据库中获取所有记录，并显示到列表视图中
void CCEDBUseDlg::OnBtnrefresh() 
{
	CEOID ceOid;
	WORD wProps;
	DWORD dwRecSize;
	PBYTE pBuff;
	PCEPROPVAL pRecord;

	REC_STUDENT * pStudent;
 
	//得到数据库记录数
	int iRecordCount = GetRecordCount(&m_ceGuid,m_ceOid);
	DWORD dwIndex;
	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	pListCtrl->DeleteAllItems();
	for (int k=0;k<iRecordCount;k++)
	{
		//移动记录指针
		ceOid = CeSeekDatabase(m_hDB,CEDB_SEEK_BEGINNING,k,&dwIndex);

		ASSERT(ceOid !=0);
		pBuff = 0;	
		//读取所有字段值
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
		
		//向列表框中添加学生信息
		pListCtrl->InsertItem(k,_T("Test"));
		//添加学生编号
		pListCtrl->SetItemText(k,0,pStudent->szNo);
		//添加学生姓名
		pListCtrl->SetItemText(k,1,pStudent->szName);
		//添加学生生日，此处需要做些转换
		SYSTEMTIME systime;
		FileTimeToSystemTime(&(pStudent->ftBirthday),&systime);
		TCHAR szBirthday[11];
		swprintf(szBirthday,_T("%d-%d-%d"),systime.wYear,systime.wMonth,systime.wDay);
		pListCtrl->SetItemText(k,2,szBirthday);
		//添加学生身高，此处需要将数字转换成字符串
		TCHAR szStature[5];
		_itow(pStudent->iStature,szStature,10);
		pListCtrl->SetItemText(k,3,szStature);
		delete pStudent;
	}
}

/*
函数说明：添加一条新记录
入口参数：stu : 学生数据库表结构
出口参数：(无)
返 回 值：TRUE:添加成功;FALSE:添加失败
*/
bool CCEDBUseDlg::AddNewStudent(REC_STUDENT stu)
{
	CEOID ceOid;
	CEPROPVAL *pProps;
	pProps = new CEPROPVAL[4];
	//学生学号
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NO; 
	pProps->val.lpwstr = stu.szNo;
	//学生姓名
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NAME ; 
	pProps->val.lpwstr = stu.szName;
	//学生出生日期
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_BIRTHDAY;
	pProps->val.filetime  = stu.ftBirthday;
	//学生身高
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
函数说明：编辑记录
入口参数：stu : 学生数据库表结构
		  ceOid : 记录对象标识
出口参数：(无)
返 回 值：TRUE:编辑成功;FALSE:编辑失败
*/
bool CCEDBUseDlg::EditStudent(REC_STUDENT stu,CEOID ceOid)
{
	CEOID tmpCeOid;
	CEPROPVAL *pProps;
	pProps = new CEPROPVAL[4];
	//学生学号
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NO; 
	pProps->val.lpwstr = stu.szNo;
	//学生姓名
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_NAME ; 
	pProps->val.lpwstr = stu.szName;
	//学生出生日期
	pProps++;
	memset(pProps,0,LocalSize(pProps));
	pProps->propid = PID_BIRTHDAY;
	pProps->val.filetime  = stu.ftBirthday;
	//学生身高
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

//添加记录按钮单击实现方法
void CCEDBUseDlg::OnBtnadd() 
{
	REC_STUDENT rec_stu;
	
	CStudentInputDlg inputDlg;
	if (inputDlg.DoModal() == IDOK)
	{
		//得到编号
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//得到姓名
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//得到出生日期
		SYSTEMTIME timeDest;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		::SystemTimeToFileTime(&timeDest, &(rec_stu.ftBirthday));
		//得到身高值
		rec_stu.iStature = inputDlg.m_stature;
		AddNewStudent(rec_stu);
	}
	//添加完成之后，调用刷新按钮单击方法
	OnBtnrefresh();
}

//编辑记录按钮单击实现方法
void CCEDBUseDlg::OnBtnedit() 
{
	REC_STUDENT rec_stu;
	CEOID ceOid;
	PBYTE pBuff;
	WORD wProps;
	DWORD dwRecSize;
	PCEPROPVAL pRecord;
	REC_STUDENT *pStudent;


	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	DWORD dwIndex;
	ceOid = CeSeekDatabase(m_hDB,CEDB_SEEK_BEGINNING,iItemIndex,&dwIndex);
	ASSERT(ceOid !=0);

	pBuff = 0;	
	//读取所有记录值
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
	//同步编辑对话框输入框值
	inputDlg.m_no = pStudent->szNo;
	inputDlg.m_name = pStudent->szName;
	SYSTEMTIME tmpTime;
	FileTimeToSystemTime(&(pStudent->ftBirthday),&tmpTime);
	inputDlg.m_birthday = tmpTime;
	inputDlg.m_stature = pStudent->iStature;
	
	delete pStudent;
	if (inputDlg.DoModal() == IDOK)
	{
		//得到编号
		wcscpy(rec_stu.szNo,LPCTSTR(inputDlg.m_no));	
		//得到姓名
		wcscpy(rec_stu.szName,LPCTSTR(inputDlg.m_name));
		//得到出生日期
		SYSTEMTIME timeDest;
		inputDlg.m_birthday.GetAsSystemTime(timeDest);
		::SystemTimeToFileTime(&timeDest, &(rec_stu.ftBirthday));
		//得到身高值
		rec_stu.iStature = inputDlg.m_stature;
		EditStudent(rec_stu,ceOid);
	}
	//编辑完成之后，调用刷新按钮单击方法
	OnBtnrefresh();	
}

//删除当前记录
void CCEDBUseDlg::OnBtndelete() 
{
	//设置学生列表框标题	
	CListCtrl * pListCtrl = (CListCtrl*)GetDlgItem(IDC_LST_STUDENT);
	int iItemIndex = pListCtrl->GetNextItem(-1,LVNI_SELECTED);
	ASSERT(iItemIndex !=-1);

	DWORD dwIndex;
	CEOID ceOid;
	ceOid = CeSeekDatabase(m_hDB,CEDB_SEEK_BEGINNING,iItemIndex,&dwIndex);
	ASSERT(ceOid !=0 );
	if (!CeDeleteRecord(m_hDB,ceOid))
	{
		AfxMessageBox(_T("删除失败"));
	}
}
