//Download by http://www.NewXing.com
// God.h: interface for the CGod class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOD_H__1DE64F01_DABC_44C6_9B3C_1987E13060CA__INCLUDED_)
#define AFX_GOD_H__1DE64F01_DABC_44C6_9B3C_1987E13060CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"
//#include "Per.h"
class CPer;

class CGod : public CEntity  
{
public:
	enum Immortal{None = 0,
				Wealth/*财神*/,
				GriefMan/*哀神*/,
				Billiken/*福神*/,
				PoorMan/*穷神*/,
				Angell/*天使*/,
				present/*礼物*/,
				dog/*狗*/,
				box/*盒子*/};//神仙种类

	CGod( CDC *pDC , CPoint point, int nName  = 0 );
	virtual ~CGod();
	virtual void Draw( CDC * pDC );
	virtual bool IsWalkNum();
	virtual void GetGod();//神明付身
	virtual void LeaveGod();//神明离开
	virtual void DrawOnPerInfo();
	virtual int ReduceWalkNum();//减少神仙作用期

	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );
private:
	int m_WalkNum;//步数
	int m_immortal;//神仙种类

	CBitmap m_FlyShadowBitmap;
	CDC m_FlyShadowDC;

	CBitmap m_FlyBitmap;
	CDC m_FlyDC;
};

#endif // !defined(AFX_GOD_H__1DE64F01_DABC_44C6_9B3C_1987E13060CA__INCLUDED_)
