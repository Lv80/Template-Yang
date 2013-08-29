
// TemplateCADDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "resource.h"
#include "TemplateCAD.h"
#include "TemplateCADDlg.h"
#include "afxdialogex.h"
#include "MenuTipManager.h"

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
	: CDialogEx(CTemplateCADDlg::IDD, pParent),
	m_nLastCommandId(0)
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
	 //下面是其他一些建立好的菜单选项的消息映射
	ON_COMMAND(IDM_OPENDATA, &CTemplateCADDlg::OnOpenData) //打开数据
	ON_COMMAND(IDM_SAVEDATA, &CTemplateCADDlg::OnSaveData) //保存数据
	ON_COMMAND(IDM_SAVEDATAAS, &CTemplateCADDlg::OnSaveDataAs) //另存数据
	ON_COMMAND(IDM_CONTROL, &CTemplateCADDlg::OnControlData) //控制数据
	ON_COMMAND(IDM_COORDINATE, &CTemplateCADDlg::OnCoorData) //坐标数据
	ON_WM_INITMENUPOPUP()
END_MESSAGE_MAP()

void CTemplateCADDlg::OnOpenData()
{
	SaveLastCommand( IDM_OPENDATA );

	//导入选择对话框
	CString szFilter;
	szFilter.Format(L"%s", L"输入数据 (*.prj)|*.prj||");
	CFileDialog dlg(TRUE, L"prj", L"", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter.GetBuffer(), this, 0/*, TRUE*/);

	//存放路径[默认工程文件与可执行程序在同一目录下]
	CString exeFullPath;   

	//第一个参数为NULL时,则得到调用当前DLL文件的可执行程序的路径,为DLL句柄时,就得到DLL文件的路径
	GetModuleFileName(NULL, exeFullPath.GetBufferSetLength(MAX_PATH+1), MAX_PATH);
	printf("\n模板程序的路径是【%s】", exeFullPath.GetBuffer());

	CString exeFoler = exeFullPath.Left(exeFullPath.ReverseFind('\\'));
	dlg.m_ofn.lpstrInitialDir = exeFoler.GetBuffer();

	if (dlg.DoModal() == IDOK) 
	{
		//得到导入文件
        CString impFile = dlg.GetPathName();
		printf("\n导入的工程文件是【%s】.",impFile.GetBuffer());

		//TODO
		//打开文件并保存到数据结构中
	}
}

void CTemplateCADDlg::OnSaveData()
{
	SaveLastCommand( IDM_SAVEDATA );  
}

void CTemplateCADDlg::OnSaveDataAs()
{
	SaveLastCommand( IDM_SAVEDATAAS );  
}

void CTemplateCADDlg::OnControlData()
{
	SaveLastCommand( IDM_CONTROL ); 
}

void CTemplateCADDlg::OnCoorData()
{
	SaveLastCommand( IDM_COORDINATE );  
}

void CTemplateCADDlg::SaveLastCommand(UINT nCommandId)
{
	MarkMenuById( nCommandId );

	ShowMenuOnStatusBar( nCommandId );

	ChangeMenuColorAsSelected( nCommandId );

	m_nLastCommandId = nCommandId;
}

void CTemplateCADDlg::MarkMenuById( UINT nMenuId )
{
	if( nMenuId == m_nLastCommandId )
		return;

	HMENU hmenu = ::GetMenu(m_hWnd);

	// deselect last menu
	CheckMenuItem(hmenu, m_nLastCommandId, MF_BYCOMMAND | MF_UNCHECKED);

	// select the new menu
	CheckMenuItem(hmenu, nMenuId, MF_BYCOMMAND | MF_CHECKED); 
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

	CMenuTipManager tip;
	tip.Install(this);

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
        width[0]=(int)(Rect.Width()*0.1);
		width[1]=(int)(Rect.Width()*0.4);
        width[2]=(int)(Rect.Width()*0.6);
        width[3]=(int)(Rect.Width()*0.8);
        width[4]=Rect.Width();

        m_StatusBarCtrl.SetParts(5,width);
        m_StatusBarCtrl.SetText(L"提示说明",0,0);
        m_StatusBarCtrl.SetText(L"",1,0);
        m_StatusBarCtrl.SetText(L"当前菜单",3,0);

        SetTimer(1,1000,NULL);                             //设置定时器
	}
}

void CTemplateCADDlg::ShowMenuOnStatusBar( UINT nMenuId )
{
	TCHAR menuString[256];
	HMENU hmenu = ::GetMenu(m_hWnd);
	GetMenuString(hmenu, nMenuId, menuString, 256, MF_BYCOMMAND);

	m_StatusBarCtrl.SetText(menuString,4,0);
}

