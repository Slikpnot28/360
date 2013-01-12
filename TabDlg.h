#if !defined(AFX_CBitmapTab_H__3A257AE4_5019_4E06_B21A_F466476BF7D5__INCLUDED_)
#define AFX_CBitmapTab_H__3A257AE4_5019_4E06_B21A_F466476BF7D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CBitmapTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitmapTab window
#include <afxtempl.h>


enum{BTN_SELCHANGE = WM_USER + 1234};
enum{BTN_FOCUS = WM_USER +1235};

class CBitmapTab : public CWnd
{
/************************************************************************/
/* @struct STData : 保存每张图片的节点
/* @CArray<STData,STData> : 各张图片的信息
/************************************************************************/
struct STData
{
	int nItem;        // 行(图的序列号)
	int nItemSel;     // 列
	int nItemFocus;   // 
};	
	CArray<STData,STData>m_arr;

	// Construction
	int m_nSel;
	int m_nFocus;
	CSize m_size;
	CImageList *m_pImageList;
	void RegisterClass();
public:
	static LPCSTR m_szClass;

	
	CBitmapTab();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapTab)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL GetItemRect(int nItem, LPRECT lpRect);
	CSize SetItemSize(CSize size);
	BOOL InsertItem(int nItem,int nItemSel,int nItemFocus);
	CImageList * SetImageList(CImageList* pImageList);
	BOOL Create(DWORD dwStyle,const RECT& rect,CWnd* pParentWmd,UINT nID);
	virtual ~CBitmapTab();

	CImageList* GetImageList()const
	{
		return m_pImageList;
	}
	int GetItemCount()const;
	int GetCurSel()const
	{
		return m_nSel;
	}
	int GetCurSel(int nItem)
	{
		m_nSel = nItem;
		Invalidate(FALSE);
	}
	BOOL DeleteItem(int nItem)
	{
		if(nItem >= m_arr.GetSize())
			return FALSE;
		m_arr.RemoveAt(nItem);
		return TRUE;
	}
	BOOL DeleteAllItems()
	{
		m_arr.RemoveAll();
		Invalidate(FALSE);
	}
	// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapTab)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CBitmapTab_H__3A257AE4_5019_4E06_B21A_F466476BF7D5__INCLUDED_)
