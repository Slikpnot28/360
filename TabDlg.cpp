// CBitmapTab.cpp : implementation file
//

#include "stdafx.h"
#include "360.h"
#include "TabDlg.h"
#include "MemDC.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapTab

CBitmapTab::CBitmapTab()
{
}

CBitmapTab::~CBitmapTab()
{
}

LPCSTR CBitmapTab::m_szClass = "lwz_tab";
BEGIN_MESSAGE_MAP(CBitmapTab, CWnd)
	//{{AFX_MSG_MAP(CBitmapTab)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBitmapTab message handlers
int CBitmapTab::GetItemCount()const
{
	int size = m_arr.GetSize();
	return size;
}


void CBitmapTab::RegisterClass()
{
	HINSTANCE hInstance = AfxGetInstanceHandle();
	WNDCLASS wc = {0};
	if(::GetClassInfo(hInstance,m_szClass,&wc))
		return;
	wc.lpszClassName = m_szClass;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_BTNFACE;
	wc.style = CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc = ::DefWindowProc;
	if(!AfxRegisterClass(&wc))
	{
		TRACE("Unable to register window class %s \n",m_szClass);
		return;
	}
}

BOOL CBitmapTab::Create(DWORD dwStyle, const RECT &rect, CWnd *pParentWmd, UINT nID)
{
	RegisterClass();
	return CWnd::Create(m_szClass,NULL,dwStyle,rect,pParentWmd,nID);
}

CImageList * CBitmapTab::SetImageList(CImageList *pImageList)
{
	CImageList *p = m_pImageList;
	m_pImageList = pImageList;
	return p;
}

BOOL CBitmapTab::InsertItem(int nItem, int nItemSel, int nItemFocus)
{
	STData data = {nItem,nItemSel,nItemFocus};
	m_arr.Add(data);
	Invalidate(FALSE);
	return TRUE;
}

CSize CBitmapTab::SetItemSize(CSize size)
{
	CSize s= m_size;
	m_size = size;
	return s;
}

BOOL CBitmapTab::GetItemRect(int nItem, LPRECT lpRect)
{
	CRect rect(0,0,m_size.cx,m_size.cy);
	int i = 0;
	int nSel = m_arr.GetSize();
	while(i<nSel)
	{
		if(i == nItem)
		{
			CRect rt(CPoint(m_size.cx*i,0),CSize(m_size.cx,m_size.cy));
			*lpRect = rt;
			return TRUE;
		}
		rect.OffsetRect(CSize(m_size.cx,0));
		i++;
	}
	return TRUE;
}

void CBitmapTab::OnPaint() 
{
	CPaintDC dc(this);
	
	if(!m_pImageList)
		return;
	int i = 0;
	int nSize = m_arr.GetSize();
	CRect rect(0,0,m_size.cx,m_size.cy);
	
	CMemDC mdc;
	while (i<nSize)
	{
		if(i == m_nSel)
		{
			m_pImageList->Draw(&dc,i*3+2,rect.TopLeft(),ILD_NORMAL);
		}
		else
		{
			if(GetCapture() == this && i ==m_nFocus )
				m_pImageList->Draw(&dc,i*3+1,rect.TopLeft(),ILD_NORMAL);
			else
				m_pImageList->Draw(&dc,i*3,rect.TopLeft(),ILD_NORMAL);
		}
		rect.OffsetRect(m_size.cx,0);
		i++;
	}
	dc.BitBlt(0,0,rect.Width()*6,rect.Height(),&mdc,0,0,SRCCOPY);
}

void CBitmapTab::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CRect rect(0,0,m_size.cx,m_size.cy);
	int i = 0;
	int nSize = m_arr.GetSize();
	while (i < nSize)
	{
		if(rect.PtInRect(point))
		{
			if(i!=m_nSel)
			{
				m_nSel = i;
				Invalidate(FALSE);
				CWnd * pWnd = GetParent();
				if(pWnd)
				{
					pWnd->PostMessage(BTN_SELCHANGE,i,GetDlgCtrlID());
				}
			}
		}
		rect.OffsetRect(CSize(m_size.cx,0));
		i++;
	}
	CWnd::OnLButtonDown(nFlags, point);
}
#ifndef IDC_HAND
#define IDC_HAND            MAKEINTRESOURCE(32649)
#endif /* WINVER >= 0x0500 */

void CBitmapTab::OnMouseMove(UINT nFlags, CPoint point) 
{
	::SetCursor(::LoadCursor(NULL,IDC_HAND));
	
	CRect rect(0,0,m_size.cx,m_size.cy);
	int i=0;
	int nSize=m_arr.GetSize();
	if(GetCapture() != this)
	{
		
		SetCapture();
		
		Invalidate(FALSE);
	}
	else
	{
		
		while(i<nSize)
		{
			if(rect.PtInRect(point))
			{
				
				if(i!=m_nFocus)
				{
					m_nFocus=i;
					Invalidate(FALSE);
					CWnd * pWnd=GetParent();
					if(pWnd)
					{
						pWnd->PostMessage(BTN_FOCUS,i,GetDlgCtrlID());
						
					}
				}
			}
			else
			{
				ReleaseCapture();
				Invalidate(FALSE);
			}
			
			rect.OffsetRect(CSize(m_size.cx,0));
			i++;
		}
	}
	CWnd::OnMouseMove(nFlags, point);
}

void CBitmapTab::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CWnd::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}
