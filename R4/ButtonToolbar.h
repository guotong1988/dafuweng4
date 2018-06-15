//Download by http://www.NewXing.com
// ButtonToolbar.h: interface for the CButtonToolbar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUTTONTOOLBAR_H__D745C453_1E12_45C8_9C99_1DF04FE852A7__INCLUDED_)
#define AFX_BUTTONTOOLBAR_H__D745C453_1E12_45C8_9C99_1DF04FE852A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

//°´Å¥¹¤¾ßÀ¸*
class CButtonToolbar : public CEntity  
{
public:
	CButtonToolbar();
	virtual ~CButtonToolbar();

	virtual void Draw( CDC * pDC );
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar ){}
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar ){}
};

#endif // !defined(AFX_BUTTONTOOLBAR_H__D745C453_1E12_45C8_9C99_1DF04FE852A7__INCLUDED_)
