#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>

const int BSIZE = 40;

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
	static int x, y;
	static RECT rectView;
	


	
	switch (iMsg) {
	case WM_CREATE:
		x = y = 50;
		GetClientRect(hwnd, &rectView);
		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case VK_UP: y -= 20; break;
		case VK_RIGHT: x += 20; break;
		case VK_DOWN: y += 20; break;
		case VK_LEFT: x -= 20; break;
		}
		
		if (x + 20 > rectView.right) x -= 20;
		if (y - 20 < 0) y += 20;
		if (y + 20 > rectView.bottom) y -= 20;
		if (x - 20 < 0) x += 20;

		InvalidateRgn(hwnd, NULL, TRUE);
		break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		Ellipse(hdc, x + BSIZE, y + BSIZE, x - BSIZE, y - BSIZE);

		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);  
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
