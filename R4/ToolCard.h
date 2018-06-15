//Download by http://www.NewXing.com
// ToolCard.h: interface for the CToolCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLCARD_H__80082746_11DE_4C53_A56D_37CA24F67C67__INCLUDED_)
#define AFX_TOOLCARD_H__80082746_11DE_4C53_A56D_37CA24F67C67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolCard : public CTool  
{
public:
	CToolCard(CDC *pDC);
	virtual ~CToolCard();
	virtual void Draw(CDC *pDC);
	virtual void Init_DC_BM( CDC * pDC );
	virtual void OnLButtonDown(CDC *pDC,CPoint ptPos);
	virtual int ToolName( CPoint point );
	virtual bool IsOnMe( CPoint point ){return true;}
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}


	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){};
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){};

private:
	CCard * m_pCard;

};

#endif // !defined(AFX_TOOLCARD_H__80082746_11DE_4C53_A56D_37CA24F67C67__INCLUDED_)
