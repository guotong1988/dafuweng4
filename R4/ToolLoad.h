//Download by http://www.NewXing.com
// ToolLoad.h: interface for the CToolLoad class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLLOAD_H__975A9E91_D319_4719_A7D3_C655B7D4BD35__INCLUDED_)
#define AFX_TOOLLOAD_H__975A9E91_D319_4719_A7D3_C655B7D4BD35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolLoad : public CTool  
{
public:
	CToolLoad( CDC * pDC );
	virtual ~CToolLoad();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point );
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos ){}
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual void OnTimer( CDC * pDC, CPoint point){}
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLLOAD_H__975A9E91_D319_4719_A7D3_C655B7D4BD35__INCLUDED_)
