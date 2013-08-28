
// TemplateCADDlg.h : 標頭檔
//

#pragma once


// CTemplateCADDlg 對話方塊
class CTemplateCADDlg : public CDialogEx
{
// 建構
public:
	CTemplateCADDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_TEMPLATECAD_DIALOG };

protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

// 程式碼實作
protected:

	HICON m_hIcon;

	CToolBar m_wndToolBar;

	CStatusBar m_StatusBar;
	CStatusBarCtrl m_StatusBarCtrl;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();

	//菜单事件
	afx_msg void OnOpenData();
	afx_msg void OnSaveData();
	afx_msg void OnSaveDataAs();
	afx_msg void OnControlData();
	afx_msg void OnCoorData();
	
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);

	void CreateToolBar();
	void CreateStatusBar();

	DECLARE_MESSAGE_MAP()

private:

	void SaveLastCommand(UINT nCommandId);

	void MarkMenuById( UINT nMenuId );

private:

	UINT m_nLastCommandId;
};
