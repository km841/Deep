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
	HDC hdc, memdc;
	PAINTSTRUCT ps;
	static RECT rect;
	static int div;

	static HBITMAP hBit, oldBit;

	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		GetClientRect(hwnd, &rect);
		div = 5;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hdc = BeginPaint(hwnd, &ps);
		memdc = CreateCompatibleDC(hdc);
		oldBit = (HBITMAP)SelectObject(memdc, hBit);
		//StretchBlt(hdc, 0, 0, rect.right, rect.bottom, memdc, 0, 0, 819, 614, SRCCOPY);

		for (int i = 0; i < rect.right / (rect.right / div); i++) {
			for (int j = 0; j < rect.bottom / (rect.bottom / div); j++) {
				StretchBlt(hdc, (rect.right / div) * i, (rect.bottom / div) * j, rect.right / div, rect.bottom / div,
					memdc, (819 / div) * ((rect.right / (rect.right / div)) - i - 1), (614 / div) * ((rect.bottom / (rect.bottom / div)) - j - 1), 819 / div, 614 / div, SRCCOPY);
			}

		}

		SelectObject(memdc, oldBit);
		DeleteDC(memdc);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_3BY3:
			div = 3;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case ID_4BY4:
			div = 4;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;
			
		case ID_5BY5:
			div = 5;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;
		}
		break;

	case WM_DESTROY:
		DeleteObject(hBit);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
