// Page3.cpp : implementation file
//

#include "stdafx.h"
#include "360.h"
#include "Page3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage3 dialog


CPage3::CPage3(CWnd* pParent /*=NULL*/)
	: CDialog(CPage3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage3, CDialog)
	//{{AFX_MSG_MAP(CPage3)
	ON_WM_PAINT()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3 message handlers

BOOL CPage3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_dcbk.LoadBitmap(IDB_PAGE3);
	MoveWindow(0,0,m_dcbk.Width(),m_dcbk.Height());
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPage3::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rect;
	GetClientRect(rect);
	dc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&m_dcbk,0,0,SRCCOPY);
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CPage3::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}
