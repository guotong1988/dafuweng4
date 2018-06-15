//Download by http://www.NewXing.com
// EntityList.h: interface for the CEntityList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENTITYLIST_H__FED8B631_4B28_42C7_B7AD_DCE3A2DF899C__INCLUDED_)
#define AFX_ENTITYLIST_H__FED8B631_4B28_42C7_B7AD_DCE3A2DF899C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EntityNode.h"

//路链表*
class CEntityList  
{
public:
	CEntityList();
	virtual ~CEntityList();

	void AddEntityNode( CPoint ptCoordinate,
						int nWayName = 0, CGod * pGod = NULL,
						CGlebe * pGlebe = NULL,
						CPer * pPer = NULL );	//添加节点*
	void AddGodOrProperty( CEntity * pEntity , CPoint point );	//添加神仙或道具
	void Draw( CDC * pDC );
	void DrawOnSmallMap( CDC * pDC );
	void DrawOnSmallMapView( CDC * pDC );
	void FreeAll();
	int GetCount();
	bool IsOnGlebe( CPoint point );
	bool IsOnNode( CPoint point );
	bool IsOnPer( CPoint point );
	void ReadFromFile( CDC * pDC, CArchive & ar );
	void SaveToFile( CArchive & ar );
	void SetPerGlebe( CPer::Gelbe * m_Gelbe , int nName );
	int ToolName( CPoint point ){return 0;}

private:
	CEntityNode * m_pENHead;
};

#endif // !defined(AFX_ENTITYLIST_H__FED8B631_4B28_42C7_B7AD_DCE3A2DF899C__INCLUDED_)
