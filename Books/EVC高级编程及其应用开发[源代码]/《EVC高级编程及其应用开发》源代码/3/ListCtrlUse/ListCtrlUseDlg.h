// ListCtrlUseDlg.h : header file
//

#if !defined(AFX_LISTCTRLUSEDLG_H__52475FD2_4D1B_4F77_9C54_1F8A7E10A77B__INCLUDED_)
#define AFX_LISTCTRLUSEDLG_H__52475FD2_4D1B_4F77_9C54_1F8A7E10A77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CListCtrlUseDlg dialog

class CListCtrlUseDlg : public CDialog
{
// Construction
public:
	CListCtrlUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListCtrlUseDlg)
	enum { IDD = IDD_LISTCTRLUSE_DIALOG };
	CListCtrl	m_listCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListCtrlUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListctrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL	m_bSingleSel;		//是否支持多选
	BOOL	m_bEditLabels;		//是否可以编辑标签
	BOOL	m_bNoColumnHeader;	//是否有表头 //此项只对报表样式有效
	CString	m_cstrViewMode;		//指定报表样式
	CString	m_cstrSort;			//指定排序样式
	CString	m_cstrAlignMode;	//指定对齐样式
private:
	CImageList * m_pImageList ;		// 存储列表视图正常图标列表
	CImageList * m_pImageListSmall;	// 存储列表视图小图标列表
private:
	void FillListCtrl(void);	//填充列表视图
	void SetListCtrl(void);		//设置列表视图
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLUSEDLG_H__52475FD2_4D1B_4F77_9C54_1F8A7E10A77B__INCLUDED_)
