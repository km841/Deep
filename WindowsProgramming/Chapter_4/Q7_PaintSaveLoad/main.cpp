#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <locale>
#include "resource.h"

enum {
	LINE = 1,
	ELLIPSE = 2,
	RECTANGLE = 3
};

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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU4_2);
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
	FILE* fPtr;

	OPENFILENAME ofn;
	static TCHAR lpstrFile[100], buf[100];

	int mx, my;
	static int startX, startY;
	static int beforeX, beforeY;

	static int tool;
	static BOOL clicked;
	static BOOL drag;

	static CHOOSECOLOR color;
	CHOOSEFONT font;

	static COLORREF fColor, sColor, tmp[16];
	static HBRUSH hBrush, oldBrush;
	static HPEN hPen, oldPen;

	static int spaintX[1024], spaintY[1024];
	static int epaintX[1024], epaintY[1024];
	static int shapeTypes[1024];
	static COLORREF colorNums[1024];
	static int paintCnt;


	switch (iMsg) {
	case WM_CREATE:
		tool = 0;
		startX = startY = 0;
		clicked = FALSE;
		drag = FALSE;
		fColor = 0xffffff;
		paintCnt = 0;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_LINE:
			tool = 1;
			break;

		case ID_ELLIPSE:
			tool = 2;
			break;

		case ID_RECTANGLE:
			tool = 3;
			break;

		case ID_PENCOLOR:
			for (int i = 0; i < 16; i++) {
				tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
			}
			memset(&color, 0, sizeof(CHOOSECOLOR));
			color.lStructSize = sizeof(CHOOSECOLOR);
			color.hwndOwner = hwnd;
			color.lpCustColors = tmp;
			color.Flags = CC_FULLOPEN;
			if (ChooseColor(&color) != 0) {
				fColor = color.rgbResult;
			}


			break;

		case ID_FACECOLOR:
			for (int i = 0; i < 16; i++) {
				tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
			}
			memset(&color, 0, sizeof(CHOOSECOLOR));
			color.lStructSize = sizeof(CHOOSECOLOR);
			color.hwndOwner = hwnd;
			color.lpCustColors = tmp;
			color.Flags = CC_FULLOPEN;
			if (ChooseColor(&color) != 0) {
				sColor = color.rgbResult;
			}
			break;

		case ID_FILESAVE:
			memset(&ofn, 0, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hwnd;
			ofn.lpstrFilter = _T("텍스트 파일(*.txt)\0*.txt\0");
			ofn.lpstrFile = lpstrFile;
			ofn.nMaxFile = 256;
			ofn.lpstrInitialDir = _T(".");
			if (GetSaveFileName(&ofn) != 0) {
#ifdef _UNICODE
				_tfopen_s(&fPtr, lpstrFile, _T("w, ccs=UNICODE"));
#else
				_tfopen_s(&fPtr, lpstrFile, _T("w"));

				
#endif
				for (int i = 0; i < paintCnt; i++) {
					if (i == 0) {
						_stprintf(buf, _T("%d"), paintCnt);
						_fputts(buf, fPtr);
					}

					_stprintf(buf, _T("\n%d %d %d %d %d %d"), spaintX[i], spaintY[i], epaintX[i], epaintY[i], colorNums[i], shapeTypes[i]);
					_fputts(buf, fPtr);
				}

				fclose(fPtr);
			}

			break;

		case ID_FILEOPEN:
			memset(&ofn, 0, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hwnd;
			ofn.lpstrFilter = _T("텍스트 파일(*.txt)\0*.txt\0");
			ofn.lpstrFile = lpstrFile;
			ofn.nMaxFile = 256;
			ofn.lpstrInitialDir = _T(".");
			if (GetOpenFileName(&ofn) != 0) {
#ifdef _UNICODE
				_tfopen_s(&fPtr, lpstrFile, _T("r, ccs=UNICODE"));
#else
				_tfopen_s(&fPtr, lpstrFile, _T("r"));
#endif
				_ftscanf(fPtr, _T("%d"), &paintCnt);

				for (int i = 0; i < paintCnt; i++) {
					_ftscanf(fPtr, _T("\n%d %d %d %d %d %d"), &spaintX[i], &spaintY[i], &epaintX[i], &epaintY[i], &colorNums[i], &shapeTypes[i]);
				}

				fclose(fPtr);
			}

			break;
		}
		InvalidateRgn(hwnd, NULL, TRUE);
		break;
		


	case WM_LBUTTONDOWN:
		drag = TRUE;
		startX = LOWORD(lParam);
		startY = HIWORD(lParam);

		spaintX[paintCnt] = LOWORD(lParam);
		spaintY[paintCnt] = HIWORD(lParam);

		

		//InvalidateRgn(hwnd, NULL, TRUE);
		break;

	case WM_LBUTTONUP:
		drag = FALSE;
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		

		startX = 0;
		startY = 0;
		beforeX = 0;
		beforeY = 0;
		
		epaintX[paintCnt] = mx;
		epaintY[paintCnt] = my;
		shapeTypes[paintCnt] = tool;
		if (tool == 1)
			colorNums[paintCnt++] = fColor;

		else if (tool == 2 || tool == 3) {
			colorNums[paintCnt++] = sColor;
		}

		else if (tool == 0)
			colorNums[paintCnt++] = RGB(0, 0, 0);
		

		InvalidateRgn(hwnd, NULL, TRUE);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		

		for (int i = 0; i < paintCnt; i++) {
			if (colorNums[i] == RGB(255, 255, 255)) {
				colorNums[i] = RGB(0, 0, 0);
			}
			if (shapeTypes[i] == 1) {
				hPen = CreatePen(PS_SOLID, 1, colorNums[i]);
				oldPen = (HPEN)SelectObject(hdc, hPen);
				MoveToEx(hdc, spaintX[i], spaintY[i], NULL);
				LineTo(hdc, epaintX[i], epaintY[i]);
				SelectObject(hdc, oldPen);
				DeleteObject(hPen);
			}

			else if (shapeTypes[i] == 2) {
				hBrush = CreateSolidBrush(colorNums[i]);
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				Ellipse(hdc, spaintX[i], spaintY[i], epaintX[i], epaintY[i]);
				SelectObject(hdc, oldBrush);
				DeleteObject(hBrush);
			}

			else if (shapeTypes[i] == 3) {
				hBrush = CreateSolidBrush(colorNums[i]);
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				Rectangle(hdc, spaintX[i], spaintY[i], epaintX[i], epaintY[i]);
				SelectObject(hdc, oldBrush);
				DeleteObject(hBrush);
			}
		}

		EndPaint(hwnd, &ps);
		break;

	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		SetROP2(hdc, R2_XORPEN);
		SelectObject(hdc, (HPEN)GetStockObject(WHITE_PEN));

		if (drag && tool == 1) {
			hPen = CreatePen(PS_SOLID, 1, fColor);
			oldPen = (HPEN)SelectObject(hdc, hPen);

			if (startX > 0 && startY > 0 && beforeX > 0 && beforeY > 0) {
				MoveToEx(hdc, startX, startY, NULL);
				LineTo(hdc, beforeX, beforeY);
			}
			
			MoveToEx(hdc, startX, startY, NULL);
			LineTo(hdc, mx, my);

			SelectObject(hdc, oldPen);
			DeleteObject(hPen);
		}

		else if (drag && tool == 2) {
			hBrush = CreateSolidBrush(sColor);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

			if (startX > 0 && startY > 0 && beforeX > 0 && beforeY > 0) {
				Ellipse(hdc, startX, startY, beforeX, beforeY);
			}

			Ellipse(hdc, startX, startY, mx, my);

			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
		}

		else if (drag && tool == 3) {
			hBrush = CreateSolidBrush(sColor);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

			if (startX > 0 && startY > 0 && beforeX > 0 && beforeY > 0) {
				Rectangle(hdc, startX, startY, beforeX, beforeY);
			}

			Rectangle(hdc, startX, startY, mx, my);

			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
		}

		beforeX = mx;
		beforeY = my;

		ReleaseDC(hwnd, hdc);
		break;




	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}
	

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
