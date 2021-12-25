#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <commctrl.h>
#include "resource.h"

const int BSIZE = 50;
const int UNSELECTED = -1;
LPCTSTR align_list[3] = { _T("왼쪽"), _T("오른쪽"), _T("가운데") };

void MakeColumn(HWND hDlg, int selection)
{
	HWND hCombo;
	HWND hList;
	TCHAR name[20];
	TCHAR size_temp[20];
	int size;
	RECT rect;
	
	TCHAR align[10];
	int alignPos;
	static int pos = 0;
	static int count = 0;

	LVCOLUMN lv;
	memset(&lv, 0, sizeof(LVCOLUMN));
	

	hCombo = GetDlgItem(hDlg, IDC_COMBO_ALIGN);
	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	GetClientRect(hList, &rect);

	GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 20);
	GetDlgItemText(hDlg, IDC_EDIT_SIZE, size_temp, 20);
	pos = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
	size = _ttoi(size_temp);

	

	lv.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	if (_tcscmp(align_list[pos], _T("가운데")) == 0) 
		lv.fmt = LVCFMT_CENTER;
	else if (_tcscmp(align_list[pos], _T("오른쪽")) == 0) 
		lv.fmt = LVCFMT_RIGHT;
	else if (_tcscmp(align_list[pos], _T("왼쪽")) == 0) 
		lv.fmt = LVCFMT_LEFT;

	lv.cx = size;
	lv.pszText = name;
	lv.iSubItem = count++;

	SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&lv);
}

BOOL CALLBACK Q6_12PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hList;
	static HWND hCombo;
	static int selection;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hCombo = GetDlgItem(hDlg, IDC_COMBO_ALIGN);
		
		for (int i = 0; i < 3; i++) {
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)align_list[i]);
		}
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DestroyWindow(hDlg);
			return 0;

		case IDC_BUTTON_MAKE:
			MakeColumn(hDlg, selection);
			break;

		case IDC_COMBO_ALIGN:
			if (HIWORD(wParam) == CBN_SELCHANGE)
				selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
		}
		break;
	}
	
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.lpszClassName = _T("Window Class Name");

	RegisterClass(&WndClass);

	hwnd = CreateWindow(_T("Window Class Name"),
		_T("첫 번째 윈도우"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInst;
	HWND hDlg;
	switch (iMsg)
	{
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_Q12_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q12), hwnd, Q6_12PROC);
			ShowWindow(hDlg, SW_SHOW);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
