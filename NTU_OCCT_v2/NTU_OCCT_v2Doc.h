
// NTU_OCCT_v2Doc.h : interface of the CNTU_OCCT_v2Doc class
//


#pragma once
#include <OCC_3dDoc.h>




class CNTU_OCCT_v2Doc : public OCC_3dDoc
{
public:
	CNTU_OCCT_v2Doc();
	DECLARE_DYNCREATE(CNTU_OCCT_v2Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	int ReadSTLFcn(TCollection_AsciiString &aFileName);

// Implementation
public:
	virtual ~CNTU_OCCT_v2Doc();
public:
	//void ActivateFrame(CRuntimeClass* pViewClass, int nCmdShow = SW_RESTORE  );
	virtual void Popup (const Standard_Integer  x ,
		const Standard_Integer  y       ,
		const Handle(V3d_View)& aView   );  // ���U�k��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
	afx_msg void OnBox();
	afx_msg void OnCylinder();
	afx_msg void OnSphere();
	afx_msg void OnRotate();
	afx_msg void OnTorus();
	afx_msg void OnRobot();
	afx_msg void OnTranslation();
	afx_msg void OnPrism();
	afx_msg void OnVolume();
	// Import Export
	afx_msg void OnFileImportCSFDB();
	afx_msg void OnFileExportCSFDB();
	afx_msg void OnFileImportIges();
	afx_msg void OnFileExportIges();
	afx_msg void OnFileImportStep();
	afx_msg void OnFileExportStep();
	afx_msg void OnFileImportBrep();
	afx_msg void OnFileExportBrep();

	afx_msg void OnFileExportVrml();
	afx_msg void OnFileImportStl();
	afx_msg void OnFileExportStl();

protected:
	DECLARE_MESSAGE_MAP()
	Handle_AIS_Shape myCylinder;
	Handle_AIS_Shape mySphere;
	Handle_AIS_Shape myBox;
	gp_Pnt myBoxPntOld;
	gp_Pnt myBoxPntNew;
public:
	void TransformationFcn(int TranslationSelec);
};
