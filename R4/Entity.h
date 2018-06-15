//Download by http://www.NewXing.com
// Entity.h: interface for the CEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENTITY_H__C462478F_B828_4816_877C_4709250387DA__INCLUDED_)
#define AFX_ENTITY_H__C462478F_B828_4816_877C_4709250387DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//实体类父类*
class CEntity  
{
public:
    enum Type
	{
		Nothing = 0,
		Glebe,
		Per,
		God
	};

	CEntity();
	virtual ~CEntity();

	virtual void Draw( CDC * pDC ) = 0;		//贴图到临时内存*
	virtual void DrawOnPerInfo(){}			//在人物信息中显示有关内容
	virtual bool IsWalkNum(){return false;}
	virtual bool IsOnMe( CPoint point ) = 0;	//点是否在我的作用区*
	virtual void ReadFromStream( CDC * pDC, CArchive & ar ) = 0;	//读取*
	virtual int ToolName( CPoint point ) = 0;	//我需要的工具*
	virtual void WriteToStream( CArchive & ar ) = 0;	//保存*
	void ChangeMyRect(CPoint point);  //为了道具和卡片画在大地图上
	virtual int GetID(){return 0;}
	virtual void GetGod(){}				//神明付身
	virtual void LeaveGod(){}			//神明离开
	virtual int ReduceWalkNum(){return 0;}	
	virtual int IsCard(){return 0;}//判断是卡片还是道具
	virtual void CardISBeUsed( int nI ){}//人被卡片作用
	virtual void PropertyIsBeUsed( int nI ){};//人被道具作用

protected:
	CBitmap m_MyShadowBitmap;	//贴图用*
	CDC m_MyShadowDC;
	CBitmap m_MyBitmap;
	CDC m_MyDC;
	CRect m_MyRect;				//作用区域*
};

#endif // !defined(AFX_ENTITY_H__C462478F_B828_4816_877C_4709250387DA__INCLUDED_)
