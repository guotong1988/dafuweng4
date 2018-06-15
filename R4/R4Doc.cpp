//Download by http://www.NewXing.com
// R4Doc.cpp : implementation of the CR4Doc class
//

#include "stdafx.h"
#include "R4.h"

#include "R4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CR4Doc

IMPLEMENT_DYNCREATE(CR4Doc, CDocument)

BEGIN_MESSAGE_MAP(CR4Doc, CDocument)
	//{{AFX_MSG_MAP(CR4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CR4Doc construction/destruction

CR4Doc::CR4Doc()
{
	// TODO: add one-time construction code here

}

CR4Doc::~CR4Doc()
{
}

BOOL CR4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CR4Doc serialization

void CR4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CR4Doc diagnostics

#ifdef _DEBUG
void CR4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CR4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CR4Doc commands
