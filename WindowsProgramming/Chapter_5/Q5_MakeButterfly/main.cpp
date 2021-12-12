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
	HDC hdc, mem1dc, mem2dc;
	PAINTSTRUCT ps;
	static COORD pos[100];
	static int posCount;
	static RECT rect;

	static HBITMAP hBit, oldBit, hBit1;
	static HBITMAP oldBit1, oldBit2;
	static HBITMAP butter, butterM;
	int x, y;



	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		posCount = 0;
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5_7));
		butter = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_B1));
		butterM = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_BM1));
		GetClientRect(hwnd, &rect);
		break;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		pos[posCount].X = x;
		pos[posCount].Y = y;

		posCount++;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		mem1dc = CreateCompatibleDC(hdc);
		mem2dc = CreateCompatibleDC(mem1dc);
		oldBit = (HBITMAP)SelectObject(mem2dc, hBit);
		hBit1 = CreateCompatibleBitmap(hdc, 1024, 768);
		SelectObject(mem1dc, hBit1);
		StretchBlt(mem1dc, 0, 0, 1024, 768, mem2dc, 0, 0, 1024, 768, SRCCOPY);

		for (int i = 0; i < posCount; i++) {
			x = pos[i].X - 55/2;
			y = pos[i].Y - 55/2;
			
			oldBit1 = (HBITMAP)SelectObject(mem2dc, butterM);
			BitBlt(mem1dc, x, y, 55, 55, mem2dc, 0, 0, SRCAND);
			oldBit2 = (HBITMAP)SelectObject(mem2dc, butter);
			BitBlt(mem1dc, x, y, 55, 55, mem2dc, 0, 0, SRCPAINT);

			SelectObject(mem2dc, oldBit1);
		}

		BitBlt(hdc, 0, 0, 1024, 768, mem1dc, 0, 0, SRCCOPY);

		DeleteDC(mem2dc);
		DeleteDC(mem1dc);
		SelectObject(mem1dc, oldBit);
		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		DeleteObject(hBit);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
