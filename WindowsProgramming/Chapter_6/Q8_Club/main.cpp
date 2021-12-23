#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <commctrl.h>
#include "resource.h"

const int BSIZE = 50;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Q6_8PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int select;
	TCHAR buf[256];
	TCHAR name[100];
	TCHAR phone[100];
	int birth;
	HWND hEdit;
	HWND hCombo;
	HWND hList;
	int pos;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		select = 0;
		memset(buf, 0, sizeof(TCHAR) * 256);
		CheckRadioButton(hDlg, IDC_RADIO_MAN, IDC_RADIO_GIRL, IDC_RADIO_MAN);
		hCombo = GetDlgItem(hDlg, IDC_COMBO_BIRTH);
		for (int i = 1990; i < 2022; i++) {
			_stprintf(buf, _T("%d"), i);
			SendMessage(hCombo, CB_ADDSTRING, NULL, (LPARAM)buf);
		}
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_NEW:
			SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));
			select = 0;
			CheckRadioButton(hDlg, IDC_RADIO_MAN, IDC_RADIO_GIRL, IDC_RADIO_MAN);
			break;

		case IDC_BUTTON_JOIN:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 100);
			GetDlgItemText(hDlg, IDC_EDIT_PHONE, phone, 100);

			SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));

			hCombo = GetDlgItem(hDlg, IDC_COMBO_BIRTH);

			birth = SendMessage(hCombo, CB_GETCURSEL, 0, 0);

			_stprintf(buf, _T("이름: %s, 전화번호: %s, 성별: %s, 출생연도: %d"), name, phone, select ? _T("여자") : _T("남자"),
				birth + 1990);
			
			hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
			SendMessage(hList, LB_ADDSTRING, NULL, (LPARAM)buf);
			
			break;

		case IDC_BUTTON_OUT:
			hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
			pos = SendMessage(hList, LB_GETCURSEL, 0, 0);
			SendMessage(hList, LB_DELETESTRING, pos, 0);
			break;

		case IDCANCEL:
			DestroyWindow(hDlg);
			return 0;

		case IDC_RADIO_MAN:
			select = 0;
			break;

		case IDC_RADIO_GIRL:
			select = 1;
			break;

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
	HWND hDlg;


	switch (iMsg)
	{
	case WM_CREATE:
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_Q8_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q8), hwnd, Q6_8PROC);
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
