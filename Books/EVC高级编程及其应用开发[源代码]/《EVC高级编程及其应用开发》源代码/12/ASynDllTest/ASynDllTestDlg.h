// ASynDllTestDlg.h : header file
//

#if !defined(AFX_ASYNDLLTESTDLG_H__9571CBBF_FC51_41B1_945E_54D18BA38555__INCLUDED_)
#define AFX_ASYNDLLTESTDLG_H__9571CBBF_FC51_41B1_945E_54D18BA38555__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//定义ASynDll中的函数类型
typedef long (*TQueryData)(void);
typedef long (*TSetCallbackProcAddr)(long);
/////////////////////////////////////////////////////////////////////////////
// CASynDllTestDlg dialog

class CASynDllTestDlg : public CDialog
{
// Construction
public:
	CASynDllTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CASynDllTestDlg)
	enum { IDD = IDD_ASYNDLLTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CASynDllTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CASynDllTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtncall();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	//存储Dll句柄
    HINSTANCE	m_hModule;
	//定义Dll中的输入函数
	TQueryData m_pQueryData;
    TSetCallbackProcAddr m_pSetCallbackProcAddr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASYNDLLTESTDLG_H__9571CBBF_FC51_41B1_945E_54D18BA38555__INCLUDED_)
