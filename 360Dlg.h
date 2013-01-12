// 360Dlg.h : header file
//
#include "BmpBtn.h"
#include "MemDC.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
#include "Page4.h"
#include "Page5.h"
#include "Page6.h"
#include "TabDlg.h"
#if !defined(AFX_360DLG_H__20D50D3E_FF56_4938_8F38_F5FD1A46BE8A__INCLUDED_)
#define AFX_360DLG_H__20D50D3E_FF56_4938_8F38_F5FD1A46BE8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy360Dlg dialog
enum{IDC_CLOSE = 1000,IDC_MINI = 2001,IDC_MENU = 3001};

class CMy360Dlg : public CDialog
{
// Construction
	CToolTipCtrl m_tt;
public:
	BOOL SetTipText(UINT id,NMHDR *pTTTStruct,LRESULT *pResult);
	void OnSelChangeTab(WPARAM w,LPARAM lR);
	CImageList m_iList;         
	CMemDC m_dcbk;
	CBmpBtn m_tab1,m_tab2,m_tab3,m_tab4,m_tab5,m_tab6;
	
	CPage1 m_p1;
	CPage2 m_p2;
	CPage3 m_p3;
	CPage4 m_p4;
	CPage5 m_p5;
	CPage6 m_p6;

	CBmpBtn m_btClose;
	CBmpBtn m_btMini;
	CBmpBtn m_btMenu;

	CBitmapTab m_tab;
	void OnBtMini();
	void OnBtMenu();
	void OnBtClose();
	CMy360Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy360Dlg)
	enum { IDD = IDD_MY360_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy360Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy360Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnNcPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_360DLG_H__20D50D3E_FF56_4938_8F38_F5FD1A46BE8A__INCLUDED_)
