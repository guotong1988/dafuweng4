//Download by http://www.NewXing.com
// Property.cpp: implementation of the CProperty class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Property.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
/*
	Torpedo = 1,      //地雷
	RoadBlock,    //路障       
	TimeBomb,	  //定时炸弹
    Missile,      //飞弹
	Nucleon,      //核子飞弹
    Car,          //汽车  
	Engine,       //机车  
	RemoteDice,  //遥控色子
	Mobile,       //工程车  
	Robot,        //机器工人
	TimeMachine,  //时光机
    TransMachine, //传送机
	RobotBaby     //机器娃娃
*/
CProperty::CProperty( CDC * pDC, int nID , CPoint point)
{
	//初始化工具蓝道具坐标
	m_MyRect.top = point.y;
	m_MyRect.left = point.x;
	m_MyRect.right = point.x + 60;
	m_MyRect.bottom = point.y + 60;
	m_nDays = 0;
	Init_DC_BM( pDC );

	if( nID < 1 )
	{
		m_ID = rand()%3 + 1; 
	}
	else
	{
		m_ID = nID;
	}

	switch(m_ID)
	{
	case 1:
		m_BmpCount = "\\3";
	break;
	case 2:
		m_BmpCount = "\\5";
	break;	
	case 3:
		m_BmpCount = "\\2";
	break;	
	case 4:
		m_BmpCount = "\\3";
	break;	
	case 5:
		m_BmpCount = "\\4";
	break;	
	case 6:
		m_BmpCount = "\\5";
	break;	
	case 7:
		m_BmpCount = "\\6";
	break;	
	case 8:
		m_BmpCount = "\\7";
	break;	
	case 9:
		m_BmpCount = "\\8";
	break;	
	case 10:
		m_BmpCount = "\\9";
	break;	
	case 11:
		m_BmpCount = "\\10";
	break;	
	case 12:
		m_BmpCount = "\\11";
	break;	
	case 13:
		m_BmpCount = "\\13";
	break;	
	default:
		return;
	}
	
	CString head = "img\\";
	CString root = "pro.bmp";  
	m_Bmp = head + m_BmpCount + root;

	root = "proshd.bmp";
	m_BmpShadow = head + m_BmpCount + root;

	m_MyBitmap.DeleteObject();
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,  m_Bmp, IMAGE_BITMAP, 60,60, LR_LOADFROMFILE );
	m_MyDC.SelectObject(m_MyBitmap);

	m_MyShadowBitmap.DeleteObject();
	m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_BmpShadow, IMAGE_BITMAP, 60,60, LR_LOADFROMFILE );
	m_MyShadowDC.SelectObject(m_MyShadowBitmap);
}

CProperty::~CProperty()
{
	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
	m_MyShadowBitmap.DeleteObject();
	m_MyBitmap.DeleteObject();
}

//炸人住院函数。参数1 玩家对象（指针）  2住院天数
//地雷  定时炸弹   飞弹   核子飞弹使用
void CProperty::MakePeopleInHispital(CPer *, int)
{
}

//改变色子函数。参数1 色子个数  2色子点数
//汽车  机车  遥控色子使用
void CProperty::ChangeNumberOrCountOfDice()
{
}

//改变房子等级或拆房。参数 房子对象（指针）
//工程车  机器工人使用
void CProperty::ChangeOrDestoryHouse()
{
}

//Load上一回合方法  时光机使用
void  CProperty::ReturnLast()
{
	//CSystem::系统类的某一静态方法
}
		

//移动对象到指定地点  传送机使用
void  CProperty::MoveObject( )
{
}

//阻止玩家移动  路障使用
void  CProperty::StopPeople()
{
}

//清除所有道具 机器娃娃使用
void CProperty::ClearRoad()
{
}

void CProperty::Draw( CDC * pDC )
{
	//画影子
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x, 
		                         m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
								 m_MyRect.right - m_MyRect.left,
								 m_MyRect.bottom - m_MyRect.top,
								 & m_MyShadowDC,
								 0,
								 0,
								 SRCAND );
	//画颜色
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
		                         m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
								 m_MyRect.right - m_MyRect.left,
								 m_MyRect.bottom - m_MyRect.top,
								 & m_MyDC,
								 0,
								 0,
								 SRCPAINT );
}

void CProperty::Draw( bool isBig, CPoint point ) 
{


	m_MyBitmap.DeleteObject();
	m_MyShadowBitmap.DeleteObject();
	
	if(isBig)
	{		
		m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_BmpShadow, IMAGE_BITMAP, 45,45, LR_LOADFROMFILE );
		m_MyShadowDC.SelectObject(m_MyShadowBitmap);
		m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_Bmp, IMAGE_BITMAP, 45,45, LR_LOADFROMFILE );
		m_MyDC.SelectObject(m_MyBitmap);
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 45, 45, &m_MyShadowDC, 0, 0, SRCAND );
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 45, 45, &m_MyDC, 0, 0, SRCPAINT );
	}
	else
	{
		m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_BmpShadow, IMAGE_BITMAP, 30,30, LR_LOADFROMFILE );
		m_MyShadowDC.SelectObject(m_MyShadowBitmap);
		m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_Bmp, IMAGE_BITMAP, 30,30, LR_LOADFROMFILE );
		m_MyDC.SelectObject(m_MyBitmap);
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 30, 30, &m_MyShadowDC, 0, 0, SRCAND );
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 30, 30, &m_MyDC, 0, 0, SRCPAINT );
	}	
}

int CProperty::GetID()
{
	return m_ID;
}

void CProperty::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyShadowDC.CreateCompatibleDC( pDC);

}

bool CProperty::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

int CProperty::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return 0;
}


void CProperty::ChangeMyRect(CPoint point)
{
	m_MyRect.top = point.y +  theApp.m_BigMap.m_ptBigMapCoordinate.y - 30;
	m_MyRect.left = point.x +  theApp.m_BigMap.m_ptBigMapCoordinate.x - 30;
	m_MyRect.right = m_MyRect.left + 60;
	m_MyRect.bottom = m_MyRect.top + 60;
}

int CProperty::IsCard()
{
	//返回道具标志
	return 2;
}

void CProperty::WriteToStream( CArchive & ar )
{
	ar << m_ID; 
	ar << m_Money;
}

void CProperty::ReadFromStream( CDC * pDC, CArchive & ar)
{
	ar >> m_Money;
}

void CProperty::PropertyIsBeUsed( int nName )
{
	int nI(0);
	switch(m_ID)
	{
	case 1://地雷
		m_nDays = 3;
		for( nI = 0 ; nI < 2 ; nI++ )
		{
			if( theApp.m_pAllPer[nI]->GetName() == nName )
			{
				theApp.m_pAllPer[nI]->ChangeDays( ( m_ID+ 3),m_nDays );
			}
		}
		break;
	case 2://路障
		for( nI = 0 ; nI < 2 ; nI++ )
		{
			if( theApp.m_pAllPer[nI]->GetName() == nName )
			{
				theApp.m_pAllPer[nI]->ChangeDays( (m_ID + 3),m_nDays );
			}
		}
		break;
	case 3://定时炸弹
		m_nDays = 5;
		for( nI = 0 ; nI < 2 ; nI++ )
		{
			if( theApp.m_pAllPer[nI]->GetName() == nName )
			{
				theApp.m_pAllPer[nI]->ChangeDays( (m_ID + 1),m_nDays );
				theApp.m_pAllPer[nI]->m_ptCoordinate.x = 200;
				theApp.m_pAllPer[nI]->m_ptCoordinate.y = 1200;
			}
		}
		break;
	}
}