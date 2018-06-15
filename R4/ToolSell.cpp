//Download by http://www.NewXing.com
// ToolSell.cpp: implementation of the CToolSell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolSell.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolSell::CToolSell(CDC * pDC)
{
	m_MyDC.CreateCompatibleDC(pDC);

	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, "img\\SellObjiect.bmp", IMAGE_BITMAP, 144,96, LR_LOADFROMFILE );

	m_MyDC.SelectObject( m_MyBitmap );

	m_MyRect.top = 0;
	m_MyRect.bottom = 0;
	m_MyRect.left = 0;
	m_MyRect.right = 0;	
}

CToolSell::~CToolSell()
{
	m_MyDC.DeleteDC();

	m_MyBitmap.DeleteObject();
}

void CToolSell::Draw( CDC * pDC )
{}

bool CToolSell::IsOnMe( CPoint point )
{
	return false;
}

void CToolSell::OnLButtonDown( CDC * pDC, CPoint ptPos )
{}