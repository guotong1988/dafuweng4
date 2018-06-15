//Download by http://www.NewXing.com
// Per.cpp: implementation of the CPer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Per.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPer::CPer( CDC *pDC, int nName , CPoint point )
{
	m_ptCoordinate.y = point.y;
	m_ptCoordinate.x = point.x;

	m_MyRect.bottom = m_ptCoordinate.y + 60 ;
	m_MyRect.top =	m_ptCoordinate.y ;
	m_MyRect.right = m_ptCoordinate.x + 60 ;
	m_MyRect.left = m_ptCoordinate.x ;

	//给影子分派DC
	m_PershadowDC[0].CreateCompatibleDC( pDC );
	m_PershadowDC[1].CreateCompatibleDC( pDC );
	m_PershadowDC[2].CreateCompatibleDC( pDC );
	m_PershadowDC[3].CreateCompatibleDC( pDC );

	//给有色画面分派DC
	m_PerDC[0].CreateCompatibleDC( pDC );
	m_PerDC[1].CreateCompatibleDC( pDC );
	m_PerDC[2].CreateCompatibleDC( pDC );
	m_PerDC[3].CreateCompatibleDC( pDC );

	
	m_SmallDC.CreateCompatibleDC(pDC);

	switch(nName)
	{
	case ZhangJun:
		m_Pershadowbmp[0].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\m0.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Pershadowbmp[1].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\m1.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Pershadowbmp[2].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\m2.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Pershadowbmp[3].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\m3.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );

		m_Perbmp[0].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\p0.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Perbmp[1].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\p1.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Perbmp[2].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\p2.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Perbmp[3].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\p3.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\yp.bmp", IMAGE_BITMAP, 15 , 
			15 , LR_LOADFROMFILE );
		break;
	case KongFanYin:
		m_Pershadowbmp[0].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mm0.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Pershadowbmp[1].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mm1.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Pershadowbmp[2].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mm2.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Pershadowbmp[3].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mm3.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );

		m_Perbmp[0].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mp0.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Perbmp[1].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mp1.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Perbmp[2].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mp2.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		m_Perbmp[3].m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\mp3.bmp", IMAGE_BITMAP, 480,60, LR_LOADFROMFILE );
		
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( 
			NULL, "img\\ymp.bmp", IMAGE_BITMAP, 15 , 
			15 , LR_LOADFROMFILE );
		break;
	}
	m_PershadowDC[0].SelectObject(m_Pershadowbmp[0]);
	m_PershadowDC[1].SelectObject(m_Pershadowbmp[1]);
	m_PershadowDC[2].SelectObject(m_Pershadowbmp[2]);
	m_PershadowDC[3].SelectObject(m_Pershadowbmp[3]);

	m_PerDC[0].SelectObject( m_Perbmp[0] );
	m_PerDC[1].SelectObject( m_Perbmp[1] );
	m_PerDC[2].SelectObject( m_Perbmp[2] );
	m_PerDC[3].SelectObject( m_Perbmp[3] );
	
	m_SmallDC.SelectObject( m_SmallBitmap );

	m_Name = nName;
	m_WalkNum = 0;
	m_nStep = 0;
	m_Way = rand()%2;
	m_Cash = 100000;
	m_Fund = 100000;
	m_Loan = 0;
	m_Point = 0;
	m_SafetyDate = 0;
	m_HouseNum = 0;
	m_Build = 0;
	m_LandNum = 0;
	m_nOrientation = 2;
	m_God = NULL;
	m_PageNum = 1;
	m_iType = 0;
	int nJ(0);
	//清空所有道具指针
	for ( int nI(0) ; nI < 15 ; nI++ )
	{
		m_Item[nI].nTpye = 0;
		for(  nJ = 0 ; nJ < 9 ; nJ++ )
		{
			m_Item[nI].pItem[nJ] = NULL;	
		}
	}
	//清空所有卡片指针
	for (int nI = 0 ; nI < 15 ; nI++ )
	{
		m_Card[nI] = NULL;
	}
	m_CompanyNum = 0;
	for(int nI = 0 ; nI < 100 ; nI++ )
	{
		m_Gelbe[nI].Sport = 0;
		m_Gelbe[nI].Develop = 0;	
		m_Gelbe[nI].Value = 0;
	}
	for(int nI = 0 ; nI < 12 ; nI++ )
	{
		m_Stock[nI].StockName = 0;
		m_Stock[nI].StockMoney = 0;
		m_Stock[nI].StockNum = 0;
	}
}

CPer::~CPer()//析构
{
	m_PerDC[0].DeleteDC();
	m_PerDC[1].DeleteDC();
	m_PerDC[2].DeleteDC();
	m_PerDC[3].DeleteDC();

	m_PershadowDC[0].DeleteDC();
	m_PershadowDC[1].DeleteDC();
	m_PershadowDC[2].DeleteDC();
	m_PershadowDC[3].DeleteDC();

	
	m_SmallDC.DeleteDC();

	m_Pershadowbmp[0].DeleteObject();
	m_Pershadowbmp[1].DeleteObject();
	m_Pershadowbmp[2].DeleteObject();
	m_Pershadowbmp[3].DeleteObject();

	m_Perbmp[0].DeleteObject();
	m_Perbmp[1].DeleteObject();
	m_Perbmp[2].DeleteObject();
	m_Perbmp[3].DeleteObject();

	m_SmallBitmap.DeleteObject();
}

//增加现金
void CPer::AddCash(int nMoney)
{
	m_Cash += nMoney;
}

//减少现金
void CPer::ReduceCash(int nMoney)
{
	m_Cash -= nMoney;
}

//增加存款
void CPer::AddFund(int nMoney)
{
	m_Fund += nMoney;
}

//减少存款
void CPer::ReduceFund(int nMoney)
{
	m_Fund -= nMoney;
}

//增加总产值
void CPer::AddValue(int nMoney)
{
	m_Value += nMoney;
}

//减少总产值
void CPer::ReduceValue(int nMoney)
{
	m_Value -=  nMoney;
}

//增加贷款
void CPer::AddLoan(int nMoney)
{
	m_Loan += nMoney;
}

//减少贷款
void CPer::ReduceLoan(int nMoney)
{
	m_Loan -= nMoney;
}

//增加点数
void CPer::AddPoint(int nPoint)
{
	m_Point += nPoint;
}

//减少点数
void CPer::ReducePoint(int nPoint)
{
	m_Point -= nPoint;
}

//改变步数
void CPer::SplashDice( CDC * pDC, int nWalkNum )
{
	m_nState = Going;
	theApp.m_ToolManager.SetActiveTool( pDC, CTool::PerMove,NULL);
	if( m_iType == 1 )
	{
		m_WalkNum = 0;
	}
	else if( m_iType == 3 )
	{
		m_WalkNum = 1;
	}
	else if( m_iType == 0 )
	{
		m_WalkNum = nWalkNum;
	}
}

