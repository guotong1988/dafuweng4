//Download by http://www.NewXing.com
// ToolPerGlebeInfo.h: interface for the CToolPerGlebeInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPERGLEBEINFO_H__265BB405_FD69_4C89_9D8C_70402E3235D5__INCLUDED_)
#define AFX_TOOLPERGLEBEINFO_H__265BB405_FD69_4C89_9D8C_70402E3235D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolPerGlebeInfo : public CTool  
{
public:
	CToolPerGlebeInfo(CDC * pDC);
	virtual ~CToolPerGlebeInfo();
	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLPERGLEBEINFO_H__265BB405_FD69_4C89_9D8C_70402E3235D5__INCLUDED_)
