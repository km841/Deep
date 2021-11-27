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
	RECT rect = { 0, 500, 500, 520 };
	static TCHAR str[100];
	static int count;
	static SIZE size;
	static TCHAR* ptr;
	static TCHAR* arg1, * arg2, * arg3, * arg4;
	static TCHAR* tok;
	
	switch (iMsg) {
	case WM_CREATE:
		CreateCaret(hwnd, NULL, 5, 15);
		ShowCaret(hwnd);
		count = 0;
		break;

	case WM_CHAR:

		if (wParam == VK_RETURN) {

			tok = new TCHAR[count];
			for (int i = 0; i < count; i++) {
				tok[i] = str[i];
			}

			ptr = _tcstok(tok, _T("("));
			arg1 = _tcstok(NULL, _T(","));
			arg2 = _tcstok(NULL, _T(","));
			arg3 = _tcstok(NULL, _T(","));
			arg4 = _tcstok(NULL, _T(")"));

		}

		else if (wParam == VK_BACK && count > 0) {
			count--;
			str[count] = NULL;
		}

		else {
			if (wParam != VK_BACK) {
				str[count++] = wParam;
				str[count] = NULL;
			}
		}

		InvalidateRect(hwnd, NULL, TRUE);
		break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		TextOut(hdc, 0, 500, str, _tcslen(str));
		GetTextExtentPoint(hdc, str, _tcslen(str), &size);
		SetCaretPos(size.cx, 500);


		if (ptr != NULL && (_tcscmp(_T("Rectangle"), ptr) == 0)) {
			Rectangle(hdc, _ttoi(arg1), _ttoi(arg2), _ttoi(arg3), _ttoi(arg4));
		}

		else if (ptr != NULL && (_tcscmp(_T("Line"), ptr) == 0)) {
			MoveToEx(hdc, _ttoi(arg1), _ttoi(arg2), NULL);
			LineTo(hdc, _ttoi(arg3), _ttoi(arg4));
		}

		else if (ptr != NULL && (_tcscmp(_T("Ellipse"), ptr) == 0)) {
			Ellipse(hdc, _ttoi(arg1), _ttoi(arg2), _ttoi(arg3), _ttoi(arg4));
		}

		EndPaint(hwnd, &ps);
		if (tok != NULL) {
			delete[] tok;
			tok = NULL;
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