//增加土地数目
void CPer::AddLandNum( CEntityNode * pNode )
{
	m_LandNum++;
	for( int nI(0) ; nI < 100 ; nI++ )
	{
		if( m_Gelbe[nI].Sport == 0 )
		{
			m_Gelbe[nI].Sport = pNode->m_WayName;
			m_Gelbe[nI].Develop = pNode->m_pGlebe->GetLevel();	
			m_Gelbe[nI].Value = pNode->m_pGlebe->GetValue();
			break;
		}
	    m_PageCount = nI/10 + 1;
	}
}

//减少土地数目
void CPer::ReduceLandNum()
{
	m_LandNum--;
}

//增加房屋数目
void CPer::AddHouseNum()
{
	m_HouseNum++;
	for( int nI(0) ; nI < 100 ; nI++ )
	{
			m_Gelbe[nI].Sport = 0;
			m_Gelbe[nI].Develop = 0;
			m_Gelbe[nI].Value = 0;
	}
	theApp.m_EntityRoadList.SetPerGlebe( m_Gelbe , m_Name );
}

//减少房屋数目
void CPer::ReduceHouseNum()
{
	m_HouseNum--;
}

//购买卡片
void CPer::AddCard(CCard &card)
{
	for (int i(0); m_Card[i] != NULL && i < 15; i++)
	{
		if (i < 15)
		{
			m_Card[i] = &card;
		}
		else
		{
			AfxMessageBox("您的卡片栏已满!", MB_OK);
		}
	}
}

//使用卡片
CCard * CPer::ReduceCard(int nI)
{
	CCard * pCard = NULL;

	int nK(0);

	for( int nS(0) ; nS < 15 ; nS++ )
	{
		if(m_Card[nS] != NULL)
		{
			nK++;
			if(nK == nI)
			{
				break;
			}
		}
	
		if( m_Card != NULL )
		{
			pCard = m_Card[nS];
			m_Card[nS] = NULL;
			return pCard;
		}
	}
	return NULL;
}

//购买道具
void CPer::AddItem( CProperty& item )
{
	int nJ(0),nKey(0);
	for ( int nI(0) ; nI < 15 && 0 != m_Item[nI].nTpye ; nI++ )
	{
		if( item.GetID() == m_Item[nI].nTpye )
		{
			for(  nJ = 0 ; m_Item[nI].pItem[nJ] != NULL && nJ < 9 ; nJ++ )
			{}
			if( nJ < 9 )
			{
				m_Item[nI].pItem[nJ] = &item;
				nKey = 1;
				break;
			}
		}
	
		if( nI < 15 && nKey == 0 )
		{
			m_Item[nI].nTpye = item.GetID();
			m_Item[nI].pItem[0] = &item;
		}
		else if( nKey == 0 )
		{
			AfxMessageBox("道具栏已满!");
		}
	}
}

//使用道具
CProperty* CPer::ReduceItem( int nType )
{
	CProperty *pProperty = NULL;
	int nJ(0),nK(0);
	for( int nI(0) ; nI < 15 ; nI++ )
	{
		if(m_Item[nI].nTpye != 0)
		{
			nK++;
			if(nK == nType)
			{
				break;
			}
		}
	
	for(  nJ = 0 ; nJ < 9 && m_Item[nI].pItem[nJ] != NULL ; nJ++ )
	{	
	
		if( nJ - 1 > 0 )
		{
			pProperty = m_Item[nI].pItem[nJ - 1];
			m_Item[nI].pItem[nJ-1] = NULL;
			return pProperty;
		}
		else if( nJ - 1 == 0 )
		{
			pProperty = m_Item[nI].pItem[nJ - 1];
			m_Item[nI].pItem[nJ-1] = NULL;
			m_Item[nI].nTpye = 0;
			return pProperty;
		}
	}
	}
	return NULL;

}



//神明付身
void CPer::SetGod( CEntity & god )
{
	delete m_God;
	m_God = NULL;
	m_God = &god;
}

//神明离开
void CPer::LeaveGod()
{
	delete m_God;
	m_God = NULL;	
}

//购入股票
void CPer::AddStock(int nMoney,int nName,int nNum)
{
	//遍例股票数组
	for (int i(0);
		m_Stock[i].StockName != nName  && i < 12;
		i++){

		//当找到与以前所买的股票相同的股票时
		if (m_Stock[i].StockName == nName)
		{
			m_Stock[i].StockMoney = ((m_Stock[i].StockMoney * m_Stock[i].StockNum)
				+ (nMoney * nNum)) / (m_Stock[i].StockNum + nNum);
			m_Stock[i].StockNum += nNum;
		}

		//当没有买过该股票时
		if (m_Stock[i].StockName != nName)
		{
			//遍例股票数组
			for (int i(0);
				m_Stock[i].StockName != 0 && i < 12;
				i++);

			//如果第i位为空时,将买入股票添加进人物股票结构中
			if (m_Stock[i].StockName == 0)
			{
				m_Stock[i].StockName = nName;
				m_Stock[i].StockMoney = nMoney;
				m_Stock[i].StockNum += nNum;
			}
		}
	}
}

//卖出股票
void CPer::ReduceStock(int nName,int nNum)
{
	for (int i(0);
		m_Stock[i].StockName != nName && i < 12;
		i++){
		if (m_Stock[i].StockNum > 0)
		{
			m_Stock[i].StockNum -= nNum;
		}
		else
		{
			m_Stock[i].StockName = 0;
			m_Stock[i].StockMoney = 0;
		}
	}
}

//改变住院,坐牢天数
void CPer::ChangeDays(int nID ,int nDay)
{
	m_iType = nID;
	m_Days = nDay;
}

//改变方向
void CPer::ChangeWay()
{
	if( m_Way == Next )
	{
		m_Way = Up;
	}
	else if( m_Way == Up )
	{
		m_Way = Next;
	}
}

//住院
void CPer::InHospital()
{
	m_Days--;
}

//出院
void CPer::OutHospital()
{

}

//坐牢
void CPer::InGaol()
{
	m_Days--;
}
//出狱
void CPer::OutGaol()
{

}

//住旅馆
void CPer::InHotel()
{
	m_Days--;
}

//出旅馆
void CPer::OutHotel()
{

}

