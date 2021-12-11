#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <locale>
#include "resource.h"

const int BSIZE = 20;

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
	HACCEL hAcc;
	hAcc = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR5_1));
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
		if (!TranslateAccelerator(hwnd, hAcc, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static HMENU hMenu, hSubMenu;
	OPENFILENAME ofn;

	static COLORREF fColor;
	static BOOL selection;
	static BOOL copy;
	static int x, y;
	static RECT rect;

	int mx, my;
	static int pasteCount;
	HPEN hPen, oldPen;

	TCHAR fName[500] = _T("");


	switch (iMsg) {
	case WM_CREATE:
		hMenu = GetMenu(hwnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		x = y = 20;
		copy = FALSE;
		selection = FALSE;
		pasteCount = 0;
		GetClientRect(hwnd, &rect);


		EnableMenuItem(hSubMenu, ID_EDITCOPY, MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_EDITPASTE, MF_GRAYED);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EnableMenuItem(hSubMenu, ID_EDITCOPY, selection ? MF_ENABLED : MF_GRAYED);
		EnableMenuItem(hSubMenu, ID_EDITPASTE, copy ? MF_ENABLED : MF_GRAYED);

		if (selection) {
			Rectangle(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
		}
		Ellipse(hdc, x - BSIZE, y - BSIZE, x + BSIZE, y + BSIZE);
		for (int i = 0; i < pasteCount; i++) {
			Ellipse(hdc, x + (i + 1) * 20 - BSIZE, y + (i + 1) * 20 - BSIZE, x + (i + 1) * 20 + BSIZE, y + (i + 1) * 20 + BSIZE);
		}

		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if ((InCircle(x, y, mx, my)) && (selection == FALSE)) selection = TRUE;
		else selection = FALSE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_EDITCOPY:
			copy = TRUE;
			break;

		case ID_EDITPASTE:
			if (pasteCount < 10) pasteCount++;
			break;
			
		case ID_EDITUNDO:
			if (pasteCount > 0) pasteCount--;
			break;
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
