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
//����ѧ��������Ϣ�ṹ
typedef struct _CStudentData
{
   TCHAR xsbh[7];  //ѧ�����
   TCHAR xsxm[21]; //ѧ������
   TCHAR xb[3];    //ѧ���Ա�
   TCHAR csrq[11]; //��������
   TCHAR bjmc[21]; //�༶����
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
	//����洢ѧ�����ݱ�Ķ���
	CList<CStudentData,CStudentData&> m_lstStudent;

	//���������ʶ, 0 - �������; 1 - ����༭
	int m_operID ; 
	//�洢ָ��λ��
	int m_iCurPos;
private:
	//���ÿؼ���Ч��
	void SetControlEnable(bool aValue);
    //����ָ���ƶ���ť����Ч��
	void SetNavigatorButton(int aValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEEXAMDLG_H__EDECC86A_BEDA_4955_AAFF_EA13A077D293__INCLUDED_)
