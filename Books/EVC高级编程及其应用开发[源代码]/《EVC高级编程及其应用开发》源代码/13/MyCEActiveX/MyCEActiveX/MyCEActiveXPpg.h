#if !defined(AFX_MYCEACTIVEXPPG_H__F05AAA0B_6C3A_4426_A0F9_D493D597BAF4__INCLUDED_)
#define AFX_MYCEACTIVEXPPG_H__F05AAA0B_6C3A_4426_A0F9_D493D597BAF4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// MyCEActiveXPpg.h : Declaration of the CMyCEActiveXPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CMyCEActiveXPropPage : See MyCEActiveXPpg.cpp.cpp for implementation.

class CMyCEActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMyCEActiveXPropPage)
	DECLARE_OLECREATE_EX(CMyCEActiveXPropPage)

// Constructor
public:
	CMyCEActiveXPropPage();

// Dialog Data
	//{{AFX_DATA(CMyCEActiveXPropPage)
	enum { IDD = IDD_PROPPAGE_MYCEACTIVEX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CMyCEActiveXPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCEACTIVEXPPG_H__F05AAA0B_6C3A_4426_A0F9_D493D597BAF4__INCLUDED)
