
// NTU_OCCT_v2Doc.h : interface of the CNTU_OCCT_v2Doc class
//


#pragma once
#include <OCC_3dDoc.h>




class CNTU_OCCT_v2Doc : public OCC_3dDoc
{
	DECLARE_DYNCREATE(CNTU_OCCT_v2Doc)
protected: // create from serialization only
	CNTU_OCCT_v2Doc();
	void InitViewButtons();
	void DoSample();

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CNTU_OCCT_v2Doc();
	void UpdateResultMessageDlg (CString theTitle, const TCollection_AsciiString& theMessage);
	void UpdateResultMessageDlg (CString theTitle, CString theMessage);

public:
	void ActivateFrame(CRuntimeClass* pViewClass, int nCmdShow = SW_RESTORE  );
	virtual void Popup (const Standard_Integer  x       ,
		const Standard_Integer  y       ,
		const Handle(V3d_View)& aView   );
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
	Handle_AIS_Shape GetBox();

protected:

// Generated message map functions
	afx_msg void OnBox();
	afx_msg void OnCylinder();
	afx_msg void OnSphere();

protected:
	DECLARE_MESSAGE_MAP()
	Handle_AIS_Shape myCylinder;
	Handle_AIS_Shape mySphere;
	Handle_AIS_Shape myBox;
#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
