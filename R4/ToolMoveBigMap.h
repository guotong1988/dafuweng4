//Download by http://www.NewXing.com
// MoveBigMap.h: interface for the CMoveBigMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVEBIGMAP_H__0F929E10_E6DC_43ED_AF58_E75B6F26618E__INCLUDED_)
#define AFX_MOVEBIGMAP_H__0F929E10_E6DC_43ED_AF58_E75B6F26618E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolMoveBigMap : public CTool //通过小地图移动大地图的工具类 
{
public:
	CToolMoveBigMap();
	virtual ~CToolMoveBigMap();

	virtual void Draw( CDC * pDC ){}
	virtual bool IsOnMe( CPoint point ){return false;}
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos );
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos );
	virtual int ToolName( CPoint point ){return 0;}
};

#endif // !defined(AFX_MOVEBIGMAP_H__0F929E10_E6DC_43ED_AF58_E75B6F26618E__INCLUDED_)
