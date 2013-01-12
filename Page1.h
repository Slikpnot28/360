#if !defined(AFX_PAGE1_H__85DB8862_76B3_4CE2_8EE7_D7383C11D745__INCLUDED_)
#define AFX_PAGE1_H__85DB8862_76B3_4CE2_8EE7_D7383C11D745__INCLUDED_
#include "MemDC.h"
#include "BmpBtn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog
enum{IDC_FAST = 1001,IDC_ALL = 1002,IDC_POINT = 1003};
class CPage1 : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	BOOL SetTipText(UINT id, NMHDR *pTTTStruct, LRESULT *pResult);
	void OnBtPoint();
	void OnBtAll();
	void OnBtFast();
	CMemDC m_dcbk;
	CBmpBtn m_btFast;
	CBmpBtn m_btAll;
	CBmpBtn m_btPoint;

	CPage1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage1)
	enum { IDD = IDD_PAGE1_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__85DB8862_76B3_4CE2_8EE7_D7383C11D745__INCLUDED_)