//行走Next,Up,Hospital,Goal,Hotel
void CPer::Move( CDC * pDC )
{
	CPoint pt;
	int nI(0) ,nJ(0);
	CEntityNode * pENTmp = NULL;
	CString strInfo;

	switch( m_nState )
	{
	case Going:
		if( (m_ptCoordinate.x > m_pEntityNode->m_ptCoordinate.x - 1
			&& m_ptCoordinate.x < m_pEntityNode->m_ptCoordinate.x + 1
			&& m_ptCoordinate.y > m_pEntityNode->m_ptCoordinate.y - 1
			&& m_ptCoordinate.y < m_pEntityNode->m_ptCoordinate.y + 1 )
			|| m_nStep > 6 )
		{
			m_nStep = 0;
			m_ptCoordinate.x = m_pEntityNode->m_ptCoordinate.x;
			m_ptCoordinate.y = m_pEntityNode->m_ptCoordinate.y;
			m_MyRect.bottom = m_ptCoordinate.y + 60 ;
			m_MyRect.top =	m_ptCoordinate.y ;
			m_MyRect.right = m_ptCoordinate.x + 60 ;
			m_MyRect.left = m_ptCoordinate.x ;
			MoveOnNode( pDC );
		}
		else
		{
			switch( m_Way )
			{
			case Next:
				m_ptCoordinate.x += 
					(int)((m_pEntityNode->m_ptCoordinate.x - 
					m_pEntityNode->m_pENPrevious->m_ptCoordinate.x) 
					/ 8.0);
				m_ptCoordinate.y += 
					(int)((m_pEntityNode->m_ptCoordinate.y - 
					m_pEntityNode->m_pENPrevious->m_ptCoordinate.y) 
					/ 8.0);
				m_MyRect.bottom = m_ptCoordinate.y + 60 ;
				m_MyRect.top =	m_ptCoordinate.y ;
				m_MyRect.right = m_ptCoordinate.x + 60 ;
				m_MyRect.left = m_ptCoordinate.x ;
				break;
			case Up:
				m_ptCoordinate.x += 
					(int)((m_pEntityNode->m_ptCoordinate.x - 
					m_pEntityNode->m_pENNext->m_ptCoordinate.x) 
					/ 8.0);
				m_ptCoordinate.y += 
					(int)((m_pEntityNode->m_ptCoordinate.y - 
					m_pEntityNode->m_pENNext->m_ptCoordinate.y) 
					/ 8.0);
				m_MyRect.bottom = m_ptCoordinate.y + 60 ;
				m_MyRect.top =	m_ptCoordinate.y ;
				m_MyRect.right = m_ptCoordinate.x + 60 ;
				m_MyRect.left = m_ptCoordinate.x ;
				break;
			case Hospital:
				//到医院
				break;
			case Goal:
				//到监狱
				break;
			case Hotel:
				//到旅馆
				break;
			}
			//步数增加*
			m_nStep++;
			//移动大、小地图*
			pt.x = m_ptCoordinate.x - 220 + 30;
			pt.y = m_ptCoordinate.y - 220 - 10;
			theApp.m_BigMap.MoveBigMap( pDC, pt );
			pt.x = (int)(m_ptCoordinate.x * 5.0 / 66.0) + 440;
			pt.y = (int)(m_ptCoordinate.y / 11.0) + 280;
			theApp.m_SmallMap.MoveRectangle( pt );

			theApp.Draw( pDC );
		}
		break;
	case Invest://交易
		m_nState = Stop;
		//接到神仙
		if( NULL != this->m_pEntityNode->m_pGod )
		{
			SetGod(* (m_pEntityNode->m_pGod));
			this->m_pEntityNode->m_pGod = NULL;
			m_God->GetGod();
		}
		if( NULL != m_God && m_God->IsCard() == 2 )
		{
			m_God->PropertyIsBeUsed( m_Name );
		}
		//神仙产生的功能

		if( NULL != this->m_pEntityNode->m_pGlebe )
		{
			
			if( NoOne == m_pEntityNode->m_pGlebe->Owner() )
			{
				//卖地
				nI = m_pEntityNode->m_pGlebe->GetValue() * theApp.m_Date.GetINP();
				strInfo.Format( "地价%d ,是否购买?", nI );
				if(AfxMessageBox( strInfo, MB_OKCANCEL ) == IDOK )
				{
					ReduceCash( nI );
					m_pEntityNode->m_pGlebe->Buy( m_Name );
					AddLandNum( m_pEntityNode );
				}
			}
			else if( m_Name == m_pEntityNode->m_pGlebe->Owner() )
			{
				//升级
				nI = m_pEntityNode->m_pGlebe->GetUpGradeValue() * theApp.m_Date.GetINP();
				strInfo.Format( "升级费用%d ,是否升级?", nI );
				if(AfxMessageBox( strInfo, MB_OKCANCEL ) == IDOK )
				{
					ReduceCash( nI );
					m_pEntityNode->m_pGlebe->UpGrade();
					AddHouseNum();
				}
			}
			else
			{
				//付租金
				nI = m_pEntityNode->m_pGlebe->GetValue() * theApp.m_Date.GetINP();
				for( pENTmp = m_pEntityNode->m_pENNext;
						NULL != pENTmp->m_pGlebe;
						pENTmp = pENTmp->m_pENNext )
				{
					if( m_pEntityNode->m_pGlebe->Owner() ==
						pENTmp->m_pGlebe->Owner() )
					{
						nI += pENTmp->m_pGlebe->GetValue() * theApp.m_Date.GetINP();
					}
				}
				for( pENTmp = m_pEntityNode->m_pENPrevious;
						NULL != pENTmp->m_pGlebe;
						pENTmp = pENTmp->m_pENPrevious )
				{
					if( m_pEntityNode->m_pGlebe->Owner() ==
						pENTmp->m_pGlebe->Owner() )
					{
						nI += pENTmp->m_pGlebe->GetValue() * theApp.m_Date.GetINP();
					}
				}
				ReduceCash( nI );
				strInfo.Format( "付租金%d", nI );
				AfxMessageBox( strInfo, MB_ICONINFORMATION);
				for( nJ = 0; nJ < 2; nJ++ )
				{
					if( m_pEntityNode->m_pGlebe->Owner() ==
							theApp.m_pAllPer[nJ]->m_Name )
					{
						theApp.m_pAllPer[nJ]->AddCash( nI );
					}
				}
			}
		}
		
		if( theApp.m_pPer == theApp.m_pAllPer[0] )
		{
			//判断是否住院
			if( theApp.m_pAllPer[1]->m_iType == 4 )
			{
				theApp.m_Date.DayPass( pDC );//过一天
				theApp.m_pAllPer[1]->m_Days--;
				if( theApp.m_pAllPer[1]->m_Days <= 0)
				{
					theApp.m_pAllPer[1]->m_iType = 0;
					theApp.m_pAllPer[1]->m_Days = 0;
				}
			}
			else if( theApp.m_pAllPer[1]->m_iType != 4 )
			{
				theApp.m_pPer = theApp.m_pAllPer[1];
			}
		}
		else
		{
			theApp.m_Date.DayPass( pDC );//过一天
			theApp.m_pPer = theApp.m_pAllPer[0];
		}


		theApp.m_pPer->m_nState = Ready;
		//移动大、小地图*
		pt.x = theApp.m_pPer->m_ptCoordinate.x - 220 + 30;
		pt.y = theApp.m_pPer->m_ptCoordinate.y - 220 - 10;
		theApp.m_BigMap.MoveBigMap( pDC, pt );
		pt.x = (int)(theApp.m_pPer->m_ptCoordinate.x * 5.0 / 66.0) + 440;
		pt.y = (int)(theApp.m_pPer->m_ptCoordinate.y / 11.0) + 280;
		theApp.m_SmallMap.MoveRectangle( pt );
		theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice ,NULL);

		theApp.Draw( pDC );
		break;
	}
	if( NULL != m_God && m_God->IsWalkNum() == false )
	{
		m_God->LeaveGod();
		LeaveGod();
	}
}

