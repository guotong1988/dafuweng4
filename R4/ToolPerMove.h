//Download by http://www.NewXing.com
// ToolPerMove.h: interface for the CToolPerMove class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPERMOVE_H__6B258442_8ACD_4B2B_AA41_CECD4BE016D9__INCLUDED_)
#define AFX_TOOLPERMOVE_H__6B258442_8ACD_4B2B_AA41_CECD4BE016D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolPerMove : public CTool  
{
public:
	CToolPerMove();
	virtual ~CToolPerMove();

	virtual void Draw( CDC * pDC ){}
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos ){}
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual void OnTimer( CDC * pDC );
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLPERMOVE_H__6B258442_8ACD_4B2B_AA41_CECD4BE016D9__INCLUDED_)
