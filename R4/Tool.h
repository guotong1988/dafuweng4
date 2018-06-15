//Download by http://www.NewXing.com
// Tool.h: interface for the CTool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOL_H__50E92B15_31D3_483F_A2EF_9BF95362C723__INCLUDED_)
#define AFX_TOOL_H__50E92B15_31D3_483F_A2EF_9BF95362C723__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTool  
{
public:
	enum ToolState	//状态
	{
		stInit = 0,	//无
		stFirst,	//单击一次
		stSecond,	//单击两次
		stThird,
		stFour
	};
	enum ToolType	//种类
	{
		NoTool = 0,		//无工具
		NoChange,		//不改变
		Card,			//显示卡片
		Dice,			//洒色子
		Load,			//读取
		MoveBigMap,		//移动大地图工具
		PerGlebeInfo,	//显示人物的房屋信息
		PerInfo,		//显示人物信息
		PerMove,		//移动人
		PerSell,		//显示人物拍卖信息
		PerStockInfo,	//显示人物股票信息
		Property,		//显示道具
		Save,			//保存
		Sell,			//显示拍卖项目
		ShowSmallMap,	//显示小地图*
		Stock,			//显示股票
		UsePropertyAndCard,//使用道具卡片
		Bank,			//银行取款工具
		BankLend		//银行存款工具
	};


	CTool();
	virtual ~CTool();

	virtual void Draw( CDC * pDC ) = 0;
	virtual bool IsOnMe( CPoint point ) = 0;
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ) = 0;
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos ) = 0;
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ) = 0;
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ) = 0;
	virtual void OnTimer( CDC * pDC){}
	virtual int ToolName( CPoint point ) = 0;
	virtual void ChangeIsCard(){};

	static bool PointInRect( CPoint point, CRect rect );	//判断点是否在区域内*

protected:
	CBitmap m_MyBitmap;
	CDC m_MyDC;
	CBitmap m_MyShadowBitmap;
	CDC m_MyShadowDC;
	CRect m_MyRect;				//作用区域*
	ToolState m_ToolState;	//状态
};

#endif // !defined(AFX_TOOL_H__50E92B15_31D3_483F_A2EF_9BF95362C723__INCLUDED_)