void CPer::MoveOnHit( CDC * pDC )
{
	int nI;

	switch( m_nState )
	{
	case HitGoing:
		if( (m_ptCoordinate.x > m_pEntityNode->m_ptCoordinate.x - 1
			&& m_ptCoordinate.x < m_pEntityNode->m_ptCoordinate.x + 1
			&& m_ptCoordinate.y > m_pEntityNode->m_ptCoordinate.y - 1
			&& m_ptCoordinate.y < m_pEntityNode->m_ptCoordinate.y + 1 )
			|| m_nStep > 6 )
		{
			m_nStep = 0;
			m_ptCoordinate.x = m_pEntityNode->m_ptCoordinate.x;
			m_ptCoordinate.y = m_pEntityNode->m_ptCoordinate.y;
			m_MyRect.bottom = m_ptCoordinate.y + 60 ;
			m_MyRect.top =	m_ptCoordinate.y ;
			m_MyRect.right = m_ptCoordinate.x + 60 ;
			m_MyRect.left = m_ptCoordinate.x ;
		}
		else
		{
			switch( m_Way )
			{
			case Next:
				m_ptCoordinate.x += 
					(int)((m_pEntityNode->m_ptCoordinate.x - 
					m_pEntityNode->m_pENPrevious->m_ptCoordinate.x) 
					/ 8.0);
				m_ptCoordinate.y += 
					(int)((m_pEntityNode->m_ptCoordinate.y - 
					m_pEntityNode->m_pENPrevious->m_ptCoordinate.y) 
					/ 8.0);
				m_MyRect.bottom = m_ptCoordinate.y + 60 ;
				m_MyRect.top =	m_ptCoordinate.y ;
				m_MyRect.right = m_ptCoordinate.x + 60 ;
				m_MyRect.left = m_ptCoordinate.x ;
				break;
			case Up:
				m_ptCoordinate.x += 
					(int)((m_pEntityNode->m_ptCoordinate.x - 
					m_pEntityNode->m_pENNext->m_ptCoordinate.x) 
					/ 8.0);
				m_ptCoordinate.y += 
					(int)((m_pEntityNode->m_ptCoordinate.y - 
					m_pEntityNode->m_pENNext->m_ptCoordinate.y) 
					/ 8.0);
				m_MyRect.bottom = m_ptCoordinate.y + 60 ;
				m_MyRect.top =	m_ptCoordinate.y ;
				m_MyRect.right = m_ptCoordinate.x + 60 ;
				m_MyRect.left = m_ptCoordinate.x ;
				break;
			case Hospital:
				//到医院
				break;
			case Goal:
				//到监狱
				break;
			case Hotel:
				//到旅馆
				break;
			}
			//步数增加*
			m_nStep++;
		}
		break;
	case HitInvest:
		m_nState = Stop;
		if( NULL != this->m_pEntityNode->m_pGlebe )
		{
			
			if( NoOne == m_pEntityNode->m_pGlebe->Owner() )
			{
			}
			else if( m_Name == m_pEntityNode->m_pGlebe->Owner() )
			{
			}
			else
			{
				//有问题，进不来*
				ReduceCash( m_pEntityNode->m_pGlebe->GetValue() );
				for( nI = 0; nI < 2; nI++ )
				{
					if( m_pEntityNode->m_pGlebe->Owner() ==
							theApp.m_pAllPer[nI]->m_Name )
					{
						theApp.m_pAllPer[nI]->AddCash(
							m_pEntityNode->m_pGlebe->GetValue() );
					}
				}
			}
		}
		break;
	}
}

void CPer::MoveOnHitNode( CDC * pDC )
{
	switch(m_Way)
	{
	case Next:
		m_pEntityNode = m_pEntityNode->m_pENNext;
		if( NULL != m_pEntityNode->m_pPer )
		{
			m_pEntityNode->m_pPer->MoveOnHitNode( pDC );
			m_pEntityNode->m_pPer->m_nState = HitGoing;
		}
		m_pEntityNode->m_pPer = this;
		break;
	case Up:
		m_pEntityNode = m_pEntityNode->m_pENPrevious;
		if( NULL != m_pEntityNode->m_pPer )
		{
			m_pEntityNode->m_pPer->MoveOnHitNode( pDC );
			m_pEntityNode->m_pPer->m_nState = HitGoing;
		}
		m_pEntityNode->m_pPer = this;
		break;
	case Hospital:
		//到医院
		break;
	case Goal:
		//到监狱
		break;
	case Hotel:
		//到旅馆
		break;
	}
	m_nState = HitInvest;
}

