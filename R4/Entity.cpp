//Download by http://www.NewXing.com
// Entity.cpp: implementation of the CEntity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Entity.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEntity::CEntity()
{

}

CEntity::~CEntity()
{

}

void CEntity::ChangeMyRect(CPoint point)
{
	m_MyRect.top = point.y ;
	m_MyRect.left = point.x;
	m_MyRect.right = m_MyRect.left + 60;
	m_MyRect.bottom = m_MyRect.top + 60;
}
