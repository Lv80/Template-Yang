
// MFCģ�����View.cpp : CMFCģ�����View e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
#ifndef SHARED_HANDLERS
#include "MFCģ�����.h"
#endif

#include "MFCģ�����Doc.h"
#include "MFCģ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCģ�����View

IMPLEMENT_DYNCREATE(CMFCģ�����View, CView)

BEGIN_MESSAGE_MAP(CMFCģ�����View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCģ�����View ����/�☋

CMFCģ�����View::CMFCģ�����View()
{
	// TODO: �ڴ˼��뽨����ʽ�a

}

CMFCģ�����View::~CMFCģ�����View()
{
}

BOOL CMFCģ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˽����޸� CREATESTRUCT cs 
	// �_���޸�ҕ��e���ʽ��Ŀ��

	return CView::PreCreateWindow(cs);
}

// CMFCģ�����View ���L

void CMFCģ�����View::OnDraw(CDC* /*pDC*/)
{
	CMFCģ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˼���ԭ���Y�ϵ����L��ʽ�a
}

void CMFCģ�����View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCģ�����View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCģ�����View �\��

#ifdef _DEBUG
void CMFCģ�����View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCģ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCģ�����Doc* CMFCģ�����View::GetDocument() const // ��Ƕ�ǂ��e�汾
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCģ�����Doc)));
	return (CMFCģ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCģ�����View ӍϢ̎��ʽ
