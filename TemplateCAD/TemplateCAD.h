
// TemplateCAD.h : PROJECT_NAME ���ó�ʽ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖

#define TEMPLATE_CONFIG_FILE _T("�����ļ�.txt")

// CTemplateCADApp:
// Ո��醌�����e�� TemplateCAD.cpp
//

class CTemplateCADApp : public CWinApp
{
public:
	CTemplateCADApp();

// ����
public:
	virtual BOOL InitInstance();

// ��ʽ�a����

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