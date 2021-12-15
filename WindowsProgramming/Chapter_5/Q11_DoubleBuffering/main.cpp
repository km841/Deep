#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <locale>
#include "resource.h"

void Animation(int xPos, int yPos, HDC hdc, HINSTANCE hInst, RECT rect) {
	HDC memdc, memdc_temp;
	HBITMAP RunBit[10], hBit, oldBit, Mask[10];
	HBITMAP tempBit, oldTempBit;
	static int count;

	count++;
	count = count % 10;
	Mask[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M1));
	Mask[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M2));
	Mask[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M3));
	Mask[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M4));
	Mask[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M5));
	Mask[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M6));
	Mask[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M7));
	Mask[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M8));
	Mask[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M9));
	Mask[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_M10));
	RunBit[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R1));
	RunBit[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R2));
	RunBit[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R3));
	RunBit[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R4));
	RunBit[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R5));
	RunBit[5] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R6));
	RunBit[6] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R7));
	RunBit[7] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R8));
	RunBit[8] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R9));
	RunBit[9] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_R10));

	memdc_temp = CreateCompatibleDC(hdc);
	memdc = CreateCompatibleDC(memdc_temp);
	
	tempBit = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	
	hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5_6));
	oldBit = (HBITMAP)SelectObject(memdc_temp, hBit);

	BitBlt(memdc, 0, 0, 819, 614, memdc_temp, 0, 0, SRCCOPY);
	SelectObject(memdc, RunBit[count]);
	BitBlt(memdc, xPos, yPos, 180, 240, memdc_temp, 0, 0, SRCAND);

	SelectObject(memdc_temp, Mask[count]);
	BitBlt(memdc, xPos, yPos, 180, 240, memdc_temp, 0, 0, SRCPAINT);
	SelectObject(memdc_temp, oldBit);

	oldTempBit = (HBITMAP)SelectObject(hdc, tempBit);
	BitBlt(hdc, 0, 0, rect.right, rect.bottom, memdc, 0, 0, SRCCOPY);
	SelectObject(memdc, oldTempBit);

	for (int i = 0; i < 10; i++) {
		DeleteObject(RunBit[i]);
		DeleteObject(Mask[i]);
	}

	DeleteDC(memdc);
	DeleteDC(memdc_temp);
	DeleteObject(hBit);
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
	static HINSTANCE hInst;
	static int xPos;

	static RECT rect;


	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		xPos = -100;
		SetTimer(hwnd, 1, 100, NULL);
		break;

	case WM_TIMER:
		xPos += 10;
		if (xPos > 819) xPos = -100;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		Animation(xPos, 300, hdc, hInst, rect);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
