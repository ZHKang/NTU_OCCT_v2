
// NTU_OCCT_v2Doc.h : interface of the CNTU_OCCT_v2Doc class
//


#pragma once
#include <OCC_3dDoc.h>




class CNTU_OCCT_v2Doc : public OCC_3dDoc
{
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

// Implementation
public:
	virtual ~CNTU_OCCT_v2Doc();
public:
	void ActivateFrame(CRuntimeClass* pViewClass, int nCmdShow = SW_RESTORE  );
	virtual void Popup (const Standard_Integer  x       ,
		const Standard_Integer  y       ,
		const Handle(V3d_View)& aView   );
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
	afx_msg void OnRobot();
	afx_msg void OnTranslation();

protected:
	DECLARE_MESSAGE_MAP()
	Handle_AIS_Shape myCylinder;
	Handle_AIS_Shape mySphere;
	Handle_AIS_Shape myBox;
};
