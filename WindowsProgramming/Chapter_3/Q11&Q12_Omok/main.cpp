#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>

struct Pos {
	int x, y;
	Pos(int x, int y) : x(x), y(y) {}
};

Pos* CoordToIndex(Pos* p) {
	int coordX = p->x / 40;
	int coordY = p->y / 40;
	Pos* pos = new Pos(coordX, coordY);

	return pos;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

const int BSIZE = 20;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
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
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static Pos* pos;
	static Pos* curr;

	static bool myTurn;

	static int board[4][8];

	HBRUSH hBrush, oldBrush;

	switch (iMsg) {
	case WM_CREATE:
		memset(board, 0, 4 * (sizeof(int) * 8));
		myTurn = TRUE;
		pos = new Pos(20, 20);
		break;

	case WM_LBUTTONDOWN:
		pos->x = LOWORD(lParam);
		pos->y = HIWORD(lParam);

		curr = CoordToIndex(pos);
		if (curr->x > 8 || curr->y > 4) break;
		else {
			if (board[curr->y][curr->x] == 0) {
				if (myTurn) {
					board[curr->y][curr->x] = 1;
					myTurn = FALSE;
				}

				else {
					board[curr->y][curr->x] = 2;
					myTurn = TRUE;
				}
			}
		}

		InvalidateRgn(hwnd, NULL, TRUE);

		break;
		

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				Rectangle(hdc, (i * 40) + 20 - BSIZE, (j * 40) + 20 - BSIZE, (i * 40) + 20 + BSIZE, (j * 40) + 20 + BSIZE);
				if (board[j][i] == 1) {
					oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(BLACK_BRUSH));
					Ellipse(hdc, (i * 40) + 20 - BSIZE, (j * 40) + 20 - BSIZE, (i * 40) + 20 + BSIZE, (j * 40) + 20 + BSIZE);
					SelectObject(hdc, oldBrush);
				}

				else if (board[j][i] == 2) {
					Ellipse(hdc, (i * 40) + 20 - BSIZE, (j * 40) + 20 - BSIZE, (i * 40) + 20 + BSIZE, (j * 40) + 20 + BSIZE);

				}
			}
		}
		
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		if (pos != nullptr) {
			delete pos;
			pos = nullptr;
		}

		if (curr != nullptr) {
			delete curr;
			curr = nullptr;
		}
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
