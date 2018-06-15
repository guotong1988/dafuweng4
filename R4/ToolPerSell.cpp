//Download by http://www.NewXing.com
// ToolPerSell.cpp: implementation of the CToolPerSell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolPerSell.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolPerSell::CToolPerSell(CDC * pDC)
{
	m_MyDC.CreateCompatibleDC(pDC);

	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, "img\\PerSell.bmp", IMAGE_BITMAP, 593,346, LR_LOADFROMFILE );

	m_MyDC.SelectObject( m_MyBitmap );

	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;
}

CToolPerSell::~CToolPerSell()
{
	m_MyDC.DeleteDC();

	m_MyBitmap.DeleteObject();
}

void CToolPerSell::Draw( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt( 30 , 100 ,
								593,
								346,
								& m_MyDC, 0, 0, SRCCOPY);	
}
	
bool CToolPerSell::IsOnMe( CPoint point )
{
	if(CTool::PointInRect(point,m_MyRect))
	{
		return true;
	}
	return false;
}

void CToolPerSell::OnLButtonDown( CDC * pDC, CPoint ptPos )
{
	
}

int CToolPerSell::ToolName( CPoint point )
{
	if( IsOnMe( point ) )
	{
		if( point.x >= 538 && point.x <= 608 && point.y >= 105 && point.y <= 140 )
		{
			return CTool::NoTool;
		}
		return CTool::NoChange;
	}
	return CTool::NoTool;
}
