
// MFCģ�����View.h : CMFCģ�����View e�Ľ���
//

#pragma once


class CMFCģ�����View : public CView
{
protected: // �H�����л�����
	CMFCģ�����View();
	DECLARE_DYNCREATE(CMFCģ�����View)

// ����
public:
	CMFCģ�����Doc* GetDocument() const;

// ���I
public:

// ����
public:
	virtual void OnDraw(CDC* pDC);  // ���������L�˙zҕ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ��ʽ�a����
public:
	virtual ~CMFCģ�����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �a����ӍϢ������ʽ
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCģ�����View.cpp �еĂ��e�汾
inline CMFCģ�����Doc* CMFCģ�����View::GetDocument() const
   { return reinterpret_cast<CMFCģ�����Doc*>(m_pDocument); }
#endif

