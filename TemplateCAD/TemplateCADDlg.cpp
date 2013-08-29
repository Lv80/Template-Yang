
// TemplateCADDlg.cpp : �����n
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


// �� App About ʹ�� CAboutDlg ��Ԓ���K

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��Ԓ���K�Y��
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧Ԯ

// ��ʽ�a����
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

// CTemplateCADDlg ��Ԓ���K
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
	 //����������һЩ�����õĲ˵�ѡ�����Ϣӳ��
	ON_COMMAND(IDM_OPENDATA, &CTemplateCADDlg::OnOpenData) //������
	ON_COMMAND(IDM_SAVEDATA, &CTemplateCADDlg::OnSaveData) //��������
	ON_COMMAND(IDM_SAVEDATAAS, &CTemplateCADDlg::OnSaveDataAs) //�������
	ON_COMMAND(IDM_CONTROL, &CTemplateCADDlg::OnControlData) //��������
	ON_COMMAND(IDM_COORDINATE, &CTemplateCADDlg::OnCoorData) //��������
	ON_WM_INITMENUPOPUP()
END_MESSAGE_MAP()

void CTemplateCADDlg::OnOpenData()
{
	SaveLastCommand( IDM_OPENDATA );

	//����ѡ��Ի���
	CString szFilter;
	szFilter.Format(L"%s", L"�������� (*.prj)|*.prj||");
	CFileDialog dlg(TRUE, L"prj", L"", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter.GetBuffer(), this, 0/*, TRUE*/);

	//���·��[Ĭ�Ϲ����ļ����ִ�г�����ͬһĿ¼��]
	CString exeFullPath;   

	//��һ������ΪNULLʱ,��õ����õ�ǰDLL�ļ��Ŀ�ִ�г����·��,ΪDLL���ʱ,�͵õ�DLL�ļ���·��
	GetModuleFileName(NULL, exeFullPath.GetBufferSetLength(MAX_PATH+1), MAX_PATH);
	printf("\nģ������·���ǡ�%s��", exeFullPath.GetBuffer());

	CString exeFoler = exeFullPath.Left(exeFullPath.ReverseFind('\\'));
	dlg.m_ofn.lpstrInitialDir = exeFoler.GetBuffer();

	if (dlg.DoModal() == IDOK) 
	{
		//�õ������ļ�
        CString impFile = dlg.GetPathName();
		printf("\n����Ĺ����ļ��ǡ�%s��.",impFile.GetBuffer());

		//TODO
		//���ļ������浽���ݽṹ��
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

// CTemplateCADDlg ӍϢ̎��ʽ

BOOL CTemplateCADDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->SetBackgroundColor(RGB(207,224,226),RGB(13,125,188));

	// �� [�P�...] ���ܱ����ϵ�y���ܱ�

	// IDM_ABOUTBOX �����ϵ�y�����֮�С�
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

	// �O���ˌ�Ԓ���K�ĈDʾ�������ó�ʽ����ҕ�����ǌ�Ԓ���K�r��
	// ��ܕ��Ԅӏ��´����I
	SetIcon(m_hIcon, TRUE);			// �O����Dʾ
	SetIcon(m_hIcon, FALSE);		// �O��С�Dʾ

	// TODO: �ڴ˼����~��ĳ�ʼ�O��

	CreateToolBar();

	CreateStatusBar();

	CMenuTipManager tip;
	tip.Install(this);

	return TRUE;  // ���� TRUE����������������O�����c
}

void CTemplateCADDlg::CreateToolBar()
{
	// ������������������Դ
	if(!m_wndToolBar.CreateEx(this,TBSTYLE_TOOLTIPS, WS_CHILD | WS_VISIBLE | CBRS_TOP
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) 
		|| !m_wndToolBar.LoadToolBar(IDR_TOOLBAR_MAIN))
	{
		TRACE0("Failed to Create Dialog Toolbar\n");
		EndDialog(IDCANCEL);
	}

	CRect rcClientOld; // ����ͻ���RECT
	CRect rcClientNew; // ����TOOLBAR���CLIENT RECT
	GetClientRect(rcClientOld); // 

	// Called to reposition and resize control bars in the client area of a window
	// The reposQuery FLAG does not really traw the Toolbar. It only does the calculations.
	// And puts the new ClientRect values in rcClientNew so we can do the rest of the Math.
	//���¼���RECT��С
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0,reposQuery,rcClientNew);

	// All of the Child Windows (Controls) now need to be moved so the Tollbar does not cover them up.
	//���е��Ӵ��ڽ����ƶ������ⱻTOOLBAR����
	// Offest to move all child controls after adding Tollbar
	//�����ƶ��ľ���
	CPoint ptOffset(rcClientNew.left-rcClientOld.left,
	rcClientNew.top-rcClientOld.top);

	CRect rcChild;
	CWnd* pwndChild = GetWindow(GW_CHILD); //�õ��Ӵ���
	while(pwndChild) // ���������Ӵ���
	{//�ƶ������Ӵ���
		pwndChild->GetWindowRect(rcChild);
		ScreenToClient(rcChild); 
		rcChild.OffsetRect(ptOffset); 
		pwndChild->MoveWindow(rcChild,FALSE); 
		pwndChild = pwndChild->GetNextWindow();
	}

	CRect rcWindow;
	GetWindowRect(rcWindow); // �õ��Ի���RECT
	rcWindow.right += rcClientOld.Width() - rcClientNew.Width(); // �޸ĶԻ���ߴ�
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
		GetClientRect(&Rect);                           //��ȡ�ͻ�����
		if(!m_StatusBar.Create(this) || !m_StatusBar.SetIndicators(indicators,sizeof(indicators)/sizeof(UINT)))
		{
			TRACE0("Failed to create status bar\n");
			return;
		}

		m_StatusBar.MoveWindow(0,Rect.bottom-20,Rect.right,20);             //����״̬��λ��
	}
	else
	{
		CRect Rect;
        this->GetClientRect(&Rect);                  //��ȡ�ͻ�����
        m_StatusBarCtrl.Create(WS_CHILD | WS_VISIBLE,CRect(0,0,0,0),this, IDR_TOOLBAR_STATUS);
        int width[5];
        width[0]=(int)(Rect.Width()*0.1);
		width[1]=(int)(Rect.Width()*0.4);
        width[2]=(int)(Rect.Width()*0.6);
        width[3]=(int)(Rect.Width()*0.8);
        width[4]=Rect.Width();

        m_StatusBarCtrl.SetParts(5,width);
        m_StatusBarCtrl.SetText(L"��ʾ˵��",0,0);
        m_StatusBarCtrl.SetText(L"",1,0);
        m_StatusBarCtrl.SetText(L"��ǰ�˵�",3,0);

        SetTimer(1,1000,NULL);                             //���ö�ʱ��
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
    ::MENUINFO lpcmi; //��������д��Ȼ�޷�ʶ��
    m_brush.CreateSolidBrush(RGB(255,0,0));//�����ɫ
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

// �������С�����o�������Č�Ԓ���K������Ҫ���еĳ�ʽ�a��
// �Ա��L�u�Dʾ�����ʹ���ļ�/�zҕģʽ�� MFC ���ó�ʽ��
// ��ܕ��Ԅ���ɴ����I��

void CTemplateCADDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �L�u���b�Ã���

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ���Dʾ������Ñ��˾���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ���L�Dʾ
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ʹ������ҷ��С��ҕ���r��
// ϵ�y�����@������ȡ���Θ��@ʾ��
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
