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
const int UNSELECTED = -1;

int SelectItem(HWND hDlg, LPARAM lParam)
{
	LPNMLISTVIEW nlv;
	HWND hList;
	TCHAR name[20], phone[20];
	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	nlv = (LPNMLISTVIEW)lParam;
	
	ListView_GetItemText(hList, nlv->iItem, 0, name, 20);
	SetDlgItemText(hDlg, IDC_EDIT_NAME, name);
	
	ListView_GetItemText(hList, nlv->iItem, 1, phone, 20);
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, phone);
	return (nlv->iItem);
}

void InsertData(HWND hDlg, int gender, int year)
{
	LVITEM item;
	HWND hList;
	int count;
	TCHAR name[20], phone[20], birthDay[20];
	int birth;

	GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 20);
	GetDlgItemText(hDlg, IDC_EDIT_PHONE, phone, 20);
	
	SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));
	
	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	count = ListView_GetItemCount(hList);
	item.mask = LVIF_TEXT;
	item.iItem = count;
	item.iSubItem = 0;
	item.pszText = name;

	_stprintf(birthDay, _T("%d"), year);

	ListView_InsertItem(hList, &item);
	ListView_SetItemText(hList, count, 1, phone);
	ListView_SetItemText(hList, count, 2, gender ? _T("여자") : _T("남자"));
	ListView_SetItemText(hList, count, 3, birthDay);
}
void MakeColumn(HWND hDlg)
{
	LPTSTR name[4] = { _T("이름"), _T("전화번호"), _T("성별"), _T("출생연도")};
	LVCOLUMN lvCol = { 0, };
	HWND hList;

	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvCol.fmt = LVCFMT_LEFT;

	for (int i = 0; i < 4; i++) {
		lvCol.cx = 90;
		lvCol.iSubItem = i;
		lvCol.pszText = name[i];
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}

void DeleteData(HWND hDlg, int selection)
{
	HWND hList;
	hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
	ListView_DeleteItem(hList, selection);
	SetDlgItemText(hDlg, IDC_EDIT_NAME, _T(""));
	SetDlgItemText(hDlg, IDC_EDIT_PHONE, _T(""));
	return;
	
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Q6_9PROC(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int gender;
	HWND hCombo;
	HWND hLv;
	int idx;
	LPNMHDR hdr;
	HWND hList;

	static int selection;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		gender = 0;
		TCHAR buf[20];
		MakeColumn(hDlg);
		CheckRadioButton(hDlg, IDC_RADIO_MAN, IDC_RADIO_GIRL, IDC_RADIO_MAN);
		hCombo = GetDlgItem(hDlg, IDC_COMBO_BIRTH);
		selection = UNSELECTED;

		for (int i = 1990; i < 2022; i++) {
			_stprintf(buf, _T("%d"), i);
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)buf);
		}
		return 1;

	case WM_NOTIFY:
		hdr = (LPNMHDR)lParam;
		hList = GetDlgItem(hDlg, IDC_LIST_VIEW);
		if (hdr->hwndFrom == hList && hdr->code == LVN_ITEMCHANGING)
			selection = SelectItem(hDlg, lParam);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			DestroyWindow(hDlg);
			break;

		case IDC_BUTTON_JOIN:
			hCombo = GetDlgItem(hDlg, IDC_COMBO_BIRTH);
			InsertData(hDlg, gender, 1990+(SendMessage(hCombo, CB_GETCURSEL, 0, 0)));
			break;

		case IDC_BUTTON_OUT:
			if (selection == UNSELECTED) break;
			hLv = GetDlgItem(hDlg, IDC_LIST_VIEW);
			DeleteData(hDlg, selection);
			selection = UNSELECTED;
			return 0;

		case IDC_RADIO_MAN:
			gender = 0;
			break;

		case IDC_RADIO_GIRL:
			gender = 1;
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
		case ID_Q9_MENU:
			hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG6_Q9), hwnd, Q6_9PROC);
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
