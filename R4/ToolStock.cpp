//Download by http://www.NewXing.com
// ToolStock.cpp: implementation of the CToolStock class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolStock.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolStock::CToolStock( CDC * pDC )
{
	this->m_MyRect.bottom =480;
	this->m_MyRect.left =0;
	this->m_MyRect.top =0;
	this->m_MyRect.right =640;

	this->m_CounterRect.bottom =330;
	this->m_CounterRect.left =300;
	this->m_CounterRect.top =150;
	this->m_CounterRect.right =440;

	this->m_CounterMoveRect.bottom =m_CounterRect.bottom - 135;
	this->m_CounterMoveRect.left =m_CounterRect.left;
	this->m_CounterMoveRect.top =m_CounterRect.top;
	this->m_CounterMoveRect.right =m_CounterRect.right;

	this->m_ToolState =stInit;
	this->m_iCounterNum =0;
	this->m_CounterState =None;
//	this->m_ID =0;
	//画初始图
	m_MyDC.CreateCompatibleDC( pDC );
	//画输入器图
	m_CounterDC.CreateCompatibleDC (pDC);
	//画交易状态图
	m_BusinessStateDC.CreateCompatibleDC (pDC);
	//画曲线图
	m_GraphDC.CreateCompatibleDC (pDC);
	//画曲线图
	m_GraphBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\stockGraph.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top-60,
									LR_LOADFROMFILE );
	m_GraphDC.SelectObject( m_GraphBitmap );

	//画交易状态图
	m_BusinessStateBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\stockbg2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
	m_BusinessStateDC.SelectObject( m_BusinessStateBitmap );
	//画初始图
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\stockbg1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );	
	//画输入器图
	m_CounterBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\counter.bmp", 
								IMAGE_BITMAP,
								140, 180,
								LR_LOADFROMFILE );
	m_CounterDC.SelectObject( m_CounterBitmap);
}

CToolStock::~CToolStock()
{
	m_BusinessStateBitmap.DeleteObject();
	m_BusinessStateDC.DeleteDC();
	
	m_MyBitmap.DeleteObject();
	m_MyDC.DeleteDC();

	m_CounterBitmap.DeleteObject();
	m_CounterDC.DeleteDC();

	m_GraphBitmap.DeleteObject();
	m_GraphDC.DeleteDC();
}


