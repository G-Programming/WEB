#if !defined(AFX_TIMELOGSERVER_H__0411707B_EF8F_4068_A498_0BEC50F8C05C__INCLUDED_)
#define AFX_TIMELOGSERVER_H__0411707B_EF8F_4068_A498_0BEC50F8C05C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TimeLogServer.h : header file
//
#include "ITimeLogServer.h"
/////////////////////////////////////////////////////////////////////////////
// CTimeLogServer command target

class CTimeLogServer : public CCmdTarget
{
	DECLARE_DYNCREATE(CTimeLogServer)

	//����ʵ��ITimelog�ӿڵ�Ƕ����
	BEGIN_INTERFACE_PART(TimeLog,ITimeLog)//�Զ�����IUnknown�ӿڵ���������
	  STDMETHOD(OutputLog)(BSTR* varLogText);
	END_INTERFACE_PART(TimeLog)
	//�����ӿ�ӳ��
	DECLARE_INTERFACE_MAP()
	//�����೧
	DECLARE_OLECREATE(CTimeLogServer)

	CTimeLogServer();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeLogServer)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTimeLogServer();

	// Generated message map functions
	//{{AFX_MSG(CTimeLogServer)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
protected:
	    //��־�ļ�ָ��
	    FILE* m_logfile;  
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMELOGSERVER_H__0411707B_EF8F_4068_A498_0BEC50F8C05C__INCLUDED_)
