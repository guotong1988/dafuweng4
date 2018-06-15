//Download by http://www.NewXing.com
// Per.h: interface for the CPer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PER_H__F5BE94F0_EA14_4EC5_BFBA_D76E1D1E40C5__INCLUDED_)
#define AFX_PER_H__F5BE94F0_EA14_4EC5_BFBA_D76E1D1E40C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"
#include "Card.h"
#include "God.h"

class CEntityNode;
class CProperty;

class CPer : public CEntity  
{
public:
	enum Name
	{
		NoOne = 0,
		ZhangJun,
		KongFanYin
	};
	enum Way
	{
		Next = 0,
		Up,
		Hospital,
		Goal,
		Hotel
	};
	enum State
	{
		Stop = 0,
		Ready,
		Going,
		HitGoing,	//被撞
		HitInvest,	//被撞后的交易、事件
		Invest		//投资
		
	};
	struct STOCK//股票结构体
	{
		int StockName;//股票名称
		int StockNum;//持有数量
		double StockMoney;//购入价格
	};
	//道具情况
	struct Property
	{
		int nTpye;
		CProperty *pItem[9];
	};

	//房屋情况
	struct Gelbe
	{
		//地点
		int Sport;
		//发展状况
		int Develop;
		//价格
		int Value;
	};

	void PerGlebeInfo( CRect & rect );
	void PerStockInfo( CRect &rect );
	void PerShowInfo( CRect &rect );
	void Move( CDC * pDC );
	void MoveOnHit( CDC * pDC );
	void MoveOnHitNode( CDC * pDC );
	void MoveOnNode( CDC * pDC );
	//右下角小地图上画人
	void DrawOnSmallMap( CDC * pDC );
	//点击出现的小地图画人
	void DrawOnSmallMapView( CDC * pDC );
	//大地图上画人
	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual int ToolName( CPoint point ){return 0;}
	virtual void WriteToStream( CArchive & ar );
	CPer( CDC *pDC, int nName , CPoint point );
	virtual ~CPer();

	//拆房子
	void DestroyHouse();
	//盖房子
	void BiuldHouse();
	//创建人物
	//增加现金
	void AddCash(int nMoney);
	//减少现金
	void ReduceCash(int nMoney);
	//增加存款
	void AddFund(int nMoney);
	//减少存款
	void ReduceFund(int nMoney);
	//增加总产值
	void AddValue(int nMoney);
	//减少总产值
	void ReduceValue(int nMoney);
	//增加贷款
	void AddLoan(int nMoney);
	//减少贷款
	void ReduceLoan(int nMoney);
	//增加点数
	void AddPoint(int nPoint);
	//减少点数
	void ReducePoint(int nPoint);
	//改变步数
	void SplashDice( CDC * pDC, int nWalkNum );
	//走路
	//增加土地数目
	void AddLandNum( CEntityNode * pNode );
	//减少土地数目
	void ReduceLandNum();
	//增加房屋数目
	void AddHouseNum();
	//减少房屋数目
	void ReduceHouseNum();
	//购买卡片
	void AddCard( CCard &card );
	//使用卡片
	CCard *  ReduceCard(int nI);
	//购买道具
	void AddItem(CProperty &item);
	//使用道具
	CProperty* ReduceItem( int nType );
	//神明付身
	void SetGod( CEntity & god );
	//获得人物名字
	int GetName();
	//获得存款
	int GetFund();
	//获取现金
	int GetCash();
	//获得个人股票交易量
	int GetStockAmount(int nid);
	//获得股票成交价
	int GetStockPrice(int nid);
	//神明离开
	void LeaveGod();
	//购入股票
	void AddStock(int nMoney,int nName,int nNum);
	//卖出股票
	void ReduceStock(int nName,int nNum);
	//改变住院,坐牢,旅馆天数
	void ChangeDays(int nID ,int nDay);
	//改变人物方向
	void ChangeWay();
	//住院
	void InHospital();
	//出院
	void OutHospital();
	//坐牢
	void InGaol();
	//出狱
	void OutGaol();
	//住旅馆
	void InHotel();
	//出旅馆
	void OutHotel();
	//得到结点
	void GetEntityNode(CEntityNode & EntityNode);
	//向上翻页
	void PageDown();
	//向下翻页
	void PageUp();
	//显示右边框信息
	void ShowOtherInfo();
	void ShowStockInfo();
	void ShowGelebInfo();
	void ShowFundInfo();

	void ShowPropertyInfo( CPoint point , bool nType );
	void ShowCardInfo( CPoint point , bool nType );

	int GetWay();
	int GetLoan();
	void ChangeOrientation();

	int m_nState;
	CPoint m_ptCoordinate;	//人物坐标
private:
	int m_iType;
	int m_Build;//设施数目
	//卡片种类
	CCard *m_Card[15];//卡片种类
	//现金
	int m_Cash;
	int m_CompanyNum;//拥有公司数
	//住院,坐牢天数
	int m_Days;
	//存款
	int m_Fund;
	Gelbe m_Gelbe[100];//房屋情况
	//神明付身身情况
	CEntity * m_God;//神明种类
	//房屋数量
	int m_HouseNum;//房屋数目
	Property m_Item[15];//道具种类,数量
	//土地占有量
	int m_LandNum;//土地数目
	//贷款
	int m_Loan;
	int m_Name;	//人物名称
	int m_nOrientation;	//贴图的方向
	int m_nStep;	//贴图的步数
	//总页数
	int m_PageCount;
	//当前页数
	int m_PageNum;
	//结点指针
	CEntityNode * m_pEntityNode;//人物所在点
	CBitmap m_Perbmp[4];
	CDC m_PerDC[4];
	CBitmap m_Pershadowbmp[4];
	CDC m_PershadowDC[4];
	//点数
	int m_Point;
	int m_SafetyDate;//投保天数
	CBitmap m_SmallBitmap;
	CDC m_SmallDC;
	//股票掌握情况
	STOCK m_Stock[12];//股票掌握
	//总产值
	int m_Value;
	//步数
	int m_WalkNum;
	//人物方向
	int m_Way;
};

#endif // !defined(AFX_PER_H__F5BE94F0_EA14_4EC5_BFBA_D76E1D1E40C5__INCLUDED_)