void CToolStock::Draw(CDC *pDC)
{
	//新建画刷
	CBrush brush,* oldbrush;
	//新建画笔
	CPen pen,* oldpen;
	
	CString str;
	if (m_ToolState==stInit)
	{
		theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));	

		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCCOPY);
		//返回人物存款
		str.Format("%d",theApp.m_pPer->GetFund());
		theApp.m_TmpScreenDC.TextOut (480,10,str,strlen(str));
		//显示股票信息
		theApp.m_Stock[0]->ShowInfo(0);
		theApp.m_Stock[1]->ShowInfo(1);
	}
	//选中一种股票
	else if (m_ToolState==stFirst)
	{	
		theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));

		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_BusinessStateDC, 0, 0, SRCCOPY);
		//返回人物存款
		str.Format( "%d",theApp.m_pPer->GetFund());
		theApp.m_TmpScreenDC.TextOut (480,10,str,strlen(str));
		
		//显示股票信息
		theApp.m_Stock[0]->ShowInfo(0);
		theApp.m_Stock[1]->ShowInfo(1);

		//给选取股票画方框
		//m_BusinessStateDC.SetROP2(R2_XORPEN);//取背景颜色
		//白色画笔
		pen.CreatePen(PS_SOLID,2,RGB(255,255,255));
		oldpen=theApp.m_TmpScreenDC.SelectObject (&pen);	
		//空画刷
		brush.CreateStockObject(NULL_BRUSH);
		oldbrush=theApp.m_TmpScreenDC.SelectObject (&brush);
		//加上设备上文
		theApp.m_TmpScreenDC.SelectObject (&pen);
		theApp.m_TmpScreenDC.SelectObject (&brush);
		switch (m_ID)
		{
			case 0:
				//画矩形空画刷填充，白色边框
				theApp.m_TmpScreenDC.Rectangle(0,66,640,102);
				break;
			case 1:
				theApp.m_TmpScreenDC.Rectangle(0,136,640,101);
			
				break;
		}
		theApp.m_TmpScreenDC.SelectObject (oldpen);
		theApp.m_TmpScreenDC.SelectObject (oldbrush);
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
		pen.DeleteObject ();
		brush.DeleteObject ();
	}
	//股票交易状态卖出(人物是买进)
	else if (m_ToolState==stSecond) //&& m_CounterState ==Num
	{
		theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));
		theApp.m_TmpScreenDC.SetBkColor(RGB(144,203,244));	
		//单击画输入器图
		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_BusinessStateDC, 0, 0, SRCCOPY);

		//返回人物存款
		str.Format( "%d",theApp.m_pPer->GetFund());
		theApp.m_TmpScreenDC.TextOut (480,10,str,strlen(str));

		//显示股票信息
		theApp.m_Stock[0]->ShowInfo(0);
		theApp.m_Stock[1]->ShowInfo(1);

		theApp.m_TmpScreenDC.BitBlt(m_CounterRect.left,m_CounterRect.top,
									(m_CounterRect.right -m_CounterRect.left), 
									(m_CounterRect.bottom -m_CounterRect.top),
									& m_CounterDC, 0, 0, SRCCOPY);
		//返回交易股票数量
		str.Format("%d",m_iCounterNum);
		theApp.m_TmpScreenDC.TextOut (m_CounterRect.left+50 , m_CounterRect.top+10 , str, strlen(str));
	
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
	}
	//股票交易状态买回(人物是卖出)
	else if (m_ToolState==stThird) //&& m_CounterState ==Num
	{
		theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));
		//单击卖出时画输入器图
		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_BusinessStateDC, 0, 0, SRCCOPY);

		//返回人物存款
		str.Format( "%d",theApp.m_pPer->GetFund());
		theApp.m_TmpScreenDC.TextOut (480,10,str,strlen(str));

		//显示股票信息
		theApp.m_Stock[0]->ShowInfo(0);
		theApp.m_Stock[1]->ShowInfo(1);

		theApp.m_TmpScreenDC.BitBlt(m_CounterRect.left,m_CounterRect.top,
									(m_CounterRect.right -m_CounterRect.left), 
									(m_CounterRect.bottom -m_CounterRect.top),
									& m_CounterDC, 0, 0, SRCCOPY);
		//返回交易股票数量
		str.Format("%d",m_iCounterNum);
		theApp.m_TmpScreenDC.TextOut (m_CounterRect.left+50 , m_CounterRect.top+10 , str , strlen(str));		
	
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
	}
	//画股票曲线图
	else if (m_ToolState==stFour)
	{
		//画股票曲线图
		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_BusinessStateDC, 0, 0, SRCCOPY);
		//返回人物存款
		str.Format( "%d",theApp.m_pPer->GetFund());
		theApp.m_TmpScreenDC.TextOut (480,10,str,strlen(str));

		//显示股票信息
		theApp.m_Stock[0]->ShowInfo(0);
		theApp.m_Stock[1]->ShowInfo(1);

		theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top+40,
							m_MyRect.right - m_MyRect.left,
							m_MyRect.bottom - m_MyRect.top,
							& m_GraphDC, 0, 0, SRCCOPY);
		theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));

		switch (m_ID)
		{
			case 0:
				//画矩形空画刷填充，白色边框
				theApp.m_TmpScreenDC.TextOut (300 , 60 , "齐齐实业", strlen("齐齐实业"));
				break;
			case 1:
				theApp.m_TmpScreenDC.TextOut (300 , 60 , "李李实业", strlen("李李实业"));
				break;
		}
		theApp.m_Stock[m_ID]->StockGraphShowInfo();
		
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
	}
}


