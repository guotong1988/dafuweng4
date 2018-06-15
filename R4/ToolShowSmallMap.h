//Download by http://www.NewXing.com
// ToolShowSmallMap.h: interface for the CToolShowSmallMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLSHOWSMALLMAP_H__DF67B7A5_CC9E_4FB0_8C2F_3C29E02B56E3__INCLUDED_)
#define AFX_TOOLSHOWSMALLMAP_H__DF67B7A5_CC9E_4FB0_8C2F_3C29E02B56E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolShowSmallMap : public CTool  
{
public:
	CToolShowSmallMap( CDC * pDC );
	virtual ~CToolShowSmallMap();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos ){}
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual int ToolName( CPoint point );
};

#endif // !defined(AFX_TOOLSHOWSMALLMAP_H__DF67B7A5_CC9E_4FB0_8C2F_3C29E02B56E3__INCLUDED_)
