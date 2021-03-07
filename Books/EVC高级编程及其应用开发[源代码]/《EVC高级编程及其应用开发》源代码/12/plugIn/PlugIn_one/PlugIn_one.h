// PlugIn_one.h : main header file for the PLUGIN_ONE DLL
//

#if !defined(AFX_PLUGIN_ONE_H__E96B3728_B531_42F9_8DC2_EBDBD53D8C62__INCLUDED_)
#define AFX_PLUGIN_ONE_H__E96B3728_B531_42F9_8DC2_EBDBD53D8C62__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlugIn_oneApp
// See PlugIn_one.cpp for the implementation of this class
//

class CPlugIn_oneApp : public CWinApp
{
public:
	CPlugIn_oneApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlugIn_oneApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPlugIn_oneApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
    //����һ��ToolBarָ��
	CToolBar *m_pwndToolBar;
public:
	//�������������幤����ָ��
	void SetToolBarPointer(CToolBar *pwndToolBar);
	//������Ӱ�ť�������幤������
	void AddButtonToToolBar();
	//���ڴ���������ɾ������ӵİ�ť
	void RemoveButtonFromToolBar();
	//���ڵõ������ť�ı�ʶ
	UINT GetToolBarButtonInfo(void);
	//���ڵõ������ͼ��
	HICON* GetPlugInIcon(void);
    //����ִ���ⲿ����
    bool WinExec(LPCTSTR FileName);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGIN_ONE_H__E96B3728_B531_42F9_8DC2_EBDBD53D8C62__INCLUDED_)
