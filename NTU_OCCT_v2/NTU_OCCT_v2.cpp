
// NTU_OCCT_v2.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
//#include "afxwinappex.h"
//#include "afxdialogex.h"
#include "NTU_OCCT_v2.h"
#include "Resource.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "NTU_OCCT_v2Doc.h"
#include "NTU_OCCT_v2View.h"

#include "OCC_MainFrame.h"
#include "OCC_3dChildFrame.h"
#include "OCC_3dView.h"

// CNTU_OCCT_v2App

BEGIN_MESSAGE_MAP(CNTU_OCCT_v2App, OCC_App)
	ON_COMMAND(ID_APP_ABOUT, &CNTU_OCCT_v2App::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CNTU_OCCT_v2App construction

CNTU_OCCT_v2App::CNTU_OCCT_v2App() : OCC_App()
{
	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("NTU_OCCT_v2.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}
CNTU_OCCT_v2App::~CNTU_OCCT_v2App()
{

}

// The one and only CNTU_OCCT_v2App object

CNTU_OCCT_v2App theApp;


// CNTU_OCCT_v2App initialization

BOOL CNTU_OCCT_v2App::InitInstance()
{
	//CWinApp::InitInstance();
	//EnableTaskbarInteraction(FALSE);
	AfxEnableControlContainer();
	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_NTU_OCCT_v2TYPE,
		RUNTIME_CLASS(CNTU_OCCT_v2Doc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(OCC_3dView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	//CMainFrame* pMainFrame = new CMainFrame();
	OCC_MainFrame* pMainFrame = new OCC_MainFrame(with_AIS_TB);
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	m_ImpExpToolbar = new CToolBar;
	if ( !m_ImpExpToolbar->Create(m_pMainWnd, WS_CHILD |  WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS) ||
		!m_ImpExpToolbar->LoadToolBar(IDR_ImpExpToolbar))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;
	}
	m_ImpExpToolbar->EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	// call DragAcceptFiles only if there's a suffix
	//  In an MDI app, this should occur immediately after setting m_pMainWnd

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}
//int CNTU_OCCT_v2App::ExitInstance()
//{
//	//TODO: handle additional resources you may have added
//	return CWinApp::ExitInstance();
//}


