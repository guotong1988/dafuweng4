//Download by http://www.NewXing.com
// ToolPerStockInfo.h: interface for the CToolPerStockInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPERSTOCKINFO_H__6D4F45CD_2C05_4A42_A39F_3F2BBE3646EE__INCLUDED_)
#define AFX_TOOLPERSTOCKINFO_H__6D4F45CD_2C05_4A42_A39F_3F2BBE3646EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToolPerStockInfo  :public CTool
{
public:
	CToolPerStockInfo(CDC *pDC);
	virtual ~CToolPerStockInfo();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLPERSTOCKINFO_H__6D4F45CD_2C05_4A42_A39F_3F2BBE3646EE__INCLUDED_)
