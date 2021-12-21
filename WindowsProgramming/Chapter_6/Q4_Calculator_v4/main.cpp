  #define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <commctrl.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

enum {
	plus,
	minus,
	mul,
	divi
};

const int BSIZE = 20;

BOOL CALLBACK Q6_4PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int total;
	static long double firstTotal;
	static long double secondTotal;
	static long double firstDemicalTotal;
	static long double secondDemicalTotal;
	static std::wstring nums[2];
	static std::wstring demi[2];
	static BOOL firstNsecond;
	static BOOL oper[4];
	static BOOL dot;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		total = 0;
		firstNsecond = TRUE;
		dot = FALSE;
		for (int i = 0; i < 4; i++) oper[i] = FALSE;
		for (int i = 0; i < 2; i++) nums[i] = _T("");

		firstTotal = 0;
		secondTotal = 0;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_NUM1:
			if (firstNsecond && !dot) nums[0] += _T("1");
			else if (firstNsecond && dot) demi[0] += _T("1");
			else if (!firstNsecond && !dot) nums[1] += _T("1");
			else if (!firstNsecond && dot) demi[1] += _T("1");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}

			break;

		case IDC_BUTTON_NUM2:
			if (firstNsecond && !dot) nums[0] += _T("2");
			else if (firstNsecond && dot) demi[0] += _T("2");
			else if (!firstNsecond && !dot) nums[1] += _T("2");
			else if (!firstNsecond && dot) demi[1] += _T("2");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
			break;

		case IDC_BUTTON_NUM3:
			if (firstNsecond && !dot) nums[0] += _T("3");
			else if (firstNsecond && dot) demi[0] += _T("3");
			else if (!firstNsecond && !dot) nums[1] += _T("3");
			else if (!firstNsecond && dot) demi[1] += _T("3");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
			break;

		case IDC_BUTTON_NUM4:
			if (firstNsecond && !dot) nums[0] += _T("4");
			else if (firstNsecond && dot) demi[0] += _T("4");
			else if (!firstNsecond && !dot) nums[1] += _T("4");
			else if (!firstNsecond && dot) demi[1] += _T("4");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
			
			break;

		case IDC_BUTTON_NUM5:
			if (firstNsecond && !dot) nums[0] += _T("5");
			else if (firstNsecond && dot) demi[0] += _T("5");
			else if (!firstNsecond && !dot) nums[1] += _T("5");
			else if (!firstNsecond && dot) demi[1] += _T("5");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
			
			break;

		case IDC_BUTTON_NUM6:
			if (firstNsecond && !dot) nums[0] += _T("6");
			else if (firstNsecond && dot) demi[0] += _T("6");
			else if (!firstNsecond && !dot) nums[1] += _T("6");
			else if (!firstNsecond && dot) demi[1] += _T("6");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
			
			break;

		case IDC_BUTTON_NUM7:
			if (firstNsecond && !dot) nums[0] += _T("7");
			else if (firstNsecond && dot) demi[0] += _T("7");
			else if (!firstNsecond && !dot) nums[1] += _T("7");
			else if (!firstNsecond && dot) demi[1] += _T("7");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
		
			break;

		case IDC_BUTTON_NUM8:
			if (firstNsecond && !dot) nums[0] += _T("8");
			else if (firstNsecond && dot) demi[0] += _T("8");
			else if (!firstNsecond && !dot) nums[1] += _T("8");
			else if (!firstNsecond && dot) demi[1] += _T("8");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
		
			break;

		case IDC_BUTTON_NUM9:
			if (firstNsecond && !dot) nums[0] += _T("9");
			else if (firstNsecond && dot) demi[0] += _T("9");
			else if (!firstNsecond && !dot) nums[1] += _T("9");
			else if (!firstNsecond && dot) demi[1] += _T("9");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
	
			break;

		case IDC_BUTTON_NUM0:
			if (firstNsecond && !dot) nums[0] += _T("0");
			else if (firstNsecond && dot) demi[0] += _T("0");
			else if (!firstNsecond && !dot) nums[1] += _T("0");
			else if (!firstNsecond && dot) demi[1] += _T("0");

			if (firstNsecond) {
				if (dot) firstDemicalTotal = _ttoi(demi[0].c_str());
				firstTotal = _ttoi(nums[0].c_str()) + firstDemicalTotal / pow(10, demi[0].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal, TRUE);
			}

			else {
				if (dot) secondDemicalTotal = _ttoi(demi[1].c_str());
				secondTotal = _ttoi(nums[1].c_str()) + secondDemicalTotal / pow(10, demi[1].size() + 1);
				SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, secondTotal, TRUE);
			}
	
			break;
			
		case IDC_BUTTON_PLUS:
			for (int i = 0; i < 4; i++) oper[i] = FALSE;
			oper[plus] = TRUE;
			if (firstNsecond) firstNsecond = FALSE;

			break;

		case IDC_BUTTON_MIN:
			for (int i = 0; i < 4; i++) oper[i] = FALSE;
			oper[minus] = TRUE;
			if (firstNsecond) firstNsecond = FALSE;

			break;

		case IDC_BUTTON_MUL:
			for (int i = 0; i < 4; i++) oper[i] = FALSE;
			oper[mul] = TRUE;
			if (firstNsecond) firstNsecond = FALSE;

			break;

		case IDC_BUTTON_DIV:
			for (int i = 0; i < 4; i++) oper[i] = FALSE;
			oper[divi] = TRUE;
			if (firstNsecond) firstNsecond = FALSE;

			break;

		case IDC_BUTTON_DOT:
			dot = TRUE;
			break;

		case IDC_BUTTON_RESULT:
			if (firstTotal != 0 && secondTotal != 0) {
				if (oper[plus])
					SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal + secondTotal, TRUE);
				if (oper[minus])
					SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal - secondTotal, TRUE);
				if (oper[mul])
					SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal * secondTotal, TRUE);
				if (oper[divi])
					SetDlgItemInt(hDlg, IDC_EDIT_OUTPUT, firstTotal / secondTotal, TRUE);

				for (int i = 0; i < 2; i++) nums[i].clear();
				firstTotal = secondTotal = 0;
				firstNsecond = TRUE;
			}
			break;

		case IDCANCEL:
			DestroyWindow(hDlg);
			return 0;
		}
		break;

		
	}
	return 0;
}

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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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
	static HINSTANCE hInst;
	static HWND hDlg;

	switch (iMsg)
	{
	case WM_CREATE:
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_Q4_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q4), hwnd, Q6_4PROC);
			ShowWindow(hDlg, SW_SHOW);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
