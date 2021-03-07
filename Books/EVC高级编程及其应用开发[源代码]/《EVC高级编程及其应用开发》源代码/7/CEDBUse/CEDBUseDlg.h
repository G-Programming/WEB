// CEDBUseDlg.h : header file
//

#if !defined(AFX_CEDBUSEDLG_H__3361D3CF_D869_4CC9_9945_20224962011B__INCLUDED_)
#define AFX_CEDBUSEDLG_H__3361D3CF_D869_4CC9_9945_20224962011B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//�������ݿ��ļ���
const LPTSTR  DBFILENAME = _T("\\My Documents\\abc.db");
//�������ݿ���
const LPTSTR  DBTABLENAME = _T("Student");

//����ѧ�����ݿ��ṹ
typedef struct
{
	TCHAR szNo[7];			//ѧ�����
	TCHAR szName[20] ;		//ѧ������
	FILETIME ftBirthday;	//ѧ������
    int iStature ;          //ѧ�����
}REC_STUDENT,*PREC_STUDENT;

//����ѧ���ֶα�ʶ
#define PID_NO		MAKELONG(CEVT_LPWSTR,1)
//����ѧ�������ֶα�ʶ
#define PID_NAME	MAKELONG(CEVT_LPWSTR,2)
//����ѧ�������ֶα�ʶ
#define PID_BIRTHDAY MAKELONG(CEVT_FILETIME,3)
//����ѧ������ֶα�ʶ
#define PID_STATURE  MAKELONG(CEVT_I4,4)

/////////////////////////////////////////////////////////////////////////////
// CCEDBUseDlg dialog

class CCEDBUseDlg : public CDialog
{
// Construction
public:
	CCEDBUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCEDBUseDlg)
	enum { IDD = IDD_CEDBUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCEDBUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCEDBUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnopen();
	afx_msg void OnBtnclose();
	afx_msg void OnBtnrefresh();
	afx_msg void OnBtnadd();
	afx_msg void OnBtnedit();
	afx_msg void OnBtndelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//�õ���¼��
	int GetRecordCount(CEGUID *pCeGuid,CEOID ceOid);
	//���һ���¼�¼
	bool AddNewStudent(REC_STUDENT stu);
	//�༭��¼
	bool EditStudent(REC_STUDENT stu,CEOID ceOid);
private:
	CEGUID m_ceGuid;	//�洢���ݿ��ļ����ʶ
	HANDLE m_hDB;		//�洢���ݿ���
	CEOID  m_ceOid;     //�洢���ݿ�����ʶ
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEDBUSEDLG_H__3361D3CF_D869_4CC9_9945_20224962011B__INCLUDED_)
