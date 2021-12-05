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
	static TCHAR words[10][100];
	static int col, row;
	static int lineRow[10];

	static SIZE wordSize;

	OPENFILENAME OFN;

	static FILE* fPtr;
	
	
	switch (iMsg) {
	case WM_CREATE:
		CreateCaret(hwnd, NULL, 5, 15);
		ShowCaret(hwnd);
		col = 0;
		row = 0;
		memset(lineRow, 0, sizeof(int) * 10);
		answer = 0;
		fPtr = nullptr;
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < row+1; i++) {
			GetTextExtentPoint(hdc, words[i], _tcslen(words[i]), &wordSize);
			TextOut(hdc, 0, i * 20, words[i], _tcslen(words[i]));
			SetCaretPos(wordSize.cx, row * 20);
		}

		EndPaint(hwnd, &ps);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN && row < 10) {
			lineRow[row++] = col;
			col = 0;
		}

		else if (wParam == VK_BACK && col > 0) {
			col--;
			words[row][col] = NULL;
		}

		else if (wParam == VK_BACK && row > 0 && col == 0) {
			row--;
			col = lineRow[row];
		}

		else {
			if (col == 99 && row < 9) {
				lineRow[row] = col;
				row++;
				col = 0;
			}
			else if (row < 10 && col < 100) {
				words[row][col++] = wParam;
				words[row][col] = NULL;
			}
		}
		InvalidateRgn(hwnd, NULL, TRUE);
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
			OFN.lpstrFilter = _T("C++ 소스와 헤더 파일\0*.cpp;*.h\0모든 파일(*.*)\0*.*\0");
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
			OFN.lpstrFilter = _T("C++ 소스와 헤더 파일\0*.cpp;*.h\0모든 파일(*.*)\0*.*\0");
			OFN.lpstrFile = lpstrFile;
			OFN.nMaxFile = 100;
			OFN.lpstrInitialDir = _T(".");

			if (GetSaveFileName(&OFN) != 0) {
				_stprintf_s(buf, _T("%s 파일을 저장하시겠습니까?"), OFN.lpstrFile);
				answer = MessageBox(hwnd, buf, _T("파일 저장"), MB_YESNOCANCEL);

				if (answer == IDYES) {
#ifdef _UNICODE
					_tfopen_s(&fPtr, OFN.lpstrFile, _T("w"));
#else 
					_tfopen_s(&fPtr, OFN.lpstrFile, _T("w"));
#endif
					for (int i = 0; i < row + 1; i++) {
						_fputts(words[i], fPtr);
						_fputts(_T("\n"), fPtr);
					}
				}

				fclose(fPtr);
			}

			break;

		case ID_EXIT:
			HideCaret(hwnd);
			DestroyCaret();
			PostQuitMessage(0);
			break;
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
