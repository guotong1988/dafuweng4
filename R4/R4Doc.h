//Download by http://www.NewXing.com
// R4Doc.h : interface of the CR4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_R4DOC_H__F61E5012_DA0A_4577_8A7B_55EF3E798B8D__INCLUDED_)
#define AFX_R4DOC_H__F61E5012_DA0A_4577_8A7B_55EF3E798B8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CR4Doc : public CDocument
{
protected: // create from serialization only
	CR4Doc();
	DECLARE_DYNCREATE(CR4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CR4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CR4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CR4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_R4DOC_H__F61E5012_DA0A_4577_8A7B_55EF3E798B8D__INCLUDED_)
