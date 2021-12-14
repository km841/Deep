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
	static RECT rect;

	static HBITMAP hBit, oldBit;

	TCHAR words[5][100] = {
		_T("무궁화"),
		_T("화려강산"),
		_T("윈도우즈"),
		_T("사람"),
		_T("고달픈")
	};

	static int arr[5] = { 10, 50, 20, 100, 40 };
	static int answer[5] = { 0, };
	static int yPos;

	static HPEN hPen, oldPen;
	static COLORREF fColor;
	static HBRUSH hBrush, oldBrush;
	static SIZE size;

	static TCHAR typing[100];
	static int count;
	static BOOL start;

	



	switch (iMsg) {
	case WM_CREATE:
		CreateCaret(hwnd, NULL, 5, 15);
		ShowCaret(hwnd);
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		hBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5_7));
		GetClientRect(hwnd, &rect);
		yPos = 10;
		count = 0;
		start = FALSE;
		
		break;

	case WM_CHAR:
		if (!start) {
			SetTimer(hwnd, 1, 300, NULL);
			start = TRUE;
		}
		


		if (wParam == VK_BACK && count > 0){
			count--;
			typing[count] = NULL;
		}

		else if (count == 0 && wParam == VK_RETURN || wParam == VK_BACK) {
			break;
		}

		else if (wParam == VK_RETURN && count > 0) {
			for (int i = 0; i < 5; i++) {
				if (_tcscmp(words[i], typing) == 0) {
					answer[i] = 1;
				}
			}
			memset(typing, 0, sizeof(TCHAR) * 100);
			count = 0;
		}

		else {
			typing[count++] = wParam;
			typing[count] = NULL;
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_TIMER:
		for (int i = 0; i < 5; i++) {
			arr[i] += yPos;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;


	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hdc = BeginPaint(hwnd, &ps);
		memdc = CreateCompatibleDC(hdc);
		oldBit = (HBITMAP)SelectObject(memdc, hBit);
		StretchBlt(hdc, 0, 0, rect.right, rect.bottom, memdc, 0, 0, 1024, 768, SRCCOPY);

		SetBkMode(hdc, TRANSPARENT);
		for (int i = 0; i < 5; i++) {
			if (answer[i]) continue;
			fColor = SetTextColor(hdc, RGB(255, 0, 255));
			TextOut(hdc, i * 250, arr[i], words[i], _tcslen(words[i]));
			SetTextColor(hdc, fColor);
			
		}

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, rect.right / 2 - 100, rect.bottom - 70, rect.right / 2 + 100, rect.bottom - 50);
		TextOut(hdc, rect.right / 2 - 100, rect.bottom - 70, typing, _tcslen(typing));

		GetTextExtentPoint(hdc, typing, _tcslen(typing), &size);
		SetCaretPos(rect.right / 2 - 100 + size.cx, rect.bottom - 70);
		SelectObject(hdc, oldBrush);
		DeleteObject(hBrush);



		DeleteDC(memdc);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		HideCaret(hwnd);
		DestroyCaret();
		DeleteObject(hBit);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
