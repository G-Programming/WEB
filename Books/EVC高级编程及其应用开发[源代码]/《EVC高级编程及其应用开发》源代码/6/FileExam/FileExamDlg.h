// FileExamDlg.h : header file
//

#if !defined(AFX_FILEEXAMDLG_H__EDECC86A_BEDA_4955_AAFF_EA13A077D293__INCLUDED_)
#define AFX_FILEEXAMDLG_H__EDECC86A_BEDA_4955_AAFF_EA13A077D293__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include <Afxtempl.h>

const LPCTSTR STUDENTFILEPATH = _T("\\My Documents\\student.dat");
/////////////////////////////////////////////////////////////////////////////
// CFileExamDlg dialog
#pragma pack(push,1)
//定义学生基本信息结构
typedef struct _CStudentData
{
   TCHAR xsbh[7];  //学生编号
   TCHAR xsxm[21]; //学生姓名
   TCHAR xb[3];    //学生性别
   TCHAR csrq[11]; //出生日期
   TCHAR bjmc[21]; //班级名称
}CStudentData;
#pragma pack(pop)

class CFileExamDlg : public CDialog
{
// Construction
public:
	CFileExamDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileExamDlg)
	enum { IDD = IDD_FILEEXAM_DIALOG };
	CString	m_bjmc;
	CString	m_csrq;
	CString	m_xsbh;
	CString	m_xsxm;
	CString	m_xsxb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileExamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileExamDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnfirst();
	afx_msg void OnBtnprior();
	afx_msg void OnBtnnext();
	afx_msg void OnBtnlast();
	afx_msg void OnBtnadd();
	afx_msg void OnBtnedit();
	afx_msg void OnBtncancel();
	afx_msg void OnBtnsave();
	afx_msg void OnBtndelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//定义存储学生数据表的队列
	CList<CStudentData,CStudentData&> m_lstStudent;

	//定义操作标识, 0 - 代表添加; 1 - 代表编辑
	int m_operID ; 
	//存储指针位置
	int m_iCurPos;
private:
	//设置控件有效性
	void SetControlEnable(bool aValue);
    //设置指针移动按钮的有效性
	void SetNavigatorButton(int aValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEEXAMDLG_H__EDECC86A_BEDA_4955_AAFF_EA13A077D293__INCLUDED_)
