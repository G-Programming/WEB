// ADOAccessDlg.h : header file
//

#if !defined(AFX_ADOACCESSDLG_H__85F7B481_4E5D_4BBC_9381_83689140488A__INCLUDED_)
#define AFX_ADOACCESSDLG_H__85F7B481_4E5D_4BBC_9381_83689140488A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace MSADOCE
{
#include <adoce30.h>
}
//定义连接对象唯一标识
const IID IID__Connection = {0x113033DE,0xF682,0x11D2,{0xBB,0x62,0x00,0xC0,0x4F,0x68,0x0A,0xCC}};
//定义记录对象唯一标识
const IID IID__Recordset = {0x113033F6,0xF682,0x11D2,{0xBB,0x62,0x00,0xC0,0x4F,0x68,0x0A,0xCC}};

//定义连接对象字符串名
const TCHAR g_szADOCE30ConnProgID[]= TEXT("ADOCE.Connection.3.0");
//定义记录对象字符串名
const TCHAR g_szADOCE30RSProgID[]= TEXT("ADOCE.Recordset.3.0");

class CADOAccessDlg : public CDialog
{
// Construction
public:
	CADOAccessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CADOAccessDlg)
	enum { IDD = IDD_ADOACCESS_DIALOG };
	CString	m_strSql;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOAccessDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOAccessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBtncreatedb();
	afx_msg void OnBtnopendb();
	afx_msg void OnBtnexec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	MSADOCE::IADOCEConnection *m_pADOCEConn     ; //连接对象
	MSADOCE::IADOCERecordset  *m_pADOCERS       ; //记录集对象
	MSADOCE::IADOCEFields     *m_pADOCEFields   ; //字段集对象
	MSADOCE::IADOCEField	  *m_pADOCEField    ;  //字段对象
private:

    BOOL CreateConnection(); //建立与Access数据库连接
	void CloseConnection();  //关闭与Access数据库连接

	//打开数据库
	BOOL OpenDatabase(LPCTSTR szDbName);
	//新建数据库
	BOOL CreateDatabase(LPCTSTR szDbName);

	//将表中的记录在列表视图上显示
	void AddRecordToView();


};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOACCESSDLG_H__85F7B481_4E5D_4BBC_9381_83689140488A__INCLUDED_)
