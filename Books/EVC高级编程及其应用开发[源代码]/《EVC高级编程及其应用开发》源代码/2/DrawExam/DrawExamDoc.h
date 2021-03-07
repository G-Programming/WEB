// DrawExamDoc.h : interface of the CDrawExamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWEXAMDOC_H__F288D774_4FCC_46FC_8DEA_6CDA8A276817__INCLUDED_)
#define AFX_DRAWEXAMDOC_H__F288D774_4FCC_46FC_8DEA_6CDA8A276817__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CDrawExamDoc : public CDocument
{
protected: // create from serialization only
	CDrawExamDoc();
	DECLARE_DYNCREATE(CDrawExamDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawExamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawExamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawExamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWEXAMDOC_H__F288D774_4FCC_46FC_8DEA_6CDA8A276817__INCLUDED_)
