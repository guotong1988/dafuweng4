//Download by http://www.NewXing.com
// EntityNode.h: interface for the CEntityNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENTITYNODE_H__E04BBCE9_B606_4E93_AB00_2B7E1A65FDE3__INCLUDED_)
#define AFX_ENTITYNODE_H__E04BBCE9_B606_4E93_AB00_2B7E1A65FDE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"
#include "Glebe.h"
#include "Per.h"

//路节点*
class CEntityNode  
{
public:
	enum WayName
	{
		NotOnWay = 0,
		NanJinWay,
		BeiJinway
	};

	CEntityNode( CPoint ptCoordinate, int nWayName,
				CGod * pGod, CGlebe * pGlebe, CPer * pPer);
	virtual ~CEntityNode();
	bool AddGodOrProperty( CEntity * pEntity , CPoint point );
	void Draw( CDC * pDC );
	void DrawOnSmallMap( CDC * pDC );
	void DrawOnSmallMapView( CDC * pDC );
	bool IsOnGlebe( CPoint point );
	bool IsOnMe( CPoint point );
	bool IsOnPer( CPoint point );
	void ReadFromStream( CDC * pDC, CArchive & ar );
	void WriteToStream( CArchive & ar );

public:
	CPoint m_ptCoordinate;			//坐标
	int m_WayName;					//土地所在的路名
	CGlebe * m_pGlebe;				//指向土地
	CPer * m_pPer;					//指向人
	CPer * m_pSecondPer;			//指向第二个人
	CEntity * m_pGod;				//指向神仙或道具
	CEntityNode * m_pENPrevious;	//指向前一个节点
	CEntityNode * m_pENNext;
};

#endif // !defined(AFX_ENTITYNODE_H__E04BBCE9_B606_4E93_AB00_2B7E1A65FDE3__INCLUDED_)