void CPer::MoveOnNode( CDC * pDC )
{
	int nI(0), nJ(0);

	if( m_WalkNum > 0 )
	{
		switch(m_Way)
		{
		case Next:
			m_pEntityNode->m_pPer = m_pEntityNode->m_pSecondPer;
			m_pEntityNode->m_pSecondPer = NULL;

			//设置贴图方向*
			if( m_pEntityNode->m_pENNext->m_ptCoordinate.x
					> m_pEntityNode->m_ptCoordinate.x )
			{
				nI = m_pEntityNode->m_pENNext->m_ptCoordinate.x
					- m_pEntityNode->m_ptCoordinate.x;

				if( m_pEntityNode->m_pENNext->m_ptCoordinate.y
						> m_pEntityNode->m_ptCoordinate.y )
				{
					nJ = m_pEntityNode->m_pENNext->m_ptCoordinate.y
						- m_pEntityNode->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 2;
					}
					else
					{
						m_nOrientation = 1;
					}
				}
				else
				{
					nJ = m_pEntityNode->m_ptCoordinate.y
						- m_pEntityNode->m_pENNext->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 0;
					}
					else
					{
						m_nOrientation = 1;
					}
				}
			}
			else
			{
				nI = m_pEntityNode->m_ptCoordinate.x
					- m_pEntityNode->m_pENNext->m_ptCoordinate.x;

				if( m_pEntityNode->m_pENNext->m_ptCoordinate.y
						> m_pEntityNode->m_ptCoordinate.y )
				{
					nJ = m_pEntityNode->m_pENNext->m_ptCoordinate.y
						- m_pEntityNode->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 2;
					}
					else
					{
						m_nOrientation = 3;
					}
				}
				else
				{
					nJ = m_pEntityNode->m_ptCoordinate.y
						- m_pEntityNode->m_pENNext->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 0;
					}
					else
					{
						m_nOrientation = 3;
					}
				}
			}//结束*

			m_pEntityNode = m_pEntityNode->m_pENNext;
			if( 1 == m_WalkNum )
			{
				if( NULL != m_pEntityNode->m_pPer )
				{
					m_pEntityNode->m_pPer->m_Way = m_Way;
					m_pEntityNode->m_pPer->m_nOrientation = m_nOrientation;
					m_pEntityNode->m_pPer->MoveOnHitNode( pDC );
					m_pEntityNode->m_pPer->m_nState = HitGoing;
				}
			}
			else
			{
				m_pEntityNode->m_pSecondPer = m_pEntityNode->m_pPer;
			}
			m_pEntityNode->m_pPer = this;
			break;
		case Up:
			m_pEntityNode->m_pPer = m_pEntityNode->m_pSecondPer;
			m_pEntityNode->m_pSecondPer = NULL;
			//设置贴图方向*
			if( m_pEntityNode->m_pENPrevious->m_ptCoordinate.x
					> m_pEntityNode->m_ptCoordinate.x )
			{
				nI = m_pEntityNode->m_pENPrevious->m_ptCoordinate.x
					- m_pEntityNode->m_ptCoordinate.x;

				if( m_pEntityNode->m_pENPrevious->m_ptCoordinate.y
						> m_pEntityNode->m_ptCoordinate.y )
				{
					nJ = m_pEntityNode->m_pENPrevious->m_ptCoordinate.y
						- m_pEntityNode->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 2;
					}
					else
					{
						m_nOrientation = 1;
					}
				}
				else
				{
					nJ = m_pEntityNode->m_ptCoordinate.y
						- m_pEntityNode->m_pENPrevious->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 0;
					}
					else
					{
						m_nOrientation = 1;
					}
				}
			}
			else
			{
				nI = m_pEntityNode->m_ptCoordinate.x
					- m_pEntityNode->m_pENPrevious->m_ptCoordinate.x;

				if( m_pEntityNode->m_pENPrevious->m_ptCoordinate.y
						> m_pEntityNode->m_ptCoordinate.y )
				{
					nJ = m_pEntityNode->m_pENPrevious->m_ptCoordinate.y
						- m_pEntityNode->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 2;
					}
					else
					{
						m_nOrientation = 3;
					}
				}
				else
				{
					nJ = m_pEntityNode->m_ptCoordinate.y
						- m_pEntityNode->m_pENPrevious->m_ptCoordinate.y;

					if( nJ >= nI )
					{
						m_nOrientation = 0;
					}
					else
					{
						m_nOrientation = 3;
					}
				}
			}//结束*

			m_pEntityNode = m_pEntityNode->m_pENPrevious;
			if( 1 == m_WalkNum )
			{
				if( NULL != m_pEntityNode->m_pPer )
				{
					m_pEntityNode->m_pPer->m_Way = m_Way;
					m_pEntityNode->m_pPer->m_nOrientation = m_nOrientation;
					m_pEntityNode->m_pPer->MoveOnHitNode( pDC );
					m_pEntityNode->m_pPer->m_nState = HitGoing;
				}
			}
			else
			{
				m_pEntityNode->m_pSecondPer = m_pEntityNode->m_pPer;
			}
			m_pEntityNode->m_pPer = this;
			break;
		case Hospital:
			//到医院
			break;
		case Goal:
			//到监狱
			break;
		case Hotel:
			//到旅馆
			break;
		}
		m_WalkNum--;
		
		if( NULL != m_God )
		{
			if( m_God->IsWalkNum() == true )
			{
				m_God->ReduceWalkNum();
			}
		}
	}
	else
	{
		m_nState = Invest;
		m_WalkNum = 0;
	}
	if( m_Days > 0 && m_iType != 4 )
	{
		m_Days--;
	}
	if( m_Days <= 0 )
	{
		m_iType = 0;
		m_Days = 0;
	}
}

//获得节点
void CPer::GetEntityNode(CEntityNode & JieDian)
{
	m_pEntityNode = &JieDian;
}

//盖房子
void CPer::BiuldHouse()
{
	//调用结点盖房子方法
}

//拆房子
void CPer::DestroyHouse()
{
	//调用结点拆房子方法
}

//enum Type{Ready,Going,Stop,None}
void CPer::Draw( CDC * pDC )
{
	if( m_iType == 4 )
	{}
	else
	{
		//画影子
		theApp.m_TmpScreenDC.BitBlt(
			m_ptCoordinate.x - theApp.m_BigMap.m_ptBigMapCoordinate.x,
			m_ptCoordinate.y - theApp.m_BigMap.m_ptBigMapCoordinate.y,
			60, 60, & m_PershadowDC[m_nOrientation], m_nStep*60, 0, SRCAND);
		//图颜色
		theApp.m_TmpScreenDC.BitBlt(
			m_ptCoordinate.x - theApp.m_BigMap.m_ptBigMapCoordinate.x,
			m_ptCoordinate.y - theApp.m_BigMap.m_ptBigMapCoordinate.y,
			60, 60, & m_PerDC[m_nOrientation], m_nStep*60, 0, SRCPAINT);
	}
}

