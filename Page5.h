#if !defined(AFX_PAGE5_H__B27A5D9A_6B79_4D9E_A4E8_3D743C4C67F2__INCLUDED_)
#define AFX_PAGE5_H__B27A5D9A_6B79_4D9E_A4E8_3D743C4C67F2__INCLUDED_
#include "MemDC.h"
#include "BmpBtn.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage5 dialog

class CPage5 : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	CMemDC m_dcbk;
	CBmpBtn m_normal;
	CBmpBtn m_float;
	CBmpBtn m_select;

	CPage5(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage5)
	enum { IDD = IDD_PAGE5_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage5)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE5_H__B27A5D9A_6B79_4D9E_A4E8_3D743C4C67F2__INCLUDED_)
