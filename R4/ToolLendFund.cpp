//Download by http://www.NewXing.com
// ToolLendFund.cpp: implementation of the CToolLendFund class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolLendFund.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolLendFund::CToolLendFund(CDC * pDC)
{
	//画初始图
	this->m_MyDC.CreateCompatibleDC( pDC );

	m_CounterDC.CreateCompatibleDC (pDC);
	//画加载图
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\Bank2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap);



	m_CounterBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\counter.bmp", 
								IMAGE_BITMAP,
								140,
								180,
								LR_LOADFROMFILE );
	m_CounterDC.SelectObject( m_CounterBitmap);

	this->m_CounterRect.bottom =330;
	this->m_CounterRect.left =300;
	this->m_CounterRect.top =150;
	this->m_CounterRect.right =440;

	m_MyRect.top = 0 ;
	m_MyRect.left = 0;
	m_MyRect.right = 800;
	m_MyRect.bottom = 600;

	this->m_ToolState =stInit;
	this->m_iLend =0;
}

CToolLendFund::~CToolLendFund()
{
	m_MyBitmap.DeleteObject();
	m_MyDC.DeleteDC();

	m_CounterBitmap.DeleteObject();
	m_CounterDC.DeleteDC();
}

void CToolLendFund::Draw(CDC *pDC)
{
	if (m_ToolState ==stInit)
	{
		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									& m_MyDC, 0, 0, SRCCOPY);

	}
	else if ( m_ToolState ==stSecond || m_ToolState ==stFirst )
	{
		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									& m_MyDC, 0, 0, SRCCOPY);
		
		theApp.m_TmpScreenDC.BitBlt(m_CounterRect.left,m_CounterRect.top,
								(m_CounterRect.right -m_CounterRect.left), 
								(m_CounterRect.bottom -m_CounterRect.top),
								& m_CounterDC, 0, 0, SRCCOPY);
		CString str;
		str.Format("%d",m_iLend);
		theApp.m_TmpScreenDC.TextOut (m_CounterRect.left+10 , m_CounterRect.top+10 , str , strlen(str));		
	}
}

