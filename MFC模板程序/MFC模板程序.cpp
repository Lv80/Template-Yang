
// MFCģ�����.cpp : ���x���ó�ʽ��e�О顣
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCģ�����.h"
#include "MainFrm.h"

#include "MFCģ�����Doc.h"
#include "MFCģ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCģ�����App

BEGIN_MESSAGE_MAP(CMFCģ�����App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMFCģ�����App::OnAppAbout)
	// �����ļ�����Ę˜ʙn��
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CMFCģ�����App ����

CMFCģ�����App::CMFCģ�����App()
{
	m_bHiColorIcons = TRUE;

	// ֧Ԯ�����ӹ���T
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ������ó�ʽ��ʹ�� Common Language Runtime ֧Ԯ (/clr) ���õ�:
	//     1) Ҫʹ�����ӹ���T֧Ԯ�����\����Ҫ�@���~���O����
	//     2) �ڌ����б�회����������� System.Windows.Forms �����M�н��á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ��Ψһ�� ID �ִ�ȡ������đ��ó�ʽ ID �ִ�; ���h��
	// �ִ���ʽ�� CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCģ�����.AppID.NoVersion"));

	// TODO: �ڴ˼��뽨����ʽ�a��
	// ��������Ҫ�ĳ�ʼ�O������ InitInstance ��
}

// �H�е�һ�� CMFCģ�����App ���

CMFCģ�����App theApp;


// CMFCģ�����App ��ʼ�O��

BOOL CMFCģ�����App::InitInstance()
{
	// ���瑪�ó�ʽ�YӍ���ָ��ʹ�� ComCtl32.dll 6 (��) ����汾��
	// �톢��ҕ�X����ʽ���� Windows XP �ϣ��t��Ҫ InitCommonControls()��
	// ��t�κ�ҕ���Ľ�������ʧ����
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �O��Ҫ������������Ҫ��춑��ó�ʽ�е�
	// ͨ�ÿ����e��
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// ��Ҫ�� AfxInitRichEdit2() ����ʹ�� RichEdit �����	
	// AfxInitRichEdit2();

	// �˜ʳ�ʼ�O��
	// �������ʹ���@Щ���܁K����p��
	// ������ɵĿɈ��Йn��С��������
	// �����г�ʽ�a�Ƴ�����Ҫ�ĳ�ʼ����ʽ��
	// ׃�������O��ֵ�ĵ�䛙C�a
	// TODO: ����ԓ�m���޸Ĵ��ִ�
	// (���磬��˾���Q��M�����Q)
	SetRegistryKey(_T("���C AppWizard ���a���đ��ó�ʽ"));
	LoadStdProfileSettings(4);  // �d��˜� INI �n�x� (���� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ��䛑��ó�ʽ���ļ��������ļ�����ؓ؟���ļ���
	// ���ҕ���c�zҕ�g�M���B��
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMFCģ�����Doc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ���ҕ��
		RUNTIME_CLASS(CMFCģ�����View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// �����˜� Shell ���DDE���n���_���f�n��������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ����������ָ���ķ�����������ʹ�� 
	// /RegServer��/Register��/Unregserver �� /Unregister ���ӑ��ó�ʽ�������� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// �H��ʼ��һ��ҕ���������@ʾ�K����ԓҕ��
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// ֻ���� SDI ���ó�ʽ����������Ԫ�r���ź��� DragAcceptFiles
	// �@���l��� ProcessShellCommand ֮��
	return TRUE;
}

// CMFCģ�����App ӍϢ̎��ʽ


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

// ���Ќ�Ԓ���K�đ��ó�ʽ����
void CMFCģ�����App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCģ�����App ��ӆ�d��/���淽��

void CMFCģ�����App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CMFCģ�����App::LoadCustomState()
{
}

void CMFCģ�����App::SaveCustomState()
{
}

// CMFCģ�����App ӍϢ̎��ʽ



