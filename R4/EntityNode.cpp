// EntityNode.cpp: implementation of the CEntityNode class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "EntityNode.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEntityNode::CEntityNode( CPoint ptCoordinate, int nWayName,
				CGod * pGod, CGlebe * pGlebe, CPer * pPer)
{
	m_ptCoordinate = ptCoordinate;
	m_WayName = nWayName;
	m_pGod = pGod;
	m_pGlebe = pGlebe;
	m_pPer = pPer;
	m_pSecondPer = NULL;
	if( NULL != pPer )pPer->GetEntityNode( * this );
	m_pENPrevious = NULL;
	m_pENNext = NULL;
}

CEntityNode::~CEntityNode()
{
	delete m_pGod;
	delete m_pGlebe;
	delete m_pPer;
}

bool CEntityNode::AddGodOrProperty( CEntity * pEntity , CPoint point )
{
	if( NULL == m_pGod && IsOnMe(point) && NULL == m_pPer )
	{
		pEntity->ChangeMyRect(CPoint(m_ptCoordinate.x + 10, m_ptCoordinate.y + 10));
		m_pGod = pEntity;
		return true;
	}
	return false;
}

void CEntityNode::Draw( CDC * pDC )
{
	if( m_ptCoordinate.x - theApp.m_BigMap.m_ptBigMapCoordinate.x
		> -100 &&
		m_ptCoordinate.x - theApp.m_BigMap.m_ptBigMapCoordinate.x
		< 540 &&
		m_ptCoordinate.y - theApp.m_BigMap.m_ptBigMapCoordinate.y
		> -60 &&
		m_ptCoordinate.y - theApp.m_BigMap.m_ptBigMapCoordinate.y
		< 580 )
	{
		if( NULL != m_pGlebe )
		{
			m_pGlebe->Draw( pDC );
		}
		if( NULL != m_pSecondPer )
		{
			m_pSecondPer->Draw( pDC );
		}
		if( NULL != m_pPer )
		{
			m_pPer->Draw( pDC );
		}
		if( NULL != m_pGod )
		{
			m_pGod->Draw( pDC );
		}
	}
}

void CEntityNode::DrawOnSmallMap( CDC * pDC )
{
	if( NULL != m_pGlebe )
	{
		m_pGlebe->DrawOnSmallMap( pDC );
	}
	if( NULL != m_pPer )
	{
		m_pPer->DrawOnSmallMap( pDC );
	}
}

void CEntityNode::DrawOnSmallMapView( CDC * pDC )
{
	if( NULL != m_pGlebe )
	{
		m_pGlebe->DrawOnSmallMapView( pDC );
	}
	if( NULL != m_pPer )
	{
		m_pPer->DrawOnSmallMapView( pDC );
	}
}

bool CEntityNode::IsOnGlebe( CPoint point )
{
	if( NULL != m_pGlebe )
	{
		if( m_pGlebe->IsOnMe( point ) )return true;
	}
	return false;
}

bool CEntityNode::IsOnMe( CPoint point )
{
	CRect rect;
	rect.left = m_ptCoordinate.x - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.right = rect.left + 60;
	rect.top = m_ptCoordinate.y - theApp.m_BigMap.m_ptBigMapCoordinate.y;
	rect.bottom = rect.top + 60;
	if( CTool::PointInRect(point, rect) && NULL == m_pGod  && NULL == m_pPer )
	{
		return true;
	}
	return false;
}

bool CEntityNode::IsOnPer( CPoint point )
{
	if( NULL != m_pPer )
	{
		if( m_pPer->IsOnMe( point ) )return true;
	}
	return false;
}

void CEntityNode::ReadFromStream( CDC * pDC, CArchive & ar )
{
	int iType, nName;

	if(NULL != m_pGod)
	{
		delete m_pGod;
		m_pGod = NULL;
	}

	m_pPer = NULL;

	ar >> iType;
	if( 1 == iType )
	{
		m_pGlebe->ReadFromStream( pDC, ar );
	}

	ar >> iType;
	if( 1 == iType )
	{
		ar >> nName;
		if( nName == theApp.m_pAllPer[0]->GetName() )
		{
			m_pPer = theApp.m_pAllPer[0];
			theApp.m_pAllPer[0]->GetEntityNode(*this);
		}
		else if( nName == theApp.m_pAllPer[1]->GetName() )
		{
			m_pPer = theApp.m_pAllPer[1];
			theApp.m_pAllPer[1]->GetEntityNode(*this);
		}
	}

	ar >> iType;
	if( 1 == iType )
	{
		ar >> nName;
		m_pGod = new CGod( pDC, CPoint(0,0) ,nName );
		m_pGod->ReadFromStream( pDC, ar );
	}
}

void CEntityNode::WriteToStream( CArchive & ar )
{
	if( NULL != m_pGlebe )
	{
		ar << 1;
		m_pGlebe->WriteToStream( ar );
	}
	else
	{
		ar << 0;
	}

	if( NULL != m_pPer )
	{
		ar << 1;
		ar << m_pPer->GetName();
	}
	else
	{
		ar << 0;
	}

	if( NULL != m_pGod )
	{
		ar << 1;
		m_pGod->WriteToStream( ar );
	}
	else
	{
		ar << 0;
	}
}
