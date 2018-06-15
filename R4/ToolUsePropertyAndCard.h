//Download by http://www.NewXing.com
// ToolUsePropertyAndCard.h: interface for the CToolUsePropertyAndCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLUSEPROPERTYANDCARD_H__907614F4_777E_4C84_BDF9_4F304F186D21__INCLUDED_)
#define AFX_TOOLUSEPROPERTYANDCARD_H__907614F4_777E_4C84_BDF9_4F304F186D21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"
#include "Per.h"
#include "Property.h"
#include "Entity.h"

class CToolUsePropertyAndCard : public CTool  
{
public:
	CToolUsePropertyAndCard(CDC * pDC, CEntity * pEntity);
	virtual ~CToolUsePropertyAndCard();

	virtual void Draw( CDC * pDC);
	void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );

	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos );
	int ToolName( CPoint point );
	//virtual int ToolName( CPoint point );
private:
	int m_ID;
	CDC m_noUseDC;        //“*”图像DC
	CDC m_noUseShadowDC;   //“*”图像影子DC

	CDC m_useDC;          //道具DC
	CDC m_useShadowDC;       //道具影子DC
	
	CBitmap m_noUseBitMap;      //“*”图像位图
	CBitmap m_noUseShadowBitMap;//“*”图像影子位图

	CBitmap m_useBitMap;      //道具图像位图
	CBitmap m_useShadowBitMap;//道具图像影子位图

	bool m_canUseDraw;          //画图状态
	CPoint m_point;             //移动时坐标
	CEntity * m_pEntity;        //道具或卡片指针
	CCard * m_pTest;         //测试用
	int m_IsCard;				//显示是否卡片
};

#endif // !defined(AFX_TOOLUSEPROPERTYANDCARD_H__907614F4_777E_4C84_BDF9_4F304F186D21__INCLUDED_)
