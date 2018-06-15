//Download by http://www.NewXing.com
// ToolCard.cpp: implementation of the CToolCard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolCard.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolCard::CToolCard( CDC *pDC )
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;
	m_pCard = NULL;
	Init_DC_BM( pDC );
}

CToolCard::~CToolCard()
{
	
}

void CToolCard::Draw(CDC *pDC)
{
	theApp.m_TmpScreenDC.BitBlt( 30, 160,
								400,
								200,
								& m_MyDC,
								0,
								0,
								SRCCOPY );
	theApp.m_pPer->ShowCardInfo(CPoint(50,200),1);
}

void CToolCard::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\cardbg.bmp", IMAGE_BITMAP,
									400,
									200,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );	

}

void CToolCard::OnLButtonDown(CDC *pDC,CPoint ptPos)
{
	//ÅÐ¶Ïµã»÷ÄÄÒ»¸ö¿¨Æ¬
	if( (ptPos.x > 20 && ptPos.x < 420) && (ptPos.y > 160 && ptPos.y < 360))
	{
		if((ptPos.x > 20 && ptPos.x < 100) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pCard = theApp.m_pPer->ReduceCard(1);
		}
		else if((ptPos.x > 100 && ptPos.x < 180) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pCard = theApp.m_pPer->ReduceCard(2);
		}
		else if((ptPos.x > 180 && ptPos.x < 260) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pCard = theApp.m_pPer->ReduceCard(3);
		}
		else if((ptPos.x > 260 && ptPos.x < 340) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pCard = theApp.m_pPer->ReduceCard(4);
		}
		else if((ptPos.x > 340 && ptPos.x < 420) && (ptPos.y > 160 && ptPos.y < 220))
		{
			m_pCard = theApp.m_pPer->ReduceCard(5);
		}
		else if((ptPos.x > 20 && ptPos.x < 100) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pCard = theApp.m_pPer->ReduceCard(6);
		}
		else if((ptPos.x > 100 && ptPos.x < 180) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pCard = theApp.m_pPer->ReduceCard(7);
		}
		else if((ptPos.x > 180 && ptPos.x < 260) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pCard = theApp.m_pPer->ReduceCard(8);
		}
		else if((ptPos.x > 260 && ptPos.x < 340) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pCard = theApp.m_pPer->ReduceCard(9);
		}
		else if((ptPos.x > 340 && ptPos.x < 420) && (ptPos.y > 230 && ptPos.y < 290))
		{
			m_pCard = theApp.m_pPer->ReduceCard(10);
		}
		else if((ptPos.x > 20 && ptPos.x < 100) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pCard = theApp.m_pPer->ReduceCard(11);
		}
		else if((ptPos.x > 100 && ptPos.x < 180) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pCard = theApp.m_pPer->ReduceCard(12);
		}
		else if((ptPos.x > 180 && ptPos.x < 260) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pCard = theApp.m_pPer->ReduceCard(13);
		}
		else if((ptPos.x > 260 && ptPos.x < 340) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pCard = theApp.m_pPer->ReduceCard(14);
		}
		else if((ptPos.x > 340 && ptPos.x < 420) && (ptPos.y > 300 && ptPos.y < 360))
		{
			m_pCard = theApp.m_pPer->ReduceCard(15);
		}
		if(m_pCard != NULL)
		{
	  		theApp.m_ToolManager.SetActiveTool(pDC, UsePropertyAndCard, m_pCard);
		}
	}
}

int CToolCard::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoChange;
}
