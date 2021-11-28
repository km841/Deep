#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>


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
	static int catX, catY;
	static int mouseX, mouseY;
	static BOOL MouseInRect;


	

	switch (iMsg) {
	case WM_CREATE:
		catX = catY = 100;
		MouseInRect = FALSE;
		break;

	case WM_LBUTTONDOWN:
		MouseInRect = TRUE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		MouseInRect = FALSE;
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		if (MouseInRect) {
			mouseX = LOWORD(lParam);
			mouseY = HIWORD(lParam);

			if (catX > mouseX) catX--;
			if (catY > mouseY) catY--;
			if (catX < mouseX) catX++;
			if (catY < mouseY) catY++;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_PAINT:

		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, catX, catY, _T("고양이"), _tcslen(_T("고양이")));
		if (MouseInRect) TextOut(hdc, mouseX, mouseY, _T("쥐"), _tcslen(_T("쥐")));
		
		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);  
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
