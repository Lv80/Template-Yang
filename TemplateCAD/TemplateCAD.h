
// TemplateCAD.h : PROJECT_NAME ���ó�ʽ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


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
};

extern CTemplateCADApp theApp;