#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include "resource.h"


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
	static HINSTANCE hInst;
	HDC hdc, memdc;
	PAINTSTRUCT ps;
	static HBITMAP hBit, oldBit;
	static RECT rect;

	static int x, y;
	static BOOL trigger;
	static BOOL signX, signY;


	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5_2));
		GetClientRect(hwnd, &rect);
		trigger = FALSE;
		x = y = 200;
		signX = TRUE;
		signY = TRUE;
		
		break;

	case WM_KEYDOWN:
		if (!trigger) {
			trigger = TRUE;
			SetTimer(hwnd, 1, 20, NULL);
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;


	case WM_TIMER:
		if (x + 280 > rect.right) signX = FALSE;
		if (y + 280 > rect.bottom) signY = FALSE;
		if (x < 0) signX = TRUE;
		if (y < 0) signY = TRUE;

		if (signX == TRUE) x += 5;
		else if (signX == FALSE) x -= 5;
		
		if (signY == TRUE) y += 5;
		else if (signY == FALSE) y -= 5;

		InvalidateRgn(hwnd, NULL, TRUE);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);

		memdc = CreateCompatibleDC(hdc);
		oldBit = (HBITMAP)SelectObject(memdc, hBit);
		BitBlt(hdc, x, y, 280, 280, memdc, 0, 0, SRCCOPY);

		SelectObject(memdc, oldBit);
		DeleteDC(memdc);

		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		DeleteObject(hBit);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
