//Download by http://www.NewXing.com
// R4View.cpp : implementation of the CR4View class
//

#include "stdafx.h"
#include "R4.h"
class Cper;
#include "R4Doc.h"
#include "R4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CR4View

IMPLEMENT_DYNCREATE(CR4View, CView)

BEGIN_MESSAGE_MAP(CR4View, CView)
	//{{AFX_MSG_MAP(CR4View)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CR4View construction/destruction

CR4View::CR4View()
{
	// TODO: add construction code here

}

CR4View::~CR4View()
{
}

BOOL CR4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CR4View drawing

void CR4View::OnDraw(CDC* pDC)
{
	CR4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//自定义代码

	theApp.Draw( pDC );
}

/////////////////////////////////////////////////////////////////////////////
// CR4View diagnostics

#ifdef _DEBUG
void CR4View::AssertValid() const
{
	CView::AssertValid();
}

void CR4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CR4Doc* CR4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CR4Doc)));
	return (CR4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CR4View message handlers

int CR4View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//自定义代码

	//按系统时间初始化随机数
	srand( time( NULL ) );

	MCIWndPlay( MCIWndCreate( m_hWnd , NULL , 1 , "1.wma" ) );

	//时钟
	SetTimer( 1, 40, NULL);

	CDC * pDC = GetDC();

	theApp.m_Stock[0] = new CStock ( CStock::QiBuFan );
	theApp.m_Stock[1] = new CStock ( CStock::LiWeiXin );

	//创建地图*
	CPoint point( 1000, 1670 );
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x += 80;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, new CGod( pDC , point ),
		new CGlebe( pDC, point.x + 15, point.y - 75,
					point.x + 15 + 60, point.y - 75 + 110) );
	point.x += 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 15, point.y - 75,
					point.x + 15 + 60, point.y - 75 + 110) );
	point.x += 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 15, point.y - 75,
					point.x + 15 + 60, point.y - 75 + 110) );
	point.x += 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 15, point.y - 75,
					point.x + 15 + 60, point.y - 75 + 110) );

	point.x += 65;
	point.y += 35;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x += 80;
	point.y -= 20;
	CGlebe * pGlebe = new CGlebe( pDC, point.x + 50, point.y + 0,
							point.x + 50 + 60, point.y + 0 + 110);
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );
	point.x += 50;
	point.y -= 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );

	point.x += 90;
	point.y -= 30;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x -= 110;
	point.y -= 50;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x += 40;
	point.y -= 70;
	pGlebe = new CGlebe( pDC, point.x - 70, point.y - 80,
					point.x - 70 + 60, point.y - 80 + 110);
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );
	point.x += 20;
	point.y -= 30;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );

	point.x += 40;
	point.y -= 60;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x -= 30;
	point.y -= 70;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, new CGod( pDC , point ),
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 20;
	point.y -= 35;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 20;
	point.y -= 35;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 35;
	point.y -= 55;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x -= 30;
	point.y -= 60;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 25,
					point.x - 55 + 60, point.y - 25 + 110) );
	point.x -= 35;
	point.y -= 55;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x += 35;
	point.y -= 60;
	pGlebe = new CGlebe( pDC, point.x - 70, point.y - 80,
					point.x - 70 + 60, point.y - 80 + 110);
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );
	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );

	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 60,
					point.x - 60 + 60, point.y - 60 + 110) );
	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 60,
					point.x - 60 + 60, point.y - 60 + 110) );
	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 60,
					point.x - 60 + 60, point.y - 60 + 110) );
	point.x += 25;
	point.y -= 50;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x -= 30;
	point.y -= 55;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 30,
					point.x - 60 + 60, point.y - 30 + 110) );
	point.x -= 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 30,
					point.x - 60 + 60, point.y - 30 + 110) );
	point.x -= 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 30,
					point.x - 60 + 60, point.y - 30 + 110) );
	point.x -= 35;
	point.y -= 55;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x += 30;
	point.y -= 55;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 55,
					point.x - 55 + 60, point.y - 55 + 110) );
	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 55,
					point.x - 55 + 60, point.y - 55 + 110) );
	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 55,
					point.x - 55 + 60, point.y - 55 + 110) );
	point.x += 25;
	point.y -= 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 55, point.y - 55,
					point.x - 55 + 60, point.y - 55 + 110) );

	point.x += 25;
	point.y -= 45;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x -= 85;
	point.y -= 25;
	pGlebe = new CGlebe( pDC, point.x - 0, point.y - 110,
					point.x - 0 + 60, point.y - 110 + 110);
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );
	point.x -= 50;
	point.y -= 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL, pGlebe );

	point.x -= 95;
	point.y -= 25;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x -= 85;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 75,
					point.x - 20 + 60, point.y - 75 + 110) );
	point.x -= 50;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 75,
					point.x - 20 + 60, point.y - 75 + 110) );
	point.x -= 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 75,
					point.x - 20 + 60, point.y - 75 + 110) );
	point.x -= 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 75,
					point.x - 20 + 60, point.y - 75 + 110) );
	point.x -= 80;
	point.y += 30;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x -= 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 50,
					point.x - 60 + 60, point.y - 50 + 110) );
	point.x -= 20;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 50,
					point.x - 60 + 60, point.y - 50 + 110) );
	point.x -= 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 50,
					point.x - 60 + 60, point.y - 50 + 110) );
	point.x -= 20;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 60, point.y - 50,
					point.x - 60 + 60, point.y - 50 + 110) );
	point.x -= 35;
	point.y += 50;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x += 75;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 20, point.y - 75,
					point.x + 20 + 60, point.y - 75 + 110) );
	point.x += 60;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 20, point.y - 75,
					point.x + 20 + 60, point.y - 75 + 110) );
	point.x += 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 20, point.y - 75,
					point.x + 20 + 60, point.y - 75 + 110) );
	point.x += 50;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 20, point.y - 75,
					point.x + 20 + 60, point.y - 75 + 110) );
	point.x += 65;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x += 30;
	point.y += 60;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x += 25;
	point.y += 35;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x += 35;
	point.y += 55;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x -= 80;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 70,
					point.x - 20 + 60, point.y - 70 + 110) );
	point.x -= 55;
	point.y += 20;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 70,
					point.x - 20 + 60, point.y - 70 + 110) );
	point.x -= 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 70,
					point.x - 20 + 60, point.y - 70 + 110) );
	point.x -= 55;
	point.y += 15;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 20, point.y - 70,
					point.x - 20 + 60, point.y - 70 + 110) );
	point.x -= 80;
	point.y += 30;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x -= 30;
	point.y += 45;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, new CGod( pDC , point ),
		new CGlebe( pDC, point.x + 60, point.y - 20,
					point.x + 60 + 60, point.y - 20 + 110) );
	point.x -= 20;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 60, point.y - 20,
					point.x + 60 + 60, point.y - 20 + 110) );
	point.x -= 20;
	point.y += 35;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 60, point.y - 20,
					point.x + 60 + 60, point.y - 20 + 110) );
	point.x -= 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x + 60, point.y - 20,
					point.x + 60 + 60, point.y - 20 + 110) );
	point.x -= 30;
	point.y += 50;
	theApp.m_EntityRoadList.AddEntityNode( point );
	point.x += 35;
	point.y += 60;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );
	point.x += 20;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );
	point.x += 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );
	point.x += 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );
	point.x += 30;
	point.y += 55;
	theApp.m_EntityRoadList.AddEntityNode( point );

	point.x += 25;
	point.y += 50;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );
	point.x += 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );
	point.x += 25;
	point.y += 40;
	theApp.m_pAllPer[1] = new CPer( pDC, CPer::ZhangJun , point );
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110),
					theApp.m_pAllPer[1] );
	point.x += 25;
	point.y += 40;
	theApp.m_pAllPer[0] = new CPer( pDC, CPer::KongFanYin , point );
	theApp.m_pPer = theApp.m_pAllPer[0];

	theApp.m_pAllPer[0]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[0]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[0]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[0]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[0]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[0]->AddCard( *new CCard( pDC ) );	//人接收卡片*

	theApp.m_pAllPer[0]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[0]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[0]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[0]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[0]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[0]->AddItem( *new CProperty( pDC ) );//人接收道具*

	theApp.m_pAllPer[1]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[1]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[1]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[1]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[1]->AddCard( *new CCard( pDC ) );	//人接收卡片*
	theApp.m_pAllPer[1]->AddCard( *new CCard( pDC ) );	//人接收卡片*

	theApp.m_pAllPer[1]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[1]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[1]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[1]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[1]->AddItem( *new CProperty( pDC ) );//人接收道具*
	theApp.m_pAllPer[1]->AddItem( *new CProperty( pDC ) );//人接收道具*

	//初始化内存，装载图片*必须放在这里前后都要用*
	theApp.InitAll_DC_BM( pDC );

	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, NULL,
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110),
					theApp.m_pAllPer[0] );
	point.x += 25;
	point.y += 40;
	theApp.m_EntityRoadList.AddEntityNode( point,
		CEntityNode::NanJinWay, new CGod( pDC , point ),
		new CGlebe( pDC, point.x - 50, point.y - 25,
					point.x - 50 + 60, point.y - 25 + 110) );

	//初始化工具*
	theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice ,NULL);

	ReleaseDC( pDC );

	return 0;
}

