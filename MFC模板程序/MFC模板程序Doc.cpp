
// MFCģ�����Doc.cpp : CMFCģ�����Doc e�Č���
//

#include "stdafx.h"
// SHARED_HANDLERS ���Զ��x�ڌ����A�[���s�D���ь��Y�x�l��̎��ʽ��
// ATL �����У��K���S�cԓ���������ļ���ʽ�a��
#ifndef SHARED_HANDLERS
#include "MFCģ�����.h"
#endif

#include "MFCģ�����Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCģ�����Doc

IMPLEMENT_DYNCREATE(CMFCģ�����Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCģ�����Doc, CDocument)
END_MESSAGE_MAP()


// CMFCģ�����Doc ����/�☋

CMFCģ�����Doc::CMFCģ�����Doc()
{
	// TODO: �ڴ˼���һ�ν�����ʽ�a

}

CMFCģ�����Doc::~CMFCģ�����Doc()
{
}

BOOL CMFCģ�����Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ˼������³�ʼ����ʽ�a
	// (SDI �ļ������ô��ļ�)

	return TRUE;
}




// CMFCģ�����Doc ���л�

void CMFCģ�����Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ˼��냦���ʽ�a
	}
	else
	{
		// TODO: �ڴ˼����d���ʽ�a
	}
}

#ifdef SHARED_HANDLERS

// �s�D��֧Ԯ
void CMFCģ�����Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸��@�γ�ʽ�a���L�u�ļ����Y��
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �ь�̎��ʽ��֧Ԯ
void CMFCģ�����Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// �O�������ļ��Y�ϵ��ь����ݡ�
	// ���ݲ��֑�ԓ�� ";" ���_

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCģ�����Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCģ�����Doc �\��

#ifdef _DEBUG
void CMFCģ�����Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCģ�����Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCģ�����Doc ����
