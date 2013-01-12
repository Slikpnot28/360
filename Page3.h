#if !defined(AFX_PAGE3_H__FF3E258F_9ACA_49AB_883D_82BB6CEA39CF__INCLUDED_)
#define AFX_PAGE3_H__FF3E258F_9ACA_49AB_883D_82BB6CEA39CF__INCLUDED_
#include "MemDC.h"
#include "BmpBtn.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage3 dialog

class CPage3 : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	CMemDC m_dcbk;
	CBmpBtn m_normal;
	CBmpBtn m_float;
	CBmpBtn m_select;

	CPage3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage3)
	enum { IDD = IDD_PAGE3_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage3)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3_H__FF3E258F_9ACA_49AB_883D_82BB6CEA39CF__INCLUDED_)
