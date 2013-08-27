
// MFC模板程序.h : MFC模板程序 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CMFC模板程序App:
// 請參閱實作此類別的 MFC模板程序.cpp
//

class CMFC模板程序App : public CWinAppEx
{
public:
	CMFC模板程序App();


// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC模板程序App theApp;
