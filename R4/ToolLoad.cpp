//Download by http://www.NewXing.com
// ToolLoad.cpp: implementation of the CToolLoad class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolLoad.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolLoad::CToolLoad( CDC * pDC )
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;

	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_MyDC.CreateCompatibleDC( pDC );

	m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\LoadShadow.bmp", IMAGE_BITMAP,
							m_MyRect.right - m_MyRect.left,
							m_MyRect.bottom - m_MyRect.top,
							LR_LOADFROMFILE );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\Load.bmp", IMAGE_BITMAP,
							m_MyRect.right - m_MyRect.left,
							m_MyRect.bottom - m_MyRect.top,
							LR_LOADFROMFILE );

	m_MyShadowDC.SelectObject(m_MyShadowBitmap);
	m_MyDC.SelectObject(m_MyBitmap);
}

CToolLoad::~CToolLoad()
{
	m_MyBitmap.DeleteObject();
	m_MyShadowBitmap.DeleteObject();

	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
}

void CToolLoad::Draw( CDC * pDC )
{
	//画影子
	theApp.m_TmpScreenDC.BitBlt(m_MyRect.left,m_MyRect.top,
		m_MyRect.right - m_MyRect.left,
		m_MyRect.bottom - m_MyRect.top,
		& m_MyShadowDC, 0, 0, SRCAND);

	theApp.m_TmpScreenDC.BitBlt(m_MyRect.left,m_MyRect.top,
		m_MyRect.right - m_MyRect.left,
		m_MyRect.bottom - m_MyRect.top,
		& m_MyDC, 0, 0, SRCPAINT);
}

bool CToolLoad::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CToolLoad::OnLButtonDblClk( CDC * pDC, CPoint point )
{
	char * pFileName = "Save.0";
	int nName;

	CFile f( pFileName, CFile::modeRead );
	f.Close();

	if( f.Open( pFileName, CFile::modeRead ) )
	{
		delete theApp.m_pAllPer[0];
		theApp.m_pAllPer[0] = NULL;
		
		delete theApp.m_pAllPer[1];
		theApp.m_pAllPer[1] = NULL;

		theApp.m_pPer = NULL;

		CArchive ar( &f, CArchive::load );
		theApp.m_Bankroll.ReadFromStream( pDC, ar );		//资金栏*
		theApp.m_BigMap.ReadFromStream( pDC, ar );			//大地图*
		theApp.m_Date.ReadFromStream( pDC, ar );			//日期*
		theApp.m_SmallMap.ReadFromStream( pDC, ar );		//小地图*
		theApp.m_Stock[0]->ReadFromStream( pDC, ar );
		theApp.m_Stock[1]->ReadFromStream( pDC, ar );
		ar >> nName;
		theApp.m_pAllPer[0] = new CPer( pDC, nName ,CPoint(110,110) );
		theApp.m_pAllPer[0]->ReadFromStream( pDC, ar );
		ar >> nName;
		theApp.m_pAllPer[1] = new CPer( pDC, nName ,CPoint(110,101) );
		theApp.m_pAllPer[1]->ReadFromStream( pDC, ar );

		ar >> nName;
		if( nName == theApp.m_pAllPer[0]->GetName() )
		{
			theApp.m_pPer = theApp.m_pAllPer[0];
		}
		else if( nName == theApp.m_pAllPer[1]->GetName() )
		{
			theApp.m_pPer = theApp.m_pAllPer[1];
		}

		theApp.m_EntityRoadList.ReadFromFile( pDC, ar );

		ar.Close();
	}
	f.Close();

	theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice, NULL );
}

int CToolLoad::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}
