#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <vector>
#include <tchar.h>
#include <random>
#include "Bug.h"
#include "Food.h"

const int BSIZE = 20;
std::random_device rd;
std::mt19937 random(rd());



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
	static Bug* currTail;

	static Food* food[2];
	

	static int overlapedX[3];
	static int overlapedY[3];
	static int foodCount;

	static BOOL timerFlag;

	int bugCount;

	static RECT outLine;
	HPEN hPen, tailPen, oldPen;
	HBRUSH hBrush, oldBrush;


	switch (iMsg) {
	case WM_CREATE:
		GetClientRect(hwnd, &outLine);
		
		x = 100; y = 60;
		bugCount = 1;
		bug = new Bug(x, y);
		currTail = bug;
		bug->setDir(RIGHT);
		
		foodCount = 0;
		timerFlag = FALSE;
		overlapedX[foodCount] = x;
		overlapedY[foodCount] = y;
		foodCount++;

		for (int i = 0; i < 2; i++) {
			std::uniform_int_distribution<> random_width(80, outLine.right - 80);
			std::uniform_int_distribution<> random_height(80, outLine.bottom - 80);

			int randX = random_width(random);
			int randY = random_height(random);

			for (int j = 0; j < foodCount; j++) {
				if (abs(randX - overlapedX[j]) < 20 || abs(randY - overlapedY[j]) < 20) {
					i--;
					break;
				}

				else
				{
					overlapedX[i + 1] = randX;
					overlapedY[i + 1] = randY;
				}
			}
		}

		for (int i = 0; i < 2; i++) {
			food[i] = new Food(overlapedX[i + 1], overlapedY[i + 1]);
		}

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
		SetTimer(hwnd, 1, 200, NULL);

		break;


	case WM_TIMER:
		
		bug->bugMove(dir, outLine);

		static Bug* isCurrTail;
		static Bug* prevTail;
		prevTail = bug;
		isCurrTail = bug->getTail();
		while (prevTail->isTail()) {
			isCurrTail->setPrevX(isCurrTail->getX());
			isCurrTail->setPrevY(isCurrTail->getY());

			isCurrTail->setX(prevTail->getPrevX());
			isCurrTail->setY(prevTail->getPrevY());

			isCurrTail->tailPos(isCurrTail->getPrevX(), isCurrTail->getPrevY());

			prevTail = isCurrTail;
			isCurrTail = isCurrTail->getTail();
		}
		

		for (int i = 0; i < 2; i++) {
			if (bug->isEat(food[i]->getX(), food[i]->getY())) {
				food[i]->setX(outLine.right + 40);
				food[i]->setY(outLine.bottom + 40);
				
				currTail->addTail();
				currTail = currTail->getTail();
				break;
			}
		}
		

		InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		for (int i = 20; i < outLine.right; i += 40) {
			Rectangle(hdc, i - BSIZE, 0, i + BSIZE, 40);
			Rectangle(hdc, i - BSIZE, outLine.bottom - BSIZE * 2, i + BSIZE, outLine.bottom);
		}

		for (int i = 60; i < outLine.bottom - 40; i += 40) {
			Rectangle(hdc, 0, i - BSIZE, 40, i + BSIZE);
			Rectangle(hdc, outLine.right - 55, i - BSIZE, outLine.right - 15, i + BSIZE);
		}

		Bug* curr;
		curr = bug;

		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		oldPen = (HPEN)SelectObject(hdc, hPen);
		Ellipse(hdc, curr->getX() - BSIZE, curr->getY() - BSIZE, curr->getX() + BSIZE, curr->getY() + BSIZE);
		curr = curr->getTail();
		SelectObject(hdc, hPen);
		DeleteObject(hPen);

		tailPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		oldPen = (HPEN)SelectObject(hdc, tailPen);
		while (curr) {
			Ellipse(hdc, curr->getX() - BSIZE, curr->getY() - BSIZE, curr->getX() + BSIZE, curr->getY() + BSIZE);
			curr = curr->getTail();
		}
		SelectObject(hdc, oldPen);
		DeleteObject(tailPen);

		

		for (int i = 0; i < 2; i++) {
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			Rectangle(hdc, food[i]->getX() - 20, food[i]->getY() - 20, food[i]->getX() + 20, food[i]->getY() + 20);

			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
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

		for (int i = 0; i < 2; i++) {
			if (food[i] != nullptr) {
				delete food[i];
				food[i] = nullptr;
			}
		}

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
