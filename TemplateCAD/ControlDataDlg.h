#pragma once
#include "afxwin.h"
#include "TemplateData.h"

// CControlDataDlg dialog

class CControlDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CControlDataDlg)

public:
	CControlDataDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CControlDataDlg();

// Dialog Data
	enum { IDD = IDD_CONTROL_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	// Represent the single radio button
	CButton m_btnModeSingle;
	CButton m_btnModeMulti;

	CButton m_btnSingleTypeLine;
	CButton m_btnSingleTypeRect;
	CButton m_btnSingleTypeCircle;

	CButton m_btnMultiTypeLine;
	CButton m_btnMultiTypeRect;
	CButton m_btnMultiTypeCircle;

private:

	CTemplateData::DRAW_MODE m_DrawMode;
	int m_DrawType;

public:

	void CalculateDrawType();
	void EnableSingleDraw();
	void EnableMultiDraw();

public:

	afx_msg void OnClickedRadioSingle();
	afx_msg void OnClickedRadioMulti();
	afx_msg void OnClickedRadioSingleLine();
	afx_msg void OnClickedRadioSingleRect();
	afx_msg void OnClickedRadioSingleCircle();
	afx_msg void OnClickedCheckMultiLine();
	afx_msg void OnBnClickedOk();
};
