#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include "Bug.h"

const int BSIZE = 20;

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
	static int x, y;
	static int tailX, tailY;
	static int dir;
	static Bug* bug;

	static BOOL timerFlag;

	int bugCount;

	static RECT outLine;
	HPEN hPen, tailPen, oldPen;



	switch (iMsg) {
	case WM_CREATE:
		GetClientRect(hwnd, &outLine);
		x = 60; y = 20;
		bugCount = 1;
		bug = new Bug(x, y);
		timerFlag = FALSE;

		break;

	case WM_KEYDOWN:
		if (timerFlag) {
			timerFlag = FALSE;
		}

		switch (wParam) {
		case VK_UP: dir = UP; break;
		case VK_RIGHT: dir = RIGHT; break;
		case VK_DOWN: dir = DOWN; break;
		case VK_LEFT: dir = LEFT; break;
		}


		timerFlag = TRUE;
		SetTimer(hwnd, 1, 100, NULL);

		break;


	case WM_TIMER:

		static Bug* curr = bug;
		static Bug* tail = curr->getTail();

		curr->bugMove(dir, outLine);

		while (curr->getTail()) {
			tail = bug->getTail();
			tail->bugMove(tail->getDir(), outLine);
			tail->setDir(curr->getDir());
			curr = tail;
		}

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, bug->getX() - BSIZE, bug->getY() - BSIZE, bug->getX() + BSIZE, bug->getY() + BSIZE);

		Bug* currBug;
		while (bug->getTail()) {
			currBug = bug->getTail();
			Ellipse(hdc, currBug->getX() - BSIZE, currBug->getY() - BSIZE, currBug->getX() + BSIZE, currBug->getY() + BSIZE);
		}

		
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:

		Bug* delBug = bug->getTail();

		while (delBug != nullptr) {
			delete bug;
			bug = delBug;
			delBug = bug->getTail();
		}

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
