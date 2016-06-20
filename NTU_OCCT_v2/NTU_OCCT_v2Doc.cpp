
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

BEGIN_MESSAGE_MAP(CNTU_OCCT_v2Doc, OCC_3dDoc)
	ON_COMMAND(ID_BOX, OnBox)
	ON_COMMAND(ID_Cylinder, OnCylinder)
	ON_COMMAND(ID_SPHERE, OnSphere)
	ON_COMMAND(ID_TORUS, OnTorus)
	ON_COMMAND(ID_Rotation,OnRotate)
	ON_COMMAND(ID_Robot,OnRobot)
	ON_COMMAND(ID_TRANSLATION,OnTranslation)
	ON_COMMAND(ID_PRISM, OnPrism)
	ON_COMMAND(ID_VOLUME, OnVolume)
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
	//CDocument::AssertValid();
}

void CNTU_OCCT_v2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNTU_OCCT_v2Doc commands
/////////////////////////////////////////////////////////////////////////////
int CNTU_OCCT_v2Doc::ReadSTLFcn(TCollection_AsciiString &aFileName)
{
	OSD_Path aFile(aFileName.ToCString());
	Handle(Message_ProgressIndicator) aProgInd = 0;

	Handle(StlMesh_Mesh) aSTLMesh = RWStl::ReadFile(aFile,aProgInd);
	// Fast Use MeshVS
	Handle(MeshVS_Mesh) aMesh = new MeshVS_Mesh();
	Handle( XSDRAWSTLVRML_DataSource ) aDS = new XSDRAWSTLVRML_DataSource(aSTLMesh);

	aMesh->SetDataSource(aDS);
	aMesh->AddBuilder( new MeshVS_MeshPrsBuilder( aMesh), Standard_True );//False -> No selection

	aMesh->GetDrawer()->SetBoolean(MeshVS_DA_DisplayNodes,Standard_False); //MeshVS_DrawerAttribute
	aMesh->GetDrawer()->SetBoolean(MeshVS_DA_ShowEdges,Standard_False);
	aMesh->GetDrawer()->SetMaterial(MeshVS_DA_FrontMaterial,Graphic3d_NameOfMaterial::Graphic3d_NOM_GOLD);

	aMesh->SetColor(Quantity_NOC_AZURE);
	aMesh->SetDisplayMode( MeshVS_DMF_Shading ); // Mode as defaut
	aMesh->SetHilightMode( MeshVS_DMF_WireFrame ); // Wireframe as default hilight mode
	myAISContext->Display(aMesh);
	return 0;
}

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
	TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex(gp_Pnt(-200.,-200.,0.));
	Handle(AIS_Shape) ais1 = new AIS_Shape(V1);
	myAISContext->Display(ais1,Standard_False);
	gp_Ax1 axe = gp_Ax1(gp_Pnt(-170.,-170.,0.),gp_Dir(0.,0.,1.));
	Handle(Geom_Axis1Placement) Gax1 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax1 = new AIS_Axis(Gax1);
	myAISContext->Display(ax1,Standard_False);
	TopoDS_Shape S1 = BRepPrimAPI_MakeRevol(V1,axe);
	Handle(AIS_Shape) ais2 = new AIS_Shape(S1);
	myAISContext->Display(ais2,Standard_False);

	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gp_Pnt(-120.,-120,0.), gp_Pnt(-120.,-120,100.));
	Handle(AIS_Shape) ais3 = new AIS_Shape(E);
	myAISContext->Display(ais3,Standard_False);
	axe = gp_Ax1(gp_Pnt(-100.,-100.,0.),gp_Dir(0.,0.,1.));
	Handle(Geom_Axis1Placement) Gax2 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax2 = new AIS_Axis(Gax2);
	myAISContext->Display(ax2,Standard_False);
	TopoDS_Shape S2 = BRepPrimAPI_MakeRevol(E,axe);
	Handle(AIS_Shape) ais4 = new AIS_Shape(S2);
	myAISContext->SetColor(ais4,Quantity_NOC_YELLOW,Standard_False); 
	myAISContext->SetMaterial(ais4,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais4,Standard_False);

	TopoDS_Edge E1 = BRepBuilderAPI_MakeEdge(gp_Pnt(0.,0.,0.), gp_Pnt(50.,0.,0.));
	TopoDS_Edge E2 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,0.,0.), gp_Pnt(50.,50.,0.));
	TopoDS_Edge E3 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,50.,0.), gp_Pnt(0.,0.,0.));
	TopoDS_Wire W = BRepBuilderAPI_MakeWire(E1,E2,E3);
	axe = gp_Ax1(gp_Pnt(0.,0.,30.),gp_Dir(0.,1.,0.));
	Handle(Geom_Axis1Placement) Gax3 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax3 = new AIS_Axis(Gax3);
	myAISContext->Display(ax3,Standard_False);
	TopoDS_Shape S3 = BRepPrimAPI_MakeRevol(W,axe, 210.*M_PI/180);
	Handle(AIS_Shape) ais5 = new AIS_Shape(W);
	myAISContext->Display(ais5,Standard_False);
	Handle(AIS_Shape) ais6 = new AIS_Shape(S3);
	myAISContext->SetColor(ais6,Quantity_NOC_GREEN,Standard_False); 
	myAISContext->SetMaterial(ais6,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais6,Standard_False);

	gp_Circ c = gp_Circ(gp_Ax2(gp_Pnt(200.,200.,0.),gp_Dir(0.,0.,1.)), 80.);
	TopoDS_Edge Ec = BRepBuilderAPI_MakeEdge(c);
	TopoDS_Wire Wc = BRepBuilderAPI_MakeWire(Ec);
	TopoDS_Face F = BRepBuilderAPI_MakeFace(gp_Pln(gp::XOY()),Wc);
	axe = gp_Ax1(gp_Pnt(290,290.,0.),gp_Dir(0.,1,0.));
	Handle(Geom_Axis1Placement) Gax4 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax4 = new AIS_Axis(Gax4);
	myAISContext->Display(ax4,Standard_False);
	TopoDS_Shape S4 = BRepPrimAPI_MakeRevol(F,axe, 90.*M_PI/180);
	Handle(AIS_Shape) ais8 = new AIS_Shape(S4);
	myAISContext->SetColor(ais8,Quantity_NOC_MATRABLUE,Standard_False); 
	myAISContext->SetMaterial(ais8,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais8,Standard_False);
	Fit();
}
void CNTU_OCCT_v2Doc::OnRobot()
{
	Standard_CString aFileName;
	aFileName= "..//3rdParty//CAD//Atom//BASE.STL";
	Handle(MeshVS_Mesh) bMesh = new MeshVS_Mesh();
	bMesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_SIENNA);
	//bMesh->GetDrawer()->SetBoolean(MeshVS_DA_IsAllowOverlapped, Standard_True);
	//bMesh->GetDrawer()->SetBoolean(MeshVS_DA_ShowEdges,Standard_True);
	//bMesh->GetDrawer()->SetColor(MeshVS_DA_EdgeColor,Quantity_NOC_GRAY2);
	Standard_Boolean statusb = CImportExport::ReadSTL(aFileName,bMesh);
	myAISContext->Display(bMesh);
	Fit();
	aFileName = "..//3rdParty//CAD//Atom//J1.STL";
	Handle(MeshVS_Mesh) J1Mesh = new MeshVS_Mesh();
	Standard_Boolean status1 = CImportExport::ReadSTL(aFileName,J1Mesh);
	J1Mesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_LIGHTGRAY );
	//J1Mesh->GetDrawer()->SetBoolean(MeshVS_DA_ShowEdges,Standard_True);
	myAISContext->Display(J1Mesh);
	Fit();
	aFileName = "..//3rdParty//CAD//Atom//J2.STL";
	Handle(MeshVS_Mesh) J2Mesh = new MeshVS_Mesh();
	Standard_Boolean status2 = CImportExport::ReadSTL(aFileName,J2Mesh);
	J2Mesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_GOLD );
	J2Mesh->GetDrawer()->SetBoolean(MeshVS_DA_IsAllowOverlapped, Standard_True);
	//J2Mesh->GetDrawer()->SetBoolean(MeshVS_DA_ShowEdges,Standard_True);
	myAISContext->Display(J2Mesh);
	Fit();
	aFileName = "..//3rdParty//CAD//Atom//J3.STL";
	Handle(MeshVS_Mesh) J3Mesh = new MeshVS_Mesh();
	J3Mesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_GRAY30);
	J3Mesh->GetDrawer()->SetBoolean(MeshVS_DA_IsAllowOverlapped, Standard_True);
	Standard_Boolean status3 = CImportExport::ReadSTL(aFileName,J3Mesh);
	myAISContext->Display(J3Mesh);
	Fit();
	aFileName = "..//3rdParty//CAD//Atom//J4.STL";
	Handle(MeshVS_Mesh) J4Mesh = new MeshVS_Mesh();
	J4Mesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_GOLD);
	Standard_Boolean status4 = CImportExport::ReadSTL(aFileName,J4Mesh);
	myAISContext->Display(J4Mesh);
	Fit();
	aFileName = "..//3rdParty//CAD//Atom//J5.STL";
	Handle(MeshVS_Mesh) J5Mesh = new MeshVS_Mesh();
	J5Mesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_GRAY30);
	J5Mesh->GetDrawer()->SetBoolean(MeshVS_DA_IsAllowOverlapped, Standard_True);
	Standard_Boolean status5 = CImportExport::ReadSTL(aFileName,J5Mesh);
	myAISContext->Display(J5Mesh);
	Fit();
	aFileName = "..//3rdParty//CAD//Atom//J6.STL";
	Handle(MeshVS_Mesh) J6Mesh = new MeshVS_Mesh();
	J6Mesh->GetDrawer()->SetColor(MeshVS_DA_InteriorColor ,Quantity_NOC_RED2);
	J6Mesh->GetDrawer()->SetBoolean(MeshVS_DA_IsAllowOverlapped, Standard_True);
	Standard_Boolean status6 = CImportExport::ReadSTL(aFileName,J6Mesh);
	myAISContext->Display(J6Mesh);
	Fit();

}
void CNTU_OCCT_v2Doc::OnTranslation()
{
}
void CNTU_OCCT_v2Doc::OnPrism()
{
	TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex(gp_Pnt(-200.,-200.,0.));
	Handle(AIS_Shape) ais1 = new AIS_Shape(V1);
	myAISContext->Display(ais1,Standard_False);
	TopoDS_Shape S1 = BRepPrimAPI_MakePrism(V1,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais2 = new AIS_Shape(S1);
	myAISContext->Display(ais2,Standard_False);

	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gp_Pnt(-150.,-150,0.), gp_Pnt(-50.,-50,0.));
	Handle(AIS_Shape) ais3 = new AIS_Shape(E);
	myAISContext->Display(ais3,Standard_False);
	TopoDS_Shape S2 = BRepPrimAPI_MakePrism(E,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais4 = new AIS_Shape(S2);
	myAISContext->SetColor(ais4,Quantity_NOC_CORAL2,Standard_False); 
	myAISContext->SetMaterial(ais4,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais4,Standard_False);

	TopoDS_Edge E1 = BRepBuilderAPI_MakeEdge(gp_Pnt(0.,0.,0.), gp_Pnt(50.,0.,0.));
	TopoDS_Edge E2 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,0.,0.), gp_Pnt(50.,50.,0.));
	TopoDS_Edge E3 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,50.,0.), gp_Pnt(0.,0.,0.));
	TopoDS_Wire W = BRepBuilderAPI_MakeWire(E1,E2,E3);
	TopoDS_Shape S3 = BRepPrimAPI_MakePrism(W,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais5 = new AIS_Shape(W);
	myAISContext->Display(ais5,Standard_False);
	Handle(AIS_Shape) ais6 = new AIS_Shape(S3);
	myAISContext->SetColor(ais6,Quantity_NOC_GREEN,Standard_False); 
	myAISContext->SetMaterial(ais6,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais6,Standard_False);

	gp_Circ c = gp_Circ(gp_Ax2(gp_Pnt(200.,200.,0.),gp_Dir(0.,0.,1.)), 80.);
	TopoDS_Edge Ec = BRepBuilderAPI_MakeEdge(c);
	TopoDS_Wire Wc = BRepBuilderAPI_MakeWire(Ec);
	TopoDS_Face F = BRepBuilderAPI_MakeFace(gp_Pln(gp::XOY()),Wc);
	Handle(AIS_Shape) ais7 = new AIS_Shape(F);
	myAISContext->Display(ais7,Standard_False);
	TopoDS_Shape S4 = BRepPrimAPI_MakePrism(F,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais8 = new AIS_Shape(S4);
	myAISContext->SetColor(ais8,Quantity_NOC_MATRABLUE,Standard_False); 
	myAISContext->SetMaterial(ais8,Graphic3d_NOM_PLASTIC,Standard_False);    
	myAISContext->Display(ais8,Standard_False);
	Fit();
}
void CNTU_OCCT_v2Doc::OnVolume()
{
	TopoDS_Shape S = BRepPrimAPI_MakeWedge(60.,100.,80.,20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myAISContext->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myAISContext->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myAISContext->Display(ais1,Standard_False);
	Fit();


	GProp_GProps System;
	BRepGProp::VolumeProperties(S,System);
	gp_Pnt G = System.CentreOfMass ();
	Standard_Real Volume = System.Mass();
	gp_Mat I = System.MatrixOfInertia();

	TCollection_ExtendedString string("Volume Of all the Shape =");
	TCollection_ExtendedString string1(Volume);
	string += string1;
	string += "\nCenterOfMass : \n   X=";
	string1 = G.X();
	string += string1;
	string += " Y=";
	string1 = G.Y();
	string += string1;
	string += " Z=";
	string1 = G.Z();
	string += string1;
	string +="\n";

	string += "Matrix of Inertia :\n     ";
	string1 = I(1,1);
	string += string1;
	string += " " ;
	string1 = I(1,2);
	string += string1;
	string += " " ;
	string1 = I(1,3);
	string += string1;
	string += "\n     " ;
	string1 = I(2,1);
	string += string1;
	string += " " ;
	string1 = I(2,2);
	string += string1;
	string += " " ;
	string1 = I(2,3);
	string += string1;
	string += "\n     " ;
	string1 = I(3,1);
	string += string1;
	string += " " ;
	string1 = I(3,2);
	string += string1;
	string += " " ;
	string1 = I(3,3);
	string += string1;
	string += "\n" ;

	TCollection_AsciiString Message ("\
									 \n\
									 TopoDS_Shape S = BRepBuilderAPI_MakeWedge(60.,100.,80.,20.);;\n\
									 GProp_GProps System;\n\
									 BRepGProp::VolumeProperties(S,System);\n\
									 gp_Pnt G = System.CentreOfMass ();\n\
									 Standard_Real Volume = System.Mass();\n\
									 gp_Mat I = System.MatrixOfInertia();\n\
									 \n");
	PocessTextInDialog("Volume Properties", Message);
	MessageBoxW (AfxGetApp()->m_pMainWnd->m_hWnd, (const wchar_t* )string.ToExtString(), L"Volume Properties", MB_OK);

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
	TopoDS_ListOfShape   m_shapeList;
	Handle(MeshVS_Mesh) MeshSequence = CImportExport::ReadSTL();

	myAISContext->Display(MeshSequence,Standard_False);

	Fit();
}
void CNTU_OCCT_v2Doc::OnFileExportStl()
{
	CImportExport::SaveSTL(myAISContext);
}