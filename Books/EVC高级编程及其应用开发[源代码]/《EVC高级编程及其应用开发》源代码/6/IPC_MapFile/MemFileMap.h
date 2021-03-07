#if !defined(AFX_MEMFILEMAP_H__3C0940F1_4A1B_41AA_8697_FDDC97C5780A__INCLUDED_)
#define AFX_MEMFILEMAP_H__3C0940F1_4A1B_41AA_8697_FDDC97C5780A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MemFileMap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMemFileMap window
//�����ڴ��ļ����ݱ仯��Ϣ�ַ���
const LPCTSTR  MEMFILECHANG = _T("MEMFILECHANGE");
//�����ڴ�ӳ�����ݸı��¼�
typedef void (CALLBACK* ONMEMDATACHANGE)(CWnd*);

class CMemFileMap : public CWnd
{
// Construction
public:
	CMemFileMap();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemFileMap)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMemFileMap();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMemFileMap)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	DWORD m_MaxSize ; //�ڴ��ļ���С
	CString m_MapName; //�ڴ�ӳ���ļ�����
	bool m_Syn; //�Ƿ�ͬ��
    ONMEMDATACHANGE m_OnMemDataChange; //�ڴ�ӳ�������ݸı��¼�

	//��������ڴ�ӳ���ļ�
	DWORD OpenFileMap(CWnd * pWnd);
	//�ر�ӳ���ļ�
	void CloseFileMap();
	//��ȡ�ڴ��ļ���Ϣ
	LPCTSTR ReadBuffer();
	//д���ڴ��ļ���Ϣ
	DWORD WriteBuffer(LPCTSTR buf);
private:
	HANDLE m_hMapFile; //�ڴ�ӳ���ļ����
	LPTSTR m_pMapPointer ; //�ڴ��ļ�ӳ�����ݾ��
	HANDLE m_hSynEvent ; //д�ڴ��ļ�ʱ��ͬ���¼����
	DWORD m_SynMessageID ;//ͬ����Ϣ
	CWnd  * m_pParentWnd ; //ָ����������Ĵ���ָ��
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMFILEMAP_H__3C0940F1_4A1B_41AA_8697_FDDC97C5780A__INCLUDED_)
