//Download by http://www.NewXing.com
// Date.cpp: implementation of the CDate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Date.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDate::CDate()
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	m_Year = time.wYear; 
	m_Month = time.wMonth; 
	m_Date = time.wDay;
	m_AllDay = 1;
	m_INP = 1;
	m_DayOfWeek = time.wDayOfWeek;
} 

CDate::~CDate()
{
	
}

void CDate::DayPass( CDC *pDC )
{
	if(m_Year % 100 == 0 && m_Year % 4 != 0 || m_Year % 400 == 0)
	{
		switch(m_Month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(m_Date <= 31)
			{
				m_Date++;
			}
			if(m_Date == 32)
			{
				m_Date = 1;
				break;
			}
			break;
		case 2:
			if(m_Date <= 29)
			{
				m_Date++;
			}
			if(m_Date == 30)
			{
				m_Date = 1;
				break;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(m_Date <= 30)
			{
				m_Date++;
			}
			if(m_Date == 31)
			{
				m_Date = 1;
				break;
			}
			break;
		}
	}
	else
	{
		switch(m_Month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(m_Date <= 31)
			{
				m_Date++;
			}
			if(m_Date == 32)
			{
				m_Date = 1;
				m_Month++;
				break;
			}
			break;
		case 2:
			if(m_Date <= 28)
			{
				m_Date++;
			}
			if(m_Date == 29)
			{
				m_Date = 1;
				m_Month++;
				break;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(m_Date <= 30)
			{
				m_Date++;
			}
			if(m_Date == 31)
			{
				m_Date = 1;
				m_Month++;
				break;
			}
			break;
		}
	}
	if(m_Month == 13)
	{
		m_Year++;
		m_Month = 1;
	}
	m_AllDay++;
	if(	m_AllDay == 1000 )
	{
		m_INP = 2;
	}
	if(	m_AllDay == 1500 )
	{
		m_INP = 3;
	}
	if(	m_AllDay == 1750 )
	{
		m_INP = 4;
	}
	if(	m_AllDay == 1975 )
	{
		m_INP = 5;
	}
	if(	m_AllDay == 2000 )
	{
		m_INP = 6;
	}
	theApp.m_Stock[0]->PriceDispose(m_Date);
	theApp.m_Stock[1]->PriceDispose(m_Date);
	m_DayOfWeek++;

	if(m_DayOfWeek > 7)
	{
		m_DayOfWeek = 1;
	}
	if( m_Month == 12 && m_Date == 24 )
	{
		AfxMessageBox("圣诞节到了!!!发卡片额```",MB_OK);
		theApp.m_pAllPer[0]->AddCard( *(new CCard(pDC)) );
		theApp.m_pAllPer[1]->AddCard( *(new CCard(pDC)) );
		AfxMessageBox("所有玩家获得一张卡片!",MB_OK);
	}
}

void CDate::ShowDate()
{
	CString str;
	str.Format( "%d 日期%d.%d.%d" , m_INP,m_Year,m_Month,m_Date);
	theApp.m_TmpScreenDC.TextOut( 500 , 257 , str);
}

int CDate::GetINP()
{
	return m_INP;
}

int CDate::GetDay()
{
	return m_Date;
}

int CDate::GetDayOfWeek()
{
	return m_DayOfWeek;
}

void CDate::ReadFromStream( CDC * pDC, CArchive & ar )	//读取*
{
	ar >> m_Date;		//日
	ar >> m_Month;		//月
	ar >> m_Year;		//年
	ar >> m_DayOfWeek;	//星期几
	ar >> m_AllDay;		//记录天数
	ar >> m_INP;		//物价指数
}

void CDate::WriteToStream( CArchive & ar )	//保存*
{
	ar << m_Date;		//日
	ar << m_Month;		//月
	ar << m_Year;		//年
	ar << m_DayOfWeek;	//星期几
	ar << m_AllDay;		//记录天数
	ar << m_INP;		//物价指数
}
