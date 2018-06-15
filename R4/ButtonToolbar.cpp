//Download by http://www.NewXing.com
// ButtonToolbar.cpp: implementation of the CButtonToolbar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ButtonToolbar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CButtonToolbar::CButtonToolbar()
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 40;
	m_MyRect.left = 0;
	m_MyRect.right = 440;
}

CButtonToolbar::~CButtonToolbar()
{
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
}

void CButtonToolbar::Draw( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCCOPY );
}

void CButtonToolbar::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\ButtonToolbar.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );
}

bool CButtonToolbar::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

int CButtonToolbar::ToolName( CPoint point )
{
	CRect rect;

	if( IsOnMe(point) )
	{
		rect.left = 120;
		rect.right = 160;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::Load;
		}

		rect.left = 160;
		rect.right = 200;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::Save;
		}

		rect.left = 200;
		rect.right = 240;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::ShowSmallMap;
		}

		rect.left = 240;
		rect.right = 280;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::PerInfo;
		}

		rect.left = 280;
		rect.right = 320;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::Property;
		}

		rect.left = 320;
		rect.right = 360;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::Card;
		}

		rect.left = 360;
		rect.right = 400;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::PerSell;
		}

		rect.left = 400;
		rect.right = 440;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::Stock;
		}
		rect.left = 80;
		rect.right = 120;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::Bank;
		}
		rect.left = 40;
		rect.right = 80;
		rect.top = 0;
		rect.bottom = 40;
		if( CTool::PointInRect(point, rect) )
		{
			return CTool::BankLend;
		}
	return CTool::NoChange;
	}

	return CTool::NoTool;
}
