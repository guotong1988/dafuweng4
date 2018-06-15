//Download by http://www.NewXing.com
// ToolPerGlebeInfo.cpp: implementation of the CToolPerGlebeInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolPerGlebeInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolPerGlebeInfo::CToolPerGlebeInfo( CDC *pDC)
{
	m_MyDC.CreateCompatibleDC(pDC);

	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, "img\\PerGelabe.bmp", IMAGE_BITMAP, 640,480, LR_LOADFROMFILE );

	m_MyDC.SelectObject( m_MyBitmap );

	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;
}

CToolPerGlebeInfo::~CToolPerGlebeInfo()
{
	m_MyDC.DeleteDC();

	m_MyBitmap.DeleteObject();
}

void CToolPerGlebeInfo::Draw( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt(m_MyRect.left,m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCCOPY);
	
	//调用人物输出字体信息方法
	theApp.m_pPer->PerGlebeInfo(m_MyRect);
}

bool CToolPerGlebeInfo::IsOnMe( CPoint point )
{
	if( CTool::PointInRect( point,m_MyRect ) )
	{
		return true;
	}
	return false;
}

void CToolPerGlebeInfo::OnLButtonDown( CDC * pDC, CPoint point )
{
	if( point.x >= 600 && point.x <= 640 && point.y >= 360 && point.y <= 400 )
	{
		theApp.m_pPer->PageUp();
		theApp.Draw(pDC);
	}
	else if( point.x >= 600 && point.x <= 640 && point.y >= 420 && point.y <= 460 )
	{
		theApp.m_pPer->PageDown();
		theApp.Draw(pDC);
	}
}

int CToolPerGlebeInfo::ToolName( CPoint point )
{
	if( IsOnMe( point ) )
	{
		if( point.x >= 15 && point.x <= 105 && point.y >= 290 && point.y <= 320 )
		{
			return CTool::PerInfo;
		}
		else if( point.x >= 15 && point.x <= 105 && point.y >= 410 && point.y <= 440 )
		{
			return CTool::PerStockInfo;
		}
		else if( point.x >= 495 && point.x <= 600 && point.y >= 10 && point.y <= 45 )
		{
			return CTool::NoTool;
		}
		else
		{
			return CTool::NoChange;
		}
	}
	return CTool::NoTool;	
}
