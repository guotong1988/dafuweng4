//Download by http://www.NewXing.com
// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__BB500965_5749_454F_8A65_B6D03B4F3F86__INCLUDED_)
#define AFX_STDAFX_H__BB500965_5749_454F_8A65_B6D03B4F3F86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "Bankroll.h"
#include "BigMap.h"
#include "ButtonToolbar.h"
#include "Card.h"
#include "Entity.h"
#include "EntityList.h"
#include "EntityNode.h"
#include "Glebe.h"
#include "God.h"
#include "MainFrm.h"
#include "Per.h"
#include "Property.h"
#include "Date.h"
#include "R4.h"
#include "R4Doc.h"
#include "R4View.h"
#include "Resource.h"
#include "SmallMap.h"
#include "Stock.h"
#include "Tool.h"
#include "ToolCard.h"
#include "ToolDice.h"
#include "ToolLoad.h"
#include "ToolManager.h"
#include "ToolMoveBigMap.h"
#include "ToolPerGlebeInfo.h"
#include "ToolPerInfo.h"
#include "ToolPerMove.h"
#include "ToolPerSell.h"
#include "ToolPerStockInfo.h"
#include "ToolProperty.h"
#include "ToolSave.h"
#include "ToolSell.h"
#include "ToolShowSmallMap.h"
#include "ToolStock.h"
#include "ToolUsePropertyAndCard.h"
#include "ToolBank.h"
#include "ToolLendFund.h"
#include <vfw.h>
#pragma comment(lib, "VFW32.lib")
//声明全局变量
extern CR4App theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__BB500965_5749_454F_8A65_B6D03B4F3F86__INCLUDED_)
