//Download by http://www.NewXing.com
// ToolDice.h: interface for the CToolDice class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDICE_H__298F5993_80A4_4B94_86BE_ABBD6B8F3816__INCLUDED_)
#define AFX_TOOLDICE_H__298F5993_80A4_4B94_86BE_ABBD6B8F3816__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolDice : public CTool  
{
public:
	enum GoType
	{
		None = 0,	//清除状态
		Go,			//移动人物
		Move		//移动图片
	};

	CToolDice( CDC *pDC );
	virtual ~CToolDice();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos );
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos );
	virtual void OnTimer( CDC * pDC );
	virtual int ToolName( CPoint point );

private:
	CDC m_DiceShadowDC;
	CBitmap m_DiceShadowBitmap;

	CDC m_DiceDC;
	CBitmap m_DiceBitmap;

	CDC m_LightDC;
	CBitmap m_LightBitmap;

	bool m_bBitmapType;//贴图判断
	int m_nCount;	//闪烁计数*
	int m_Type;		//判断鼠标左击触发事件
	CPoint m_pt;	//鼠标左击位置
	CRect m_DiceRect;	//色子区域*
	int m_DiceNum;		//筛子点数*
	int m_DiceStep;		//色子贴图*
	int m_nDiceCount;	//闪烁计数*

	static CRect m_MoveRect; //鼠标左击触发工具移动
};

#endif // !defined(AFX_TOOLDICE_H__298F5993_80A4_4B94_86BE_ABBD6B8F3816__INCLUDED_)
