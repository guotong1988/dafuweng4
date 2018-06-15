//Download by http://www.NewXing.com
// Property.h: interface for the CProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPERTY_H__3907DC42_5473_4FD6_9831_557BFDCA7700__INCLUDED_)
#define AFX_PROPERTY_H__3907DC42_5473_4FD6_9831_557BFDCA7700__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

class CProperty : public CEntity  
{
public:
	void ChangeMyRect(CPoint point);
	enum Type
	{
		Torpedo = 1,      //地雷
		RoadBlock,    //路障       
		TimeBomb,	  //定时炸弹
        Missile,      //飞弹
		Nucleon,      //核子飞弹
        Car,          //汽车  
		Engine,       //机车  
		RemoteDice,  //遥控色子
		Mobile,       //工程车  
		Robot,        //机器工人
		TimeMachine,  //时光机
        TransMachine, //传送机
		RobotBaby     //机器娃娃
	}; 
	CProperty(CDC * pDC, int nID =0 , CPoint point = CPoint(0, 0));
	virtual ~CProperty();
	virtual void Draw( CDC * pDC );      //画在屏幕DC上
	void Draw( bool isBig, CPoint point );   //画在背景上
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual int IsCard();
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual void PropertyIsBeUsed( int nI );

	int GetID();
	void ClearRoad();
	//void SetProperty(int);         //设置道具
	char * GetNameOfProperty(int);         //根据道具编号得到道具名称

	//炸人住院函数。参数1 玩家对象（指针）  2住院天数
	//地雷  定时炸弹   飞弹   核子飞弹使用
	void MakePeopleInHispital(CPer *, int); 

	//改变色子函数。参数1 色子个数  2色子点数
	//汽车  机车  遥控色子使用
	void ChangeNumberOrCountOfDice();

    //改变房子等级或拆房。参数 房子对象（指针）
	//工程车  机器工人使用
	void ChangeOrDestoryHouse();

	//Load上一回合方法  时光机使用
	void  ReturnLast();

	//移动对象到指定地点  传送机使用
	void  MoveObject( );

	//阻止玩家移动  路障使用
	void  StopPeople();

	//清除所有道具 机器娃娃使用
	
	enum canBuy               //道具能否被买
	{
	    yes,
		no
	};

private:
    int m_Money;          //道具的价格
	int m_ID;             //道具的编号
	int m_nDays;
	CString m_Bmp;        //每个道具图片文件名
	CString m_BmpShadow;  //每个道具影子文件名
	CString m_BmpCount;   //图片和影子的基数
};

#endif // !defined(AFX_PROPERTY_H__3907DC42_5473_4FD6_9831_557BFDCA7700__INCLUDED_)
