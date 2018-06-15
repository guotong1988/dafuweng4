//Download by http://www.NewXing.com
// ToolSell.h: interface for the CToolSell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLSELL_H__DCBB8F0E_5B03_4126_B7D0_B6145846E310__INCLUDED_)
#define AFX_TOOLSELL_H__DCBB8F0E_5B03_4126_B7D0_B6145846E310__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToolSell : public CTool  
{
public:
	CToolSell(CDC * pDC);
	virtual ~CToolSell();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual int ToolName( CPoint point ){return 0;}
};

#endif // !defined(AFX_TOOLSELL_H__DCBB8F0E_5B03_4126_B7D0_B6145846E310__INCLUDED_)
