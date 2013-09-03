#pragma once
#include "resource.h"

// CCoordinateDlg dialog

class CCoordinateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCoordinateDlg)

public:
	CCoordinateDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCoordinateDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_COORDINATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:

};
