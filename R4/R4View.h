//Download by http://www.NewXing.com
// R4View.h : interface of the CR4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_R4VIEW_H__AAB9CA83_32E7_48E0_B589_FA7853BF12CF__INCLUDED_)
#define AFX_R4VIEW_H__AAB9CA83_32E7_48E0_B589_FA7853BF12CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CR4View : public CView
{
protected: // create from serialization only
	CR4View();
	DECLARE_DYNCREATE(CR4View)

// Attributes
public:
	CR4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CR4View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CR4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CR4View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in R4View.cpp
inline CR4Doc* CR4View::GetDocument()
   { return (CR4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_R4VIEW_H__AAB9CA83_32E7_48E0_B589_FA7853BF12CF__INCLUDED_)
