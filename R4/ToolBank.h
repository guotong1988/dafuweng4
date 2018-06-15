//Download by http://www.NewXing.com
// ToolBank.h: interface for the CToolBank class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLBANK_H__3F19F795_E976_4B31_B55F_5702BE7EF671__INCLUDED_)
#define AFX_TOOLBANK_H__3F19F795_E976_4B31_B55F_5702BE7EF671__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolBank : public CTool  
{
public:
	enum {Start=0,Memory,Lend};
	CToolBank(CDC *pDC);
	virtual ~CToolBank();
	virtual void Draw( CDC * pDC );

	virtual bool IsOnMe( CPoint point );
	virtual int ToolName( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual void OnTimer( CDC * pDC){}
private:
	int m_ifund;//ÒøÐÐ´æ¿î

};

#endif // !defined(AFX_TOOLBANK_H__3F19F795_E976_4B31_B55F_5702BE7EF671__INCLUDED_)
