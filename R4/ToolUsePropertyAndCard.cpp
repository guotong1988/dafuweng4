//Download by http://www.NewXing.com
// ToolUsePropertyAndCard.cpp: implementation of the CToolUsePropertyAndCard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolUsePropertyAndCard.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolUsePropertyAndCard::CToolUsePropertyAndCard(CDC * pDC, CEntity * pEntity )
{
	//作用区域为全屏
	m_MyRect.top = 40;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 440;

	if( NULL != pEntity )
	{
		m_pEntity = pEntity;
		m_IsCard = m_pEntity->IsCard();
		m_ID = m_pEntity->GetID();
	}
	else
	{
		m_pEntity = NULL;
		m_IsCard = 0;
		m_ID = 0;
	}

	Init_DC_BM( pDC );
	m_canUseDraw = false;
}

CToolUsePropertyAndCard::~CToolUsePropertyAndCard()
{
	m_noUseDC.DeleteDC();        //“*”图像DC
	m_noUseShadowDC.DeleteDC();   //“*”图像影子DC

	m_useDC.DeleteDC();          //道具DC
	m_useShadowDC.DeleteDC();       //道具影子DC

	m_MyDC.DeleteDC();
	m_MyShadowDC.DeleteDC();
	
	m_noUseBitMap.DeleteObject();      //“*”图像位图
	m_noUseShadowBitMap.DeleteObject();
	m_useBitMap.DeleteObject();      //道具图像位图
	m_useShadowBitMap.DeleteObject();//道具图像影子位图

	m_MyShadowBitmap.DeleteObject();
	m_MyBitmap.DeleteObject();

	if( NULL != m_pEntity && m_IsCard == 2 )
	{
		theApp.m_pPer->AddItem(*(CProperty*)m_pEntity);
	}
	if( NULL != m_pEntity && m_IsCard == 1 )
	{
		theApp.m_pPer->AddCard(*(CCard*)m_pEntity);
	}
}

void CToolUsePropertyAndCard::Draw( CDC * pDC)
{	
	//根据节点来draw()；
	if(m_canUseDraw)
	{
		//画影子
		theApp.m_TmpScreenDC.BitBlt( m_point.x, m_point.y,
									380,
									300,
									& m_useShadowDC,
									0,
									0,
									SRCAND );
		//画颜色
		theApp.m_TmpScreenDC.BitBlt( m_point.x, m_point.y,
									380,
									300,
									& m_useDC,
									0,
									0,
									SRCPAINT );
	}
	else
	{
		//画影子
		theApp.m_TmpScreenDC.BitBlt( m_point.x, m_point.y,
									380,
									300,
									& m_noUseShadowDC,
									0,
									0,
									SRCAND );
		//画颜色
		theApp.m_TmpScreenDC.BitBlt( m_point.x, m_point.y,
									380,
									300,
									& m_noUseDC,
									0,
									0,
									SRCPAINT );
	}

}

void CToolUsePropertyAndCard::OnLButtonDown( CDC * pDC, CPoint ptPos )
{	
	switch(m_IsCard)
	{
	case 0:
		AfxMessageBox("No Draw !");
		break;
	case 2:
		if( m_pEntity != NULL && theApp.m_EntityRoadList.IsOnNode(ptPos))
		{
			theApp.m_EntityRoadList.AddGodOrProperty( m_pEntity, ptPos );
			m_pEntity = NULL;
			theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice , m_pEntity );	
		}		
		break;
	case 1:
		if( m_pEntity != NULL )
		{
			if(theApp.m_pAllPer[0]->IsOnMe(ptPos))
			{
				m_pEntity->CardISBeUsed(0);
				m_pEntity = NULL;
				theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice , m_pEntity );
			}
			else if(theApp.m_pAllPer[1]->IsOnMe(ptPos))
			{
				m_pEntity->CardISBeUsed(1);
				m_pEntity = NULL;
				theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice , m_pEntity );
			}
		}
		break;
	}	
}

