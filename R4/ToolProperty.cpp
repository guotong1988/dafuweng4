//Download by http://www.NewXing.com
// ToolProperty.cpp: implementation of the CToolProperty class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolProperty.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Property.h"
//#include "CString"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolProperty::CToolProperty( CDC *pDC)
{
	//CPer::Property item[], int len,
	//	theApp.m_pPer->item
	//作用区域为全屏
	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;
	m_pProperty = NULL;

	Init_DC_BM( pDC );
}

CToolProperty::~CToolProperty()
{
	for(int i = 0; i < 13; i++)
	{
		if(m_numOfType[i] > 0 )
		{
			m_Probmp[i].DeleteObject();
			m_ProDC[i].DeleteDC();
		}
	}
}

void CToolProperty::Draw( CDC * pDC)
{
	
	int j = 0;

	for(int i = 0; i < 13; i++)
	{	
		if(m_Probmp[i].m_hObject)
		{
		//改变道具在道具背景上面的坐标
			int myleft = 0, mytop = 0;
			myleft += 40;
			j++;
			if(j > 5)
			{
				j = 0;
				myleft = 50;
				mytop += 50;
			}
			CString str = (m_numOfType[i] + 48) + "0";
			
			m_MyDC.TextOut(myleft + 10, 
				           mytop + 10, 
						   str);
		   
			m_MyDC.BitBlt(  myleft, mytop,
			     			60,
							60,
							&m_ProDC[i],
							0,
							0,
							SRCCOPY );
		}
	}

	theApp.m_TmpScreenDC.BitBlt( 20, 160,
								400,
								200,
								& m_MyDC,
								0,
								0,
								SRCCOPY );
	theApp.m_pPer->ShowPropertyInfo( CPoint(26,170) , 1);
}

void CToolProperty::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\toolbg.bmp", IMAGE_BITMAP,
									400,
									200,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );
}

void CToolProperty::OnLButtonDown( CDC * pDC, CPoint ptPos )
{
	//判断点击哪一个道具
	if( (ptPos.x > 20 && ptPos.x < 420) && (ptPos.y > 160 && ptPos.y < 360))
	{
		if((ptPos.x > 20 && ptPos.x < 100) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(1);
		}
		else if((ptPos.x > 100 && ptPos.x < 180) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(2);
		}
		else if((ptPos.x > 180 && ptPos.x < 260) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(3);
		}
		else if((ptPos.x > 260 && ptPos.x < 340) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(4);
		}
		else if((ptPos.x > 340 && ptPos.x < 420) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(5);
		}
		else if((ptPos.x > 20 && ptPos.x < 100) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(6);
		}
		else if((ptPos.x > 100 && ptPos.x < 180) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(7);
		}
		else if((ptPos.x > 180 && ptPos.x < 260) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(8);
		}
		else if((ptPos.x > 260 && ptPos.x < 340) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(9);
		}
		else if((ptPos.x > 340 && ptPos.x < 420) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(10);
		}
		else if((ptPos.x > 20 && ptPos.x < 100) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(11);
		}
		else if((ptPos.x > 100 && ptPos.x < 180) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(12);
		}
		else if((ptPos.x > 180 && ptPos.x < 260) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(13);
		}
		else if((ptPos.x > 260 && ptPos.x < 340) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(14);
		}
		else if((ptPos.x > 340 && ptPos.x < 420) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pProperty = theApp.m_pPer->ReduceItem(15);
		}
		if(m_pProperty != NULL)
		{
	  		theApp.m_ToolManager.SetActiveTool(pDC, UsePropertyAndCard, m_pProperty );
		}
	}	
}

bool CToolProperty::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

int CToolProperty::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoChange;	
}
