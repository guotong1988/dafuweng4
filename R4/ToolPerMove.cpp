//Download by http://www.NewXing.com
// ToolPerMove.cpp: implementation of the CToolPerMove class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolPerMove.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolPerMove::CToolPerMove()
{
	m_MyRect.top = 0;
	m_MyRect.bottom = 480;
	m_MyRect.left = 0;
	m_MyRect.right = 640;
}

CToolPerMove::~CToolPerMove()
{

}

bool CToolPerMove::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CToolPerMove::OnTimer( CDC * pDC )
{
	theApp.m_pAllPer[0]->MoveOnHit( pDC );
	theApp.m_pAllPer[1]->MoveOnHit( pDC );
	theApp.m_pPer->Move( pDC );
}
int CToolPerMove::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}
