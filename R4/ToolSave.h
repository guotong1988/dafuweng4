//Download by http://www.NewXing.com
// ToolSave.h: interface for the CToolSave class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLSAVE_H__755BB457_6783_457D_8790_0F060CEB2106__INCLUDED_)
#define AFX_TOOLSAVE_H__755BB457_6783_457D_8790_0F060CEB2106__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolSave : public CTool  
{
public:
	CToolSave( CDC * pDC );
	virtual ~CToolSave();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point );
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual void OnTimer( CDC * pDC, CPoint point){}
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLSAVE_H__755BB457_6783_457D_8790_0F060CEB2106__INCLUDED_)
