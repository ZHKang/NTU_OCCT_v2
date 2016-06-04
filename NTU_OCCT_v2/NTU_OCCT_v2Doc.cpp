
// NTU_OCCT_v2Doc.cpp : implementation of the CNTU_OCCT_v2Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NTU_OCCT_v2.h"
#endif

#include "NTU_OCCT_v2Doc.h"

#include <propkey.h>


// CNTU_OCCT_v2Doc

IMPLEMENT_DYNCREATE(CNTU_OCCT_v2Doc, CDocument)

BEGIN_MESSAGE_MAP(CNTU_OCCT_v2Doc, OCC_3dDoc)
	ON_COMMAND(ID_BOX, OnBox)
	ON_COMMAND(ID_Cylinder, OnCylinder)
	ON_COMMAND(ID_SPHERE, OnSphere)
END_MESSAGE_MAP()


// CNTU_OCCT_v2Doc construction/destruction

CNTU_OCCT_v2Doc::CNTU_OCCT_v2Doc() : OCC_3dDoc()
{
	// TODO: add one-time construction code here
	myCylinder.Nullify();
	mySphere.Nullify();
	myBox.Nullify();

	myAISContext->DefaultDrawer()->ShadingAspect()->SetColor(Quantity_NOC_CHARTREUSE1); 
	myAISContext->DefaultDrawer()->ShadingAspect()->SetMaterial(Graphic3d_NOM_SILVER);
}

CNTU_OCCT_v2Doc::~CNTU_OCCT_v2Doc()
{
}

BOOL CNTU_OCCT_v2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

void CNTU_OCCT_v2Doc::ActivateFrame(CRuntimeClass* pViewClass,int nCmdShow)
{
	POSITION position = GetFirstViewPosition();
	while (position != (POSITION)NULL)
	{
		CView* pCurrentView = (CView*)GetNextView(position);
		if(pCurrentView->IsKindOf(pViewClass) )
		{
			ASSERT_VALID(pCurrentView);
			CFrameWnd* pParentFrm = pCurrentView->GetParentFrame();
			ASSERT(pParentFrm != (CFrameWnd *)NULL);
			// simply make the frame window visible
			pParentFrm->ActivateFrame(nCmdShow);
		}
	}
}

void  CNTU_OCCT_v2Doc::Popup(const Standard_Integer  x,
	const Standard_Integer  y ,
	const Handle(V3d_View)& aView   ) 
{
	Standard_Integer PopupMenuNumber=0;
	myAISContext->InitCurrent();

	if (myAISContext->MoreCurrent())
		PopupMenuNumber=1;

	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_Popup3D));
	CMenu* pPopup = menu.GetSubMenu(PopupMenuNumber);

	ASSERT(pPopup != NULL);
	if (PopupMenuNumber == 1) // more than 1 object.
	{
		bool OneOrMoreInShading = false;
		for (myAISContext->InitCurrent();myAISContext->MoreCurrent ();myAISContext->NextCurrent ())
			if (myAISContext->IsDisplayed(myAISContext->Current(),1)) OneOrMoreInShading=true;
		if(!OneOrMoreInShading)
			pPopup->EnableMenuItem(5, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
	}

	POINT winCoord = { x , y };
	Handle(WNT_Window) aWNTWindow=
		Handle(WNT_Window)::DownCast(aView->Window());
	ClientToScreen ( (HWND)(aWNTWindow->HWindow()),&winCoord);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON , winCoord.x, winCoord.y , 
		AfxGetMainWnd());
}
void CNTU_OCCT_v2Doc::InitViewButtons()
{
	//POSITION pos = GetFirstViewPosition();
	//while (pos != NULL)
	//{
	//	CNTU_OCCT_v2View* pView = (CNTU_OCCT_v2View*) GetNextView(pos);
	//	pView->InitButtons();
	//}
}
void CNTU_OCCT_v2Doc::DoSample()
{
	//InitViewButtons();

	//HCURSOR hOldCursor = ::GetCursor();
	//HCURSOR hNewCursor = AfxGetApp()->LoadStandardCursor(IDC_APPSTARTING);

	//SetCursor(hNewCursor);
	//{
	//	try
	//	{
	//		myPresentation->DoSample();
	//	}
	//	catch (Standard_Failure)
	//	{
	//		Standard_SStream aSStream;
	//		aSStream << "An exception was caught: " << Standard_Failure::Caught() << ends;
	//		CString aMsg = aSStream.str().c_str();
	//		AfxMessageBox (aMsg);
	//	}
	//}
	//SetCursor(hOldCursor);
}
// CNTU_OCCT_v2Doc serialization

void CNTU_OCCT_v2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CNTU_OCCT_v2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CNTU_OCCT_v2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CNTU_OCCT_v2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CNTU_OCCT_v2Doc diagnostics

#ifdef _DEBUG
void CNTU_OCCT_v2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNTU_OCCT_v2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNTU_OCCT_v2Doc commands
/////////////////////////////////////////////////////////////////////////////

void CNTU_OCCT_v2Doc::UpdateResultMessageDlg (CString theTitle, const TCollection_AsciiString& theMessage)
{
	CString aText (theMessage.ToCString());
	myCResultDialog.SetText (aText);
	myCResultDialog.SetTitle(theTitle);
}

void CNTU_OCCT_v2Doc::UpdateResultMessageDlg(CString theTitle, CString theMessage)
{
	myCResultDialog.SetText (theMessage);
	myCResultDialog.SetTitle(theTitle);
}


void CNTU_OCCT_v2Doc::OnBox()
{
	if(myBox.IsNull())
	{
		BRepPrimAPI_MakeBox B(gp_Pnt(0,-400,-100), 200.,150.,100.);


		myBox = new AIS_Shape (B.Shape());

		myAISContext->SetMaterial(myBox,Graphic3d_NOM_PEWTER);
		myAISContext->SetDisplayMode(myBox,1);

		myAISContext->Display(myBox);
		TCollection_AsciiString Message("\
										BRepPrimAPI_MakeBox Box1(gp_Pnt(0,-400,-100), 200.,150.,100.);\n\
										");

		UpdateResultMessageDlg("Create Box",Message);
	}
}

void CNTU_OCCT_v2Doc::OnCylinder()
{
}

void CNTU_OCCT_v2Doc::OnSphere()
{
	Handle_AIS_Shape mySphere;
	if(mySphere.IsNull())
	{
		//BRepPrimAPI_MakeSphere S(gp_Pnt(0,300,0), 100.);

		//mySphere = new AIS_Shape(S.Shape());

		//myAISContext->SetMaterial(mySphere,Graphic3d_NOM_BRONZE);
		//myAISContext->SetDisplayMode(mySphere,1);

		//myAISContext->Display(mySphere);
		//TCollection_AsciiString Message("\
		//								BRepPrimAPI_MakeSphere S(gp_Pnt(0,300,0), 100.);\n\
		//								");
		//UpdateResultMessageDlg("Create Sphere",Message);
	}
}

Handle_AIS_Shape CNTU_OCCT_v2Doc::GetBox()
{
	return myBox;
}