void CToolUsePropertyAndCard::OnMouseMove( CDC * pDC, CPoint ptPos )
{
	switch(m_IsCard)
	{
	case 1:
		if(theApp.m_EntityRoadList.IsOnPer(ptPos) 
			&& CTool::PointInRect(ptPos, m_MyRect ))
		{
			m_canUseDraw = true;
		}
		else
		{
			m_canUseDraw = false;
		}
		break;
	case 2:
		if(theApp.m_EntityRoadList.IsOnNode(ptPos) 
			&& CTool::PointInRect(ptPos, m_MyRect ))
		{
			m_canUseDraw = true;
		}
		else
		{
			m_canUseDraw = false;
		}
		break;
	}
	m_point.x = ptPos.x;
	m_point.y = ptPos.y;
	theApp.Draw( pDC );
}

int CToolUsePropertyAndCard::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
	     return CTool::NoChange;
	}
	return CTool::NoChange;
}

bool CToolUsePropertyAndCard::IsOnMe( CPoint point )
{
	return true;
}

void CToolUsePropertyAndCard::Init_DC_BM( CDC * pDC )
{
	//初始化不能使用图象
	m_noUseDC.CreateCompatibleDC( pDC );
	m_noUseBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\nocanuse.bmp", IMAGE_BITMAP,
								30,
								40,
								LR_LOADFROMFILE );
	m_noUseDC.SelectObject( m_noUseBitMap );



	m_noUseShadowDC.CreateCompatibleDC( pDC);
	m_noUseShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
	                               "img\\nocanuseYz.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
	m_noUseShadowDC.SelectObject( m_noUseShadowBitMap );


	//初始化可以使用图象
	if(m_pEntity != NULL && m_IsCard == 2)
	{
		switch(m_ID)
		{
		case 1:
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\3pro.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );

		m_useShadowDC.CreateCompatibleDC( pDC);
		m_useShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									   "img\\3proshd.bmp", IMAGE_BITMAP,
										30,
										40,
										LR_LOADFROMFILE );
		m_useShadowDC.SelectObject( m_useShadowBitMap );
		break;
		case 2:
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\5pro.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );

		m_useShadowDC.CreateCompatibleDC( pDC);
		m_useShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									   "img\\5proshd.bmp", IMAGE_BITMAP,
										30,
										40,
										LR_LOADFROMFILE );
		m_useShadowDC.SelectObject( m_useShadowBitMap );
		break;
		case 3:
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\2pro.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );

		m_useShadowDC.CreateCompatibleDC( pDC);
		m_useShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									   "img\\2proshd.bmp", IMAGE_BITMAP,
										30,
										40,
										LR_LOADFROMFILE );
		m_useShadowDC.SelectObject( m_useShadowBitMap );
		break;
		case 4:
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\4pro.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );

		m_useShadowDC.CreateCompatibleDC( pDC);
		m_useShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									   "img\\4proshd.bmp", IMAGE_BITMAP,
										30,
										40,
										LR_LOADFROMFILE );
		m_useShadowDC.SelectObject( m_useShadowBitMap );
		break;
		case 5:
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\5pro.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );

		m_useShadowDC.CreateCompatibleDC( pDC);
		m_useShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									   "img\\5proshd.bmp", IMAGE_BITMAP,
										30,
										40,
										LR_LOADFROMFILE );
		m_useShadowDC.SelectObject( m_useShadowBitMap );
		break;
		case 6:
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\6pro.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );

		m_useShadowDC.CreateCompatibleDC( pDC);
		m_useShadowBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									   "img\\6proshd.bmp", IMAGE_BITMAP,
										30,
										40,
										LR_LOADFROMFILE );
		m_useShadowDC.SelectObject( m_useShadowBitMap );
		break;
		default:
			AfxMessageBox("NULL what");
		}
	}
	if(m_pEntity != NULL && m_IsCard == 1)
	{
		m_useDC.CreateCompatibleDC( pDC );
		m_useBitMap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\Card.bmp", IMAGE_BITMAP,
									30,
									40,
									LR_LOADFROMFILE );
		m_useDC.SelectObject( m_useBitMap );
	}
}