void CPer::PerShowInfo(CRect &rect)
{
	char str[10];
	int nLen(0);
	
	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		30,
		80,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		30,
		80,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	if( m_God != NULL )
	{
		m_God->DrawOnPerInfo();
	}

	//显示现金
	sprintf(str,"%d",m_Cash);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 320 - nLen * 8 , rect.top + 80 , str);

	//显示存款
	sprintf(str,"%d",m_Fund);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 320 - nLen * 8 , rect.top + 130 , str);

	//显示贷款
	sprintf(str,"%d",m_Loan);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 320 - nLen * 8 , rect.top + 175 , str);

	//显示总资产
	sprintf(str,"%d", (m_Cash + m_Fund) );
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 320 - nLen * 8 , rect.top + 225 , str);

	//显示股票
	int nMoney(0);
	for( int nI(0) ; m_Stock[nI].StockName != 0 && nI < 12 ; nI++ )
	{
		nMoney = nMoney + 
			(int)(m_Stock[nI].StockMoney * m_Stock[nI].StockNum);
	}
	sprintf( str,"%d", nMoney );
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 600 - nLen * 8 , rect.top + 80 , str);

	//显示点券
	sprintf(str,"%d",m_Point);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 600 - nLen * 8 , rect.top + 130 , str);

	//显示投保天数
	sprintf(str,"%d",m_SafetyDate);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 600 - nLen * 8 , rect.top + 175 , str);

	//显示企业数量
	sprintf(str,"%d",m_CompanyNum);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 600 - nLen * 8 , rect.top + 225 , str);


	//显示土地数量
	sprintf(str,"%d",m_LandNum);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 250 - nLen * 8 , rect.top + 290 , str);

	//显示连锁店数量
	sprintf(str,"%d",m_HouseNum + m_Build);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 250 - nLen * 8 , rect.top + 340 , str);

	//显示房屋总数
	sprintf(str,"%d",m_HouseNum);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 250 - nLen * 8 , rect.top + 385 , str);

	//显示设施数量
	sprintf(str,"%d",m_Build);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut(rect.left + 250 - nLen * 8 , rect.top + 430 , str);

	CPoint point;
	
	point.x = rect.left + 270 , point.y = rect.top + 265;

	ShowPropertyInfo( point , 0 );

	point.x = rect.left + 280 , point.y = rect.top + 375;

	ShowCardInfo( point , 0 );
}

void CPer::PerStockInfo(CRect &rect)
{
	char str[10];
	int nLen(0);

	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		30,
		80,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		30,
		80,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	if( m_God != NULL )
	{
		m_God->DrawOnPerInfo();
	}

	//显示股票购买情况
	for( int nI(0) ; nI < 12 && m_Stock[nI].StockName != 0 ; nI++ )
	{
		//显示公司名称
		switch(m_Stock[nI].StockName)
		{
		case 0:
			break;
		case 1:
			theApp.m_TmpScreenDC.TextOut(rect.left + 170 , 
									rect.top + 95 + nI * 32 , "齐齐实业");
			//显示购入数量
			sprintf(str,"%d",m_Stock[nI].StockNum);
			nLen = strlen(str);
			theApp.m_TmpScreenDC.TextOut(rect.left + 320 , rect.top + 95 + nI * 32 , str);

			//显示价格
			sprintf( str,"%d", theApp.m_Stock[nI]->GetStockPrice() * m_Stock[nI].StockNum );
			nLen = strlen(str);
			theApp.m_TmpScreenDC.TextOut(rect.left + 460 , rect.top + 95 + nI * 32 , str);
			break;
		case 2:
			theApp.m_TmpScreenDC.TextOut(rect.left + 170 , 
									rect.top + 95 + nI * 32 , "李氏企业");
			//显示购入数量
			sprintf(str,"%d",m_Stock[nI].StockNum);
			nLen = strlen(str);
			theApp.m_TmpScreenDC.TextOut(rect.left + 320 , rect.top + 95 + nI * 32 , str);

			//显示价格
			sprintf( str,"%d", theApp.m_Stock[nI]->GetStockPrice() * m_Stock[nI].StockNum );
			nLen = strlen(str);
			theApp.m_TmpScreenDC.TextOut(rect.left + 460 , rect.top + 95 + nI * 32 , str);
			break;
		}		
	}
}

void CPer::PerGlebeInfo(CRect &rect)
{
	CString str;
	int nLen(0);

	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		30,
		80,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		30,
		80,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	if( m_God != NULL )
	{
		m_God->DrawOnPerInfo();
	}

	for( int nI(0) ; nI < 100 && m_Gelbe[nI].Sport != 0 ; nI++ )
	{
		if( nI - 10 * (m_PageNum - 1) >= 0 && nI < ( 10 * m_PageNum ) )
		{
			//显示房屋名称
			switch(m_Gelbe[nI % ( 10 * m_PageNum )].Sport)
			{
			case 0:
				str = "No Name";
				break;
			case 1:
				str = "台北路";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 128 , rect.top + 140 + ( nI % 10 ) * 32 , str);
				break;
			case 2:
				str = "高雄路";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 128 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			}

			//显示发展状况
			switch(m_Gelbe[nI % ( 10 * m_PageNum )].Develop)
			{
			case 0:
				str = "土地";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 250 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			case 1:
				str = "草房";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 250 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			case 2:
				str = "平房";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 250 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			case 3:
				str = "别墅";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 250 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			case 4:
				str = "大厦";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 250 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			case 5:
				str = "摩天大楼";
				nLen = strlen(str);
				theApp.m_TmpScreenDC.TextOut(rect.left + 250 , rect.top + 140 + ( nI % 10 ) * 32  , str);
				break;
			}

			//显示价值
			str.Format("%d",m_Gelbe[ nI % ( 10 * m_PageNum ) ].Value);
			nLen = strlen(str);
			theApp.m_TmpScreenDC.TextOut(rect.left + 340 , rect.top + 140 + ( nI % 10 ) * 32  , str);
			
			str.Format("%d",m_Gelbe[nI].Value);
			nLen = strlen(str);
			theApp.m_TmpScreenDC.TextOut(rect.left + 440 , rect.top + 140 + ( nI % 10 ) * 32  , str);

			theApp.m_TmpScreenDC.TextOut(rect.left + 520 , rect.top + 140 + ( nI % 10 ) * 32  , "无限");
		}
	}
}


void CPer::ShowFundInfo()
{
	char str[10];
	int nLen(0);
	CBrush brush , * pOldBrush;

	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	//写名字
	switch(m_Name)
	{
	case 0:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "No Name" );
		break;
	case 1:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "张    钧" );
		brush.CreateSolidBrush( RGB( 0 , 0 , 200 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	case 2:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "孔 凡 印" );
		brush.CreateSolidBrush( RGB( 200 , 0 , 0 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	}

	sprintf(str,"￥ %d",m_Cash);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 608 - nLen * 8, 105 , str );

	sprintf(str,"￥ %d",m_Fund);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 608 - nLen * 8, 170 , str );

	sprintf(str,"￥ %d",m_Cash + m_Fund);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 608 - nLen * 8, 235 , str );	

	theApp.m_TmpScreenDC.SetBkColor(RGB(255,255,255));
}

void CPer::ShowGelebInfo()
{
	char str[10];
	int nLen(0);
	CBrush brush , * pOldBrush;

	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	//写名字
	switch(m_Name)
	{
	case 0:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "No Name" );
		break;
	case 1:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "张    钧" );
		brush.CreateSolidBrush( RGB( 0 , 0 , 200 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	case 2:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "孔 凡 印" );
		brush.CreateSolidBrush( RGB( 200 , 0 , 0 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	}

	sprintf(str,"%d",m_LandNum);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 7, 105 , str);

	sprintf(str,"%d",m_HouseNum);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 7, 170 , str);
	
	sprintf(str,"%d",m_Build);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 7, 235 , str);

}

