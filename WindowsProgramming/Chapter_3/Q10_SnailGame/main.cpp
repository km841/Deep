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

struct Worm {
	int x, y;
	Worm(int x, int y) : x(x), y(y) {}
};

void alignWorm(std::vector<Worm>& v, int x, int y) {
	int tempX, tempY;
	int _tempX, _tempY;

	tempX = v[0].x;
	tempY = v[0].y;

	v[0].x = x;
	v[0].y = y;

	for (int i = 1; i < v.size(); i++) {
		if (v.size() >= 2) {
			_tempX = v[i].x;
			_tempY = v[i].y;
			v[i].x = tempX;
			v[i].y = tempY;
			tempX = _tempX;
			tempY = _tempY;
		}

		else break;
	}
}



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
	static int dir;
	static Food* food[2];

	static std::vector<Worm> v;


	static int overlapedX[3];
	static int overlapedY[3];
	static int foodCount;

	static BOOL timerFlag;

	static RECT outLine;
	HPEN hPen, tailPen, oldPen;
	HBRUSH hBrush, oldBrush;


	switch (iMsg) {
	case WM_CREATE:
		GetClientRect(hwnd, &outLine);

		x = 100; y = 60;
		v.emplace_back(x, y);

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

		for (int i = 0; i < 2; i++) {
			if (abs(v.front().x - food[i]->getX()) < 40 && abs(v.front().y - food[i]->getY()) < 40) {
				std::uniform_int_distribution<> random_width(80, outLine.right - 80);
				std::uniform_int_distribution<> random_height(80, outLine.bottom - 80);

				food[i]->setX(random_width(random));
				food[i]->setY(random_height(random));

				v.emplace_back(v.back().x, v.back().y);
				break;
			}
		}
		
		switch (dir) {
		case UP: y = v.front().y - 40; break;
		case RIGHT: x = v.front().x + 40; break;
		case DOWN: y = v.front().y + 40; break;
		case LEFT: x = v.front().x - 40; break;
		}

		alignWorm(v, x, y);


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


		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		oldPen = (HPEN)SelectObject(hdc, hPen);

		Ellipse(hdc, v.front().x - BSIZE, v.front().y - BSIZE, v.front().x + BSIZE, v.front().y + BSIZE);

		SelectObject(hdc, hPen);
		DeleteObject(hPen);

		tailPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		oldPen = (HPEN)SelectObject(hdc, tailPen);

		if (v.size() >= 2)
			for (int i = 1; i < v.size(); i++)
				Ellipse(hdc, v[i].x - BSIZE, v[i].y - BSIZE, v[i].x + BSIZE, v[i].y + BSIZE);
		

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
