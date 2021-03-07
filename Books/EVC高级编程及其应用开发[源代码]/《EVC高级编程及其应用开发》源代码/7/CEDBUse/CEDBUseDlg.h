// CEDBUseDlg.h : header file
//

#if !defined(AFX_CEDBUSEDLG_H__3361D3CF_D869_4CC9_9945_20224962011B__INCLUDED_)
#define AFX_CEDBUSEDLG_H__3361D3CF_D869_4CC9_9945_20224962011B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//定义数据库文件名
const LPTSTR  DBFILENAME = _T("\\My Documents\\abc.db");
//定义数据库名
const LPTSTR  DBTABLENAME = _T("Student");

//定义学生数据库表结构
typedef struct
{
	TCHAR szNo[7];			//学生编号
	TCHAR szName[20] ;		//学生姓名
	FILETIME ftBirthday;	//学生生日
    int iStature ;          //学生身高
}REC_STUDENT,*PREC_STUDENT;

//定义学生字段标识
#define PID_NO		MAKELONG(CEVT_LPWSTR,1)
//定义学生姓名字段标识
#define PID_NAME	MAKELONG(CEVT_LPWSTR,2)
//定义学生生日字段标识
#define PID_BIRTHDAY MAKELONG(CEVT_FILETIME,3)
//定义学生身高字段标识
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
	//得到记录数
	int GetRecordCount(CEGUID *pCeGuid,CEOID ceOid);
	//添加一条新记录
	bool AddNewStudent(REC_STUDENT stu);
	//编辑记录
	bool EditStudent(REC_STUDENT stu,CEOID ceOid);
private:
	CEGUID m_ceGuid;	//存储数据库文件卷标识
	HANDLE m_hDB;		//存储数据库句柄
	CEOID  m_ceOid;     //存储数据库对象标识
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEDBUSEDLG_H__3361D3CF_D869_4CC9_9945_20224962011B__INCLUDED_)
