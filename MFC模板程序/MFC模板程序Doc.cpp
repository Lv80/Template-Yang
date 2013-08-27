
// MFC模板程序Doc.cpp : CMFC模板程序Doc 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFC模板程序.h"
#endif

#include "MFC模板程序Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC模板程序Doc

IMPLEMENT_DYNCREATE(CMFC模板程序Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC模板程序Doc, CDocument)
END_MESSAGE_MAP()


// CMFC模板程序Doc 建構/解構

CMFC模板程序Doc::CMFC模板程序Doc()
{
	// TODO: 在此加入一次建構程式碼

}

CMFC模板程序Doc::~CMFC模板程序Doc()
{
}

BOOL CMFC模板程序Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此加入重新初始化程式碼
	// (SDI 文件會重用此文件)

	return TRUE;
}




// CMFC模板程序Doc 序列化

void CMFC模板程序Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此加入儲存程式碼
	}
	else
	{
		// TODO: 在此加入載入程式碼
	}
}

#ifdef SHARED_HANDLERS

// 縮圖的支援
void CMFC模板程序Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改這段程式碼以繪製文件的資料
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

// 搜尋處理常式的支援
void CMFC模板程序Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 設定來自文件資料的搜尋內容。
	// 內容部分應該以 ";" 隔開

	// 範例:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFC模板程序Doc::SetSearchContent(const CString& value)
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

// CMFC模板程序Doc 診斷

#ifdef _DEBUG
void CMFC模板程序Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC模板程序Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC模板程序Doc 命令
