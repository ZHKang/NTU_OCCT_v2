
// NTU_OCCT_v2Doc.cpp : implementation of the CNTU_OCCT_v2Doc class
//

#include "stdafx.h"

#include "NTU_OCCT_v2.h"
#include "NTU_OCCT_v2Doc.h"
#include "Resource.h"

#include <propkey.h>

#include <Geom_Axis1Placement.hxx>
#include <ImportExport/ImportExport.h>


// CNTU_OCCT_v2Doc

IMPLEMENT_DYNCREATE(CNTU_OCCT_v2Doc, CDocument)

BEGIN_MESSAGE_MAP(CNTU_OCCT_v2Doc, OCC_3dBaseDoc)
	ON_COMMAND(ID_BOX, OnBox)
	ON_COMMAND(ID_Cylinder, OnCylinder)
	ON_COMMAND(ID_SPHERE, OnSphere)
	ON_COMMAND(ID_TORUS, OnTorus)
	ON_COMMAND(ID_Rotation,OnRotate)
	ON_COMMAND(ID_Robot,OnRobot)
	ON_COMMAND(ID_TRANSLATION,OnTranslation)
	ON_COMMAND(ID_FILE_IMPORT_CSFDB, OnFileImportCSFDB)
	ON_COMMAND(ID_FILE_EXPORT_CSFDB, OnFileExportCSFDB)
	ON_COMMAND(ID_FILE_IMPORT_IGES, OnFileImportIges)
	ON_COMMAND(ID_FILE_EXPORT_IGES, OnFileExportIges)
	ON_COMMAND(ID_FILE_IMPORT_STEP, OnFileImportStep)
	ON_COMMAND(ID_FILE_EXPORT_STEP, OnFileExportStep)
	ON_COMMAND(ID_FILE_IMPORT_BREP, OnFileImportBrep)
	ON_COMMAND(ID_FILE_EXPORT_BREP, OnFileExportBrep)
	ON_COMMAND(ID_FILE_EXPORT_VRML, OnFileExportVrml)
	ON_COMMAND(ID_FILE_IMPORT_STL, OnFileImportStl)
	ON_COMMAND(ID_FILE_EXPORT_STL, OnFileExportStl)

END_MESSAGE_MAP()


// CNTU_OCCT_v2Doc construction/destruction

CNTU_OCCT_v2Doc::CNTU_OCCT_v2Doc()
{
	// TODO: add one-time construction code here
	myCylinder.Nullify();
	mySphere.Nullify();
	myBox.Nullify();

	myAISContext->DefaultDrawer()->ShadingAspect()->SetColor(Quantity_NOC_CHARTREUSE1); 
	myAISContext->DefaultDrawer()->ShadingAspect()->SetMaterial(Graphic3d_NOM_BRONZE);
	myAISContext->SetDisplayMode(AIS_Shaded,Standard_False);
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

void CNTU_OCCT_v2Doc::OnBox()
{
	if(myBox.IsNull())
	{
		BRepPrimAPI_MakeBox B(gp_Pnt(0,-400,-100), 200.,150.,100.);


		myBox = new AIS_Shape (B.Shape());

		myAISContext->SetMaterial(myBox,Graphic3d_NOM_PEWTER);
		myAISContext->Display(myBox);
		TCollection_AsciiString Message("BRepPrimAPI_MakeBox Box1(gp_Pnt(0,-400,-100), 200.,150.,100.);\n");

		PocessTextInDialog("Create Box",Message);
		Fit();
	}
}

void CNTU_OCCT_v2Doc::OnCylinder()
{
	BRepPrimAPI_MakeCylinder C(30.,100.);
	Handle(AIS_Shape) ais1 = new AIS_Shape(C.Shape());
	myAISContext->Display(ais1, Standard_False);
	Fit();
}

void CNTU_OCCT_v2Doc::OnSphere()
{
	Handle_AIS_Shape mySphere;
	if(mySphere.IsNull())
	{
		BRepPrimAPI_MakeSphere S(gp_Pnt(0,300,0), 100.);

		mySphere = new AIS_Shape(S.Shape());

		myAISContext->SetMaterial(mySphere,Graphic3d_NOM_BRONZE);
		myAISContext->SetDisplayMode(mySphere,1);
		myAISContext->Display(mySphere);
		TCollection_AsciiString Message("BRepPrimAPI_MakeSphere S(gp_Pnt(0,300,0), 100.);\n");
		PocessTextInDialog("Create Sphere",Message);
		Fit();
	}
}
void CNTU_OCCT_v2Doc::OnTorus()
{
	TopoDS_Shape S1 = BRepPrimAPI_MakeTorus(60., 20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S1);
	myAISContext->SetColor(ais1,Quantity_NOC_AZURE,Standard_False); 
	myAISContext->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais1,Standard_False);

}

void CNTU_OCCT_v2Doc::OnRotate()
{
	BRepPrimAPI_MakeCylinder C(30.,100.);
	Handle(AIS_Shape) ais1 = new AIS_Shape(C.Shape());
	myAISContext->Display(ais1, Standard_False);

	gp_Dir axis (1,1,1);
	gp_Pnt pos (50,150,0);
	gp_Trsf trans;
	trans.SetValues(1,0,axis.X(),pos.X(),
		0,1,axis.Y(),pos.Y(),
		0,0,axis.Z(),pos.Z());


	BRepPrimAPI_MakeCylinder D(30.,100.);
	TopoDS_Shape topoais2 = D.Shape();
	BRepBuilderAPI_Transform myBRepTransform(topoais2,trans,true);

	Handle(AIS_Shape) ais2 = new AIS_Shape(myBRepTransform.Shape());
	myAISContext->SetColor(ais2,Quantity_NOC_BLUE4 );
	myAISContext->Display(ais2, Standard_False);

	Fit();
}
void CNTU_OCCT_v2Doc::OnRobot()
{

}
void CNTU_OCCT_v2Doc::OnTranslation()
{
	//TopoDS_Shape S = BRepPrimAPI_MakeWedge(6.,10.,8.,2.).Shape(); 
	//Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	//myAISContext->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	//myAISContext->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
	//myAISContext->Display(ais1,Standard_False);
	//gp_Trsf theTransformation;
	//gp_Vec theVectorOfTranslation(-6,-6,6);

	//Handle (ISession_Direction) aDirection1 = new ISession_Direction(gp_Pnt(0,0,0),theVectorOfTranslation);
	//myAISContext->Display(aDirection1,Standard_False);

	//theTransformation.SetTranslation(theVectorOfTranslation);
	//BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	//TopoDS_Shape S2 = myBRepTransformation.Shape();

	//Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	//myAISContext->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	//myAISContext->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	//myAISContext->Display(ais2,Standard_False);

	//Fit();

}
void CNTU_OCCT_v2Doc::OnFileImportBrep()
{
	TopoDS_ListOfShape   m_shapeList;
	Handle(TopTools_HSequenceOfShape) BREPSequence = CImportExport::ReadBREP();
	for(int i=1;i<= BREPSequence->Length();i++)
	{
		m_shapeList.Append(BREPSequence->Value(i));
		for (TopoDS_ListIteratorOfListOfShape iter(m_shapeList); iter.More(); iter.Next())
		{
			Handle(AIS_Shape) ais = new AIS_Shape(iter.Value());
			myAISContext->Display(ais, Standard_False);
		}
	}
	Fit();
}
void CNTU_OCCT_v2Doc::OnFileExportBrep()
{CImportExport::SaveBREP(myAISContext);}
void CNTU_OCCT_v2Doc::OnFileImportCSFDB()
{
	TopoDS_ListOfShape   m_shapeList;
	Handle(TopTools_HSequenceOfShape) CSFDBSequence = CImportExport::ReadCSFDB();
	for(int i=1;i<= CSFDBSequence->Length();i++)
	{
		m_shapeList.Append(CSFDBSequence->Value(i));
		for (TopoDS_ListIteratorOfListOfShape iter(m_shapeList); iter.More(); iter.Next())
		{
			Handle(AIS_Shape) ais = new AIS_Shape(iter.Value());
			myAISContext->Display(ais, Standard_False);
		}
	}
	Fit();
}
void CNTU_OCCT_v2Doc::OnFileExportCSFDB()
{CImportExport::SaveBREP(myAISContext);}
void CNTU_OCCT_v2Doc::OnFileImportIges()
{
	TopoDS_ListOfShape   m_shapeList;
	Handle(TopTools_HSequenceOfShape) IgesSequence = CImportExport::ReadIGES();
	for(int i=1;i<= IgesSequence->Length();i++)
	{
		m_shapeList.Append(IgesSequence->Value(i));
		for (TopoDS_ListIteratorOfListOfShape iter(m_shapeList); iter.More(); iter.Next())
		{
			Handle(AIS_Shape) ais = new AIS_Shape(iter.Value());
			myAISContext->Display(ais, Standard_False);
		}
	}
	Fit();
}
void CNTU_OCCT_v2Doc::OnFileExportIges()
{
	CImportExport::SaveIGES(myAISContext);
}
void CNTU_OCCT_v2Doc::OnFileImportStep()
{
	TopoDS_ListOfShape   m_shapeList;
	Handle(TopTools_HSequenceOfShape) STEPSequence = CImportExport::ReadSTEP();
	for(int i=1;i<= STEPSequence->Length();i++)
	{
		m_shapeList.Append(STEPSequence->Value(i));
		for (TopoDS_ListIteratorOfListOfShape iter(m_shapeList); iter.More(); iter.Next())
		{
			Handle(AIS_Shape) ais = new AIS_Shape(iter.Value());
			myAISContext->Display(ais, Standard_False);
		}
	}
	Fit();
}
void CNTU_OCCT_v2Doc::OnFileExportStep()
{
	CImportExport::SaveSTEP(myAISContext);
}
void CNTU_OCCT_v2Doc::OnFileExportVrml()
{
	CImportExport::SaveVRML(myAISContext);
}
void CNTU_OCCT_v2Doc::OnFileImportStl()
{
	CFileDialog dlg(TRUE,
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"STL Files (*.STL, *.stl)|*.STL; *.stl|All Files (*.*)|*.*||",
		NULL );

	CString CASROOTValue;
	CASROOTValue.GetEnvironmentVariable (L"CASROOT");
	CString initdir = (CASROOTValue + "\\..\\data\\iges");

	dlg.m_ofn.lpstrInitialDir = initdir;
	if (dlg.DoModal() == IDOK) 
	{
		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));
		TCollection_ExtendedString aFileNameW ((Standard_ExtString )(const wchar_t* )dlg.GetPathName());
		TCollection_AsciiString    aFileName  (aFileNameW, '?');
		OSD_Path aFile(aFileName.ToCString());

		Handle(StlMesh_Mesh) aSTLMesh = RWStl::ReadFile(aFile);

		TopoDS_Compound ResultShape;
		BRep_Builder CompoundBuilder;
		CompoundBuilder.MakeCompound(ResultShape);

		Standard_Integer NumberDomains = aSTLMesh->NbDomains();
		Standard_Integer iND=1;
		gp_XYZ p1, p2, p3;
		TopoDS_Vertex Vertex1, Vertex2, Vertex3;
		TopoDS_Face AktFace;
		TopoDS_Wire AktWire;
		BRep_Builder B;
		Standard_Real x1, y1, z1;
		Standard_Real x2, y2, z2;
		Standard_Real x3, y3, z3;
		StlMesh_MeshExplorer aMExp (aSTLMesh);
			for (aMExp.InitTriangle (iND); aMExp.MoreTriangle (); aMExp.NextTriangle ())
			{
				aMExp.TriangleVertices (x1,y1,z1,x2,y2,z2,x3,y3,z3);
				p1.SetCoord(x1,y1,z1);
				p2.SetCoord(x2,y2,z2);
				p3.SetCoord(x3,y3,z3);

				if ((!(p1.IsEqual(p2,0.0))) && (!(p1.IsEqual(p3,0.0))))
				{
					Vertex1 = BRepBuilderAPI_MakeVertex(p1);
					Vertex2 = BRepBuilderAPI_MakeVertex(p2);
					Vertex3 = BRepBuilderAPI_MakeVertex(p3);

					AktWire = BRepBuilderAPI_MakePolygon( Vertex1, Vertex2, Vertex3, Standard_True);

					if( !AktWire.IsNull())
					{
						AktFace = BRepBuilderAPI_MakeFace( AktWire);
						if(!AktFace.IsNull())
							CompoundBuilder.Add(ResultShape,AktFace);
					}
				}
			}
		TopoDS_Shape aShape = ResultShape;
		Handle(AIS_Shape) ais1 = new AIS_Shape(aShape);
		myAISContext->SetColor(ais1,Quantity_NOC_AZURE,Standard_False); 
		myAISContext->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
		myAISContext->Display(ais1,Standard_False);
		Fit();
		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	}
}
void CNTU_OCCT_v2Doc::OnFileExportStl()
{
	CImportExport::SaveSTL(myAISContext);
}