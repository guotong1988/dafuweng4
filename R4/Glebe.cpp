// Glebe.cpp: implementation of the CGlebe class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Glebe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGlebe::CGlebe( CDC * pDC, int nLeft, int nTop, int nRight, int nBottom )
{
	//给我的作用区赋值
	m_MyRect.top = nTop;//上边界
	m_MyRect.bottom =nBottom;//下边界
	m_MyRect.left = nLeft;//左边界
	m_MyRect.right = nRight;//右边界

	//创建设备上下文
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_SmallDC.CreateCompatibleDC( pDC );

	m_nGrade = 0;//土地等级初始化为0
	m_nMaxGrade = 5;//房子最大等级为5
	m_nOwner = CPer::NoOne;//房子的所有者为没有人
	m_nValue = 100;//土地的价值初始化为100
}

CGlebe::~CGlebe()
{
	//释放位图和设备上下文
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
	m_MyShadowDC.DeleteDC();
	m_MyShadowBitmap.DeleteObject();
	m_SmallDC.DeleteDC();
	m_SmallBitmap.DeleteObject();
}

void CGlebe::Buy( int nName )//购买土地的方法
{
	m_nOwner = nName;//设置所有者

	//根据所有者装载图片 
	switch( m_nOwner )
	{
	case CPer::NoOne:
		//装载无颜色的图片
		break;
	case CPer::KongFanYin:

		//装载显示在小地图上的图片
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowKongSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		//根据房子等级装载图
		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		}
		break;
	case CPer::ZhangJun:
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowZhangSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		default:
			AfxMessageBox( "CGlebe::Draw消息错误！" );
		}
		break;
	}
}

void CGlebe::Degrade()//房子降级的方法
{
	if( m_nGrade> 0)
	{
		m_nGrade--;

		switch( m_nOwner )
		{
		case CPer::NoOne:
			//装载无颜色的图片*
			break;
		case CPer::KongFanYin:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			}
			break;
		case CPer::ZhangJun:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			default:
				AfxMessageBox( "CGlebe::Draw消息错误！" );
			}
			break;
		}
	}
}

void CGlebe::Draw( CDC * pDC )//显示房子的方法
{
	//向临时内存绘图
	theApp.m_TmpScreenDC.BitBlt(
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
		m_MyRect.right - m_MyRect.left,
		m_MyRect.bottom - m_MyRect.top,
		& m_MyShadowDC, 0, 0, SRCAND);

	theApp.m_TmpScreenDC.BitBlt(
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
		m_MyRect.right - m_MyRect.left,
		m_MyRect.bottom - m_MyRect.top,
		& m_MyDC, 0, 0, SRCPAINT);
}

void CGlebe::DrawOnSmallMap( CDC * pDC )//在小地图上显示房子
{
	theApp.m_TmpScreenDC.BitBlt( 
				(int)(m_MyRect.left * 5.0 / 66.0 + 440),
				(int)(m_MyRect.top / 11.0 + 280),
				5, 5, & m_SmallDC, 0, 0, SRCCOPY );
}

void CGlebe::DrawOnSmallMapView( CDC * pDC )//查看小地图时显示房子
{
	theApp.m_TmpScreenDC.BitBlt( 
				(int)(m_MyRect.left * 5.0 / 33.0 + 20),
				(int)(m_MyRect.top * 2.0 / 11.0 + 60),
				10, 10, & m_SmallDC, 0, 0, SRCCOPY );
}

int CGlebe::GetUpGradeValue()//升级房子所需的费用
{
	if(  m_nGrade< m_nMaxGrade )
	{
		return (int)(m_nValue * 2.0);
	}
	return 0;
}

int CGlebe::GetValue()//房子的价值
{
	return m_nValue;
}

bool CGlebe::IsOnMe( CPoint point )//点是否在我的作用区上
{
	CRect rect;
	rect.left =
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.right =
		m_MyRect.right - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.top =
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y;
	rect.bottom =
		m_MyRect.bottom - theApp.m_BigMap.m_ptBigMapCoordinate.y;

	if( CTool::PointInRect(point, rect) )//调用工具类的一个静态方法
	{
		return true;
	}
	return false;
}

int CGlebe::Owner()//返回所有者
{
	return m_nOwner;
}

void CGlebe::ReadFromStream( CDC * pDC, CArchive & ar )//读取房子信息
{
	ar >> m_nOwner;			//所有者
	ar >> m_nGrade;			//房子等级
	ar >> m_nMaxGrade;		//房子最高等级
	ar >> m_nValue;			//地价

	//还原设备上下文
	m_SmallDC.DeleteDC();
	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_SmallDC.CreateCompatibleDC( pDC );

	switch( m_nOwner )
	{
	case CPer::NoOne:
		//装载无颜色的图片*
		break;
	case CPer::KongFanYin:
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowKongSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		}
		break;
	case CPer::ZhangJun:
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowZhangSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		default:
			AfxMessageBox( "CGlebe::Draw消息错误！" );
		}
		break;
	}
}

int CGlebe::ToolName( CPoint point )//点击在土地上需要的工具
{
	if( IsOnMe(point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}

void CGlebe::WriteToStream( CArchive & ar )//保存房子信息
{
	ar << m_nOwner;			//所有者
	ar << m_nGrade;			//房子等级
	ar << m_nMaxGrade;		//房子最高等级
	ar << m_nValue;			//地价
}

void CGlebe::UpGrade()//升级房子
{
	if( m_nGrade< m_nMaxGrade)
	{
		m_nGrade++;
		m_nValue = (int)(m_nValue * 2.0);

		switch( m_nOwner )
		{
		case CPer::NoOne:
			//装载无颜色的图片*
			break;
		case CPer::KongFanYin:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			}
			break;
		case CPer::ZhangJun:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			default:
				AfxMessageBox( "CGlebe::Draw消息错误！" );
			}
			break;
		}
	}
	else
	{
		AfxMessageBox( "房子升级已满！" );
	}
}

int CGlebe::GetLevel()//返回房子等级
{
	return m_nGrade;
}
