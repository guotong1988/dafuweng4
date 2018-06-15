//Download by http://www.NewXing.com
// ToolDice.cpp: implementation of the CToolDice class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolDice.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRect CToolDice::m_MoveRect(300,300,373,367);


CToolDice::CToolDice( CDC * pDC )
{
	//给影子分派DC
	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Go1.bmp", IMAGE_BITMAP, 73,67, LR_LOADFROMFILE );
	m_MyShadowDC.SelectObject(m_MyShadowBitmap);

	//给白色工具分派DC
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Go2.bmp", IMAGE_BITMAP, 73,67, LR_LOADFROMFILE );
	m_MyDC.SelectObject(m_MyBitmap);

	//给发亮工具分派DC
	m_LightDC.CreateCompatibleDC( pDC );
	m_LightBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Go3.bmp", IMAGE_BITMAP, 73,67, LR_LOADFROMFILE );
	m_LightDC.SelectObject(m_LightBitmap);

	//给色子影子分派DC
	m_DiceShadowDC.CreateCompatibleDC( pDC );
	m_DiceShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\DiceShadow.bmp", IMAGE_BITMAP, 240, 40,
		LR_LOADFROMFILE );
	m_DiceShadowDC.SelectObject(m_DiceShadowBitmap);

	//给色子分派DC
	m_DiceDC.CreateCompatibleDC( pDC );
	m_DiceBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Dice.bmp", IMAGE_BITMAP, 240, 40, LR_LOADFROMFILE );
	m_DiceDC.SelectObject(m_DiceBitmap);

	//给定点击GO的区域
	m_MyRect.top = m_MoveRect.top + 20;
	m_MyRect.bottom = m_MoveRect.bottom - 20;
	m_MyRect.left = m_MoveRect.left + 30;
	m_MyRect.right = m_MoveRect.right - 10;

	m_DiceRect.left = 200;
	m_DiceRect.right = 240;
	m_DiceRect.top = 240;
	m_DiceRect.bottom = 280;
	//设置初始图片状态
	m_bBitmapType = false;
	m_nCount = 0;
	m_Type = None;		//判断鼠标左击触发事件
	m_DiceStep = 0;
	m_nDiceCount = 0;
}

CToolDice::~CToolDice()
{
	//清空DC
	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
	m_LightDC.DeleteDC();
	m_DiceShadowDC.DeleteDC();
	m_DiceDC.DeleteDC();

	//清空Bitmap
	m_MyShadowBitmap.DeleteObject();
	m_MyBitmap.DeleteObject();
	m_LightBitmap.DeleteObject();
	m_DiceShadowBitmap.DeleteObject();
	m_DiceBitmap.DeleteObject();
}

void CToolDice::Draw( CDC * pDC )
{
	if( Go == m_Type )
	{
		if( m_DiceStep < 15 )
		{
			//画影子
			theApp.m_TmpScreenDC.BitBlt(m_DiceRect.left,m_DiceRect.top,
				m_DiceRect.right - m_DiceRect.left,
				m_DiceRect.bottom - m_DiceRect.top,
				& m_DiceShadowDC, 
				(int)((m_DiceStep % 6) * 40.0), 0, SRCAND);
			//图颜色
			theApp.m_TmpScreenDC.BitBlt(m_DiceRect.left,m_DiceRect.top,
				m_DiceRect.right - m_DiceRect.left,
				m_DiceRect.bottom - m_DiceRect.top,
				& m_DiceDC, 
				(int)((m_DiceStep % 6) * 40.0), 0, SRCPAINT);
		}
		else
		{
			//画影子
			theApp.m_TmpScreenDC.BitBlt(m_DiceRect.left,m_DiceRect.top,
				m_DiceRect.right - m_DiceRect.left,
				m_DiceRect.bottom - m_DiceRect.top,
				& m_DiceShadowDC, 
				(int)((m_DiceNum - 1) * 40.0), 0, SRCAND);
			//图颜色
			theApp.m_TmpScreenDC.BitBlt(m_DiceRect.left,m_DiceRect.top,
				m_DiceRect.right - m_DiceRect.left,
				m_DiceRect.bottom - m_DiceRect.top,
				& m_DiceDC, 
				(int)((m_DiceNum - 1) * 40.0), 0, SRCPAINT);
		}
	}
	else
	{
		//画影子
		theApp.m_TmpScreenDC.BitBlt(m_MoveRect.left,m_MoveRect.top,
			m_MoveRect.right - m_MoveRect.left,
			m_MoveRect.bottom - m_MoveRect.top,
			& m_MyShadowDC, 0, 0, SRCAND);
		if(m_bBitmapType == false)
		{
			//图颜色
			theApp.m_TmpScreenDC.BitBlt(m_MoveRect.left,m_MoveRect.top,
				m_MoveRect.right - m_MoveRect.left,
				m_MoveRect.bottom - m_MoveRect.top,
				& m_MyDC, 0, 0, SRCPAINT);
		}
		else
		{
			//图颜色
			theApp.m_TmpScreenDC.BitBlt(m_MoveRect.left,m_MoveRect.top,
				m_MoveRect.right - m_MoveRect.left,
				m_MoveRect.bottom - m_MoveRect.top,
				& m_LightDC, 0, 0, SRCPAINT);
		}
	}
}

