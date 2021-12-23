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
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Q6_7PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static TCHAR words[200];
	static int pos;
	LPNMHDR hdr;
	static HWND hEdit;
	static HWND hList;
	switch (iMsg)
	{
	case WM_INITDIALOG:
		pos = 0;
		hList = GetDlgItem(hDlg, IDC_LIST_ADD);
		hEdit = GetDlgItem(hDlg, IDC_EDIT_INPUT);
		break;

	case WM_COMMAND:
		//if (LOWORD(wParam) == WM_COMMAND && HIWORD(wParam) == EN_CHANGE && pos >= 2 && words[_tcslen(words) - 2] == VK_RETURN)
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DestroyWindow(hDlg);
			break;

		case IDC_EDIT_INPUT:
			if (HIWORD(wParam) == EN_CHANGE && GetAsyncKeyState(VK_RETURN) & 0x8000) {
				GetDlgItemText(hDlg, IDC_EDIT_INPUT, words, sizeof(TCHAR) * 100) ;
				SendMessage(hList, LB_ADDSTRING, NULL, (LPARAM)words);
				SetDlgItemText(hDlg, IDC_EDIT_INPUT, _T(""));
				}
			
			break;

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
		case ID_Q7_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q7), hwnd, Q6_7PROC);
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
