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
	
	//װ��ѧ����m_lstStudent����
	CFile stuFile;
	CStudentData studentData;
	DWORD dwRead;
	//��������ļ����ڣ��Ͷ�ȡ
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
		//�ر������ļ�
		stuFile.Close();
	}
	else  //�����ļ�
	{
        if (!stuFile.Open(STUDENTFILEPATH,CFile::modeCreate|CFile::modeWrite))
		{
			AfxMessageBox(_T("�������ݿ�ʧ��"));
			return FALSE;
		}
		stuFile.Close();
	}
	
	//��ʼ��������ʾ
	if (m_lstStudent.GetCount() > 0)
	{
		studentData = m_lstStudent.GetHead();
		m_iCurPos = 0;
		//��ʼ����һ����ʾ
		m_xsbh = studentData.xsbh;
		m_xsxm = studentData.xsxm;
		m_xsxb = studentData.xb;
		m_csrq = studentData.csrq;
		m_bjmc = studentData.bjmc;
		
		UpdateData(false);
	}
    SetControlEnable(FALSE);
	//����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*
*�������ܣ����ÿؼ���Ч��
*��ڲ�����aValue����ؼ�����Ч��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::SetControlEnable(bool aValue)
{
	/*������������Ч��*/
	((CEdit*)GetDlgItem(IDC_EDTXSBH))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_EDTXSXM))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_CMBXSXB))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_EDTCSRQ))->EnableWindow(aValue);  
	((CEdit*)GetDlgItem(IDC_EDTBJMC))->EnableWindow(aValue);  
    /*����ָ���ƶ���ť����Ч��*/
	((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(!aValue);    
	((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(!aValue); 
	((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(!aValue); 
	((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(!aValue); 
	/*���ò�����ť����Ч��*/
	((CButton*)GetDlgItem(IDC_BTNADD))->EnableWindow(!aValue);
	((CButton*)GetDlgItem(IDC_BTNEDIT))->EnableWindow(!aValue);
	((CButton*)GetDlgItem(IDC_BTNCANCEL))->EnableWindow(aValue);
	((CButton*)GetDlgItem(IDC_BTNSAVE))->EnableWindow(aValue);
	((CButton*)GetDlgItem(IDC_BTNDELETE))->EnableWindow(!aValue);
}


/*
*�������ܣ�����ָ���ƶ���ť����Ч��
*��ڲ�����aValue����ǰ��¼λ��
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::SetNavigatorButton(int aValue)
{
	//���ѧ����������С��2
	if (m_lstStudent.GetCount() < 2)
	{
        ((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(FALSE);
        return;		
	}
	//ָ���Ƶ��ײ�
	if (aValue == 0)
	{
        ((CButton*)GetDlgItem(IDC_BTNFIRST))->EnableWindow(FALSE);
        ((CButton*)GetDlgItem(IDC_BTNPRIOR))->EnableWindow(FALSE);
		if (m_lstStudent.GetCount() >=2)
		{
           ((CButton*)GetDlgItem(IDC_BTNNEXT))->EnableWindow(TRUE);
           ((CButton*)GetDlgItem(IDC_BTNLAST))->EnableWindow(TRUE);
		}
	}//���ָ���Ƶ�ĩβ
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
*�������ܣ���ָ���Ƶ��ײ�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnfirst() 
{
	CStudentData studentData = m_lstStudent.GetHead();
	m_iCurPos = 0;
	//������ʾ
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);
}

/*
*�������ܣ���ָ������ǰ�ƶ�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnprior() 
{
	m_iCurPos--;
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	CStudentData studentData = m_lstStudent.GetAt(pos);
	
	//������ʾ
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);
}

/*
*�������ܣ���ָ������ƶ�
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnnext() 
{
	m_iCurPos++;
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	CStudentData studentData = m_lstStudent.GetAt(pos);
	//������ʾ
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);
}

/*
*�������ܣ���ָ���Ƶ�β��
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnlast() 
{
	CStudentData studentData = m_lstStudent.GetTail();
	m_iCurPos = m_lstStudent.GetCount() - 1;
	//������ʾ
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
    //����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);
}

/*
*�������ܣ�����¼�¼
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnadd() 
{
	m_operID = 0 ; //��ʾ��Ӳ���
	m_xsbh = _T("");
	m_xsxm = _T("");
	m_xsxb = _T("");
	m_csrq = _T("");
	m_bjmc = _T("");
    UpdateData(FALSE);
	SetControlEnable(TRUE);
}

/*
*�������ܣ��༭�ɼ�¼
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnedit() 
{
    if (m_lstStudent.IsEmpty())
	{
		AfxMessageBox(_T("û�пɱ༭�ļ�¼"));
		return;
	}
	m_operID = 1 ; //��ʾ�༭����
	SetControlEnable(TRUE);
}

/*
*�������ܣ������޸Ļ����
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtnsave() 
{
	CStudentData studentData;
	CFile stuFile;
	
	UpdateData(TRUE);
	switch (m_operID )
	{
	case 0 :  /*��Ӳ���*/
		{
			/*����ӵĶ���д���ļ�*/
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
			//�����ڴ����
			m_lstStudent.AddTail(studentData);

			SetControlEnable(FALSE);	
			//����ָ���ƶ���ť��Ч��
			m_iCurPos = m_lstStudent.GetCount()-1;
	        SetNavigatorButton(m_iCurPos);
			break;
		}
	case 1: /*�༭����*/
		{
			/*����ӵĶ���д���ļ�*/
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
			//�����ڴ����
			m_lstStudent.SetAt(m_lstStudent.FindIndex(m_iCurPos),studentData);	

		    SetControlEnable(FALSE);	
			//����ָ���ƶ���ť��Ч��
	        SetNavigatorButton(m_iCurPos);
			break;
		}
	}	
}

/*
*�������ܣ�ȡ���޸Ļ����
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtncancel() 
{
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	CStudentData studentData = m_lstStudent.GetAt(pos);
	
	//������ʾ
	m_xsbh = studentData.xsbh;
	m_xsxm = studentData.xsxm;
	m_xsxb = studentData.xb;
	m_csrq = studentData.csrq;
	m_bjmc = studentData.bjmc;
	UpdateData(false);
	SetControlEnable(FALSE);
    //����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);
}

/*
*�������ܣ�ɾ����ǰ��¼
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ��(��)
*/
void CFileExamDlg::OnBtndelete() 
{
    if (m_lstStudent.IsEmpty())
	{
		AfxMessageBox(_T("û�п�ɾ���ļ�¼"));
		return;
	}

	//�ȴӶ������Ƴ�
	POSITION pos = m_lstStudent.FindIndex(m_iCurPos);
	m_lstStudent.RemoveAt(pos);
	if (m_iCurPos != 0)
	{
		m_iCurPos--;
	}
	//���½�����ʾ
	if (!m_lstStudent.IsEmpty())
	{
		pos = m_lstStudent.FindIndex(m_iCurPos);
		CStudentData studentData = m_lstStudent.GetAt(pos);
		
		//������ʾ
		m_xsbh = studentData.xsbh;
		m_xsxm = studentData.xsxm;
		m_xsxb = studentData.xb;
		m_csrq = studentData.csrq;
		m_bjmc = studentData.bjmc;
		UpdateData(false);
	}
	else
	{
		//������ʾ
		m_xsbh = _T("");
		m_xsxm = _T("");
		m_xsxb = _T("");
		m_csrq = _T("");
		m_bjmc = _T("");
		UpdateData(false);
	}
	SetControlEnable(FALSE);
    //����ָ���ƶ���ť��Ч��
	SetNavigatorButton(m_iCurPos);
	//���ļ���д
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
