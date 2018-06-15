// R4.cpp : Defines the class behaviors for the application.
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "R4.h"

#include "MainFrm.h"
#include "R4Doc.h"
#include "R4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CR4App

BEGIN_MESSAGE_MAP(CR4App, CWinApp)
	//{{AFX_MSG_MAP(CR4App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CR4App construction
CR4App::CR4App()
{
	m_pPer = NULL;
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CR4App object

CR4App theApp;

/////////////////////////////////////////////////////////////////////////////
// CR4App initialization

BOOL CR4App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CR4Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CR4View));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CR4App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CR4App message handlers

void CR4App::Draw( CDC * pDC )
{
	m_BigMap.Draw( pDC );
	m_EntityRoadList.Draw( pDC );
	m_SmallMap.Draw( pDC );
	m_Bankroll.Draw( pDC );
	m_ButtonToolbar.Draw( pDC );
	m_Date.ShowDate();
	m_ToolManager.Draw( pDC );

	pDC->BitBlt( 0, 0, 640, 480, & m_TmpScreenDC, 0, 0, SRCCOPY);
}

void CR4App::InitAll_DC_BM( CDC * pDC )
{
	m_TmpScreenDC.CreateCompatibleDC( pDC );
	m_TmpScreenBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
		"img\\Screen.bmp", IMAGE_BITMAP, 640,480, LR_LOADFROMFILE );
	m_TmpScreenDC.SelectObject( m_TmpScreenBitmap );

	m_TmpScreenDC.SetBkMode( TRANSPARENT );

	m_BigMap.Init_DC_BM( pDC );
	m_SmallMap.Init_DC_BM( pDC );
	m_Bankroll.Init_DC_BM( pDC );
	m_ButtonToolbar.Init_DC_BM( pDC );
}

int CR4App::ToolName( CPoint point )
{
	int nToolName = m_ToolManager.ToolName(point);
	if( nToolName > CTool::NoTool )return nToolName;

	nToolName = m_ButtonToolbar.ToolName( point );
	if( nToolName > CTool::NoTool )return nToolName;

	nToolName = m_Bankroll.ToolName( point );
	if( nToolName > CTool::NoTool )return nToolName;

	nToolName = m_SmallMap.ToolName( point );
	if( nToolName > CTool::NoTool )return nToolName;

	nToolName = m_BigMap.ToolName( point );
	if( nToolName > CTool::NoTool )return nToolName;

	nToolName = m_EntityRoadList.ToolName( point );
	if( nToolName > CTool::NoTool )return nToolName;

	return CTool::Dice;
}
