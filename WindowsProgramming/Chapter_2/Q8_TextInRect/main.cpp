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
	static TCHAR str[19][1024];
	static int count;
	static SIZE size;
	static int yPos;
	static int line;
	RECT rect = { 150, 200, 550, 400 };


	switch (iMsg) {
	case WM_CREATE:
		CreateCaret(hwnd, NULL, 5, 15);
		ShowCaret(hwnd);
		count = 0;
		line = 0;
		yPos = rect.top;
		break;

	case WM_CHAR:
		if (wParam == VK_RETURN) {
			str[line][count] = NULL;
			line++;
			yPos += 20;
			count = 0;
		}

		str[line][count++] = wParam;
		str[line][count] = NULL;
		InvalidateRgn(hwnd, NULL, TRUE);

	case WM_PAINT:
		if (yPos < 380) {
			hdc = BeginPaint(hwnd, &ps);
			Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

			for (int i = 0; i < line + 1; i++)
				TextOut(hdc, rect.left, rect.top + (i * 20), str[i], _tcslen(str[i]));

			GetTextExtentPoint(hdc, str[line], _tcslen(str[line]), &size);
			if (size.cx > 400) {
				yPos += 20;
				line++;
				count = 0;
			}
			SetCaretPos(rect.left + size.cx, yPos);
			EndPaint(hwnd, &ps);
		}

		else {
			HideCaret(hwnd);
			DestroyCaret();
			yPos = 0xffff;
			memset(str, NULL, (sizeof(TCHAR) * 19) * 1024);
			line = 0;
			count = 0;
		}
		break;

		

	case WM_DESTROY:
		HideCaret(hwnd);
		DestroyCaret();
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
