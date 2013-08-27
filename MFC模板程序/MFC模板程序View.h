
// MFC模板程序View.h : CMFC模板程序View 類別的介面
//

#pragma once


class CMFC模板程序View : public CView
{
protected: // 僅從序列化建立
	CMFC模板程序View();
	DECLARE_DYNCREATE(CMFC模板程序View)

// 屬性
public:
	CMFC模板程序Doc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 程式碼實作
public:
	virtual ~CMFC模板程序View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC模板程序View.cpp 中的偵錯版本
inline CMFC模板程序Doc* CMFC模板程序View::GetDocument() const
   { return reinterpret_cast<CMFC模板程序Doc*>(m_pDocument); }
#endif

