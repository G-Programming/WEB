#if !defined(AFX_PLUGINDLG_H__8F18B557_ABA7_4F8F_B545_C1BD33E6AC68__INCLUDED_)
#define AFX_PLUGINDLG_H__8F18B557_ABA7_4F8F_B545_C1BD33E6AC68__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PlugInDlg.h : header file
//
#include "PlugIn_Main.h"

/////////////////////////////////////////////////////////////////////////////
// CPlugInDlg dialog

class CPlugInDlg : public CDialog
{
// Construction
public:
	CPlugInDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlugInDlg)
	enum { IDD = IDD_PLUGINDLG_DIALOG };
	CListCtrl	m_lstPlugIn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlugInDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlugInDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnload();
	afx_msg void OnBtnclose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
    //�������Ϣ��䵽�б���ͼ
	void FillPlugIns();
	//����ͬ��ִ���ļ���ͬĿ¼�µ�.plx����ļ���������洢���б���
	int FindDLLs(CPlugIn_MainApp *pApp);
	//����ѡ�еĲ���б�
	bool LoadDLLs(CPlugIn_MainApp *pApp, CStringList *szListSelectedDLLs);
private:
	//�洢���DLL�ļ����б�
	CStringList m_szListValidFilenames;
	//�洢������б�
	CStringList m_szListPlugInName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGINDLG_H__8F18B557_ABA7_4F8F_B545_C1BD33E6AC68__INCLUDED_)
