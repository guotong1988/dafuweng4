//Download by http://www.NewXing.com
// ToolPerInfo.h: interface for the CToolPerInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPERINFO_H__718A159E_CB1D_4B4B_8D65_FFEF66B83B31__INCLUDED_)
#define AFX_TOOLPERINFO_H__718A159E_CB1D_4B4B_8D65_FFEF66B83B31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CToolPerInfo  :public CTool
{
public:
	int ToolName( CPoint point );

	CToolPerInfo(CDC * pDC);
	virtual ~CToolPerInfo();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}

};

#endif // !defined(AFX_TOOLPERINFO_H__718A159E_CB1D_4B4B_8D65_FFEF66B83B31__INCLUDED_)
