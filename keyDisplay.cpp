#include<iostream>
#include <windows.h>
#include <tchar.h>
#include <process.h>
#include <fstream>
using namespace std;

UINT __stdcall msgDetect(void* p) {
	bool flag = true;
	HWND hwnd;
	HDC hdc;
	int index{};
	TCHAR buff[256];
	
	while (true)
	{
		if (GetAsyncKeyState(VK_HOME) & 0x8000) return 0;
		
		for (int i = 0x41; i < 0x5A; i++)
			if (GetAsyncKeyState(i) & 0x8000) {
				
				while (GetAsyncKeyState(i) & 0x8000) { }
				hwnd = GetDesktopWindow();
				hdc = GetWindowDC(hwnd);
				if (index > 250) index = 0;
				buff[index++] = (char)i;
				TextOut(hdc, 100, 100, buff, _tcslen(buff));
				
				ReleaseDC(hwnd, hdc);
			}

	}
}

LRESULT __stdcall WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HANDLE hThread;
	static HANDLE hFile;
	switch (msg)
	{
		case WM_CREATE:
			hThread = (HANDLE)_beginthreadex(0, 0, &msgDetect, 0, 0 ,0);
			WaitForSingleObject(hThread, INFINITE);
			
			CloseHandle(hThread);
			PostQuitMessage(0);
			break;
	}
	
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wnd{0};
	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.lpszClassName = _T("ClsName");	
	wnd.lpfnWndProc = WndProc;
	
	RegisterClassEx(&wnd);
	
	HWND hwnd = CreateWindowEx(
	0,
	_T("ClsName"),
	_T("ClsName"),
	WS_OVERLAPPEDWINDOW,
	0,
	0,
	500,
	500,
	0,
	0,
	0,
	0
	);
	
	MSG msg;
	
	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessage(&msg);
	}
	
	return (int)msg.wParam;
}



