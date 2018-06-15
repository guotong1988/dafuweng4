//Download by http://www.NewXing.com
// ToolSave.cpp: implementation of the CToolSave class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolSave.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolSave::CToolSave( CDC * pDC )
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;

	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_MyDC.CreateCompatibleDC( pDC );

	m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\SaveShadow.bmp", IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\Save.bmp", IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );

	m_MyShadowDC.SelectObject(m_MyShadowBitmap);
	m_MyDC.SelectObject(m_MyBitmap);
}

CToolSave::~CToolSave()
{
	m_MyBitmap.DeleteObject();
	m_MyShadowBitmap.DeleteObject();

	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
}

void CToolSave::Draw( CDC * pDC )
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

bool CToolSave::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CToolSave::OnLButtonDblClk( CDC * pDC, CPoint point )
{
	char * pFileName = "Save.0";

	CFile f( pFileName, CFile::modeCreate | CFile::modeWrite );
	f.Close();

	if( f.Open( pFileName, CFile::modeCreate | CFile::modeWrite ) )
	{
		CArchive ar( &f, CArchive::store );

		theApp.m_Bankroll.WriteToStream( ar );			//资金栏*
		theApp.m_BigMap.WriteToStream( ar );			//大地图*
		theApp.m_Date.WriteToStream( ar );				//日期*
		theApp.m_SmallMap.WriteToStream( ar );			//小地图*
		theApp.m_Stock[0]->WriteToStream( ar );
		theApp.m_Stock[1]->WriteToStream( ar );
		theApp.m_pAllPer[0]->WriteToStream( ar );
		theApp.m_pAllPer[1]->WriteToStream( ar );
		ar << theApp.m_pPer->GetName();
		theApp.m_EntityRoadList.SaveToFile( ar );

		ar.Close();
	}
	f.Close();
}

void CToolSave::OnLButtonDown( CDC * pDC, CPoint ptPos )
{
}

int CToolSave::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}
