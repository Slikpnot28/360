#if !defined(AFX_PAGE6_H__87EFB3B3_4547_4419_8F82_E1CE9DA6A6E8__INCLUDED_)
#define AFX_PAGE6_H__87EFB3B3_4547_4419_8F82_E1CE9DA6A6E8__INCLUDED_
#include "MemDC.h"
#include "BmpBtn.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page6.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage6 dialog

class CPage6 : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	CMemDC m_dcbk;
	CBmpBtn m_normal;
	CBmpBtn m_float;
	CBmpBtn m_select;

	CPage6(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage6)
	enum { IDD = IDD_PAGE6_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage6)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage6)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE6_H__87EFB3B3_4547_4419_8F82_E1CE9DA6A6E8__INCLUDED_)