void CPer::ShowStockInfo()
{
	char str[10];
	int nLen(0);
	CBrush brush , * pOldBrush;

	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	//写名字
	switch(m_Name)
	{
	case 0:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "No Name" );
		break;
	case 1:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "张    钧" );
		brush.CreateSolidBrush( RGB( 0 , 0 , 200 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	case 2:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "孔 凡 印" );
		brush.CreateSolidBrush( RGB( 200 , 0 , 0 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	}

	//显示股票
	int nMoney(0);
	//显示总市值
	for( int nI(0) ; m_Stock[nI].StockName != 0 && nI < 12 ; nI++ )
	{
		nMoney = nMoney + theApp.m_Stock[nI]->GetStockPrice() * m_Stock[nI].StockNum;
	}
	sprintf( str,"%d", nMoney );
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 7, 105 , str );
	//显示总成本
	nMoney = 0;
	for(int nI = 0 ; m_Stock[nI].StockName != 0 && nI < 12 ; nI++ )
	{
		nMoney = nMoney + 
			(int)(m_Stock[nI].StockMoney * m_Stock[nI].StockNum);
	}
	sprintf( str,"%d", nMoney );
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 7, 170 , str );
	
	sprintf(str,"%d",m_CompanyNum);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 7, 235 , str );
}

void CPer::ShowOtherInfo()
{
	char str[10];
	int nLen(0);
	CBrush brush , * pOldBrush;

	//画影子
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PershadowDC[2], 0, 0, SRCAND);
	//图颜色
	theApp.m_TmpScreenDC.BitBlt(
		450,
		15,
		60, 60, & m_PerDC[2], 0, 0, SRCPAINT);

	//写名字
	switch(m_Name)
	{
	case 0:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "No Name" );
		break;
	case 1:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "张    钧" );
		brush.CreateSolidBrush( RGB( 0 , 0 , 200 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	case 2:
		theApp.m_TmpScreenDC.TextOut( 540 , 30 , "孔 凡 印" );
		brush.CreateSolidBrush( RGB( 200 , 0 , 0 ) );
		pOldBrush = theApp.m_TmpScreenDC.SelectObject( &brush );
		theApp.m_TmpScreenDC.Rectangle(515,55,610,70);
		brush.DeleteObject();
		theApp.m_TmpScreenDC.SelectObject( pOldBrush );
		break;
	}

	sprintf(str,"%d",m_Point);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 6, 105 , str );

	sprintf(str,"%d",m_Loan);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 6, 170 , str );
	
	sprintf(str,"%d 天",m_SafetyDate);
	nLen = strlen(str);
	theApp.m_TmpScreenDC.TextOut( 600 - nLen * 6, 235 , str );
}

void CPer::ReadFromStream( CDC * pDC, CArchive & ar )
{
	int nName(0), nType(0), nI, nJ;

	ar >> m_nState;

	//人物坐标
	ar >> m_ptCoordinate.x;
	ar >> m_ptCoordinate.y;
	ar >> m_Build;

	//读取卡片信息
	for(nI = 0 ; nI < 15 ; nI++)
	{
		ar >> nType;
		if(nType == 1)
		{
			delete m_Card[nI];
			ar >> nName;
			m_Card[nI] = new CCard( pDC, nName );
			m_Card[nI]->ReadFromStream( pDC , ar );
		}
		else
		{
			m_Card[nI] = NULL;
		}
	}

	ar >> m_Cash;
	ar >> m_CompanyNum;
	ar >> m_Days;
	ar >> m_iType;
	ar >> m_Fund;

	//读取房屋信息
	ar >> m_LandNum;
	for( nI = 0; nI < m_LandNum ; nI++ )
	{
		//显示房屋名称
		ar >> m_Gelbe[nI].Sport;

		//显示发展状况
		ar >> m_Gelbe[nI].Develop;

		//显示价值
		ar >> m_Gelbe[nI].Value;
	}

	ar >> nType;
	if( nType == 1 )
	{
		ar >> nName;
		m_God = new CGod( pDC,CPoint(0,0), nName );
		m_God->ReadFromStream( pDC, ar );
	}

	//房屋数量
	ar >> m_HouseNum;//房屋数目

	//读取道具信息
	for( nI = 0 ; nI < 15 ; nI++ )
	{
		ar >> nType;
		if(nType == 1)
		{
			for( nJ = 0; nJ < 9 ; nJ++ )
			{
				ar >> nType;
				if(nType == 1)
				{
					delete m_Item[nI].pItem[nJ];
					ar >> m_Item[nI].nTpye;
					m_Item[nI].pItem[nJ] = new CProperty( pDC, m_Item[nI].nTpye );
					m_Item[nI].pItem[nJ]->ReadFromStream( pDC, ar ); 
				}
				else
				{
					delete m_Item[nI].pItem[nJ];
					m_Item[nI].pItem[nJ] = NULL;
				}
			}
		}
	}

	ar >> m_Loan;
	ar >> m_nOrientation;	//贴图的方向
	ar >> m_nStep;
	ar >> m_PageCount;
	ar >> m_PageNum;
	ar >> m_Point;
	ar >> m_SafetyDate;//投保天数

	//股票掌握情况
	for( nI = 0 ; nI < 12 ; nI++ )
	{
		ar >> nType;
		if( nType == 1 )
		{
			ar >> m_Stock[nI].StockName;
			ar >> m_Stock[nI].StockMoney;
			ar >> m_Stock[nI].StockNum;
		}
	}

	//总产值
	ar >> m_Value;
	ar >> m_WalkNum;
	//人物方向
	ar >> m_Way;

	//保存人作用区
	ar >> m_MyRect.top;
	ar >> m_MyRect.right;
	ar >> m_MyRect.left;
	ar >> m_MyRect.bottom;
}

