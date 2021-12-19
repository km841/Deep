#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <commctrl.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

const int BSIZE = 20;

BOOL CALLBACK Q6_1_PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int x = 20, y = 20;
	static RECT rect;
	HDC hdc;
	PAINTSTRUCT ps;
	static bool xFlag, yFlag;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		GetClientRect(hDlg, &rect);
		return 1;

	case WM_TIMER:
		if (x+20 > rect.right) xFlag = FALSE;
		else if (x-20 < 0) xFlag = TRUE;

		if (xFlag == TRUE) x+=5;
		else if (xFlag == FALSE) x-=5;

		if (y + 20 > rect.bottom - 50) yFlag = FALSE;
		else if (y - 20 < 0) yFlag = TRUE;

		if (yFlag == TRUE) y += 5;
		else if (yFlag == FALSE) y -= 5;


		
		InvalidateRgn(hDlg, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
		EndPaint(hDlg, &ps);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_START:
			SetTimer(hDlg, 1, 100, NULL);
			break;
			
		case ID_STOP:
			KillTimer(hDlg, 1);
			break;

		case IDCANCEL:
			DestroyWindow(hDlg);
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
		case ID_Q1_MENU:
			if (!IsWindow(hDlg)) {
				hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q1), hwnd, Q6_1_PROC);
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
