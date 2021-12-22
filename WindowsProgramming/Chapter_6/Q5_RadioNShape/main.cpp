#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <commctrl.h>
#include "resource.h"

enum
{
	rect = 1,
	circle = 2
};
const int BSIZE = 50;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Q6_5PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int status;
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		status = 0;
		return 1;

	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		if (status == rect) {
			Rectangle(hdc, 0, 0, 100, 100);
		}

		else if (status == circle) {
			Ellipse(hdc, 0, 0, 100, 100);
		}
		EndPaint(hDlg, &ps);

		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			DestroyWindow(hDlg);
			return 0;

		case IDCANCEL:
			DestroyWindow(hDlg);
			return 0;

		case IDC_RADIO_REC:
			status = rect;
			InvalidateRgn(hDlg, NULL, TRUE);
			break;

		case IDC_RADIO_CIR:
			status = circle;
			InvalidateRgn(hDlg, NULL, TRUE);
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
		case ID_Q5_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q5), hwnd, Q6_5PROC);
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
