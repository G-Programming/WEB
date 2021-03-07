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
	BOOL	m_bSingleSel;		//�Ƿ�֧�ֶ�ѡ
	BOOL	m_bEditLabels;		//�Ƿ���Ա༭��ǩ
	BOOL	m_bNoColumnHeader;	//�Ƿ��б�ͷ //����ֻ�Ա�����ʽ��Ч
	CString	m_cstrViewMode;		//ָ��������ʽ
	CString	m_cstrSort;			//ָ��������ʽ
	CString	m_cstrAlignMode;	//ָ��������ʽ
private:
	CImageList * m_pImageList ;		// �洢�б���ͼ����ͼ���б�
	CImageList * m_pImageListSmall;	// �洢�б���ͼСͼ���б�
private:
	void FillListCtrl(void);	//����б���ͼ
	void SetListCtrl(void);		//�����б���ͼ
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLUSEDLG_H__52475FD2_4D1B_4F77_9C54_1F8A7E10A77B__INCLUDED_)
