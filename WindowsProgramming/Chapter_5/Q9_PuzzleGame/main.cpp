#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include "resource1.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

COORD getCoord(int xsize, int ysize, int picSizeX, int picSizeY) {
	COORD c;
	c.X = xsize / picSizeX;
	c.Y = ysize / picSizeY;

	return c;
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
	srand(static_cast<unsigned int>(time(nullptr)));

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
	static int randX;
	static int randY;
	static BOOL startFlag;
	static BOOL select;

	static int mx, my;
	static int xSize, ySize;
	static COORD checkPoint;
	static COORD beforeCheckPoint;

	static HBITMAP hBit, oldBit;
	static HPEN hPen, oldPen;
	static HBRUSH hBrush, oldBrush;

	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		GetClientRect(hwnd, &rect);
		div = 5;
		randX = rand() % div;
		randY = rand() % div;
		xSize = rect.right / div;
		ySize = rect.bottom / div;
		mx = my = 0;
		checkPoint.X = -1;
		checkPoint.Y = -1;
		beforeCheckPoint.X = -1;
		beforeCheckPoint.Y = -1;
		select = FALSE;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		xSize = rect.right / div;
		ySize = rect.bottom / div;
		hdc = BeginPaint(hwnd, &ps);
		memdc = CreateCompatibleDC(hdc);
		oldBit = (HBITMAP)SelectObject(memdc, hBit);
		//StretchBlt(hdc, 0, 0, rect.right, rect.bottom, memdc, 0, 0, 819, 614, SRCCOPY);

		for (int i = 0; i < rect.right / (rect.right / div); i++) {
			for (int j = 0; j < rect.bottom / (rect.bottom / div); j++) {
				if (startFlag && randX == i && randY == j) {
					continue;

				}
				StretchBlt(hdc, (rect.right / div) * i, (rect.bottom / div) * j, rect.right / div, rect.bottom / div,
					memdc, (819 / div) * ((rect.right / (rect.right / div)) - i - 1), (614 / div) * ((rect.bottom / (rect.bottom / div)) - j - 1), 
					819 / div, 614 / div, SRCCOPY);
			}
		}

		if (checkPoint.X > -1 && checkPoint.Y > -1) {
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)GetStockObject(NULL_BRUSH));
			oldPen = (HPEN)SelectObject(hdc, hPen);
			Rectangle(hdc, checkPoint.X * xSize, checkPoint.Y * ySize, 
				checkPoint.X * xSize + xSize, checkPoint.Y * ySize + ySize);
			SelectObject(hdc, oldPen);
			SelectObject(hdc, oldBrush);
			DeleteObject(hPen);
			select = TRUE;
		}

		SelectObject(memdc, oldBit);
		DeleteDC(memdc);
		break;

	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		beforeCheckPoint.X = checkPoint.X;
		beforeCheckPoint.Y = checkPoint.Y;
		checkPoint = getCoord(mx, my, xSize, ySize);


		if (select && checkPoint.X == randX && checkPoint.Y == randY) {
			randX = beforeCheckPoint.X;
			randY = beforeCheckPoint.Y;
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_3BY3:
			div = 3;
			randX = rand() % div;
			randY = rand() % div;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case ID_4BY4:
			div = 4;
			randX = rand() % div;
			randY = rand() % div;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;
			
		case ID_5BY5:
			div = 5;
			randX = rand() % div;
			randY = rand() % div;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case ID_GAMESTART:
			startFlag = TRUE;
			InvalidateRgn(hwnd, NULL, TRUE);
			break;

		case ID_OVERVIEW:
			startFlag = FALSE;
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
