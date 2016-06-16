
// NTU_OCCT_v2.h : main header file for the NTU_OCCT_v2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include <OCC_App.h>

// CNTU_OCCT_v2App:
// See NTU_OCCT_v2.cpp for the implementation of this class
//

class CNTU_OCCT_v2App : public OCC_App
{
public:
	CNTU_OCCT_v2App();
	~CNTU_OCCT_v2App();


// Overrides
public:
	virtual BOOL InitInstance();
	//virtual int ExitInstance();

// Implementation
	DECLARE_MESSAGE_MAP()
private:
	CToolBar *m_ImpExpToolbar;
};

//extern CNTU_OCCT_v2App theApp;