void CTemplateCADDlg::ChangeMenuColorAsSelected( UINT nMenuId )
{
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_MENU_BACK);

	CBrush m_brush;
    ::MENUINFO lpcmi; //：：必须写不然无法识别
    m_brush.CreateSolidBrush(RGB(255,0,0));//你的颜色
    memset(&lpcmi,0,sizeof(::LPCMENUINFO));
    lpcmi.cbSize=sizeof(MENUINFO);
    lpcmi.fMask= MIM_BACKGROUND;   
    lpcmi.hbrBack=(HBRUSH)m_brush.operator HBRUSH();
    ::SetMenuInfo(GetMenu()->m_hMenu,&lpcmi);

	int count = GetMenu()->GetMenuItemCount();
	CMenu* subMenu = GetMenu()->GetSubMenu(count - 2);

	int subCount = subMenu->GetMenuItemCount();
	subMenu->SetMenuItemBitmaps(subCount-1, MF_BYPOSITION, &bitmap, &bitmap);

	CString text;
	subMenu->GetMenuStringW(subCount-1, text, MF_BYPOSITION);
	//SetMenuItemInfo(::GetMenu(m_hWnd), nMenuId, false, &lpcmi);
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


void CTemplateCADDlg::OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu)
{
    ASSERT(pPopupMenu != NULL);
    // Check the enabled state of various menu items. 

    CCmdUI state;
    state.m_pMenu = pPopupMenu;
    ASSERT(state.m_pOther == NULL);
    ASSERT(state.m_pParentMenu == NULL); 

    // Determine if menu is popup in top-level menu and set m_pOther to
    // it if so (m_pParentMenu == NULL indicates that it is secondary popup).
    HMENU hParentMenu;
    if (AfxGetThreadState()->m_hTrackingMenu == pPopupMenu->m_hMenu){
        state.m_pParentMenu = pPopupMenu;    // Parent == child for tracking popup.
	}
    else if ((hParentMenu = ::GetMenu(m_hWnd)) != NULL)
    {
        CWnd* pParent = this;
           // Child Windows don't have menus--need to go to the top!
        if (pParent != NULL &&
           (hParentMenu = ::GetMenu(pParent->m_hWnd)) != NULL)
        {
           int nIndexMax = ::GetMenuItemCount(hParentMenu);
           for (int nIndex = 0; nIndex < nIndexMax; nIndex++)
           {
            if (::GetSubMenu(hParentMenu, nIndex) == pPopupMenu->m_hMenu)
            {
                // When popup is found, m_pParentMenu is containing menu.
                state.m_pParentMenu = CMenu::FromHandle(hParentMenu);
                break;
            }
           }
        }
    } 

    state.m_nIndexMax = pPopupMenu->GetMenuItemCount();
	for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
      state.m_nIndex++)
    {
        state.m_nID = pPopupMenu->GetMenuItemID(state.m_nIndex);
        if (state.m_nID == 0)
           continue; // Menu separator or invalid cmd - ignore it. 

        ASSERT(state.m_pOther == NULL);
        ASSERT(state.m_pMenu != NULL);
        if (state.m_nID == (UINT)-1)
        {
           // Possibly a popup menu, route to first item of that popup.
           state.m_pSubMenu = pPopupMenu->GetSubMenu(state.m_nIndex);
           if (state.m_pSubMenu == NULL ||
            (state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
            state.m_nID == (UINT)-1)
           {
				continue;       // First item of popup can't be routed to.
           }
           state.DoUpdate(this, TRUE);   // Popups are never auto disabled.
        }
        else
        {
           // Normal menu item.
           // Auto enable/disable if frame window has m_bAutoMenuEnable
           // set and command is _not_ a system command.
           state.m_pSubMenu = NULL;

		   //TODO what you want
		   //state.Enable(false);
		   //state.SetRadio();

		   MENUITEMINFO  lpcmi;
		   memset(&lpcmi,0,sizeof(::MENUITEMINFO));
		   lpcmi.cbSize = sizeof(MENUITEMINFO);

		   GetMenuItemInfo(::GetMenu(m_hWnd), state.m_nID, MF_BYCOMMAND, &lpcmi);
		   lpcmi.fState = MFS_HILITE;   
		   SetMenuItemInfo(::GetMenu(m_hWnd), state.m_nID, MF_BYCOMMAND, &lpcmi);
           state.DoUpdate(this, TRUE);

		} 

		// Adjust for menu deletions and additions.
        UINT nCount = pPopupMenu->GetMenuItemCount();
        if (nCount < state.m_nIndexMax)
        {
           state.m_nIndex -= (state.m_nIndexMax - nCount);
           while (state.m_nIndex < nCount && pPopupMenu->GetMenuItemID(state.m_nIndex) == state.m_nID)
           {
				state.m_nIndex++;
           }
        }
        state.m_nIndexMax = nCount;
    }

	DrawMenuBar();
}
