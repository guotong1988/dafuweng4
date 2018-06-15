//Download by http://www.NewXing.com
// ToolPerSell.h: interface for the CToolPerSell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPERSELL_H__2A77E061_923A_4E2B_B983_3D110D0A8654__INCLUDED_)
#define AFX_TOOLPERSELL_H__2A77E061_923A_4E2B_B983_3D110D0A8654__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolPerSell : public CTool  
{
public:
	CToolPerSell(CDC * pDC);
	virtual ~CToolPerSell();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLPERSELL_H__2A77E061_923A_4E2B_B983_3D110D0A8654__INCLUDED_)