void CPer::WriteToStream( CArchive & ar )
{
	ar << m_Name;
	ar << m_nState;

	//人物坐标
	ar << m_ptCoordinate.x;
	ar << m_ptCoordinate.y;
	ar << m_Build;

	//保存Card
	for( int nI(0); nI < 15 ; nI++)
	{
		if( m_Card[nI] != NULL )
		{
			ar << 1;
			m_Card[nI]->WriteToStream( ar );
		}
		else
		{
			ar << 0;
		}
	}

	ar << m_Cash;
	ar << m_CompanyNum;
	ar << m_Days;
	ar << m_iType;
	ar << m_Fund;

	//保存房屋
	ar << m_LandNum;
	for(int nI = 0; nI < m_LandNum ; nI++ )
	{
		//显示房屋名称
		ar << m_Gelbe[nI].Sport;

		//显示发展状况
		ar << m_Gelbe[nI].Develop;

		//显示价值
		ar << m_Gelbe[nI].Value;
	}

	if( m_God != NULL)
	{
		ar << 1;
		m_God->WriteToStream( ar );
	}
	else
	{
		ar << 0;
	}

	//房屋数量
	ar << m_HouseNum;//房屋数目

	//保存道具
	for(int nI = 0 ; nI < 15 ; nI++ )
	{
		if(m_Item[nI].nTpye != 0)
		{
			ar << 1;
			for( int nJ(0); nJ < 9 ; nJ++ )
			{
				if( m_Item[nI].pItem[nJ] != NULL )
				{
					ar << 1;
					m_Item[nI].pItem[nJ]->WriteToStream( ar );
				}
				else 
				{
					ar << 0;
				}
			}
		}
		else
		{
			ar << 0;
		}
	}

	ar << m_Loan;
	ar << m_nOrientation;	//贴图的方向
	ar << m_nStep;
	ar << m_PageCount;
	ar << m_PageNum;
	ar << m_Point;
	ar << m_SafetyDate;//投保天数

	//股票掌握情况
	for(int nI = 0 ; nI < 12 ; nI++ )
	{
		if( m_Stock[nI].StockName != 0 )
		{
			ar << 1;
			ar << m_Stock[nI].StockName;
			ar << m_Stock[nI].StockMoney;
			ar << m_Stock[nI].StockNum;
		}
		else
		{
			ar << 0;
		}
	}

	//总产值
	ar << m_Value;
	ar << m_WalkNum;
	//人物方向
	ar << m_Way;

	//保存人作用区
	ar << m_MyRect.top;
	ar << m_MyRect.right;
	ar << m_MyRect.left;
	ar << m_MyRect.bottom;
}

int CPer::GetName()
{
	return m_Name;
}

int CPer::GetFund()
{
	return m_Fund;
}

void CPer::DrawOnSmallMap( CDC * pDC )
{
	theApp.m_TmpScreenDC.BitBlt( 
					(int)(m_MyRect.left * 5.0 / 66.0) + 440,
					(int)(m_MyRect.top / 11.0) + 280,
					15, 15, & m_SmallDC, 0, 0, SRCCOPY );
}

void CPer::DrawOnSmallMapView( CDC * pDC )
{
	m_SmallBitmap.DeleteObject();
	switch(m_Name)
	{
	case ZhangJun:
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( 
				NULL, "img\\yp.bmp", IMAGE_BITMAP, 20 , 
				20 , LR_LOADFROMFILE );
		break;
	case KongFanYin:
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( 
				NULL, "img\\ymp.bmp", IMAGE_BITMAP, 20 , 
				20 , LR_LOADFROMFILE );
		break;
	}
	m_SmallDC.SelectObject( m_SmallBitmap );
	theApp.m_TmpScreenDC.BitBlt( 
					(int)(m_MyRect.left * 5.0 / 33.0) + 20,
					(int)(m_MyRect.top * 2.0 / 11.0) + 60,
					20, 20, & m_SmallDC, 0, 0, SRCCOPY );
}
//显示道具
void CPer::ShowPropertyInfo( CPoint point , bool nType)
{
	int nJ(0),nK(0);
	CString str;
	CPoint pt;
	for( int nI(0) ; nI < 15 ; nI++ )
	{
		if(m_Item[nI].nTpye != 0)
		{
			if( 0 == nType )
			{
				pt.x = point.x +(nK % 5) * 71 , pt.y = point.y + nK/5 * 33;
				m_Item[nI].pItem[0]->Draw( nType , pt );
				for( nJ = 0; m_Item[nI].pItem[nJ] != NULL && nJ < 9 ; nJ++ );
				str.Format(" x %d",nJ);
				theApp.m_TmpScreenDC.TextOut(pt.x + 35 , pt.y + 8, str);
			}
			else
			{
				pt.x = point.x +(nK % 5) * 77 , pt.y = point.y + nK/5 * 62;
				m_Item[nI].pItem[0]->Draw( nType , pt );
				for( nJ = 0; m_Item[nI].pItem[nJ] != NULL && nJ < 9 ; nJ++ );
				str.Format(" x %d",nJ);
				theApp.m_TmpScreenDC.TextOut(pt.x + 45 , pt.y + 10, str);
			}
			nK++;
		}
	}
}
//显示卡片
void CPer::ShowCardInfo( CPoint point , bool nType )
{
	CPoint pt;
	int nK(0);
	for( int nI(0) ; nI < 15 ; nI++ )
	{
		if( m_Card[nI] != NULL )
		{
			if( 0 == nType )
			{
				pt.x = point.x +(nK % 5) * 71 , pt.y = point.y + nK/5 * 33;
				m_Card[nI]->Draw( pt );
			}
			else
			{
				pt.x = point.x +(nK % 5) * 77 , pt.y = point.y + nK/5 * 62;
				m_Card[nI]->Draw( pt );
			}
			nK++;
		}
	}
}

void CPer::PageDown()
{
	if( m_PageNum > 1)
	{
		m_PageNum++;
	}
}

void CPer::PageUp()
{
	if( m_PageNum < m_PageCount)
	{
		m_PageNum--;
	}
}

//返回股票数量
int CPer::GetStockAmount( int nid )
{
	for (int i(0);i<12;i++)
	{
		if ( m_Stock[i].StockName == nid )
		{
			return m_Stock[i].StockNum;
		} 
	}	
	return 0;
}

//返回股票平均价格
int CPer::GetStockPrice( int nid )
{
	for (int i(0);i<12;i++)
	{
		if ( m_Stock[i].StockName == nid )
		{
			return (int)(m_Stock[i].StockMoney);
		} 
	}
	return 0;
}

bool CPer::IsOnMe( CPoint point )
{
	CRect rect;
	rect.left =
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.right =
		m_MyRect.right - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.top =
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y;
	rect.bottom =
		m_MyRect.bottom - theApp.m_BigMap.m_ptBigMapCoordinate.y;

	if( CTool::PointInRect(point, rect) )
	{
		return true;
	}
	return false;
}

int CPer::GetWay()
{
	return m_Way;
}

int CPer::GetCash()
{
	return m_Cash;
}

void CPer::ChangeOrientation()
{
	if( m_nOrientation == 1 )
	{
		m_nOrientation = 3;
	}
	else if( m_nOrientation == 3 )
	{
		m_nOrientation = 1;
	}

	if( m_nOrientation == 2 )
	{
		m_nOrientation = 0;
	}
	else if( m_nOrientation == 0 )
	{
		m_nOrientation = 2;
	}
}

//返回贷款
int CPer::GetLoan()
{
	return m_Loan;
}