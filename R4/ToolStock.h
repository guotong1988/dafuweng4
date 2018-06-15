//Download by http://www.NewXing.com
// ToolStock.h: interface for the CToolStock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLSTOCK_H__3FE57EE0_A672_4C3D_BA75_1E42B8D8D191__INCLUDED_)
#define AFX_TOOLSTOCK_H__3FE57EE0_A672_4C3D_BA75_1E42B8D8D191__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"


class CToolStock : public CTool  
{
public:
	enum CounterState{None,Move};//清除状态,移动状态
	bool IsOnCounterMove(CPoint pt);
	bool IsOnCounterNum( CPoint pt_Num);

	CToolStock(CDC * pDC);
	virtual ~CToolStock();
	virtual void Draw( CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ) ;
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ) ;
	virtual void OnLButtonDblClk( CDC * pDC, CPoint ptPos );
	virtual void OnRButtonDown( CDC * pDC, CPoint point );
	virtual int ToolName( CPoint point );
private:
	CDC m_CounterDC;//输入器上下文
	CBitmap m_CounterBitmap;//输入器位图
	CDC m_BusinessStateDC;//交易状态上下文
	CBitmap m_BusinessStateBitmap;//交易状态位图
	CDC m_GraphDC;//交易状态上下文
	CBitmap m_GraphBitmap;//交易状态位图

	CRect m_CounterRect;//输入器区域
	CRect m_CounterMoveRect;//输入器可移动区域(显输入数字)

	CPoint m_ptCounter;	//确定鼠标左击位置
	CounterState m_CounterState;//确定计算器状态
	int m_iCounterNum;//记录入的数字
	int m_ID;
};

#endif // !defined(AFX_TOOLSTOCK_H__3FE57EE0_A672_4C3D_BA75_1E42B8D8D191__INCLUDED_)
