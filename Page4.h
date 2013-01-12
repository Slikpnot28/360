#if !defined(AFX_PAGE4_H__833BC42C_3EC2_4AEB_9BAF_F5406371A814__INCLUDED_)
#define AFX_PAGE4_H__833BC42C_3EC2_4AEB_9BAF_F5406371A814__INCLUDED_
#include "MemDC.h"
#include "BmpBtn.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage4 dialog

class CPage4 : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	CMemDC m_dcbk;
	CBmpBtn m_normal;
	CBmpBtn m_float;
	CBmpBtn m_select;

	CPage4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage4)
	enum { IDD = IDD_PAGE4_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage4)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE4_H__833BC42C_3EC2_4AEB_9BAF_F5406371A814__INCLUDED_)
