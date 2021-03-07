// PlugIn_MainDoc.h : interface of the CPlugIn_MainDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLUGIN_MAINDOC_H__AC6F7E50_F73A_48B9_8CF1_43F43C3FF2B3__INCLUDED_)
#define AFX_PLUGIN_MAINDOC_H__AC6F7E50_F73A_48B9_8CF1_43F43C3FF2B3__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPlugIn_MainDoc : public CDocument
{
protected: // create from serialization only
	CPlugIn_MainDoc();
	DECLARE_DYNCREATE(CPlugIn_MainDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlugIn_MainDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlugIn_MainDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlugIn_MainDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGIN_MAINDOC_H__AC6F7E50_F73A_48B9_8CF1_43F43C3FF2B3__INCLUDED_)