void CToolLendFund::OnLButtonDown( CDC * pDC, CPoint ptPos )
{
	int itmpNum = 0;
	if (m_iLend < 99999999)
	{
		if (m_ToolState ==stInit && 
		((ptPos.x > 315 && ptPos.x < 420) && (ptPos.y > 320 && ptPos.y < 380)) )
		{
			AfxMessageBox( "输入贷款金额!" );//贷款状态
			m_ToolState =stSecond;
			
		}
		else if (m_ToolState ==stInit && 
			((ptPos.x > 420 && ptPos.x < 530) && (ptPos.y > 320 && ptPos.y < 380)))
		{
			//还款
			AfxMessageBox( "你可以还贷款!" );
			m_ToolState =stFirst;
		}
		else if (m_ToolState ==stFirst || m_ToolState ==stSecond)
		{
			//1
			if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
				&& (ptPos.y >= m_CounterRect.top +153 && ptPos.y <= m_CounterRect.bottom+1))
			{
				itmpNum=1;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//2
			else if ( (ptPos.x >= m_CounterRect.left+46 && ptPos.x <= m_CounterRect.right-48)
			&& (ptPos.y >= m_CounterRect.top +153 && ptPos.y <= m_CounterRect.bottom+1))
			{
				itmpNum=2;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//3
			else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right)
			&& (ptPos.y >= m_CounterRect.top +153 && ptPos.y <= m_CounterRect.bottom+1))
			{
				itmpNum=3;	
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//4
			else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
			&& (ptPos.y >= m_CounterRect.top +126 && ptPos.y <= m_CounterRect.bottom-28))
			{
				itmpNum=4;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//5
			else if ((ptPos.x >= m_CounterRect.left+46 && ptPos.x <= m_CounterRect.right-48)
			&& (ptPos.y >= m_CounterRect.top +126 && ptPos.y <= m_CounterRect.bottom-28))
			{
				itmpNum=5;	
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//6
			else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right)
			&& (ptPos.y >= m_CounterRect.top +126 && ptPos.y <= m_CounterRect.bottom-28))
			{
				itmpNum=6;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//7
			else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
			&& (ptPos.y >= m_CounterRect.top +100 && ptPos.y <= m_CounterRect.bottom-55))
			{
				itmpNum=7;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//8
			else if ((ptPos.x >= m_CounterRect.left+46 && ptPos.x <= m_CounterRect.right-48)
			&& (ptPos.y >= m_CounterRect.top +100 && ptPos.y <= m_CounterRect.bottom-55))
			{
				itmpNum=8;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//9
			else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right)
			&& (ptPos.y >= m_CounterRect.top +100 && ptPos.y <= m_CounterRect.bottom-55))
			{
				itmpNum=9;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//0
			else if ((ptPos.x >= m_CounterRect.left+47 && ptPos.x <= m_CounterRect.right-47)
			&& (ptPos.y >= m_CounterRect.top +72 && ptPos.y <= m_CounterRect.bottom-82))
			{
				itmpNum=0;
				this->m_iLend = m_iLend *10 + itmpNum;
			}
			//c
			else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
			&& (ptPos.y >= m_CounterRect.top +72 && ptPos.y <= m_CounterRect.bottom-82))
			{
				m_iLend =0;
			}
			//悔上一个数
			else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right-1)
			&& (ptPos.y >= m_CounterRect.top +72 && ptPos.y <= m_CounterRect.bottom-82))
			{	
				m_iLend = (int)(m_iLend / 10.0);
			}
			//MAX
			else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-70)
			&& (ptPos.y >= m_CounterRect.top +36 && ptPos.y <= m_CounterRect.bottom-108))
			{
				if (m_ToolState ==stSecond)//贷款状态
				{
					m_iLend  = theApp.m_pPer->GetFund() + theApp.m_pPer->GetCash();
				}
				else if (m_ToolState ==stFirst )/*还款区域*/
				{
					m_iLend = theApp.m_pPer->GetFund() + 
							theApp.m_pPer->GetCash() -
							theApp.m_pPer->GetLoan ();  	
				}
			}	
			//确定
			else if ((ptPos.x >= m_CounterRect.left+71 && ptPos.x <= m_CounterRect.right-1)
			&& (ptPos.y >= m_CounterRect.top +36 && ptPos.y <= m_CounterRect.bottom-108))
			{
				if (m_ToolState ==stSecond)//贷款状态
				{
					if ( m_iLend < (theApp.m_pPer->GetFund()+ theApp.m_pPer->GetCash()) )
					{
						theApp.m_pPer->AddFund(m_iLend );
						theApp.m_pPer->AddLoan(m_iLend);
					}
					else
					{
						AfxMessageBox( "输入金额不对!" );
					}		
				}
				else if (m_ToolState ==stFirst)/*还款区域*/
				{
					if (m_iLend == theApp.m_pPer->GetLoan() )
					{
						if ( (m_iLend ) < (theApp.m_pPer->GetFund() + 
											theApp.m_pPer->GetCash() -
											theApp.m_pPer->GetLoan ()) )
						{
							if ( m_iLend > theApp.m_pPer->GetFund())
							{
								theApp.m_pPer->ReduceFund( theApp.m_pPer->GetFund() );
								theApp.m_pPer->ReduceCash ( m_iLend -theApp.m_pPer->GetFund() );
		
							}
							else
							{
								theApp.m_pPer->ReduceFund (m_iLend);
							}
							theApp.m_pPer->ReduceLoan (m_iLend);
							m_iLend =0;
						}
						else
						{
							AfxMessageBox( "你的资产不足!" );
						}
					}
					else
					{
						AfxMessageBox( "你输入有误!" );
					}
				}	
				m_ToolState = stInit;
				m_iLend =0;
				itmpNum =0;
			}
		}
	//	m_iLend = m_iLend *10 + itmpNum;
	}
	else
	{
		AfxMessageBox( "输入有误!" );
		m_iLend =0;
	}
	theApp.Draw(pDC);
}

int CToolLendFund::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		if( (point.x >= 540 && point.x <= 640)
		&& (point.y >= 0 && point.y <= 40))
		{
			return CTool::NoTool;
		}
		return CTool::NoChange;
	}
	return CTool::NoTool;
}

//在EXIT时退出STOCK界面
bool CToolLendFund::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point,m_MyRect) )
	{
		return true;
	}
	return false;
}


		

