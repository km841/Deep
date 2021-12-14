#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include "resource1.h"


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
	HDC hdc, ready_memdc, memdc;
	PAINTSTRUCT ps;
	static RECT rect;
	static HBITMAP hBitCat, hBitMouse, oldBitCat, oldBitMouse;
	static HBITMAP backgr, oldBgr;

	static COORD catPos;
	static COORD mousePos;

	static BOOL clicked;
	int mx, my;
	


	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		GetClientRect(hwnd, &rect);
		hBitCat = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_CAT));
		hBitMouse = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_MOUSE));
		mousePos.X = 0;
		mousePos.Y = 0;
		catPos.X = 100;
		catPos.Y = 100;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hdc = BeginPaint(hwnd, &ps);
		//ready_memdc = CreateCompatibleDC(hdc);
		//backgr = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		//oldBgr = (HBITMAP)SelectObject(ready_memdc, backgr);
		

		memdc = CreateCompatibleDC(hdc);

		oldBitCat = (HBITMAP)SelectObject(memdc, hBitCat);
		BitBlt(hdc, catPos.X - 67 / 2, catPos.Y - 48 / 2, 67, 48, memdc, 0, 0, SRCCOPY);
		SelectObject(memdc, oldBitCat);

		oldBitMouse = (HBITMAP)SelectObject(memdc, hBitMouse);
		BitBlt(hdc, mousePos.X - 68 / 2, mousePos.Y - 49 / 2, 68, 49, memdc, 0, 0, SRCCOPY);
		SelectObject(memdc, oldBitMouse);

		BitBlt(hdc, 0, 0, rect.right, rect.bottom, memdc, 0, 0, SRCCOPY);

		DeleteObject(backgr);
		//DeleteDC(ready_memdc);
		DeleteDC(memdc);


		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		clicked = TRUE;
		break;

	case WM_LBUTTONUP:
		clicked = FALSE;
		break;

	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		mousePos.X = mx;
		mousePos.Y = my;

		if (clicked) {
			if (catPos.X < mx) catPos.X++;
			if (catPos.Y < my) catPos.Y++;
			if (catPos.X > mx) catPos.X--;
			if (catPos.Y > my) catPos.Y--;
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		DeleteObject(hBitCat);
		DeleteObject(hBitMouse);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
