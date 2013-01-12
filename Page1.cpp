// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "360.h"
#include "Page1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog


CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1, CDialog)
	//{{AFX_MSG_MAP(CPage1)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_FAST, OnBtFast)
	ON_BN_CLICKED(IDC_ALL, OnBtAll)
	ON_BN_CLICKED(IDC_POINT, OnBtPoint)
	ON_NOTIFY_EX(TTN_NEEDTEXT,0,SetTipText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

BOOL CPage1::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_dcbk.LoadBitmap(IDB_PAGE1); //加载背景
	
	m_btFast.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(4,247,4+212,247+175),this,IDC_FAST);
	m_btFast.SetBitmaps(IDB_FAST1,IDB_FAST2,IDB_FAST3);
	m_btAll.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(216,247,216+198,247+175),this,IDC_ALL);
	m_btAll.SetBitmaps(IDB_ALL1,IDB_ALL2,IDB_ALL3);
	m_btPoint.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(414,247,414+209,247+175),this,IDC_POINT);
	m_btPoint.SetBitmaps(IDB_POINT1,IDB_POINT2,IDB_POINT3);

	EnableToolTips(TRUE); 
	m_tt.Create(this); 
	m_tt.Activate(TRUE); 
	
	m_tt.AddTool(&m_btFast,LPSTR_TEXTCALLBACK);
	m_tt.AddTool(&m_btAll,LPSTR_TEXTCALLBACK);
	m_tt.AddTool(&m_btPoint,LPSTR_TEXTCALLBACK);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPage1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetClientRect(rect);
	dc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&m_dcbk,0,0,SRCCOPY);
}

void CPage1::OnBtFast()
{

}

void CPage1::OnBtAll()
{

}

void CPage1::OnBtPoint()
{

}


BOOL CPage1::SetTipText(UINT id, NMHDR *pTTTStruct, LRESULT *pResult)
{
	TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pTTTStruct;    
	UINT nID =pTTTStruct->idFrom; //得到相应窗口ID
	if (pTTT->uFlags & TTF_IDISHWND)
	{ 
		nID = ::GetDlgCtrlID((HWND)nID);//从HWND得到ID值
		switch(nID) 
		{
		case IDC_FAST:       
			{
				strcpy(pTTT->lpszText,"扫描病毒、木马藏身的关键位置，精确查杀");//设置 
			}
			return TRUE; 
		case IDC_ALL:       
			{
				strcpy(pTTT->lpszText,"对您计算机的所有分区进行扫描");
			}
			return TRUE; 
		case IDC_POINT:       
			{
				strcpy(pTTT->lpszText,"扫描您指定的目录或文件");
			}
			return TRUE; 
		}
	} 
	return(FALSE); 
}
