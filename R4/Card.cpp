// Card.cpp: implementation of the CCard class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Card.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCard::CCard(CDC * pDC , int nID)
{
	if(1 > nID)
	{
		m_ID = rand()%3 + 1;
	}
	else
	{
		m_ID = nID;
	}

	switch(m_ID)
	{ 
	case AngelCard:
		m_Point=160;
		break;
	case SleepCard:
		m_Point=30;
		break;
	case LeagueCard:
		m_Point=70;
		break;
	case FreeCard:
		m_Point=25;
		break;
	case RemissionCard:
		m_Point=25;
		break;
	case ChangeWayCard:
		m_Point=200;
		break;
	}

	Init_DC_BM( pDC );

	//CString root = "card.bmp";  
	//m_Bmp += root;
}

CCard::~CCard()
{

}


//增加房屋层数
void CCard::AddBiuldHouse()
{
	//theApp.m_EntityRoadList//一条街房屋增加一层
}

void CCard::Harden()
{
	//theApp.m_pPer->ChangeDays(m_nDays);
}

void CCard::Remission()
{	//if(/*状态为坐牢*/)
//	theApp.m_pPer->ChangeDays(m_nDays);		
}


int CCard::Poor()
{
	return 0;
}

void CCard::Draw( CDC * pDC )
{/*
	m_MyBitmap.DeleteObject();
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_Bmp, IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
	m_MyDC.SelectObject(m_MyBitmap);

	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC,
								0,
								0,
								SRCCOPY );*/
}

void CCard::Draw( CPoint point ) 
{	
	switch(m_ID)
	{
	case 1:
		m_str = "停留卡";
		theApp.m_TmpScreenDC.TextOut( point.x, point.y,m_str );
		break;
	case 2:
		m_str = "转向卡";
		theApp.m_TmpScreenDC.TextOut( point.x, point.y,m_str );
		break;
	case 3:
		m_str = "乌龟卡";
		theApp.m_TmpScreenDC.TextOut( point.x, point.y,m_str );
		break;
	case 4:
		m_str = "免费卡";
		theApp.m_TmpScreenDC.TextOut( point.x, point.y,m_str );
		break;
	case 5:
		m_str = "免罪卡";
		theApp.m_TmpScreenDC.TextOut( point.x, point.y,m_str );
		break;
	case 6:
		m_str = "均贫卡";
		theApp.m_TmpScreenDC.TextOut( point.x, point.y,m_str );
		break;
	}	
}

int CCard::GetID()
{
	return m_ID;
}

void CCard::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
}

bool CCard::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

int CCard::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return 0;
}

int CCard::IsCard()
{
	//返回卡片标志
	return 1;
}

void CCard::WriteToStream( CArchive & ar )
{
	ar << m_ID;
	ar << m_Point;
	ar << m_nDays;
}

void CCard::ReadFromStream( CDC * pDC, CArchive & ar)
{
	ar >> m_Point;
	ar >> m_nDays;
}


void CCard::CardISBeUsed( int nI )
{
	switch(m_ID)
	{
	case 1://停留卡
		m_nDays = 1;
		theApp.m_pAllPer[nI]->ChangeDays( m_ID,m_nDays );
		break;
	case 2://转向卡
		theApp.m_pAllPer[nI]->ChangeWay();
		theApp.m_pAllPer[nI]->ChangeOrientation();
		break;
	case 3://乌龟卡
		m_nDays = 3;
		theApp.m_pAllPer[nI]->ChangeDays( m_ID,m_nDays );
		break;
	}
}