//左键进入
void CToolStock::OnLButtonDown(CDC *pDC, CPoint ptPos)
{
	int itmpNum (0);

	if ( theApp.m_Date.GetDayOfWeek() ==7)
	{
		AfxMessageBox( "周日休市!" );
		theApp.m_ToolManager.SetActiveTool(pDC,CTool::Dice,NULL);
	}
	else if ((ptPos.x >0 && ptPos.x<125) && (ptPos.y >0 && ptPos.y <40))
	{
		m_ToolState =stInit;	
	}
	//选中一种股票
	else if( (ptPos.x >= 0 && ptPos.x <= 640) && (ptPos.y >= 65 && ptPos.y <= 100) )
	{
		m_ToolState =stFirst;
		m_ID =0;
	}
	else if( (ptPos.x >= 0 && ptPos.x <= 640) && (ptPos.y >= 101 && ptPos.y <= 136) )
	{
		m_ToolState =stFirst;
		m_ID =1;
	}
	//选中股票交易状态卖出(人物是买进)
	else if (	(ptPos.x >125 && ptPos.x<270) 
				&& (ptPos.y >0 && ptPos.y <40) 
				&& m_ToolState ==stFirst  )
	{
		
		if ( theApp.m_Stock[m_ID]->BuseinessType() != stThird)
		{
			m_ToolState =stSecond;
			m_ptCounter.x = ptPos.x;
			m_ptCounter.y = ptPos.y;
			m_CounterState =Move;
		}
		else
		{
			m_ToolState =stInit;
			AfxMessageBox( "股票跌停不能买进!"  );	
		}	
	}
	//选中股票交易状态买回(人物是卖出)
	else if (	(ptPos.x >270 && ptPos.x<418) 
				&& (ptPos.y >0 && ptPos.y <40)
				&& m_ToolState ==stFirst  )
	{
		if (theApp.m_Stock[m_ID]->BuseinessType() != stSecond)
		{
			m_ToolState =stThird;
			m_ptCounter.x = ptPos.x;
			m_ptCounter.y = ptPos.y;
			m_CounterState =Move;	
		}
		else
		{
			m_ToolState =stInit;
			AfxMessageBox( "股票涨停不能卖出!" );	
		}			
	}
	//选中输入器移动区域(显输入数字区载)
	else if ( (m_ToolState == stThird || stSecond == m_ToolState) && IsOnCounterMove(ptPos) )
	{
		m_ptCounter.x = ptPos.x;
		m_ptCounter.y = ptPos.y;
		m_CounterState = Move;
	}
	//选中输入器输入值区域
	else if ( (m_ToolState == stThird || stSecond == m_ToolState) && IsOnCounterNum(ptPos) )
	{
		//1
		if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
		&& (ptPos.y >= m_CounterRect.top +153 && ptPos.y <= m_CounterRect.bottom+1))
		{
			itmpNum=1;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//2
		else if ( (ptPos.x >= m_CounterRect.left+46 && ptPos.x <= m_CounterRect.right-48)
		&& (ptPos.y >= m_CounterRect.top +153 && ptPos.y <= m_CounterRect.bottom+1))
		{
			itmpNum=2;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//3
		else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right)
		&& (ptPos.y >= m_CounterRect.top +153 && ptPos.y <= m_CounterRect.bottom+1))
		{
			itmpNum=3;	
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//4
		else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
		&& (ptPos.y >= m_CounterRect.top +126 && ptPos.y <= m_CounterRect.bottom-28))
		{
			itmpNum=4;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//5
		else if ((ptPos.x >= m_CounterRect.left+46 && ptPos.x <= m_CounterRect.right-48)
		&& (ptPos.y >= m_CounterRect.top +126 && ptPos.y <= m_CounterRect.bottom-28))
		{
			itmpNum=5;	
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//6
		else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right)
		&& (ptPos.y >= m_CounterRect.top +126 && ptPos.y <= m_CounterRect.bottom-28))
		{
			itmpNum=6;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//7
		else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
		&& (ptPos.y >= m_CounterRect.top +100 && ptPos.y <= m_CounterRect.bottom-55))
		{
			itmpNum=7;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//8
		else if ((ptPos.x >= m_CounterRect.left+46 && ptPos.x <= m_CounterRect.right-48)
		&& (ptPos.y >= m_CounterRect.top +100 && ptPos.y <= m_CounterRect.bottom-55))
		{
			itmpNum=8;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//9
		else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right)
		&& (ptPos.y >= m_CounterRect.top +100 && ptPos.y <= m_CounterRect.bottom-55))
		{
			itmpNum=9;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//0
		else if ((ptPos.x >= m_CounterRect.left+47 && ptPos.x <= m_CounterRect.right-47)
		&& (ptPos.y >= m_CounterRect.top +72 && ptPos.y <= m_CounterRect.bottom-82))
		{
			itmpNum=0;
			this->m_iCounterNum = m_iCounterNum *10 + itmpNum;
		}
		//c
		else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-93)
		&& (ptPos.y >= m_CounterRect.top +72 && ptPos.y <= m_CounterRect.bottom-82))
		{
			m_iCounterNum =0;
		}
		//悔上一个数
		else if ((ptPos.x >= m_CounterRect.left + 93 && ptPos.x <= m_CounterRect.right-1)
		&& (ptPos.y >= m_CounterRect.top +72 && ptPos.y <= m_CounterRect.bottom-82))
		{	
			m_iCounterNum = (int)(m_iCounterNum / 10.0);
		}
		//MAX
		else if ((ptPos.x >= m_CounterRect.left+1 && ptPos.x <= m_CounterRect.right-70)
		&& (ptPos.y >= m_CounterRect.top +36 && ptPos.y <= m_CounterRect.bottom-108))
		{
			if (m_ToolState ==stSecond)
			{
				m_iCounterNum  = theApp.m_pPer->GetFund() / theApp.m_Stock[m_ID]->GetStockPrice();
			}
			else if (m_ToolState ==stThird )
			{
				m_iCounterNum =theApp.m_pPer->GetStockAmount(m_ID + 1);
			}
		}	
		//确定
		else if ((ptPos.x >= m_CounterRect.left+71 && ptPos.x <= m_CounterRect.right-1)
		&& (ptPos.y >= m_CounterRect.top +36 && ptPos.y <= m_CounterRect.bottom-108))
		{
			if (m_ToolState ==stSecond)
			{
				//选中股票交易状态卖出(人物是买进)
				if (m_iCounterNum > 0)
				{
					if ( theApp.m_pPer->GetFund() >= (theApp.m_Stock[m_ID]->GetStockPrice() * m_iCounterNum) )
					{
						theApp.m_pPer->AddStock( theApp.m_Stock[m_ID]->GetStockPrice(),(m_ID + 1),m_iCounterNum );
						theApp.m_pPer->ReduceFund( theApp.m_Stock[m_ID]->GetStockPrice() * m_iCounterNum );
						theApp.m_Stock[m_ID]->ReduceStockAmount (m_iCounterNum); 
					}
					else
					{
						AfxMessageBox( "您的存款不够!" );
					}		
				}
				else
				{
					AfxMessageBox( "输入股票数量不对!" );
			//		m_ToolState = stInit;
					m_CounterState =None;
				}
			}
			else if (m_ToolState ==stThird)
			{
				if (m_iCounterNum >0)
				{
					if ( theApp.m_pPer->GetStockAmount(m_ID + 1) >=m_iCounterNum)
					{
						//选中股票交易状态买回(人物是卖出)
						theApp.m_pPer->ReduceStock((m_ID + 1),m_iCounterNum );//人减少股票持有量
						//人加存款
						theApp.m_pPer->AddFund(theApp.m_Stock[m_ID]->GetStockPrice() * m_iCounterNum );
						//股票收购回增加
						theApp.m_Stock[m_ID]->AddStockAmount (m_iCounterNum );
					}
					else
					{
						AfxMessageBox( "股票数量不对!" );
					}
				
				}
				else
				{
					AfxMessageBox( "输入股票数量不对!" );
				//	m_ToolState = stInit;
					m_CounterState =None;
				}
			}
			m_iCounterNum =NULL;
			m_ToolState = stInit;
			m_CounterState =None;
		}
		
	}
	else if (IsOnMe(ptPos) ) //stFour == m_ToolState && 
	{
		m_ToolState =stInit;
		m_CounterState = None;
	}
	theApp.Draw (pDC);
}


