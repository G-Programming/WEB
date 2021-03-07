#if !defined(AFX_MYCEACTIVEXCTL_H__1A8E7B8D_134C_4DB3_B2C2_0DCD69446236__INCLUDED_)
#define AFX_MYCEACTIVEXCTL_H__1A8E7B8D_134C_4DB3_B2C2_0DCD69446236__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// MyCEActiveXCtl.h : Declaration of the CMyCEActiveXCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXCtrl : See MyCEActiveXCtl.cpp for implementation.

class CMyCEActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMyCEActiveXCtrl)

// Constructor
public:
	CMyCEActiveXCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCEActiveXCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CMyCEActiveXCtrl();

	DECLARE_OLECREATE_EX(CMyCEActiveXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMyCEActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMyCEActiveXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMyCEActiveXCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CMyCEActiveXCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CMyCEActiveXCtrl)
	afx_msg BSTR GetMsgContext();
	afx_msg void SetMsgContext(LPCTSTR lpszNewValue);
	afx_msg void ShowMessage();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CMyCEActiveXCtrl)
	void FireOnMsgChange()
		{FireEvent(eventidOnMsgChange,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CMyCEActiveXCtrl)
	dispidMsgContext = 1L,
	dispidShowMessage = 2L,
	eventidOnMsgChange = 1L,
	//}}AFX_DISP_ID
	};
private:
   CString m_MsgContext;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCEACTIVEXCTL_H__1A8E7B8D_134C_4DB3_B2C2_0DCD69446236__INCLUDED)
