//Download by http://www.NewXing.com
// Glebe.h: interface for the CGlebe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLEBE_H__98EB5134_8155_42DA_A1AD_3F9D45FE2193__INCLUDED_)
#define AFX_GLEBE_H__98EB5134_8155_42DA_A1AD_3F9D45FE2193__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

//土地类*
class CGlebe : public CEntity  //继承实体类
{
public://公共的
	CGlebe( CDC * pDC, int nTop, int nLeft, int nBottom, int nRight );//构造函数
	virtual ~CGlebe();//析构函数

	void Buy( int nName );//购买土地方法
	void Degrade();//降级房子的方法
	virtual void Draw( CDC * pDC );//显示土地的方法
	void DrawOnSmallMap( CDC * pDC );//在小地图上显示土地
	void DrawOnSmallMapView( CDC * pDC );//在查看小土地时显示土地
	int GetUpGradeValue();//返回升级房子所需的费用
	int GetValue();//土地的租金
	int GetLevel();			//获得房子等级
	virtual bool IsOnMe( CPoint point );//判断是否点在房子上
	int Owner();//返回土地的所有者
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );//读取房子的信息
	virtual int ToolName( CPoint point );//返回点在房子上所需的工具
	virtual void WriteToStream( CArchive & ar );//保存房子信息
	void UpGrade();//升级房子

private://私有的
	int m_nOwner;			//所有者
	int m_nGrade;			//房子等级
	int m_nMaxGrade;		//房子最高等级
	int m_nValue;			//地价
	CBitmap m_SmallBitmap;//用来装载显示在小地图上的图片
	CDC m_SmallDC;//显示图的设备上下文
};

#endif // !defined(AFX_GLEBE_H__98EB5134_8155_42DA_A1AD_3F9D45FE2193__INCLUDED_)
