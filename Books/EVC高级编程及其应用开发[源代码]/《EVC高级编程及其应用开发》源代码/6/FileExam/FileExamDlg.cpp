// FileExamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileExam.h"
#include "FileExamDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileExamDlg dialog

CFileExamDlg::CFileExamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileExamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileExamDlg)
	m_bjmc = _T("");
	m_csrq = _T("");
	m_xsbh = _T("");
	m_xsxm = _T("");
	m_xsxb = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileExamDlg)
	DDX_Text(pDX, IDC_EDTBJMC, m_bjmc);
	DDX_Text(pDX, IDC_EDTCSRQ, m_csrq);
	DDX_Text(pDX, IDC_EDTXSBH, m_xsbh);
	DDX_Text(pDX, IDC_EDTXSXM, m_xsxm);
	DDX_CBString(pDX, IDC_CMBXSXB, m_xsxb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileExamDlg, CDialog)
	//{{AFX_MSG_MAP(CFileExamDlg)
	ON_BN_CLICKED(IDC_BTNFIRST, OnBtnfirst)
	ON_BN_CLICKED(IDC_BTNPRIOR, OnBtnprior)
	ON_BN_CLICKED(IDC_BTNNEXT, OnBtnnext)
	ON_BN_CLICKED(IDC_BTNLAST, OnBtnlast)
	ON_BN_CLICKED(IDC_BTNADD, OnBtnadd)
	ON_BN_CLICKED(IDC_BTNEDIT, OnBtnedit)
	ON_BN_CLICKED(IDC_BTNCANCEL, OnBtncancel)
	ON_BN_CLICKED(IDC_BTNSAVE, OnBtnsave)
	ON_BN_CLICKED(IDC_BTNDELETE, OnBtndelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileExamDlg message handlers

BOOL CFileExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	//装载学生表到m_lstStudent队列
	CFile stuFile;
	CStudentData studentData;
	DWORD dwRead;
	//如果数据文件存在，就读取
	ZeroMemory(&studentData,sizeof(studentData));
	if (stuFile.Open(STUDENTFILEPATH,CFile::modeRead))
	{
		do
		{
			dwRead = stuFile.Read(&studentData,sizeof(studentData));
			if (dwRead != 0 )
			{
				m_lstStudent.AddTail(studentData);
			}
		}while(dwRead > 0);
		//关闭数据文件
		stuFile.Close();
	}
	else  //创建文件
	{
        if (!stuFile.Open(STUDENTFILEPATH,CFile::modeCreate|CFile::modeWrite))
		{
			AfxMessageBox(_T("创建数据库失败"));
			return FALSE;
		}
		stuFile.Close();
	}
	
	//初始化界面显示
	if (m_lstStudent.GetCount() > 0)
	{
		studentData = m_lstStudent.GetHead();
		m_iCurPos = 0;
		//初始划第一条显示
		m_xsbh = studentData.xsbh;
		m_xsxm = studentData.xsxm;
		m_xsxb = studentData.xb;
		m_csrq = studentData.csrq;
		m_bjmc = studentData.bjmc;
		
		UpdateData(false);
	}
    SetControlEnable(FALSE);
	//设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*函数介绍：设置控件有效性
*入口参数：aValue代表控件的有效性
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::SetControlEnable(bool aValue)
{
	/*设置输入框的有效性*/
	((CEdit*)GetDlgItem(IDC_EDTXSBH))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_EDTXSXM))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_CMBXSXB))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_EDTCSRQ))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_EDTBJMC))->EnableWindow(aValue);  
    /*设置指针移动按钮的有效性*/
	((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(!aValue);    
	((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(!aValue); 
	((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(!aValue); 
	((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(!aValue); 
	/*设置操作按钮的有效性*/
	((CButton*)GetDlgItem(IDC_BTNADD))->EnableWindow(!aValue);
	((CButton*)GetDlgItem(IDC_BTNEDIT))->EnableWindow(!aValue);
	((CButton*)GetDlgItem(IDC_BTNCANCEL))->EnableWindow(aValue);
	((CButton*)GetDlgItem(IDC_BTNSAVE))->EnableWindow(aValue);
	((CButton*)GetDlgItem(IDC_BTNDELETE))->EnableWindow(!aValue);
}


/*
*函数介绍：设置指针移动按钮的有效性
*入口参数：aValue代表当前记录位置
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::SetNavigatorButton(int aValue)
{
	//如果学生队列数据小于2
	if (m_lstStudent.GetCount() < 2)
	{
        ((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(FALSE);
        return;		
	}
	//指针移到首部
	if (aValue == 0)
	{
        ((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(FALSE);
		if (m_lstStudent.GetCount() >=2)
		{
           ((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(TRUE);
           ((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(TRUE);
		}
	}//如果指针移到末尾
    else if (aValue == m_lstStudent.GetCount() - 1)
	{
        ((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(FALSE);
		if (m_lstStudent.GetCount() >=2)
		{
           ((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(TRUE);
           ((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(TRUE);
		}
	}
	else
	{
           ((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(TRUE);
           ((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(TRUE);
           ((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(TRUE);
           ((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(TRUE);
	}
}



/*
*函数介绍：将指针移到首部
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnfirst() 
{
	CStudentData studentData = m_lstStudent.GetHead();
	m_iCurPos = 0;
	//更新显示
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);
}

/*
*函数介绍：将指针移向前移动
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnprior() 
{
	m_iCurPos--;
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	CStudentData studentData = m_lstStudent.GetAt(pos);
	
	//更新显示
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);
}

/*
*函数介绍：将指针向后移动
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnnext() 
{
	m_iCurPos++;
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	CStudentData studentData = m_lstStudent.GetAt(pos);
	//更新显示
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);
}

/*
*函数介绍：将指针移到尾部
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnlast() 
{
	CStudentData studentData = m_lstStudent.GetTail();
	m_iCurPos = m_lstStudent.GetCount() - 1;
	//更新显示
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);
}

/*
*函数介绍：添加新记录
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnadd() 
{
	m_operID = 0 ; //表示添加操作
	m_xsbh = _T("");
	m_xsxm = _T("");
	m_xsxb = _T("");
	m_csrq = _T("");
	m_bjmc = _T("");
    UpdateData(FALSE);
	SetControlEnable(TRUE);
}

/*
*函数介绍：编辑旧记录
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnedit() 
{
    if (m_lstStudent.IsEmpty())
	{
		AfxMessageBox(_T("没有可编辑的记录"));
		return;
	}
	m_operID = 1 ; //表示编辑操作
	SetControlEnable(TRUE);
}

/*
*函数介绍：保存修改或添加
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtnsave() 
{
	CStudentData studentData;
	CFile stuFile;
	
	UpdateData(TRUE);
	switch (m_operID )
	{
	case 0 :  /*添加操作*/
		{
			/*将添加的东西写入文件*/
			ZeroMemory(&studentData,sizeof(studentData));
			wcscpy(studentData.xsbh,m_xsbh);
			wcscpy(studentData.xsxm,m_xsxm);
			wcscpy(studentData.xb,m_xsxb);
			wcscpy(studentData.csrq,m_csrq);
			wcscpy(studentData.bjmc,m_bjmc);
			stuFile.Open(STUDENTFILEPATH,CFile::modeRead | CFile::modeWrite);
			stuFile.SeekToEnd();
			stuFile.Write(&studentData,sizeof(studentData));
			stuFile.Close();
			//更新内存队列
			m_lstStudent.AddTail(studentData);

			SetControlEnable(FALSE);	
			//设置指针移动按钮有效性
			m_iCurPos = m_lstStudent.GetCount()-1;
	        SetNavigatorButton(m_iCurPos);
			break;
		}
	case 1: /*编辑操作*/
		{
			/*将添加的东西写入文件*/
			ZeroMemory(&studentData,sizeof(studentData));
			wcscpy(studentData.xsbh,m_xsbh);
			wcscpy(studentData.xsxm,m_xsxm);
			wcscpy(studentData.xb,m_xsxb);
			wcscpy(studentData.csrq,m_csrq);
			wcscpy(studentData.bjmc,m_bjmc);
			stuFile.Open(STUDENTFILEPATH,CFile::modeRead | CFile::modeWrite);
			stuFile.Seek(sizeof(studentData)*(m_iCurPos) ,CFile::begin);
			stuFile.Write(&studentData,sizeof(studentData));
			stuFile.Close();
			//更新内存队列
			m_lstStudent.SetAt(m_lstStudent.FindIndex(m_iCurPos),studentData);	

		    SetControlEnable(FALSE);	
			//设置指针移动按钮有效性
	        SetNavigatorButton(m_iCurPos);
			break;
		}
	}	
}

/*
*函数介绍：取消修改或添加
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtncancel() 
{
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	CStudentData studentData = m_lstStudent.GetAt(pos);
	
	//更新显示
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
	SetControlEnable(FALSE);
    //设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);
}

/*
*函数介绍：删除当前记录
*入口参数：(无)
*出口参数：(无)
*返回值：(无)
*/
void CFileExamDlg::OnBtndelete() 
{
    if (m_lstStudent.IsEmpty())
	{
		AfxMessageBox(_T("没有可删除的记录"));
		return;
	}

	//先从队列中移除
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	m_lstStudent.RemoveAt(pos);
	if (m_iCurPos != 0)
	{
		m_iCurPos--;
	}
	//更新界面显示
	if (!m_lstStudent.IsEmpty())
	{
		pos = m_lstStudent.FindIndex(m_iCurPos);
		CStudentData studentData = m_lstStudent.GetAt(pos);
		
		//更新显示
		m_xsbh = studentData.xsbh;
		m_xsxm = studentData.xsxm;
		m_xsxb = studentData.xb;
		m_csrq = studentData.csrq;
		m_bjmc = studentData.bjmc;
		UpdateData(false);
	}
	else
	{
		//更新显示
		m_xsbh = _T("");
		m_xsxm = _T("");
		m_xsxb = _T("");
		m_csrq = _T("");
		m_bjmc = _T("");
		UpdateData(false);
	}
	SetControlEnable(FALSE);
    //设置指针移动按钮有效性
	SetNavigatorButton(m_iCurPos);
	//将文件重写
    CStudentData studentData;
	CFile stuFile;
	stuFile.Open(STUDENTFILEPATH,CFile::modeCreate | CFile::modeWrite);
    
	pos = m_lstStudent.GetHeadPosition();
	for (int i=0;i<m_lstStudent.GetCount();i++)
	{
		ZeroMemory(&studentData,sizeof(studentData));
		studentData = m_lstStudent.GetNext(pos);
		stuFile.Write(&studentData,sizeof(studentData));
	}
	stuFile.Close();
}
