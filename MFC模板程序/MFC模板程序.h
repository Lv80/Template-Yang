
// MFCģ�����.h : MFCģ����� ���ó�ʽ�������^�n
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"       // ��Ҫ��̖


// CMFCģ�����App:
// Ո��醌�����e�� MFCģ�����.cpp
//

class CMFCģ�����App : public CWinAppEx
{
public:
	CMFCģ�����App();


// ����
public:
	virtual BOOL InitInstance();

// ��ʽ�a����
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCģ�����App theApp;
