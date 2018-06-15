//Download by http://www.NewXing.com
// ToolLendFund.h: interface for the CToolLendFund class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLLENDFUND_H__FA96168B_CB59_473F_AF02_4E372DE1B07D__INCLUDED_)
#define AFX_TOOLLENDFUND_H__FA96168B_CB59_473F_AF02_4E372DE1B07D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolLendFund : public CTool  
{
public:
	CToolLendFund(CDC * pDC);
	virtual ~CToolLendFund();

	virtual void Draw(CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual void OnTimer( CDC * pDC){}
	virtual int ToolName( CPoint point);

private:
	int m_iLend;//贷款
	CRect m_CounterRect;//输入器区域
	CDC m_CounterDC;//输入器上下文
	CBitmap m_CounterBitmap;//输入器位图
};

#endif // !defined(AFX_TOOLLENDFUND_H__FA96168B_CB59_473F_AF02_4E372DE1B07D__INCLUDED_)
