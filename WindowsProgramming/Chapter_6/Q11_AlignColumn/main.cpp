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

void MakeColumn(HWND hDlg)
{
	LPTSTR name[3] = { _T("이름"), _T("전화번호"), _T("주소")};
	LVCOLUMN lvCol = { 0, };
	HWND hList;
	RECT rect;

	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	GetClientRect(hList, &rect);

	

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			lvCol.fmt = LVCFMT_LEFT;
			lvCol.cx = rect.right * 0.2;
		}

		else if (i == 1) {
			lvCol.fmt = LVCFMT_RIGHT;
			lvCol.cx = rect.right * 0.3;
		}
		else if (i == 2) {
			lvCol.fmt = LVCFMT_CENTER;
			lvCol.cx = rect.right * 0.5;
		}
		lvCol.iSubItem = i;
		lvCol.pszText = name[i];
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}


	
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Q6_11PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		MakeColumn(hDlg);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DestroyWindow(hDlg);
			return 0;
		}
		break;

	}

	return 0;
}




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
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_Q11_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q11), hwnd, Q6_11PROC);
			ShowWindow(hDlg, SW_SHOW);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <commctrl.h>
#include "resource.h"

const int BSIZE = 50;

void MakeColumn(HWND hDlg)
{
	LPTSTR name[3] = { _T("이름"), _T("전화번호"), _T("주소")};
	LVCOLUMN lvCol = { 0, };
	HWND hList;
	RECT rect;

	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	GetClientRect(hList, &rect);

	

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			lvCol.fmt = LVCFMT_LEFT;
			lvCol.cx = rect.right * 0.2;
		}

		else if (i == 1) {
			lvCol.fmt = LVCFMT_RIGHT;
			lvCol.cx = rect.right * 0.3;
		}
		else if (i == 2) {
			lvCol.fmt = LVCFMT_CENTER;
			lvCol.cx = rect.right * 0.5;
		}
		lvCol.iSubItem = i;
		lvCol.pszText = name[i];
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}


	
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Q6_11PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		MakeColumn(hDlg);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DestroyWindow(hDlg);
			return 0;
		}
		break;

	}

	return 0;
}




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
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_Q11_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q11), hwnd, Q6_11PROC);
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