void CToolDice::OnLButtonDown( CDC * pDC, CPoint ptPos )
{
//	IsOnMe( ptPos );
	if( Go == m_Type )
	{
		switch (1)
		{
		case 1:
			m_DiceNum = rand()%6 + 1;
//			theApp.m_pPer->SplashDice( pDC,  );
//			m_ToolState = stFirst;
			break;
		case 2:
	//		theApp.m_pPer->SplashDice( rand()%6 + 1 + rand()%6 + 1 );
			break;
		case 3:
	//		theApp.m_pPer->SplashDice( rand()%6 + 1 + rand()%6 + 1 + rand()%6 + 1 );
			break;
		}
	}
}

bool CToolDice::IsOnMe( CPoint point )
{
	if( (point .x >= m_MyRect.left && point.x <= m_MyRect.right)
		&& (point.y >= m_MyRect.top && point.y <= m_MyRect.bottom) )
	{
		m_Type = Go;
		return true;
	}
	else if( (point.x >= m_MoveRect.left && point.x <= m_MoveRect.right)
			&& (point.y >= m_MoveRect.top && point.y <= m_MoveRect.bottom) )
	{
		m_Type = Move;
		m_pt.x = point.x;
		m_pt.y = point.y;
		return true;
	}
	else
	{
		m_Type =None;
		return false;
	}
}

void CToolDice::OnLButtonUp( CDC * pDC, CPoint ptPos )
{
	if( Move == m_Type )
	{
		m_Type = None;
	}
}

void CToolDice::OnMouseMove( CDC * pDC, CPoint ptPos )
{
	if( Move == m_Type )
	{
		m_MoveRect.top += ptPos.y - m_pt.y;
		m_MoveRect.left += ptPos.x - m_pt.x;
		m_MoveRect.bottom = m_MoveRect.top + 67;
		m_MoveRect.right = m_MoveRect.left + 73; 

		m_pt.x = ptPos.x;
		m_pt.y = ptPos.y;

		m_MyRect.top = m_MoveRect.top + 20;
		m_MyRect.bottom = m_MoveRect.bottom - 20;
		m_MyRect.left = m_MoveRect.left + 30;
		m_MyRect.right = m_MoveRect.right - 10;

		theApp.Draw( pDC );
	}
}

int CToolDice::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}

void CToolDice::OnTimer( CDC * pDC )
{
	//闪烁*
	if( true == m_bBitmapType )
	{
		if( 10 == m_nCount )
		{
			m_bBitmapType = false;
			m_nCount = 0;
		}
		else
		{
			m_nCount++;
		}
	}
	else
	{
		if( 10 == m_nCount )
		{
			m_bBitmapType = true;
			m_nCount = 0;
		}
		else
		{
			m_nCount++;
		}
	}

	//色子动画*
	
	if( Go == m_Type )
	{
		if( 25 == m_DiceStep )
		{
			theApp.m_pPer->SplashDice( pDC, m_DiceNum );
		}
		else
		{
			m_DiceStep++;
			if( m_DiceStep < 16 )
			{
				m_DiceRect.left -= 8;
				m_DiceRect.right -= 8;
				m_DiceRect.top += (int)((m_DiceStep - 8) * 5.0);
				m_DiceRect.bottom += (int)((m_DiceStep - 8) * 5.0);
			}
		}
	}

	theApp.Draw( pDC );
}
