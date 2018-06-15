//Download by http://www.NewXing.com
// Date.h: interface for the CDate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATE_H__FE19F358_D6BE_490F_AE37_4E884B58728D__INCLUDED_)
#define AFX_DATE_H__FE19F358_D6BE_490F_AE37_4E884B58728D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDate : public CEntity
{
public:
	void ShowDate();
	void DayPass( CDC *pDC );
	int GetINP();
	int GetDay();
	int GetDayOfWeek();
	CDate();
	virtual ~CDate();
	
	virtual void Draw( CDC * pDC ){}		//贴图到临时内存*
	virtual bool IsOnMe( CPoint point ){return false;}	//点是否在我的作用区*
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );	//读取*
	virtual int ToolName( CPoint point ){return 0;}	//我需要的工具*
	virtual void WriteToStream( CArchive & ar );	//保存*

private:
	int m_Date;		//日
	int m_Month;	//月
	int m_Year;		//年
	int m_DayOfWeek;//星期几
	int m_AllDay;	//记录天数
	int m_INP;		//物价指数
};

#endif // !defined(AFX_DATE_H__FE19F358_D6BE_490F_AE37_4E884B58728D__INCLUDED_)
