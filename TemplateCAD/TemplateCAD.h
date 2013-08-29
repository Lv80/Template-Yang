
// TemplateCAD.h : PROJECT_NAME 應用程式的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號

#define TEMPLATE_CONFIG_FILE _T("配置文件.txt")

// CTemplateCADApp:
// 請參閱實作此類別的 TemplateCAD.cpp
//

class CTemplateCADApp : public CWinApp
{
public:
	CTemplateCADApp();

// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作

	DECLARE_MESSAGE_MAP()
	afx_msg void OnUpdateOpendata(CCmdUI *pCmdUI);

public:

	CString& GetWorkingDirectory() { return m_szWorkingDirectory; }
	CString& GetWorkingPrjFile() { return m_szWoringPrjFile; }

protected:

	void InitializeWorkingDir();
	void InitializeConfig();

private:

	CString m_szWorkingDirectory;
	CString m_szWoringPrjFile;
	CString m_szConfigFile;
};

extern CTemplateCADApp theApp;