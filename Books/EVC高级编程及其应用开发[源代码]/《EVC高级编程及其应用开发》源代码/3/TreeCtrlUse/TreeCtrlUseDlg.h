// TreeCtrlUseDlg.h : header file
//

#if !defined(AFX_TREECTRLUSEDLG_H__11DB8384_142A_4EB6_A0BB_F76A2529CFD7__INCLUDED_)
#define AFX_TREECTRLUSEDLG_H__11DB8384_142A_4EB6_A0BB_F76A2529CFD7__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlUseDlg dialog

class CTreeCtrlUseDlg : public CDialog
{
// Construction
public:
	CTreeCtrlUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeCtrlUseDlg)
	enum { IDD = IDD_TREECTRLUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtrlUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTreeCtrlUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL	m_bHasButtons; //�Ƿ�ť��ʾ 
	BOOL	m_bHasLines;   //�Ƿ���ʾ������
	BOOL	m_bLinesAtRoot;  //�������Ƿ�Ӹ���ʼ
	BOOL	m_bEditLabels;   //�Ƿ���Ա༭��ǩ
	BOOL	m_bShowSelAlways; //�Ƿ�ʼ����ʾѡ��

	CImageList *m_pImgList;	//���ڴ洢ͼƬ�б�
private:
	//��ʼ������������Ҫ����������
	void InitTree();
	//����ĳ��������
	void SetNewStyle(long lStyleMask, BOOL bSetBits);
	//��������ʽ
	void SetTreeCtrlStyle();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREECTRLUSEDLG_H__11DB8384_142A_4EB6_A0BB_F76A2529CFD7__INCLUDED_)
