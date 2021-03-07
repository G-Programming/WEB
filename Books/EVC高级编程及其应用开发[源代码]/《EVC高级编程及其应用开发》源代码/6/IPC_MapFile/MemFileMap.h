#if !defined(AFX_MEMFILEMAP_H__3C0940F1_4A1B_41AA_8697_FDDC97C5780A__INCLUDED_)
#define AFX_MEMFILEMAP_H__3C0940F1_4A1B_41AA_8697_FDDC97C5780A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MemFileMap.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMemFileMap window
//定义内存文件内容变化消息字符串
const LPCTSTR  MEMFILECHANG = _T("MEMFILECHANGE");
//定义内存映射内容改变事件
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
	DWORD m_MaxSize ; //内存文件大小
	CString m_MapName; //内存映射文件名称
	bool m_Syn; //是否同步
    ONMEMDATACHANGE m_OnMemDataChange; //内存映射区内容改变事件

	//创建或打开内存映射文件
	DWORD OpenFileMap(CWnd * pWnd);
	//关闭映射文件
	void CloseFileMap();
	//读取内存文件信息
	LPCTSTR ReadBuffer();
	//写入内存文件信息
	DWORD WriteBuffer(LPCTSTR buf);
private:
	HANDLE m_hMapFile; //内存映射文件句柄
	LPTSTR m_pMapPointer ; //内存文件映射数据句柄
	HANDLE m_hSynEvent ; //写内存文件时，同步事件句柄
	DWORD m_SynMessageID ;//同步消息
	CWnd  * m_pParentWnd ; //指定创建此类的窗体指针
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMFILEMAP_H__3C0940F1_4A1B_41AA_8697_FDDC97C5780A__INCLUDED_)
