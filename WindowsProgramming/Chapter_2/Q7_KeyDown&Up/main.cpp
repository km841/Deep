#include <Windows.h>
#include <iostream>
#include <tchar.h>

enum {
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3
};
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
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;
	int radius = 20;
	static int pos;
	RECT rect[4] = {
		{200, 10, 250, 110},
		{250, 110, 300, 210},
		{200, 210, 250, 310},
		{150, 110, 200, 210}
	};


	switch (iMsg) {
	case WM_CREATE:
		break;

	case WM_KEYDOWN:
		
		if (wParam == VK_UP) pos = 0;
		else if (wParam == VK_RIGHT) pos = 1;
		else if (wParam == VK_DOWN) pos = 2;
		else if (wParam == VK_LEFT) pos = 3;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_KEYUP:
		InvalidateRgn(hwnd, NULL, TRUE);
		break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));

		for (int i = 0; i < 4; i++) {
			if (pos == i) {
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				Rectangle(hdc, rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
				SelectObject(hdc, oldBrush);
				pos = 0xff;
			}
			else
				Rectangle(hdc, rect[i].left, rect[i].top, rect[i].right, rect[i].bottom);
		}
		

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
