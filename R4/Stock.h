//Download by http://www.NewXing.com
// Stock.h: interface for the CStock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCK_H__ECEBB9CE_1509_4046_90A3_E3F7C290E29E__INCLUDED_)
#define AFX_STOCK_H__ECEBB9CE_1509_4046_90A3_E3F7C290E29E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"



class CStock : public CEntity  
{
public:
	CStock( int nCompanyName );
	virtual ~CStock();
	enum PriceState{up =0,
					down};//价格状态

	enum BusinessState {
						all = 1,
						out,
						into
						};//交易状态
	
	enum StockIDName{
					QiBuFan = 0,
					LiWeiXin
					};//股票企业名称

	int BuseinessType();//确定交易状态
	int GetStockPrice();//返回当天价格
	int GetStockID();//返回股票名称(ID)
	int GetStochSum();//返回股票流通量
	void StockGraphShowInfo();//显股票曲线图
	void PriceDispose( int nNum );//确定新价格
	void ShowInfo(int nI);//显示股票信息量
	void AddStockAmount(int iAmount);//购回加数量
	void ReduceStockAmount(int iAmount);//卖出减数量

	virtual void Draw(CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC,CArchive & ar );//CDC * pDC,
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );//CDC * pDC,
private:
	int m_iStockID;	//股票名称
	int m_iSum;		//持有数量
	int m_iPrice;	//购入价格
	int m_DisposePrice;//浮动价格
	int m_PriceState;//价格状态
	int m_iPriceArray[32];//保存一个月的价格
	int m_BusinessState;//交易状态
};

#endif // !defined(AFX_STOCK_H__ECEBB9CE_1509_4046_90A3_E3F7C290E29E__INCLUDED_)
