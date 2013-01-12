#if !defined(AFX_PAGE2_H__A5EF5D02_7A38_400C_8D01_78E2DB43FB65__INCLUDED_)
#define AFX_PAGE2_H__A5EF5D02_7A38_400C_8D01_78E2DB43FB65__INCLUDED_
#include "MemDC.h"
#include "BmpBtn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog

class CPage2 : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	CMemDC m_dcbk;
	CBmpBtn m_normal;
	CBmpBtn m_float;
	CBmpBtn m_select;

	CPage2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage2)
	enum { IDD = IDD_PAGE2_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage2)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__A5EF5D02_7A38_400C_8D01_78E2DB43FB65__INCLUDED_)
