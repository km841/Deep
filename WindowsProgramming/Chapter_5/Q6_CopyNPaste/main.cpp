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
	static HBITMAP hBit, oldBit;
	static HBITMAP pBit, pOldBit;
	HDC hdc, memdc;
	HDC mem1dc;
	PAINTSTRUCT ps;

	static BOOL clicked;
	static BOOL select;
	static BOOL copyFlag;
	static BOOL pasteFlag;

	static RECT rect;
	static int startX, startY;
	static int beforeX, beforeY;
	static int endX, endY;
	int x, y;

	static COORD startPos;
	static COORD endPos;

	static COORD paste_startPos;
	static COORD paste_endPos;

	static int beforeMode;

	static HBRUSH hBrush, oldBrush;
	static HPEN hPen, oldPen;


	



	switch (iMsg) {
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5_7));
		GetClientRect(hwnd, &rect);
		clicked = FALSE;
		select = FALSE;
		copyFlag = FALSE;
		pasteFlag = FALSE;
	
		break;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		
		startX = x;
		startY = y;

		clicked = TRUE;

		startPos.X = x;
		startPos.Y = y;
	
		break;

	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		hdc = GetDC(hwnd);
		beforeMode = SetROP2(hdc, R2_XORPEN);
		SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));

		if (clicked) {
			if (beforeX && beforeY && startX && startY)
			Rectangle(hdc, startX, startY, beforeX, beforeY);
			Rectangle(hdc, startX, startY, x, y);
		}

		beforeX = x;
		beforeY = y;

		SetROP2(hdc, beforeMode);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_LBUTTONUP:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		startX = 0;
		startY = 0;
		beforeX = 0;
		beforeY = 0;

		endPos.X = x;
		endPos.Y = y;
		clicked = FALSE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		memdc = CreateCompatibleDC(hdc);
		oldBit = (HBITMAP)SelectObject(memdc, hBit);
		BitBlt(hdc, 0, 0, 1024, 768, memdc, 0, 0, SRCCOPY);

		if (startPos.X && startPos.Y && endPos.X && endPos.Y) {
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			oldPen = (HPEN)SelectObject(hdc, hPen);
			hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			Rectangle(hdc, startPos.X, startPos.Y, endPos.X, endPos.Y);
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
			SelectObject(hdc, oldPen);
			DeleteObject(hPen);
			select = TRUE;
		}

		if (pasteFlag && pBit) {
			mem1dc = CreateCompatibleDC(hdc);
			pOldBit = (HBITMAP)SelectObject(mem1dc, pBit);
			BitBlt(hdc, 0, 0, paste_endPos.X - paste_startPos.X, paste_endPos.Y - paste_startPos.Y, mem1dc, 0, 0, SRCCOPY);

			SelectObject(mem1dc, pOldBit);
			
			DeleteDC(mem1dc);
		}


		DeleteDC(memdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {

		case ID_EDITCOPY:
			copyFlag = TRUE;
			paste_startPos.X = startPos.X;
			paste_startPos.Y = startPos.Y;
			paste_endPos.X = endPos.X;
			paste_endPos.Y = endPos.Y;
			break;

		case ID_EDITPASTE:
			if (copyFlag && select) {
				hdc = GetDC(hwnd);
				mem1dc = CreateCompatibleDC(hdc);
				pBit = CreateCompatibleBitmap(hdc, paste_endPos.X - paste_startPos.X, paste_endPos.Y - paste_startPos.Y);

				pOldBit = (HBITMAP)SelectObject(mem1dc, pBit);
				BitBlt(mem1dc, 0, 0, paste_endPos.X, paste_endPos.Y, hdc, paste_startPos.X, paste_startPos.Y, SRCCOPY);
				BitBlt(hdc, 0, 0, paste_endPos.X - paste_startPos.X, paste_endPos.Y - paste_startPos.Y, mem1dc, 0, 0, SRCCOPY);
				SelectObject(mem1dc, pOldBit);

				DeleteDC(mem1dc);
				//DeleteObject(pBit);

				ReleaseDC(hwnd, hdc);
				pasteFlag = TRUE;
				InvalidateRgn(hwnd, NULL, TRUE);
			}
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
