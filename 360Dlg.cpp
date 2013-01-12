// 360Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "360.h"
#include "360Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy360Dlg dialog

CMy360Dlg::CMy360Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy360Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy360Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy360Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy360Dlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy360Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy360Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CLOSE, OnBtClose)
	ON_BN_CLICKED(IDC_MINI, OnBtMini)
	ON_BN_CLICKED(IDC_MENU, OnBtMenu)
	ON_MESSAGE(BTN_SELCHANGE, OnSelChangeTab)
	ON_NOTIFY_EX(TTN_NEEDTEXT,0,SetTipText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy360Dlg message handlers

BOOL CMy360Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ModifyStyle(GetStyle(),0);
	ModifyStyleEx(GetExStyle(),WS_EX_TOOLWINDOW);
	// 加载背景,从资源中加载
	m_dcbk.LoadBitmap(IDB_BACK); 

	// 设置窗口和图片大小一致
	MoveWindow(0,0,m_dcbk.Width(),m_dcbk.Height());
	// 加载系统光标
	m_hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	SetClassLong(m_hWnd,GCL_HICON,(LONG)m_hIcon);

	// 加载关闭、最小化、菜单按钮图标
	m_btClose.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,
		CRect(791,1,791+46,1+19),this,IDC_CLOSE);
	m_btClose.SetBitmaps(IDB_CLOSE1,IDB_CLOSE2,IDB_CLOSE3);

	m_btMini.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,
		CRect(758,1,758+34,1+19),this,IDC_MINI);
	m_btMini.SetBitmaps(IDB_MINI1,IDB_MINI2,IDB_MINI3);

	m_btMenu.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,
		CRect(725,1,726+32,1+19),this,IDC_MENU);
	m_btMenu.SetBitmaps(IDB_MENU1,IDB_MENU2,IDB_MENU3);


	m_tab.Create(WS_CHILD|WS_VISIBLE,CRect(11,83,11+123*5+119,83+39),this,IDC_TAB);
	m_tab.SetItemSize(CSize(123,39));
	m_iList.Create(123,39,ILC_COLOR32,12,12);

	int i=0;
	CString str;
	// 贴图
	while(i<19)
	{
		str.Format("./img/%d.bmp",i);
		// HANDLE LoadImage()可以加载icon, cursor, or bitmap,此处加载bitmap
		HBITMAP hb=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			str,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		// 将每一张图添加到CImageList中去
		m_iList.Add(CBitmap::FromHandle(hb),RGB(0,0,0));
		i++;
	}
	// 将所以的图添加到对应的位置
	m_tab.SetImageList(&m_iList);
	// 将6张图按顺序添加相应的位置
	m_tab.InsertItem(0,3,1);
	m_tab.InsertItem(1,5,2);
	m_tab.InsertItem(2,8,6);
	m_tab.InsertItem(3,11,9);
	m_tab.InsertItem(4,14,11);
	m_tab.InsertItem(5,17,15);



	
    // 创建六个子窗口
	CRect rect(4,122,4+842,122+451);

	m_p1.Create(IDD_PAGE1_DLG,this);
	m_p1.MoveWindow(rect);
	m_p1.ShowWindow(SW_SHOW);
	
	m_p2.Create(IDD_PAGE2_DLG,this);
	m_p2.MoveWindow(rect);

	m_p3.Create(IDD_PAGE3_DLG,this);
	m_p3.MoveWindow(rect);
	
	m_p4.Create(IDD_PAGE4_DLG,this);
	m_p4.MoveWindow(rect);

	m_p5.Create(IDD_PAGE5_DLG,this);
	m_p5.MoveWindow(rect);

	m_p6.Create(IDD_PAGE6_DLG,this);
	m_p6.MoveWindow(rect);


//	m_opcl.Create(NULL,WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,CRect(435,258,435+56,258+18),this,IDC_CLOSE);
//	m_opcl.SetBitmaps(IDB_OPEN,IDB_CLOSE);
//动态显示文字

	EnableToolTips(TRUE);
	m_tt.Create(this);
	m_tt.Activate(TRUE);

	m_tt.AddTool(&m_btMenu,LPSTR_TEXTCALLBACK);
	m_tt.AddTool(&m_btMini,LPSTR_TEXTCALLBACK);
	m_tt.AddTool(&m_btClose,LPSTR_TEXTCALLBACK);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy360Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy360Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy360Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy360Dlg::OnBtClose()
{
	CDialog::OnCancel();
}

void CMy360Dlg::OnBtMenu()
{
	CMenu menu;
	menu.LoadMenu(IDR_MENU);
	CMenu *pMenu = menu.GetSubMenu(0);
	CPoint pt;
	GetCursorPos(&pt);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y+15,this);
}

void CMy360Dlg::OnBtMini()
{
	WINDOWPLACEMENT lp;
	GetWindowPlacement(&lp);
	lp.showCmd = SW_SHOWMINIMIZED;
	SetWindowPlacement(&lp);
}

BOOL CMy360Dlg::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	GetClientRect(rect);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&m_dcbk,0,0,SRCCOPY);
	return TRUE;
}

UINT CMy360Dlg::OnNcHitTest(CPoint point) 
{
	UINT nHitTest = CDialog::OnNcHitTest(point);
	if(nHitTest == HTCLIENT && ::GetAsyncKeyState(MK_LBUTTON) < 0)
		nHitTest = HTCAPTION;
	return nHitTest;
}



void CMy360Dlg::OnSelChangeTab(WPARAM w, LPARAM lR)
{
	CWnd * pWnd[]={&m_p1,&m_p2,&m_p3,&m_p4,&m_p5,&m_p6};
	int i=0;
	int nCount=m_tab.GetItemCount();
	int nSel=m_tab.GetCurSel();
	while(i<nCount)
	{
		pWnd[i]->ShowWindow((i==nSel)?SW_SHOW:SW_HIDE);
		i++;
	}
}

BOOL CMy360Dlg::SetTipText(UINT id, NMHDR *pTTTStruct, LRESULT *pResult)
{
	TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pTTTStruct;    
	UINT nID =pTTTStruct->idFrom; //得到相应窗口ID
	if (pTTT->uFlags & TTF_IDISHWND)
	{ 
		nID = ::GetDlgCtrlID((HWND)nID);//从HWND得到ID值
		switch(nID) 
		{
		case IDC_CLOSE:
			{
				strcpy(pTTT->lpszText,"关闭");
			}
			return TRUE; 
		case IDC_MINI:
			{
				strcpy(pTTT->lpszText,"最小化");
			}
			return TRUE; 
		case IDC_MENU:
			{
				strcpy(pTTT->lpszText,"菜单");
			}
			return TRUE; 
		}
	} 
	return(FALSE); 
}
