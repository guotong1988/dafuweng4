//Download by http://www.NewXing.com
// SmallMap.cpp: implementation of the CSmallMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "SmallMap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSmallMap::CSmallMap()//构造
{
	//设置作用区
	m_MyRect.top = 280;
	m_MyRect.bottom = 480;
	m_MyRect.left = 440;
	m_MyRect.right = 640;
}

CSmallMap::~CSmallMap()//析构
{
	//释放设备上下文和位图
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
}

void CSmallMap::Draw( CDC * pDC )//显示小土地图的方法
{
	CBrush brush, * pOldBrush;//定义一个刷子
	CPen pen, * pOldPen;//定义一只画笔

	//画小土地图
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCCOPY );
	//画地图上的物体
	theApp.m_EntityRoadList.DrawOnSmallMap( pDC );

	//创建刷子和画笔
	brush.CreateStockObject( NULL_BRUSH );//创建一个空刷子
	pOldBrush = theApp.m_TmpScreenDC.SelectObject( & brush );
	pen.CreatePen( PS_SOLID,1,RGB( 255, 0, 0 ) );
	pOldPen = theApp.m_TmpScreenDC.SelectObject( & pen);

	//画矩形
	theApp.m_TmpScreenDC.Rectangle( m_ptCoordinate.x - 17,
									m_ptCoordinate.y - 20,
									m_ptCoordinate.x + 17,
									m_ptCoordinate.y + 20 );

	brush.DeleteObject();
	pen.DeleteObject();

	theApp.m_TmpScreenDC.SelectObject( pOldPen );
	theApp.m_TmpScreenDC.SelectObject( pOldBrush );
}

void CSmallMap::Init_DC_BM( CDC * pDC )//初始化
{
	//装载图片
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\SmallMap.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );

	//设置矩形的位置
	m_ptCoordinate.x = 
		(int)(theApp.m_pPer->m_ptCoordinate.x * 5.0 / 66.0) + 440;
	m_ptCoordinate.y = 
		(int)(theApp.m_pPer->m_ptCoordinate.y / 11.0) + 280;
}

bool CSmallMap::IsOnMe( CPoint point )//点是否在我的作用区上
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CSmallMap::MoveRectangle( CPoint ptPos )//移动矩形
{
	m_ptCoordinate.x = ptPos.x;
	m_ptCoordinate.y = ptPos.y;

	//判断边界
	if( m_ptCoordinate.x < 457 )m_ptCoordinate.x = 457;
	if( m_ptCoordinate.y < 300 )m_ptCoordinate.y = 300;
	if( m_ptCoordinate.x > 627 )m_ptCoordinate.x = 627;
	if( m_ptCoordinate.y > 460 )m_ptCoordinate.y = 460;
}

void CSmallMap::ReadFromStream( CDC * pDC, CArchive & ar )//读取小土地图的信息
{
	ar >> m_ptCoordinate.x;
	ar >> m_ptCoordinate.y;
}

int CSmallMap::ToolName( CPoint point )//小土地图所用的工具
{
	if( IsOnMe( point) )
	{
		return CTool::MoveBigMap;
	}
	return CTool::NoTool;
}

void CSmallMap::WriteToStream( CArchive & ar )//保存小地图的信息
{
	ar << m_ptCoordinate.x;
	ar << m_ptCoordinate.y;
}
