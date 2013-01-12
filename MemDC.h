#ifndef __MEMDC_H__
#define __MEMDC_H__
//Author:www.baojy.com

class CMemDC :public CDC
{
	CSize m_size;
public:
	void BitTrans(
		int nXDest,		// Ŀ�����X
        int nYDest,		// Ŀ�����Y
        int nWidthDest,	// Ŀ�����
        int nHeightDest,// Ŀ��߶�
		CDC* pDC,		// Ŀ��DC
        int nXSrc,		// ��Դ���X
        int nYSrc,		// ��Դ���Y
        COLORREF crTrans// ͸��ɫ
        )
	{
		CMemDC dcImage(nWidthDest, nHeightDest,pDC);//��ʱDC
		CBitmap bmpMask;
		bmpMask.CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);            // ������ɫ����λͼ
		CDC dcMask;//����DC 
		dcMask.CreateCompatibleDC(pDC);
		dcMask.SelectObject(bmpMask);
		//������λͼ���ڴ�DC�е�λͼ����������ʱDC��
		dcImage.BitBlt( 0, 0, nWidthDest, nHeightDest, this, nXSrc, nYSrc, SRCCOPY);
		
		// ������ʱDC��͸��ɫ
		dcImage.SetBkColor(crTrans);
		//����DC��͸������Ϊ��ɫ��������Ϊ��ɫ
		dcMask.BitBlt(0, 0, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCCOPY);
		
		//��ʱDC͸������Ϊ��ɫ���������򱣳ֲ���
		dcImage.SetBkColor(RGB(0,0,0));
		dcImage.SetTextColor(RGB(255,255,255));
		dcImage.BitBlt( 0, 0, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		
		// Ŀ��DC͸�����ֱ�����Ļ���䣬�������ֱ�ɺ�ɫ
		pDC ->SetBkColor(RGB(255,255,255));
		pDC ->SetTextColor(RGB(0,0,0));
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCPAINT);
	} 
	void StretchTrans(
		int nXDest,			// Ŀ�����X
		int nYDest,			// Ŀ�����Y
		int nWidthDest,     // Ŀ�����
		int nHeightDest,    // Ŀ��߶�
		CDC* pDC,			// Ŀ��DC
		int nXSrc,			// ��Դ���X
		int nYSrc,			// ��Դ���Y
		int nWidthSrc,		// ��Դ����
		int nHeightSrc,		// ��Դ�߶�
		COLORREF crTrans	// ͸��ɫ
		)
	{
		CMemDC dcImage(nWidthDest, nHeightDest,pDC);//��ʱDC
		CBitmap bmpMask;
		// ������ɫ����λͼ
		bmpMask.CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);
		CDC dcMask;
		dcMask.CreateCompatibleDC(pDC);
		dcMask.SelectObject(bmpMask);
	
		// ������λͼ���ڴ�DC�е�λͼ����������ʱDC��
		if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)
			dcImage.BitBlt(0, 0, nWidthDest, nHeightDest, this, nXSrc, nYSrc, SRCCOPY);
		else
			dcImage.StretchBlt(0, 0, nWidthDest, nHeightDest, 
				this, nXSrc, nYSrc, nWidthSrc, nHeightSrc, SRCCOPY);
		
		// ������ʱDC��͸��ɫ
		dcImage.SetBkColor( crTrans);
		//����DC��͸������Ϊ��ɫ��������Ϊ��ɫ
		dcMask.BitBlt(0,0,nWidthDest, nHeightDest,&dcImage,0,0,SRCCOPY);
		
		//��ʱDC͸������Ϊ��ɫ���������򱣳ֲ���
		dcImage.SetBkColor(RGB(0,0,0));
		dcImage.SetTextColor(RGB(255,255,255));
		dcImage.BitBlt(0, 0, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		
		// Ŀ��DC͸�����ֱ�����Ļ���䣬�������ֱ�ɺ�ɫ
		pDC ->SetBkColor(RGB(255,255,255));
		pDC ->SetTextColor(RGB(0,0,0));
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCPAINT);
	}	
	CMemDC()
	{
		m_size.cx = m_size.cy = 0;
	}
	// ����Դ�м���λͼ
	BOOL LoadBitmap(UINT nBitmapID,CDC* pDC=NULL)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(nBitmapID);
		BITMAP bm;
		bitmap.GetBitmap(&bm);
		m_size.cx = bm.bmWidth;
		m_size.cy = bm.bmHeight;
		CreateCompatibleDC(pDC);
		SelectObject(bitmap);
		return TRUE;
	}
	CMemDC(UINT nBitmapID,CDC* pDC=NULL)
	{
		LoadBitmap(nBitmapID,pDC);
	}
	// ��.bmp�ļ��м���λͼ
	BOOL LoadBitmap(LPCSTR szBitmapFile,CDC* pDC=NULL)
	{
		HBITMAP hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			szBitmapFile,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		BITMAP bm;
		// ����һ������λͼ��Ϣ��BITMAP�ṹ
		GetObject(hBitmap,sizeof(bm),&bm);
		m_size.cx = bm.bmWidth;
		m_size.cy = bm.bmHeight;
		// �����豸DC
		CreateCompatibleDC(pDC);
		// ����λͼ
		CreateBitmapIndirect(&bm);
		SelectObject(hBitmap);		
		return TRUE;
	}
	CMemDC(LPCSTR szBitmapFile,CDC* pDC=NULL)
	{
		LoadBitmap(szBitmapFile,pDC);
	}
	//����һ�ſհ��ڴ滭��
	BOOL Create(int cx,int cy,CDC* pDC = NULL)
	{
		if(CreateCompatibleDC(pDC) == NULL)
		{
			MessageBox(NULL,"�����ڴ滭��ʧ��",NULL,MB_OK);
		}
		CBitmap bitmap;
		if(pDC)
			// ����һ�����豸ϵͳ���ݵ�λͼ������ָ��λ������λ��ȣ�������CreateBitmapIndirect()
			bitmap.CreateCompatibleBitmap(pDC,cx,cy);
		else
			bitmap.CreateCompatibleBitmap(&CClientDC(NULL),cx,cy);
		m_size.cx = cx;
		m_size.cy = cy;
		SelectObject(bitmap);
		return TRUE;
	}
	CMemDC(int cx,int cy,CDC* pDC = NULL)
	{
		Create(cx,cy,pDC);
	}
	//�ݻ�
	BOOL DeleteDC()
	{
		if(!GetSafeHdc())
			return TRUE;
		CBitmap * pBitmap = GetCurrentBitmap();
		pBitmap ->DeleteObject();
		return CDC::DeleteDC();
	}
	~CMemDC()
	{
		DeleteDC();
	}
	inline int Width(){return m_size.cx;}
	inline int Height(){return m_size.cy;}
};

#endif //__MEMDC_H__