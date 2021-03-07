// ASynDll.h : main header file for the ASYNDLL DLL
//

#if !defined(AFX_ASYNDLL_H__72262C09_06CC_43AD_BCC0_E2227C411015__INCLUDED_)
#define AFX_ASYNDLL_H__72262C09_06CC_43AD_BCC0_E2227C411015__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CASynDllApp
// See ASynDll.cpp for the implementation of this class
//
class CASynDllApp : public CWinApp
{
public:
	CASynDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CASynDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CASynDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//���������ASynDLL_EXPORTS��
//������ASynDLL_APIΪ����,��������Ϊ����
#ifdef ASynDLL_EXPORTS
#define ASynDLL_API __declspec(dllexport)
#else
#define ASynDLL_API __declspec(dllimport)
#endif

//����Dll����
extern "C" 
{
	//��ѯ���ݣ��첽����
	long ASynDLL_API QueryData(void); 
	//���ûص�����
    long ASynDLL_API SetCallbackProcAddr(long); 
}

//����ص���������
typedef void (* TDataReadNotify)(long);

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASYNDLL_H__72262C09_06CC_43AD_BCC0_E2227C411015__INCLUDED_)
