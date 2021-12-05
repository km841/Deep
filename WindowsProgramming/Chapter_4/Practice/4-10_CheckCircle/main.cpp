#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <locale>
#include "resource.h"

const int BSIZE = 40;

double LengthPts(int x1, int y1, int x2, int y2) {
	return (sqrt((float)(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

BOOL InCircle(int x, int y, int mx, int my) {
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU4_2);
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
	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y;
	static int px, py;
	int mx, my;
	
	static BOOL select;
	static BOOL copy, next;

	static HMENU hMenu, hSubMenu;
	HPEN hPen, oldPen;
	


	
	switch (iMsg) {
	case WM_CREATE:
		hMenu = GetMenu(hwnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		select = FALSE;
		copy = FALSE;
		next = FALSE;
		x = 50, y = 50;
		px = x + 20;
		py = y + 20;
		break;

	case WM_PAINT:
		EnableMenuItem(hSubMenu, ID_EDITCOPY, select ? MF_ENABLED : MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_EDITPASTE, copy ? MF_ENABLED : MF_GRAYED);

		hdc = BeginPaint(hwnd, &ps);
		if (select) {
			hPen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(hdc, hPen);
			Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
			SelectObject(hdc, oldPen);
			DeleteObject(hPen);
		}
		Ellipse(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);

		if (next) {
			Ellipse(hdc, px - BSIZE, py - BSIZE, px + BSIZE, py + BSIZE);
			next = FALSE;
		}
		
		EndPaint(hwnd, &ps);
		break;

	case WM_COMMAND:
		if (LOWORD(wParam) == ID_EDITCOPY) {
			copy = TRUE;
			InvalidateRgn(hwnd, NULL, TRUE);
		}

		else if (LOWORD(wParam) == ID_EDITPASTE) {
			next = TRUE;
			InvalidateRgn(hwnd, NULL, TRUE);
		}
		break;

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		if (InCircle(x, y, mx, my) && select == FALSE) select = TRUE;
		else if (select) select = FALSE;

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