void CR4View::OnMouseMove(UINT nFlags, CPoint point) 
{
	//自定义代码

	CDC * pDC = GetDC();

	theApp.m_ToolManager.DispatchMsg( pDC, WM_MOUSEMOVE, point );

	ReleaseDC( pDC );

	CView::OnMouseMove(nFlags, point);
}

void CR4View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//自定义代码

	CDC * pDC = GetDC();

	//调用工具管理器的创建工具
	theApp.m_ToolManager.SetActiveTool( pDC, theApp.ToolName(point) ,NULL);
	//调用工具管理器的消息处理
	theApp.m_ToolManager.DispatchMsg( pDC, WM_LBUTTONDOWN, point );

	ReleaseDC( pDC );

	CView::OnLButtonDown(nFlags, point);
}

void CR4View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//自定义代码

	CDC * pDC = GetDC();

	theApp.m_ToolManager.DispatchMsg( pDC, WM_LBUTTONUP, point );

	ReleaseDC( pDC );

	CView::OnLButtonUp(nFlags, point);
}

void CR4View::OnDestroy() 
{
	CView::OnDestroy();

	//自定义代码

	//销毁资源
	KillTimer(1);

	theApp.m_TmpScreenDC.SetBkMode( OPAQUE );

	delete theApp.m_Stock[0];
	delete theApp.m_Stock[1];
	theApp.m_TmpScreenDC.DeleteDC();
	theApp.m_TmpScreenBitmap.DeleteObject();
}

void CR4View::OnTimer(UINT nIDEvent) 
{
	//自定义代码

	CDC * pDC = GetDC();

	theApp.m_ToolManager.DispatchMsg( pDC, WM_TIMER );

	ReleaseDC( pDC );

	CView::OnTimer(nIDEvent);
}

void CR4View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	//自定义代码

	CDC * pDC = GetDC();

	theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice ,NULL);

	ReleaseDC( pDC );

	CView::OnRButtonDown(nFlags, point);
}

void CR4View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	//自定义代码

	CDC * pDC = GetDC();

	theApp.m_ToolManager.DispatchMsg( pDC, WM_LBUTTONDBLCLK, point );

	ReleaseDC( pDC );

	CView::OnLButtonDblClk(nFlags, point);
}
