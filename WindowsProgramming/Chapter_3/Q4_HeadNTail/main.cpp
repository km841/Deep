#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>


enum Dir {
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3,

	DIR = 4
};

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
	static BOOL flag;
	static int x, y;
	static int tailX, tailY;
	static int dir;

	static RECT outLine;
	
	HPEN hPen, tailPen, oldPen;

	


	
	switch (iMsg) {
	case WM_CREATE:
		GetClientRect(hwnd, &outLine);
		x = 60; y = 20;
		tailX = 20; tailY = 20;
		flag = FALSE;
		break;

	case WM_KEYDOWN:
		if (flag)
		{
			KillTimer(hwnd, 1);
			flag = FALSE;
		}

		switch (wParam) {
		case VK_UP: dir = UP; break;
		case VK_RIGHT: dir = RIGHT; break;
		case VK_DOWN: dir = DOWN; break;
		case VK_LEFT: dir = LEFT; break;
		}
		
		if (!flag) {
			SetTimer(hwnd, 1, 100, NULL);
			flag = TRUE;
		}

		break;


	case WM_TIMER:
		if (dir == UP) {
			y -= 40;
			tailX = x;
			tailY = y + 40;
			if (y - 20 < 0) {
				y += 40;
				tailY = y + 40;
			}
		}

		else if (dir == RIGHT) {
			x += 40;
			tailX = x - 40;
			tailY = y;
			if (x + 20 > outLine.right) {
				x -= 40;
				tailX = x - 40;
			}
		}

		else if (dir == DOWN) {
			y += 40;
			tailX = x;
			tailY = y - 40;
			if (y + 20 > outLine.bottom) {
				y -= 40;
				tailY = y - 40;
			}
		}

		else if (dir == LEFT) {
			x -= 40;
			tailX = x + 40;
			tailY = y;
			if (tailX - 40 < 0) {
				x += 40;
				tailX = x + 40;
			}
		}


		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Rectangle(hdc, outLine.left, outLine.top, outLine.right, outLine.bottom);

		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		oldPen = (HPEN)SelectObject(hdc, hPen);
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);

		tailPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		SelectObject(hdc, tailPen);
		Ellipse(hdc, tailX - 20, tailY - 20, tailX + 20, tailY + 20);
		SelectObject(hdc, oldPen);

		DeleteObject(hPen);
		DeleteObject(tailPen);
	
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);  
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
