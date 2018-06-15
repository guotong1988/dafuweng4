//Download by http://www.NewXing.com
// BigMap.cpp: implementation of the CBigMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "BigMap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBigMap::CBigMap()
{
	m_MyRect.top = 40;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 440;

	m_ptBigMapSize.x = 2640;
	m_ptBigMapSize.y = 2200;
}

CBigMap::~CBigMap()
{
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
}

void CBigMap::Draw( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC,
								m_ptBigMapCoordinate.x,
								m_ptBigMapCoordinate.y,
								SRCCOPY );
}

void CBigMap::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\BigMap.bmp", IMAGE_BITMAP,
								m_ptBigMapSize.x,
								m_ptBigMapSize.y, LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );

	m_ptBigMapCoordinate.x = theApp.m_pPer->m_ptCoordinate.x - 220 + 30;
	m_ptBigMapCoordinate.y = theApp.m_pPer->m_ptCoordinate.y - 220 - 10;
}

bool CBigMap::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CBigMap::MoveBigMap( CDC * pDC, CPoint ptPos )
{
	m_ptBigMapCoordinate.x = ptPos.x;
	m_ptBigMapCoordinate.y = ptPos.y;

	if( m_ptBigMapCoordinate.x < 0 )m_ptBigMapCoordinate.x = 0;
	if( m_ptBigMapCoordinate.y < 0 )m_ptBigMapCoordinate.y = 0;
	if( m_ptBigMapCoordinate.x >
		m_ptBigMapSize.x - m_MyRect.right + m_MyRect.left )
		m_ptBigMapCoordinate.x =
		m_ptBigMapSize.x - m_MyRect.right + m_MyRect.left;
	if( m_ptBigMapCoordinate.y >
		m_ptBigMapSize.y - m_MyRect.bottom + m_MyRect.top )
		m_ptBigMapCoordinate.y =
		m_ptBigMapSize.y - m_MyRect.bottom + m_MyRect.top;
}

CPoint CBigMap::Point_SmallMapToBigMap( CPoint ptPos )
{
	CPoint pt;
	pt.x = (int)((ptPos.x - 440) * m_ptBigMapSize.x / 200.0 -
			m_MyRect.right / 2.0 + m_MyRect.left / 2.0);
	pt.y = (int)((ptPos.y - 280) * m_ptBigMapSize.y / 200.0 -
			m_MyRect.bottom / 2.0 + m_MyRect.top / 2.0);
	return pt;
}

void CBigMap::ReadFromStream( CDC * pDC, CArchive & ar )
{
	ar >> m_ptBigMapCoordinate.x;
	ar >> m_ptBigMapCoordinate.y;
}

int CBigMap::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}

void CBigMap::WriteToStream( CArchive & ar )
{
	ar << m_ptBigMapCoordinate.x;
	ar << m_ptBigMapCoordinate.y;
}
