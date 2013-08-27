// 模本程序.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "模本程序.h"
#include <string>
#include <CommCtrl.h>

#pragma comment(lib,"Comctl32.lib")

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
VOID				ShowControlDialog(HWND);
INT_PTR CALLBACK	ControlDialogHandle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
VOID				SingleSelect(HWND);
VOID				ShowCoordinateDialog(HWND);
INT_PTR CALLBACK	CoordinateDialogHandle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
VOID				InitCoordinateValue(HWND);
INT_PTR CALLBACK	CoordinateListHandle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
		
	HMENU hmenu = GetMenu(hWnd);	

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		
		CheckMenuItem(hmenu, wmId, MF_BYCOMMAND | MF_CHECKED); 

		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_CUST_EXIT:
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_MN_CONTROL:
			ShowControlDialog(hWnd);
			break;
		case ID_MN_COORDINATE:
			ShowCoordinateDialog(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

VOID ShowControlDialog(HWND hWnd)
{
	DialogBox(hInst, MAKEINTRESOURCE(IDD_CONTROL_DLG), hWnd, ControlDialogHandle);
}

// Message handler for about box.
INT_PTR CALLBACK ControlDialogHandle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	int wmId, wmEvent;

	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		switch(wmId)
		{
		case IDOK:
		case IDCANCEL:

			EndDialog(hDlg, LOWORD(wParam));
			break;

		case IDC_RADIO_SINGLE:
			SingleSelect(hDlg);
		}

		return true;

	default: 

		break;
	}

	return (INT_PTR)FALSE;
}

VOID SingleSelect(HWND hDlg)
{
	HWND hMultiWnd = GetDlgItem(hDlg, IDC_RADIO_MULTI);
	INT multiID = GetWindowLong(hMultiWnd, GWL_ID);
	SendMessage(hMultiWnd, BM_SETCHECK, BST_UNCHECKED,0);

	HWND checkItem = GetDlgItem(hDlg, IDC_CHECK_MULTI_LINE);
	EnableWindow(checkItem,false);
}

VOID ShowCoordinateDialog(HWND hWnd)
{
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_COORDINATE), hWnd, CoordinateDialogHandle);
}

// Message handler for about box.
INT_PTR CALLBACK CoordinateDialogHandle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	int wmId, wmEvent;

	switch (message)
	{
	case WM_INITDIALOG:
		{
			HWND hMultiWnd = GetDlgItem(hDlg, IDC_EDIT_REC_X1);
			SetWindowLong(hMultiWnd, GWL_WNDPROC, (LONG)CoordinateListHandle);

			SetWindowText(hMultiWnd, L"-1.2");

			wchar_t text[100];
			GetWindowText(hMultiWnd, text, 100);

			int message = LVM_INSERTCOLUMN;
			InitCommonControls();

			HWND hCoordinates = GetDlgItem(hDlg, IDC_LIST_COORDINATES);
			LVCOLUMN ColInfo = {0};

			ColInfo.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
			ColInfo.iSubItem = 0;
			ColInfo.fmt = LVCFMT_CENTER;
			ColInfo.cx  = 140;
			ColInfo.pszText = L"坐标X";
			ColInfo.cchTextMax = 50;
			SendMessage(hCoordinates, LVM_INSERTCOLUMN, WPARAM(0), LPARAM(&ColInfo));

			return (INT_PTR)TRUE;
		}

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		switch(wmId)
		{
		case IDOK:
		case IDCANCEL:

			EndDialog(hDlg, LOWORD(wParam));
			break;

		case IDC_RADIO_SINGLE:
			SingleSelect(hDlg);
		}

		return true;

	default: 
		return DefWindowProc(hDlg, message, wParam, lParam);

		break;
	}

	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK CoordinateListHandle(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	int wmId, wmEvent;

	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		{

		}
		break;

	case NM_DBLCLK:
		{
			int a = 0;
			break;
		}

	default:
		return DefWindowProc(hDlg, message, wParam, lParam);
	}

	return (INT_PTR)FALSE;
}