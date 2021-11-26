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
	static TCHAR str[10][100];
	static int row, colume;
	static int yPos;
	static int columeCnt[10];
	static SIZE size;


	switch (iMsg) {
	case WM_CREATE:
		row = 0;
		colume = 0;
		yPos = 0;
		CreateCaret(hwnd, NULL, 5, 15);
		ShowCaret(hwnd);
		break;

	case WM_CHAR:
		if ((wParam == VK_RETURN) || (colume == 99)) {
			columeCnt[row] = colume;
			row++;
			colume = 0;
			yPos += 20;
		}

		else if ((wParam == VK_BACK) && (colume == 0) && (row > 0)) {
			row--;
			colume = columeCnt[row];
			colume--;
			str[row][colume] = NULL;
			yPos -= 20;
		}

		else if (wParam == VK_BACK && colume > 0) {
			colume--;
			str[row][colume] = NULL;
		}

		else if (row < 10) {
			str[row][colume++] = wParam;
			str[row][colume] = NULL;

		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetTextExtentPoint(hdc, str[row], _tcslen(str[row]), &size);
		for (int i = 0; i < row + 1; i++)
			TextOut(hdc, 0, i * 20, str[i], _tcslen(str[i]));

		SetCaretPos(size.cx, yPos);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		HideCaret(hwnd);
		DestroyCaret();
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
