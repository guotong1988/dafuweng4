//Download by http://www.NewXing.com
// Bankroll.h: interface for the CBankroll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BANKROLL_H__ECBB1EF7_7724_425A_B063_300EE13DF704__INCLUDED_)
#define AFX_BANKROLL_H__ECBB1EF7_7724_425A_B063_300EE13DF704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

//统计栏*
class CBankroll : public CEntity
{
public:
	enum ShowType		//显示类型*
	{
		My = 0,		//资金*
		Land,		//地产*
		Stock,		//股票*
		Rest		//其他*
	};

	CBankroll();
	virtual ~CBankroll();

	virtual void Draw( CDC * pDC );
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );

private:
	CBitmap m_LandBitmap;
	CDC m_LandDC;
	CBitmap m_StockBitmap;
	CDC m_StockDC;
	CBitmap m_RestBitmap;
	CDC m_RestDC;
	int m_ShowType;
};

#endif // !defined(AFX_BANKROLL_H__ECBB1EF7_7724_425A_B063_300EE13DF704__INCLUDED_)
