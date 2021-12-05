#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <locale>
#include "resource.h"

const int BSIZE = 40;

double LengthPts(int x1, int y1, int x2, int y2) {
	return (sqrt((float)(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

BOOL InCircle(int x, int y, int mx, int my) {
	if (LengthPts(x, y, mx, my) < BSIZE) return TRUE;
	else return FALSE;
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
	int answer;

	TCHAR lpstrFile[100] = _T(""), buf[100] = _T("");
	TCHAR selectFile[100];

	OPENFILENAME OFN;
	
	
	switch (iMsg) {
	case WM_CREATE:
		answer = 0;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_FILENEW:
			answer = MessageBox(hwnd, _T("편집을 취소 하겠습니까?"), _T("편집 취소"), MB_YESNO);
			if (answer == IDYES) {
				PostQuitMessage(0);
				break;
			}
			break;
		case ID_FILEOPEN:
			memset(&OFN, 0, sizeof(OPENFILENAME));
			OFN.lStructSize = sizeof(OPENFILENAME);
			OFN.hwndOwner = hwnd;
			OFN.lpstrFilter = _T("모든 파일(*.*)\0*.*\0");
			OFN.lpstrFile = lpstrFile;
			OFN.nMaxFile = 100;
			OFN.lpstrInitialDir = _T(".");

			if (GetOpenFileName(&OFN) != 0) {
				_stprintf_s(buf, _T("%s 파일을 여시겠습니까?"), OFN.lpstrFile);
				MessageBox(hwnd, buf, _T("파일 열기"), MB_YESNOCANCEL);
			}
			break;


		case ID_FILESAVE:
			memset(&OFN, 0, sizeof(OPENFILENAME));
			OFN.lStructSize = sizeof(OPENFILENAME);
			OFN.hwndOwner = hwnd;
			OFN.lpstrFilter = _T("모든 파일(*.*)\0*.*\0");
			OFN.lpstrFile = lpstrFile;
			OFN.nMaxFile = 100;
			OFN.lpstrInitialDir = _T(".");

			if (GetSaveFileName(&OFN) != 0) {
				_stprintf_s(buf, _T("%s 파일을 저장하시겠습니까?"), OFN.lpstrFile);
				answer = MessageBox(hwnd, buf, _T("파일 저장"), MB_YESNOCANCEL);
				if (answer == IDYES || answer == IDNO) {
					PostQuitMessage(0);
					break;
				}
			}

			break;

		case ID_EXIT:
			PostQuitMessage(0);
			break;
		}
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
