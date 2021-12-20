#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <commctrl.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

const int BSIZE = 20;

BOOL CALLBACK Q6_3_PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int first;
	int second;
	int total;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		first = 0;
		second = 0;
		total = 0;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_PLUS:
			first = GetDlgItemInt(hDlg, IDC_EDIT_FIRST, NULL, TRUE);
			second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);
			total = first + second;
			SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, total, TRUE);
			break;
		
		case IDC_BUTTON_MINUS:
			first = GetDlgItemInt(hDlg, IDC_EDIT_FIRST, NULL, TRUE);
			second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);
			total = first - second;
			SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, total, TRUE);
			break;

		case IDC_BUTTON_MUL:
			first = GetDlgItemInt(hDlg, IDC_EDIT_FIRST, NULL, TRUE);
			second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);
			total = first * second;
			SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, total, TRUE);
			break;

		case IDC_BUTTON_DIV:
			first = GetDlgItemInt(hDlg, IDC_EDIT_FIRST, NULL, TRUE);
			second = GetDlgItemInt(hDlg, IDC_EDIT_SECOND, NULL, TRUE);
			total = first / second;
			SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, total, TRUE);
			break;

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
	static HWND hDlg;
	switch (iMsg)
	{
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_Q3_MENU:
			if (!IsWindow(hDlg))
			{
				hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q3), hwnd, Q6_3_PROC);
				ShowWindow(hDlg, SW_SHOW);
			}
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
