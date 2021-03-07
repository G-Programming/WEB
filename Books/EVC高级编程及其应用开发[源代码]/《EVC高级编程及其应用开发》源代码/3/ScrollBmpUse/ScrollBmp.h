#if !defined(AFX_SCROLLBMP_H__EFA04A27_BC09_4D9D_BEEE_BBC11197695E__INCLUDED_)
#define AFX_SCROLLBMP_H__EFA04A27_BC09_4D9D_BEEE_BBC11197695E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ScrollBmp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScrollBmp window

class CScrollBmp : public CWnd
{
// Construction
public:
	CScrollBmp();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollBmp)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScrollBmp();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScrollBmp)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CScrollBar	m_vbar;			//��ֱ������
	CScrollBar	m_hbar;			//ˮƽ������

	CDC m_dcMem;				//�ڴ��豸���������ڻ���λͼ
	
	HBITMAP m_hBmpOld;			// ����ɵ�Bitmap������
	HBITMAP m_hBmpNew;			// �����µ�Bitmap������
   
	CRect m_rectStaticClient;	//�洢bmp��ʾ�ؼ��Ĵ�С

	BOOL m_erase;				//�����Ƿ����

	int m_offsetX,m_offsetY;	//������ʾλͼ��ƫ����
	int m_sourceX, m_sourceY;	//������ʾλͼʱ��Դλͼ�Ŀ�ʼ��
public:
	//��ʼ������λͼ��ʾ�ؼ�
	void InitBmpCtrl(); 
	//�����ļ�������ͼƬ
	BOOL LoadBmp(LPTSTR lpszResourceName);
	//����λͼ��ԴID����ͼƬ
	BOOL LoadBmp(UINT nIDResource);
private:
	void LoadBmpToCtrl();

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLBMP_H__EFA04A27_BC09_4D9D_BEEE_BBC11197695E__INCLUDED_)
