//Download by http://www.NewXing.com
// ToolShowSmallMap.cpp: implementation of the CToolShowSmallMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolShowSmallMap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolShowSmallMap::CToolShowSmallMap( CDC * pDC )
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;

	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\SmallMap.bmp", IMAGE_BITMAP,
							400, 400, LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );
}

CToolShowSmallMap::~CToolShowSmallMap()
{
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
}

void CToolShowSmallMap::Draw( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt( 20, 60, 400, 400,
									& m_MyDC, 0, 0, SRCCOPY );
	theApp.m_EntityRoadList.DrawOnSmallMapView( pDC );
}

bool CToolShowSmallMap::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

int CToolShowSmallMap::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}
