// Tool.cpp: implementation of the CTool class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Tool.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTool::CTool()
{

}

CTool::~CTool()
{

}

bool CTool::PointInRect( CPoint point, CRect rect )
{
	if( point.x < rect.left )return false;
	if( point.x > rect.right )return false;
	if( point.y < rect.top )return false;
	if( point.y > rect.bottom )return false;
	return true;
}
