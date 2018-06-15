//Download by http://www.NewXing.com
// Card.h: interface for the CCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARD_H__3BBA202D_DE48_4956_AB9F_289382023C26__INCLUDED_)
#define AFX_CARD_H__3BBA202D_DE48_4956_AB9F_289382023C26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

class CCard : public CEntity  
{
public:
	int Poor();
	//枚举卡片类型
    enum Type
	{
		AngelCard = 1,	//天使卡
		SleepCard,		//冬眠卡
		LeagueCard,		//同盟卡
		FreeCard,		//免费卡
		RemissionCard,	//免罪卡
		ChangeWayCard	//转向卡
	};

	CCard(CDC * pDC,int nID = 0);
	virtual ~CCard();
	virtual void CardISBeUsed( int nI );
	//一条街房屋加盖一层
	virtual void AddBiuldHouse();
	//股票涨停三天
	void Harden();
	//gupiao zhangting santian

	//免费卡免费抵消一次
	//virtual void Free();
	//免罪卡
	void Remission();

	virtual void Draw( CDC * pDC );      //画在屏幕DC上
	void Draw( CPoint point );   //画在背景上
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual int IsCard();
	virtual int ToolName( CPoint point );
	int GetID();
	virtual void WriteToStream( CArchive & ar );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );

private:
	int m_Point;	//卡片点数
	int m_nDays;
	int m_ID;       //卡片的编号
	CString m_Bmp;  //每个卡片图片的文件名
	CString m_str;    //根据ID得到卡片字符串
};

#endif // !defined(AFX_CARD_H__3BBA202D_DE48_4956_AB9F_289382023C26__INCLUDED_)
