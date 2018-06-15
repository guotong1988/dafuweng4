// Bankroll.cpp: implementation of the CBankroll class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Bankroll.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBankroll::CBankroll()
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 280;
	m_MyRect.left = 440;
	m_MyRect.right = 640;

	m_ShowType= My;
}

CBankroll::~CBankroll()
{
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();

	m_LandDC.DeleteDC();
	m_LandBitmap.DeleteObject();

	m_StockDC.DeleteDC();
	m_StockBitmap.DeleteObject();

	m_RestDC.DeleteDC();
	m_RestBitmap.DeleteObject();
}

void CBankroll::Draw( CDC * pDC )
{
	switch( m_ShowType )
	{
	case My:
		theApp.m_TmpScreenDC.BitBlt( 440, 0, 200, 280, & m_MyDC,
													0, 0, SRCCOPY);
		theApp.m_pPer->ShowFundInfo();
		break;
	case Land:
		theApp.m_TmpScreenDC.BitBlt( 440, 0, 200, 280, & m_LandDC,
													0, 0, SRCCOPY);
		theApp.m_pPer->ShowGelebInfo();
		break;
	case Stock:
		theApp.m_TmpScreenDC.BitBlt( 440, 0, 200, 280, & m_StockDC,
													0, 0, SRCCOPY);
		theApp.m_pPer->ShowStockInfo();
		break;
	case Rest:
		theApp.m_TmpScreenDC.BitBlt( 440, 0, 200, 280, & m_RestDC,
													0, 0, SRCCOPY);
		theApp.m_pPer->ShowOtherInfo();
		break;
	default:
		AfxMessageBox( "CBankroll::DrawÏûÏ¢´íÎó£¡" );
	}
}

void CBankroll::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Bankroll.bmp",IMAGE_BITMAP,200,280,LR_LOADFROMFILE);
	m_MyDC.SelectObject( m_MyBitmap );

	m_LandDC.CreateCompatibleDC( pDC );
	m_LandBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Land.bmp",IMAGE_BITMAP,200,280,LR_LOADFROMFILE);
	m_LandDC.SelectObject( m_LandBitmap );

	m_StockDC.CreateCompatibleDC( pDC );
	m_StockBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Stock.bmp",IMAGE_BITMAP,200,280,LR_LOADFROMFILE);
	m_StockDC.SelectObject( m_StockBitmap );

	m_RestDC.CreateCompatibleDC( pDC );
	m_RestBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Rest.bmp",IMAGE_BITMAP,200,280,LR_LOADFROMFILE);
	m_RestDC.SelectObject( m_RestBitmap );
}

bool CBankroll::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CBankroll::ReadFromStream( CDC * pDC, CArchive & ar )
{
	ar >> m_ShowType;
}

int CBankroll::ToolName( CPoint point )
{
	CRect rect;

	if( IsOnMe( point) )
	{
		rect.left = 620;
		rect.right = 640;
		rect.top = 10;
		rect.bottom = 70;
		if( CTool::PointInRect(point, rect) )
		{
			m_ShowType = My;
		}

		rect.top = 80;
		rect.bottom = 140;
		if( CTool::PointInRect(point, rect) )
		{
			m_ShowType = Land;
		}

		rect.top = 150;
		rect.bottom = 210;
		if( CTool::PointInRect(point, rect) )
		{
			m_ShowType = Stock;
		}

		rect.top = 220;
		rect.bottom = 280;
		if( CTool::PointInRect(point, rect) )
		{
			m_ShowType = Rest;
		}
	}
	return CTool::NoTool;
}

void CBankroll::WriteToStream( CArchive & ar )
{
	ar << m_ShowType;
}
