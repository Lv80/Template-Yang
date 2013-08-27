
// MFC模板程序View.cpp : CMFC模板程序View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFC模板程序.h"
#endif

#include "MFC模板程序Doc.h"
#include "MFC模板程序View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC模板程序View

IMPLEMENT_DYNCREATE(CMFC模板程序View, CView)

BEGIN_MESSAGE_MAP(CMFC模板程序View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC模板程序View 建構/解構

CMFC模板程序View::CMFC模板程序View()
{
	// TODO: 在此加入建構程式碼

}

CMFC模板程序View::~CMFC模板程序View()
{
}

BOOL CMFC模板程序View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CMFC模板程序View 描繪

void CMFC模板程序View::OnDraw(CDC* /*pDC*/)
{
	CMFC模板程序Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
}

void CMFC模板程序View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC模板程序View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC模板程序View 診斷

#ifdef _DEBUG
void CMFC模板程序View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC模板程序View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC模板程序Doc* CMFC模板程序View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC模板程序Doc)));
	return (CMFC模板程序Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC模板程序View 訊息處理常式
