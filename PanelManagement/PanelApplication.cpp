#include "pch.h"
#include "PanelApplication.h"
#include "resource.h"
#include "PanelManagement.h"

//Global Variable
static PanelManagement* boxManager;
static HINSTANCE hInst;
static vector<wstring> boxYears;
static map<wstring, vector<Project>> boxPjt;
static vector<pair<ElectricBox, wstring>> panels;

//Menu Selection
static int year_selection;
static int pjt_selection;
static int pnl_selection;

//PVIEW_PROPERTY_VARIABLE
static wstring projectName;
static wstring panelName;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);


BOOL CALLBACK WIN32_PVIEW_PROPERTY_DIALOG(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;
	
	static RECT rect;
	static ElectricBox* bp;
	static wstring* comment;
	static HBITMAP hBit, oldBit;
	static HWND hPic;

	static BITMAP currBit;
	
	switch (iMsg)
	{
	case WM_INITDIALOG:
		for (int i = 0; i < panels.size(); i++) {
			if (_tcscmp(panels[i].first.getName().c_str(), panelName.c_str()) == 0) {
				bp = &panels[i].first;
				if (bp->getComment() == _T(""))
					comment = &panels[i].second;
				else
					comment = &bp->getComment();

			}
		}

		GetClientRect(hPic, &rect);

		if (bp->getImageID() != -1) {
			hBit = LoadBitmap(hInst, MAKEINTRESOURCE(bp->getImageID()));
			hPic = GetDlgItem(hDlg, IDC_PICTURE);
			GetObject(hBit, sizeof(currBit), &currBit);
		}

		//Project Name
		SetDlgItemText(hDlg, IDC_EDIT_PROJECT, projectName.c_str());

		//Panel Name
		SetDlgItemText(hDlg, IDC_EDIT_PANEL, panelName.c_str());

		//Panel Size (Width)
		SetDlgItemText(hDlg, IDC_EDIT_OWIDTH, bp->getWidth().c_str());

		//Panel Size (Height)
		if (bp->isBase()) 
			SetDlgItemText(hDlg, IDC_EDIT_OHEIGHT, bp->getHeightString().c_str());
		else 
			SetDlgItemText(hDlg, IDC_EDIT_OHEIGHT, bp->getHeight().c_str());
			

		//Panel Size (Depth)
		SetDlgItemText(hDlg, IDC_EDIT_ODEPTH, bp->getDepth().c_str());

		if (bp->isInnerFront()) {
			//Front Inner Plate Size (Width)
			SetDlgItemText(hDlg, IDC_EDIT_FWIDTH, bp->getInnerFrontWidth().c_str());
			//Front Inner Plate Size (Height)
			SetDlgItemText(hDlg, IDC_EDIT_FHEIGHT, bp->getInnerFrontHeight().c_str());
		}

		if (bp->isInnerSide()) {
			//Side Inner Plate Size (Width)
			SetDlgItemText(hDlg, IDC_EDIT_SWIDTH, bp->getInnerSideWidth().c_str());
			//Side Inner Plate Size (Height)
			SetDlgItemText(hDlg, IDC_EDIT_SHEIGHT, bp->getInnerSideHeight().c_str());
		}

		if (comment->c_str() != _T("")) {
			SetDlgItemText(hDlg, IDC_EDIT_COMMENT, comment->c_str());
		}

		break;

	case WM_PAINT:
		GetClientRect(hPic, &rect);
		
		if (bp->getImageID() != -1) {
			hdc = BeginPaint(hPic, &ps);
			memdc = CreateCompatibleDC(hdc);
			oldBit = (HBITMAP)SelectObject(memdc, hBit);
			StretchBlt(hdc, 0, 0, rect.right, rect.bottom, memdc, 0, 0, currBit.bmWidth, currBit.bmHeight, SRCCOPY);
			SelectObject(memdc, oldBit);

			DeleteDC(memdc);
			EndPaint(hDlg, &ps);
		}

		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			break;
		}

		break;
	}
	return 0;
}


