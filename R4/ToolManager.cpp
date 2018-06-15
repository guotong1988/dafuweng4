//Download by http://www.NewXing.com
// ToolManager.cpp: implementation of the CToolManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolManager::CToolManager()
{
	m_pTool = NULL;
}

CToolManager::~CToolManager()
{
	if( NULL != m_pTool ) delete m_pTool;
}

void CToolManager::DispatchMsg( CDC * pDC, UINT message, CPoint point )
{
	//管理器对消息的响应
	switch( message )
	{
	case WM_LBUTTONDOWN:
		if( NULL != m_pTool )
		{
			m_pTool->OnLButtonDown( pDC, point);
		}
		break;
	case WM_MOUSEMOVE:
		if( NULL != m_pTool )
		{
			m_pTool->OnMouseMove( pDC, point);
		}
		break;
	case WM_LBUTTONUP:
		if( NULL != m_pTool )
		{
			m_pTool->OnLButtonUp( pDC, point);
		}
		break;
	case WM_LBUTTONDBLCLK:
		if( NULL != m_pTool )
		{
			m_pTool->OnLButtonDblClk( pDC, point);
		}
		break;
	case WM_TIMER:
		if( NULL != m_pTool )
		{
			m_pTool->OnTimer( pDC );
		}
		break;
	default:
		AfxMessageBox( "CToolManager.DispatchMsg消息错误！" );
	}
}

void CToolManager::Draw( CDC * pDC )
{
	if( NULL != m_pTool )
	{
		m_pTool->Draw( pDC );
	}
}

bool CToolManager::IsOnMe( CPoint point )
{
	
	if( NULL != m_pTool )
	{
		return m_pTool->IsOnMe( point );
	}
	return false;
}

void CToolManager::SetActiveTool( CDC * pDC, const int ToolType, CEntity * pEntity  )
{
	//生成工具
	switch( ToolType )
	{
	case CTool::NoTool:
		if( NULL != m_pTool )
		{
			delete m_pTool;
			m_pTool = NULL;	//一定要，不然会出错*
		}
		break;
	case CTool::NoChange:
		break;
	case CTool::Card:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolCard( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::Dice:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolDice( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::Load:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolLoad( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::MoveBigMap:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolMoveBigMap;
		break;
	case CTool::PerGlebeInfo:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolPerGlebeInfo( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::PerInfo:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolPerInfo( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::PerMove:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolPerMove;
		break;
	case CTool::PerSell:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolPerSell( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::PerStockInfo:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolPerStockInfo( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::Property:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolProperty( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::Save:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolSave( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::Sell:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolSell( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::ShowSmallMap:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolShowSmallMap( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::Stock:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolStock( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::UsePropertyAndCard:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolUsePropertyAndCard( pDC,pEntity);
		theApp.Draw( pDC );
		break;
	case CTool::Bank:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolBank( pDC );
		theApp.Draw( pDC );
		break;
	case CTool::BankLend:
		if( NULL != m_pTool ) delete m_pTool;
		m_pTool = new CToolLendFund( pDC );
		theApp.Draw( pDC );
		break;
	default:
		AfxMessageBox( "CToolManager.SetActiveTool消息错误！" );
	}
}

int CToolManager::ToolName( CPoint point )
{
	if( NULL != m_pTool )
	{
		return m_pTool->ToolName( point );
	}
	return CTool::NoTool;
}
