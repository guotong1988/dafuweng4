//Download by http://www.NewXing.com
// R4.h : main header file for the R4 application
//

#if !defined(AFX_R4_H__4080D773_53FA_4CA6_87FC_AEF67EF168AF__INCLUDED_)
#define AFX_R4_H__4080D773_53FA_4CA6_87FC_AEF67EF168AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "EntityList.h"
#include "ToolManager.h"
#include "SmallMap.h"
#include "Bankroll.h"
#include "ButtonToolbar.h"
#include "Stock.h"

/////////////////////////////////////////////////////////////////////////////
// CR4App:
// See R4.cpp for the implementation of this class
//

class CR4App : public CWinApp
{
public:
	CR4App();

	void Draw( CDC * pDC );
	void InitAll_DC_BM( CDC * pDC );
	int ToolName( CPoint point );

public:
	CBankroll m_Bankroll;			//资金栏*
	CBigMap m_BigMap;				//大地图*
	CButtonToolbar m_ButtonToolbar;	//工具栏*
	CEntityList m_EntityRoadList;	//路节点链表*
	CPer * m_pPer;					//当前游戏者*
	CPer * m_pAllPer[2];			//所有游戏者*
	CDate m_Date;					//日期*
	CSmallMap m_SmallMap;			//小地图*
	CStock * m_Stock[2];					//股票*
	CBitmap m_TmpScreenBitmap;		//临时桌面*
	CDC m_TmpScreenDC;
	CToolManager m_ToolManager;		//工具管理器*

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CR4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CR4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_R4_H__4080D773_53FA_4CA6_87FC_AEF67EF168AF__INCLUDED_)