BOOL CALLBACK WIN32_PVIEW_DIALOG(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

// Property Dialog Variable
	//Property Dialog Handle
	static HWND hProperty;
	//Property Button Control Handle
	static HWND hButton;

// Menu Insert Variable
	//Menu ListBox Control Handle
	static HWND hList_Year;
	static HWND hList_Project;
	static HWND hList_Panel;

	//Menu Insert Container
	static vector<wstring> boxYears;
	static map<wstring, vector<Project>> boxPjt;

	//Menu Count
	int curCount;

	//Select Menu Pointer
	
// Other Dialog Deliver
	TCHAR buf[256];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hList_Year = GetDlgItem(hDlg, IDC_LIST_YEAR);
		hList_Project = GetDlgItem(hDlg, IDC_LIST_PROJECT);
		hList_Panel = GetDlgItem(hDlg, IDC_LIST_PANEL);
		hButton = GetDlgItem(hDlg, IDC_BUTTON_POPEN);

		boxYears = boxManager->getYears();
		boxPjt = boxManager->getProject();
		
		for (int i = 0; i < boxYears.size(); i++)
			SendMessage(hList_Year, LB_ADDSTRING, 0, (LPARAM)boxYears[i].c_str());
		return 1;

	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);

		EndPaint(hDlg, &ps);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DestroyWindow(hDlg);
			break;

		case IDC_BUTTON_POPEN:
			hProperty = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_PPRT), hDlg, WIN32_PVIEW_PROPERTY_DIALOG);
			ShowWindow(hProperty, SW_SHOW);
			break;

		case IDC_LIST_YEAR:
			if (HIWORD(wParam) == LBN_SELCHANGE) {
				pnl_selection = -1;
				EnableWindow(hButton, FALSE);
				// Project Menu Initialize
				curCount = SendMessage(hList_Project, LB_GETCOUNT, 0, 0);
				if (curCount != 0) {
					for (int i = 0; i < curCount; i++) {
						SendMessage(hList_Project, LB_DELETESTRING, 0, 0);
					}
				}

				// Panel Menu Initialize
				curCount = SendMessage(hList_Panel, LB_GETCOUNT, 0, 0);
				if (curCount != 0) {
					for (int i = 0; i < curCount; i++) {
						SendMessage(hList_Panel, LB_DELETESTRING, 0, 0);
					}
				}

				// Insert Project in Menu
				year_selection = (int)SendMessage(hList_Year, LB_GETCURSEL, 0, 0);
				for (int i = 0; i < boxPjt[boxYears[year_selection].c_str()].size(); i++) {
					SendMessage(
						hList_Project, 
						LB_ADDSTRING, 
						0, 
						(LPARAM)boxPjt[boxYears[year_selection].c_str()][i].getName().c_str());
				}
			}
			break;

		case IDC_LIST_PROJECT:
			if (HIWORD(wParam) == LBN_SELCHANGE) {
				pnl_selection = -1;
				EnableWindow(hButton, FALSE);
				// Panel Menu Initialize
				curCount = SendMessage(hList_Panel, LB_GETCOUNT, 0, 0);
				if (curCount != 0) {
					for (int i = 0; i < curCount; i++) {
						SendMessage(hList_Panel, LB_DELETESTRING, 0, 0);
					}
				}

				pjt_selection = (int)SendMessage(hList_Project, LB_GETCURSEL, 0, 0);
				SendMessage(hList_Project, LB_GETTEXT, pjt_selection, (LPARAM)buf);
				projectName = buf;
				
				// Insert Panel in Menu

				for (int i = 0; i < boxPjt[boxYears[year_selection].c_str()].size(); i++) {
					if (_tcscmp(boxPjt[boxYears[year_selection].c_str()][i].getName().c_str(), buf) == 0) {
						panels = boxPjt[boxYears[year_selection].c_str()][i].getBoxes();

						for (int j = 0; j < panels.size(); j++)
							SendMessage(hList_Panel, LB_ADDSTRING, 0, (LPARAM)panels[j].first.getName().c_str());
					}
				}
			}
			break;

		case IDC_LIST_PANEL:
			if (HIWORD(wParam) == LBN_SELCHANGE) {
				pnl_selection = (int)SendMessage(hList_Panel, LB_GETCURSEL, 0, 0);
				if (pnl_selection > -1) EnableWindow(hButton, TRUE);

				SendMessage(hList_Panel, LB_GETTEXT, pnl_selection, (LPARAM)buf);
				panelName = buf;
			}

			else if (HIWORD(wParam) == LBN_DBLCLK) {
				pnl_selection = (int)SendMessage(hList_Panel, LB_GETCURSEL, 0, 0);
				hProperty = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_PPRT), hDlg, WIN32_PVIEW_PROPERTY_DIALOG);
				ShowWindow(hProperty, SW_SHOW);
				break;

			}
			break;
		}

		break;
	}


	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	hInst = hInstance;

	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(hInstance, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU_DEF);
	WndClass.lpszClassName = _T("Panel Management Program");
	RegisterClass(&WndClass);

	hwnd = CreateWindow(_T("Panel Management Program"),
		_T("Panel Management Program"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		396,
		456,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memdc;
	PAINTSTRUCT ps;

	static RECT rect;
	static HBITMAP hBit, oldBit;
	static HINSTANCE hInst;
	static BITMAP bgrBit;
	static HWND hDlg;
	 
	switch (iMsg)
	{
	case WM_CREATE:
		boxManager = new PanelManagement;
		boxManager->Init();
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		GetClientRect(hwnd, &rect);
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_LOGO));
		GetObject(hBit, sizeof(bgrBit), &bgrBit);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_PLIST_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG_PVIEW), hwnd, WIN32_PVIEW_DIALOG);
			ShowWindow(hDlg, SW_SHOW);
			break;
		
		case ID_QUIT_MENU:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		memdc = CreateCompatibleDC(hdc);
		oldBit = (HBITMAP)SelectObject(memdc, hBit);
		BitBlt(hdc, 0, 0, bgrBit.bmWidth, bgrBit.bmHeight, memdc, 0, 0, SRCCOPY);

		SelectObject(memdc, oldBit);
		DeleteDC(memdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		delete boxManager;
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
