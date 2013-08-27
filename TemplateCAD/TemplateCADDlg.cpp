
// TemplateCADDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "resource.h"
#include "TemplateCAD.h"
#include "TemplateCADDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CTemplateCADDlg 對話方塊
static UINT indicators[] = { ID_SEPARATOR, IDS_COMPANY, IDS_MICROSOFT, IDS_TIME };

CTemplateCADDlg::CTemplateCADDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTemplateCADDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTemplateCADDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTemplateCADDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_OPENDATA, &CTemplateCADDlg::OnOpenData) //下面是其他一些建立好的菜单选项的消息映射
END_MESSAGE_MAP()

void CTemplateCADDlg::OnOpenData()
{
	int a = 0;
}

// CTemplateCADDlg 訊息處理常式

BOOL CTemplateCADDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->SetBackgroundColor(RGB(207,224,226),RGB(13,125,188));

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	CreateToolBar();

	CreateStatusBar();

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CTemplateCADDlg::CreateToolBar()
{
	// 创建工具条并调入资源
	if(!m_wndToolBar.CreateEx(this,TBSTYLE_TOOLTIPS, WS_CHILD | WS_VISIBLE | CBRS_TOP
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) 
		|| !m_wndToolBar.LoadToolBar(IDR_TOOLBAR_MAIN))
	{
		TRACE0("Failed to Create Dialog Toolbar\n");
		EndDialog(IDCANCEL);
	}

	CRect rcClientOld; // 加入客户区RECT
	CRect rcClientNew; // 加入TOOLBAR后的CLIENT RECT
	GetClientRect(rcClientOld); // 

	// Called to reposition and resize control bars in the client area of a window
	// The reposQuery FLAG does not really traw the Toolbar. It only does the calculations.
	// And puts the new ClientRect values in rcClientNew so we can do the rest of the Math.
	//重新计算RECT大小
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0,reposQuery,rcClientNew);

	// All of the Child Windows (Controls) now need to be moved so the Tollbar does not cover them up.
	//所有的子窗口将被移动，以免被TOOLBAR覆盖
	// Offest to move all child controls after adding Tollbar
	//计算移动的距离
	CPoint ptOffset(rcClientNew.left-rcClientOld.left,
	rcClientNew.top-rcClientOld.top);

	CRect rcChild;
	CWnd* pwndChild = GetWindow(GW_CHILD); //得到子窗口
	while(pwndChild) // 处理所有子窗口
	{//移动所有子窗口
		pwndChild->GetWindowRect(rcChild);
		ScreenToClient(rcChild); 
		rcChild.OffsetRect(ptOffset); 
		pwndChild->MoveWindow(rcChild,FALSE); 
		pwndChild = pwndChild->GetNextWindow();
	}

	CRect rcWindow;
	GetWindowRect(rcWindow); // 得到对话框RECT
	rcWindow.right += rcClientOld.Width() - rcClientNew.Width(); // 修改对话框尺寸
	rcWindow.bottom += rcClientOld.Height() - rcClientNew.Height(); 
	MoveWindow(rcWindow,FALSE); // Redraw Window

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
}

void CTemplateCADDlg::CreateStatusBar()
{
	int method = 2;

	if( method == 1 )
	{
		CRect Rect;
		GetClientRect(&Rect);                           //获取客户区域
		if(!m_StatusBar.Create(this) || !m_StatusBar.SetIndicators(indicators,sizeof(indicators)/sizeof(UINT)))
		{
			TRACE0("Failed to create status bar\n");
			return;
		}

		m_StatusBar.MoveWindow(0,Rect.bottom-20,Rect.right,20);             //设置状态栏位置
	}
	else
	{
		CRect Rect;
        this->GetClientRect(&Rect);                  //获取客户区域
        m_StatusBarCtrl.Create(WS_CHILD | WS_VISIBLE,CRect(0,0,0,0),this, IDR_TOOLBAR_STATUS);
        int width[5];
        width[0]=Rect.Width()*0.1;
		width[1]=Rect.Width()*0.4;
        width[2]=Rect.Width()*0.6;
        width[3]=Rect.Width()*0.8;
        width[4]=Rect.Width();
        m_StatusBarCtrl.SetParts(5,width);
        m_StatusBarCtrl.SetText(L"说明",0,0);
        m_StatusBarCtrl.SetText(L"AutoCAD模板程序",1,0);
        m_StatusBarCtrl.SetText(L"系统时间",3,0);
        SetTimer(1,1000,NULL);                             //设置定时器
	}
}

void CTemplateCADDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CTemplateCADDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CTemplateCADDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

