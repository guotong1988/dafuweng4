//Download by http://www.NewXing.com
// SmallMap.h: interface for the CSmallMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMALLMAP_H__594E1251_F9C4_4C40_A8B8_B83D076A0413__INCLUDED_)
#define AFX_SMALLMAP_H__594E1251_F9C4_4C40_A8B8_B83D076A0413__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

class CSmallMap : public CEntity  
{
public:
	CSmallMap();//构造函数
	virtual ~CSmallMap();//析构函数

	virtual void Draw( CDC * pDC );//显示小地图
	virtual void Init_DC_BM( CDC * pDC );//初始化设备上下文
	virtual bool IsOnMe( CPoint point );//是否点在我的作用区上
	void MoveRectangle( CPoint ptPos );//点小图移动矩形
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );//读取小地图信息
	virtual int ToolName( CPoint point );//点小图时所需的工具
	virtual void WriteToStream( CArchive & ar );//保存小地图信息

public:
	CPoint m_ptCoordinate;	//大地图显示区域中心坐标在小地图中的位置*
};

#endif // !defined(AFX_SMALLMAP_H__594E1251_F9C4_4C40_A8B8_B83D076A0413__INCLUDED_)
