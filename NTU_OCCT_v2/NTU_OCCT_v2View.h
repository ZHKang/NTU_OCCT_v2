
// NTU_OCCT_v2View.h : interface of the CNTU_OCCT_v2View class
//

#pragma once
#include <OCC_3dView.h>


class CNTU_OCCT_v2View : public CView//OCC_3dView
{
protected: // create from serialization only
	CNTU_OCCT_v2View();
	DECLARE_DYNCREATE(CNTU_OCCT_v2View)

// Attributes
public:
	CNTU_OCCT_v2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CNTU_OCCT_v2View();
	afx_msg void OnStop();
	//void FitAll(Quantity_Coefficient Coef)
	//{
	//	if (Coef != -1)
	//		myView->FitAll(Coef);
	//	else myView->FitAll();
	//	myView->ZFitAll();
	//};
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NTU_OCCT_v2View.cpp
inline CNTU_OCCT_v2Doc* CNTU_OCCT_v2View::GetDocument() const
   { return reinterpret_cast<CNTU_OCCT_v2Doc*>(m_pDocument); }
#endif

