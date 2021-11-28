#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include "Circle.h"


const int radius = 20;
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
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");

	RegisterClass(&WndClass);

	hwnd = CreateWindow(_T("Window Class Name"),
		_T("확씨의 첫 번째 윈도우"),
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
	const int radius = 50;
	static int myX, myY;
	static int oldX, oldY;
	static BOOL Drag;
	static BOOL Flag;
	static RECT rect;
	static Circle circles[10] = {
		{500, 30, 50},
		{300, 250, 30},
		{500, 500, 70},
		{250, 400, 50},
		{500, 120, 40},
		{500, 380, 70},
		{400, 190, 70},
		{840, 40, 50},
		{680, 200, 70},
		{780, 600, 20},
	};

	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;
	static TCHAR* outputString;
	static int count;
	static int nCount;



	switch (iMsg) {
	case WM_CREATE:
		count = 0;
		nCount = 0;
		myX = myY = 0;
		Drag = FALSE;
		Flag = FALSE;
		outputString = new TCHAR[100];
		GetClientRect(hwnd, &rect);
		break;

	case WM_LBUTTONDOWN:
		Drag = TRUE;
		break;

	case WM_LBUTTONUP:
		Drag = FALSE;
		break;

	case WM_MOUSEMOVE:
		if (Drag) {
			myX = LOWORD(lParam);
			myY = HIWORD(lParam);
		}
		InvalidateRgn(hwnd, NULL, TRUE);


		if (myX + 50 > rect.right && myY + 50 > rect.bottom) {
			Flag = TRUE;
			if (nCount == 0)
				for (int i = 0; i < 10; i++) {
					if (!circles[i].getStatus()) count++;
				}
			nCount++;
		}


		break;

	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);

		if (Flag) {
			

			_stprintf(outputString, _T("충돌한 공의 개수는 %d개 입니다."), count);

			TextOut(hdc, rect.right / 2 - 100, rect.bottom / 2, outputString, _tcslen(outputString));
			Flag = FALSE;

		}
		Ellipse(hdc, myX - radius, myY - radius, myX + radius, myY + radius);

		for (int i = 0; i < 10; i++) {
			circles[i].isCrash(myX, myY);

			if (circles[i].getStatus() == TRUE) {
				hBrush = CreateSolidBrush(RGB(0, 255, 0));
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

				Ellipse(
					hdc,
					circles[i].getX() - radius,
					circles[i].getY() - radius,
					circles[i].getX() + radius,
					circles[i].getY() + radius);

				SelectObject(hdc, oldBrush);
				DeleteObject(hBrush);
			}

			else {
				hBrush = CreateSolidBrush(RGB(255, 0, 0));
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

				Ellipse(
					hdc,
					circles[i].getX() - radius,
					circles[i].getY() - radius,
					circles[i].getX() + radius,
					circles[i].getY() + radius);

				SelectObject(hdc, oldBrush);
				DeleteObject(hBrush);
			}
		}

		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		delete[] outputString;
		PostQuitMessage(0);  
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
