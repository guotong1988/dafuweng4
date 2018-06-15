//Download by http://www.NewXing.com
// ToolProperty.h: interface for the CToolProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLPROPERTY_H__D03AA870_E807_4AE0_B24A_D361864DF476__INCLUDED_)
#define AFX_TOOLPROPERTY_H__D03AA870_E807_4AE0_B24A_D361864DF476__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"
#include "Per.h"
#include "Property.h"
#include "CString"

class CToolProperty  : public CTool
{
public:
	CToolProperty(CDC *pDC);
	virtual ~CToolProperty();

	virtual void Draw( CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	void Init_DC_BM( CDC * pDC );
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){};
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){};
	virtual int ToolName( CPoint point );

private:
	CProperty * m_pProperty;
	CBitmap m_Probmp[15];
	CDC m_ProDC[15];
	int m_numOfType[15];
	CString m_string[13];
};

#endif // !defined(AFX_TOOLPROPERTY_H__D03AA870_E807_4AE0_B24A_D361864DF476__INCLUDED_)
