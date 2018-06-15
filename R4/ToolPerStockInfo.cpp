//Download by http://www.NewXing.com
// ToolPerStockInfo.cpp: implementation of the CToolPerStockInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolPerStockInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolPerStockInfo::CToolPerStockInfo( CDC *pDC)
{
	m_MyDC.CreateCompatibleDC(pDC);

	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, "img\\PerStock.bmp", IMAGE_BITMAP, 640,480, LR_LOADFROMFILE );

	m_MyDC.SelectObject( m_MyBitmap );

	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;
}

CToolPerStockInfo::~CToolPerStockInfo()
{
	m_MyDC.DeleteDC();

	m_MyBitmap.DeleteObject();
}

void CToolPerStockInfo::Draw( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt(m_MyRect.left,m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCCOPY);
	
	//调用人物输出字体信息方法
	theApp.m_pPer->PerStockInfo(m_MyRect);
}

bool CToolPerStockInfo::IsOnMe( CPoint point )
{
	if( CTool::PointInRect( point,m_MyRect ) )
	{
		return true;
	}
	return false;
}

void CToolPerStockInfo::OnLButtonDown( CDC * pDC, CPoint ptPos )
{

}

int CToolPerStockInfo::ToolName( CPoint point )
{
	if( IsOnMe( point ) )
	{
		if( point.x >= 15 && point.x <= 105 && point.y >= 290 && point.y <= 320 )
		{
			return CTool::PerInfo;
		}
		else if( point.x >= 15 && point.x <= 105 && point.y >= 350 && point.y <= 380 )
		{
			return CTool::PerGlebeInfo;
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