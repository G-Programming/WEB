// IPC_MapFileDlg.h : header file
//

#if !defined(AFX_IPC_MAPFILEDLG_H__6AA34B7F_0ED7_4656_B705_E3A3E2C2E277__INCLUDED_)
#define AFX_IPC_MAPFILEDLG_H__6AA34B7F_0ED7_4656_B705_E3A3E2C2E277__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "MemFileMap.h"
/////////////////////////////////////////////////////////////////////////////
// CIPC_MapFileDlg dialog

class CIPC_MapFileDlg : public CDialog
{
// Construction
public:
	CIPC_MapFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIPC_MapFileDlg)
	enum { IDD = IDD_IPC_MAPFILE_DIALOG };
	BOOL	m_Exist;
	BOOL	m_Open;
	BOOL	m_Syn;
	CString	m_MemData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPC_MapFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIPC_MapFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnopen();
	afx_msg void OnBtnclose();
	afx_msg void OnBtnread();
	afx_msg void OnBtnwrite();
	afx_msg void OnCksyn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
  	//定义内存映射文件通讯类变量
	CMemFileMap m_memFileMap;
private:
	//内存映射文件内容变化事件函数
	static void CALLBACK OnMemDataChange(CWnd *pWnd);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPC_MAPFILEDLG_H__6AA34B7F_0ED7_4656_B705_E3A3E2C2E277__INCLUDED_)
