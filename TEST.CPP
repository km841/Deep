#include <windows.h>
#include <iostream>
#include <tchar.h>

HINSTANCE g_hInst;

LRESULT __stdcall WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEdit;
	switch (msg)
	{

	case WM_CREATE:
		hEdit = CreateWindowEx(
			0, _T("edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 20, 100, 50, hwnd, (HMENU)0x1001, g_hInst, 0);
		break;

	case WM_KEYDOWN:
		//MessageBoxA(0, "", "", MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}


	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
	g_hInst = hInst;
	WNDCLASSEX wnd{ 0 };
	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.lpszClassName = _T("EditClass");
	wnd.lpfnWndProc = WndProc;
	wnd.hCursor = LoadCursor(hInst, IDC_ARROW);
	wnd.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));

	ATOM atom = RegisterClassEx(&wnd);
	
	HWND hwnd = CreateWindowEx(
		0, _T("EditClass"), _T("EditClass"), WS_OVERLAPPEDWINDOW,
		0, 0, 500, 500, 0, 0, 0, 0
	);

	ShowWindow(hwnd, SW_SHOW);

	MSG msg;

	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

