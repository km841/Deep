#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <locale>
#include "resource.h"

enum {
	LINE = 1,
	ELLIPSE = 2,
	RECTANGLE = 3
};

const int BSIZE = 20;



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
	int mx, my;
	static int startX, startY;
	static int beforeX, beforeY;

	static int tool;
	static BOOL clicked;
	static BOOL drag;

	static CHOOSECOLOR color;
	CHOOSEFONT font;

	static COLORREF fColor, sColor, tmp[16];
	static HBRUSH hBrush, oldBrush;
	static HPEN hPen, oldPen;

	switch (iMsg) {
	case WM_CREATE:
		tool = 0;
		startX = startY = 0;
		clicked = FALSE;
		drag = FALSE;
		fColor = 0xffffff;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_LINE:
			tool = 1;
			break;

		case ID_ELLIPSE:
			tool = 2;
			break;

		case ID_RECTANGLE:
			tool = 3;
			break;

		case ID_PENCOLOR:
			for (int i = 0; i < 16; i++) {
				tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
			}
			memset(&color, 0, sizeof(CHOOSECOLOR));
			color.lStructSize = sizeof(CHOOSECOLOR);
			color.hwndOwner = hwnd;
			color.lpCustColors = tmp;
			color.Flags = CC_FULLOPEN;
			if (ChooseColor(&color) != 0) {
				fColor = color.rgbResult;
			}


			break;

		case ID_FACECOLOR:
			for (int i = 0; i < 16; i++) {
				tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
			}
			memset(&color, 0, sizeof(CHOOSECOLOR));
			color.lStructSize = sizeof(CHOOSECOLOR);
			color.hwndOwner = hwnd;
			color.lpCustColors = tmp;
			color.Flags = CC_FULLOPEN;
			if (ChooseColor(&color) != 0) {
				sColor = color.rgbResult;
			}
			break;

		}
		break;

	case WM_LBUTTONDOWN:
		drag = TRUE;
		startX = LOWORD(lParam);
		startY = HIWORD(lParam);

		//InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		drag = FALSE;
		startX = 0;
		startY = 0;
		beforeX = 0;
		beforeY = 0;
		//InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		SetROP2(hdc, R2_XORPEN);
		//SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));

		if (drag && tool == 1) {
			hPen = CreatePen(PS_SOLID, 1, fColor);
			oldPen = (HPEN)SelectObject(hdc, hPen);

			if (startX > 0 && startY > 0 && beforeX > 0 && beforeY > 0) {
				MoveToEx(hdc, startX, startY, NULL);
				LineTo(hdc, beforeX, beforeY);
			}
			
			MoveToEx(hdc, startX, startY, NULL);
			LineTo(hdc, mx, my);

			SelectObject(hdc, oldPen);
			DeleteObject(hPen);
		}

		else if (drag && tool == 2) {
			hBrush = CreateSolidBrush(sColor);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			if (startX > 0 && startY > 0 && beforeX > 0 && beforeY > 0) {
				Ellipse(hdc, startX, startY, beforeX, beforeY);
			}

			Ellipse(hdc, startX, startY, mx, my);

			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);

		}

		else if (drag && tool == 3) {
			hBrush = CreateSolidBrush(sColor);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

			if (startX > 0 && startY > 0 && beforeX > 0 && beforeY > 0) {
				Rectangle(hdc, startX, startY, beforeX, beforeY);
			}

			Rectangle(hdc, startX, startY, mx, my);

			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
		}

		beforeX = mx;
		beforeY = my;

		ReleaseDC(hwnd, hdc);
		break;




	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}
	

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