void CToolStock::OnLButtonDblClk( CDC * pDC, CPoint ptPos )
{//画股票曲线图
	if( (ptPos.x >= 0 && ptPos.x <= 640) && (ptPos.y >= 65 && ptPos.y <= 100) )
	{
		m_ToolState = stFour;
		m_CounterState =None;
	}
	else if( (ptPos.x >= 0 && ptPos.x <= 640) && (ptPos.y >= 101 && ptPos.y <= 136) )
	{
		m_ToolState = stFour;
		m_CounterState =None;
	}
//在输入器移动区域双击关闭输入器
	else if ((ptPos.x >= m_CounterMoveRect.left && ptPos.x <= m_CounterMoveRect.right)
		&& (ptPos.y >= m_CounterMoveRect.top  && ptPos.y <= m_CounterMoveRect.bottom))
	{
		m_ToolState = stInit;
		m_CounterState =None;
	}
	theApp.Draw (pDC);
}

void CToolStock::OnLButtonUp( CDC * pDC, CPoint ptPos ) 
{
	m_CounterState = None;
}


void CToolStock::OnMouseMove( CDC * pDC, CPoint ptPos ) 
{
	//输入器移动
	if( (m_ToolState == stThird || m_ToolState == stSecond) && Move == m_CounterState )
	{
		m_CounterMoveRect.top += ptPos.y - m_ptCounter.y;
		m_CounterMoveRect.left += ptPos.x - m_ptCounter.x;
		m_CounterMoveRect.bottom = m_CounterMoveRect.top +45;
		m_CounterMoveRect.right = m_CounterMoveRect.left +140; 

		m_ptCounter.x = ptPos.x;
		m_ptCounter.y = ptPos.y;
		
		m_CounterRect.bottom =m_CounterMoveRect.bottom+135;
		m_CounterRect.left =m_CounterMoveRect.left;
		m_CounterRect.top =m_CounterMoveRect.top;
		m_CounterRect.right =m_CounterMoveRect.right;
		theApp.Draw (pDC);
	}
	else
	{
		m_CounterState = None;
	}
	//对移动区域作判断
	if (m_CounterMoveRect.left < 1)
	{
		m_CounterMoveRect.left =1;
	}
	else if (m_CounterMoveRect.right >500)
	{
		m_CounterMoveRect.right=500;
	}
	else if (m_CounterMoveRect.top <1)
	{
		m_CounterMoveRect.top =1;
	}
	else if (m_CounterMoveRect.bottom >300)
	{
		m_CounterMoveRect.bottom =300;
	}
}
//在EXIT时退出STOCK界面
bool CToolStock::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point,m_MyRect) )
	{
		return true;
	}
	return false;
}
//是否在数字区域
bool CToolStock::IsOnCounterMove(CPoint pt)
{
	if((pt.x >= m_CounterMoveRect.left && pt.x <= m_CounterMoveRect.right)
	&& (pt.y >= m_CounterMoveRect.top && pt.y <= m_CounterMoveRect.bottom) )
	{	
		return true;
	}
	return false;	
}
//是否在数字区域
bool CToolStock::IsOnCounterNum(CPoint pt_Num)
{
	if((pt_Num.x >= m_CounterRect.left && pt_Num.x <= m_CounterRect.right)
	&& (pt_Num.y >= m_CounterRect.top+36 && pt_Num.y <= m_CounterRect.bottom) )
	{
		return true;
	}
	return false;	
}
//在EXIT时退出STOCK界面
int CToolStock::ToolName( CPoint point )
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

//右键退出未做
void CToolStock::OnRButtonDown( CDC * pDC, CPoint point )
{

}

