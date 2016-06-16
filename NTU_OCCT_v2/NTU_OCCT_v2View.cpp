
// NTU_OCCT_v2View.cpp : implementation of the CNTU_OCCT_v2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NTU_OCCT_v2.h"
#endif

#include "NTU_OCCT_v2Doc.h"
#include "NTU_OCCT_v2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNTU_OCCT_v2View

IMPLEMENT_DYNCREATE(CNTU_OCCT_v2View, CView)

BEGIN_MESSAGE_MAP(CNTU_OCCT_v2View, CView)
END_MESSAGE_MAP()

// CNTU_OCCT_v2View construction/destruction

CNTU_OCCT_v2View::CNTU_OCCT_v2View()
{
	// TODO: add construction code here

}

CNTU_OCCT_v2View::~CNTU_OCCT_v2View()
{
}

BOOL CNTU_OCCT_v2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CNTU_OCCT_v2View drawing

void CNTU_OCCT_v2View::OnDraw(CDC* /*pDC*/)
{
	CNTU_OCCT_v2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CNTU_OCCT_v2View diagnostics

#ifdef _DEBUG
void CNTU_OCCT_v2View::AssertValid() const
{
	CView::AssertValid();
}

void CNTU_OCCT_v2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNTU_OCCT_v2Doc* CNTU_OCCT_v2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNTU_OCCT_v2Doc)));
	return (CNTU_OCCT_v2Doc*)m_pDocument;
}
#endif //_DEBUG


// CNTU_OCCT_v2View message handlers
