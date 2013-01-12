// 360.h : main header file for the 360 application
//

#if !defined(AFX_360_H__CC667B81_33A8_46CC_872D_81F6FBA87938__INCLUDED_)
#define AFX_360_H__CC667B81_33A8_46CC_872D_81F6FBA87938__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy360App:
// See 360.cpp for the implementation of this class
//

class CMy360App : public CWinApp
{
public:
	CMy360App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy360App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy360App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_360_H__CC667B81_33A8_46CC_872D_81F6FBA87938__INCLUDED_)
