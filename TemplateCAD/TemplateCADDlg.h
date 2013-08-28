
// TemplateCADDlg.h : ���^�n
//

#pragma once


// CTemplateCADDlg ��Ԓ���K
class CTemplateCADDlg : public CDialogEx
{
// ����
public:
	CTemplateCADDlg(CWnd* pParent = NULL);	// �˜ʽ�����ʽ

// ��Ԓ���K�Y��
	enum { IDD = IDD_TEMPLATECAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧Ԯ


// ��ʽ�a����
protected:
	HICON m_hIcon;

	CToolBar m_wndToolBar;

	CStatusBar m_StatusBar;
	CStatusBarCtrl m_StatusBarCtrl;

	// �a����ӍϢ������ʽ
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnOpenData();
	afx_msg void OnPaint();
	
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);

	void CreateToolBar();
	void CreateStatusBar();

	DECLARE_MESSAGE_MAP()
};
