#include "pch.h"
#include "Colume.h"
#include "Row.h"
#include "Sheet.h"
#include "ExcelManager.h"
#include "AddressModule.h"

/* GLOBAL MEMBER INITIALIZATION */
HHOOK g_hHook;
HINSTANCE g_hInst;
BOM::HwndControl g_hWndControl;

/* CLASS STATIC MEMBER INITIALIZATION */
int BOM::Colume::temp_id = 0x2001;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdLine)
{
	g_hInst = hInstance;
	const TCHAR* clsName = _T("BOM APPLICATION");

	
	WNDCLASSEX wc{ 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = clsName;
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));

	ATOM atom = RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(
		0, clsName, clsName, WS_OVERLAPPEDWINDOW &~ (WS_THICKFRAME | WS_MAXIMIZEBOX), 0, 0, 1450, 500, 0, 0, 0, 0
	);

	ShowWindow(hwnd, SW_SHOW);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessage(&msg);
		TranslateMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
	{
		PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;

		if (nCode >= 0 && (int)wParam == 256) {

			if (pKey->vkCode == VK_UP)
			{
				HWND currHwnd = GetFocus();
				for (int i = 0; i < g_hWndControl.size(); i++)
				{

					auto it = std::find(
						std::begin(g_hWndControl[i]),
						std::end(g_hWndControl[i]),
						currHwnd);

					if (it != std::end(g_hWndControl[i]))
					{

						if (i == 0)
							break;

						else if (i == 1)
							SetFocus(g_hWndControl[0][0]);

						else
							SetFocus(g_hWndControl[i - 1][it - std::begin(g_hWndControl[i])]);

						return TRUE;
						
					}

				}
			}

			else if ((pKey->vkCode == VK_RETURN) || (pKey->vkCode == VK_DOWN)) 
			{

				HWND currHwnd = GetFocus();
				for (int i = 0; i < g_hWndControl.size(); i++) 
				{
					
					auto it = std::find(
						std::begin(g_hWndControl[i]),
						std::end(g_hWndControl[i]),
						currHwnd);
					
					if (it != std::end(g_hWndControl[i])) 
					{
						if ((i + 1) != g_hWndControl.size())
						{
							if (i == 0)
								SetFocus(g_hWndControl[1][1]);
								

							else
								SetFocus(g_hWndControl[i + 1][it - std::begin(g_hWndControl[i])]);

							return TRUE;
						}
					}
					
				}
				
			}

			else if (pKey->vkCode == VK_TAB)
			{
				HWND currHwnd = GetFocus();
				for (int i = 0; i < g_hWndControl.size(); i++)
				{

					auto it = std::find(
						std::begin(g_hWndControl[i]),
						std::end(g_hWndControl[i]),
						currHwnd);

					if (it != std::end(g_hWndControl[i]))
					{
						if ((it + 1) != std::end(g_hWndControl[i]))
						{
							if (i == 0)
								break;


							else
								SetFocus(g_hWndControl[i][it - std::begin(g_hWndControl[i]) + 1]);


							return TRUE;
						}
					}

				}
			}
		}
	}

	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	std::locale::global(std::locale("korean"));

	/* GUI CONTROL OBJECT */
	static std::shared_ptr<BOM::Sheet> sheet = std::make_shared<BOM::Sheet>(g_hInst, hwnd);
	static std::shared_ptr<ExcelManager> manager = std::make_shared<ExcelManager>(sheet);
	static std::shared_ptr<AddressModule> addr = std::make_shared<AddressModule>(g_hInst, hwnd, 30, WidthStruct{ 100, 500, 100 });
	
	/* STATIC VARIABLE */
	static HFONT hFont, hEmailFont;
	static HDC hdc;
	static PAINTSTRUCT ps;
	static RECT rect;
	static HWND hStatic;

	switch (msg)
	{
	case WM_CREATE:
	{
		g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, g_hInst, 0);
		/* MAKE SHEET */
		{
			sheet.get()->AddRow(100, { 1450 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 }, true); // READONLY DATA
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->AddRow(30,  { 50, 400, 400, 100, 50, 50, 200, 200 });
			sheet.get()->DrawSheet();
		}

		manager.get()->SetProperty();

		/* TITLE FONT SETTING */
		hFont = CreateFont(60, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));
		hEmailFont = CreateFont(20, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));
		SendMessage(sheet.get()->GetHwnd(1, 1), WM_SETFONT, (WPARAM)hFont, 0);


		/* MEMBER INITIALIZATION */
		{
			sheet.get()->SetData(1, 1, _T("타이틀을 입력하세요."));

			sheet.get()->SetData(2, 1, _T("NO."));
			sheet.get()->SetData(3, 1, _T("1"));
			sheet.get()->SetData(4, 1, _T("2"));
			sheet.get()->SetData(5, 1, _T("3"));
			sheet.get()->SetData(6, 1, _T("4"));
			sheet.get()->SetData(7, 1, _T("5"));
			sheet.get()->SetData(8, 1, _T("6"));
		
			sheet.get()->SetData(2, 2, _T("품목"));
			sheet.get()->SetData(2, 3, _T("규격"));
			sheet.get()->SetData(2, 4, _T("재질"));
			sheet.get()->SetData(2, 5, _T("수량"));
			sheet.get()->SetData(2, 6, _T("단위"));
			sheet.get()->SetData(2, 7, _T("요청 납기"));
			sheet.get()->SetData(2, 8, _T("비고"));

			sheet.get()->SetData(3, 6, _T("EA"));
			sheet.get()->SetData(4, 6, _T("EA"));
			sheet.get()->SetData(5, 6, _T("EA"));
			sheet.get()->SetData(6, 6, _T("EA"));
			sheet.get()->SetData(7, 6, _T("EA"));
			sheet.get()->SetData(8, 6, _T("EA"));
		}

		/* INPUT ADDRESS MODULE */
		GetClientRect(hwnd, &rect);
		addr.get()->DrawModule(10, rect.bottom - 40);

		g_hWndControl = sheet.get()->GetHwndTotalList();

		hStatic = CreateWindowEx(
			0, _T("static"), _T("문의 : "), WS_CHILD | WS_VISIBLE | ES_LEFT,
			rect.right - 260, rect.bottom - 30, 300, 30, hwnd, 0, g_hInst, 0);

		SendMessage(hStatic, WM_SETFONT, (WPARAM)hEmailFont, 0);

		break;
	}

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;


	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_ADDR:
			if (GetSaveFileName(addr.get()->GetOfn())) {
				addr.get()->SetEditFilePath();

				if (MessageBox(
					hwnd, 
					(boost::wformat(_T("%s\n 저장하시겠습니까?")) % addr.get()->GetSelectFullPath()).str().c_str(), _T("확인 메시지"),
					MB_OKCANCEL) == IDOK) 

				{
					manager.get()->Mapping();
					manager.get()->Save(addr.get()->GetSelectFullPath());
				}
			}
			break;

		}
		break;

	case WM_DESTROY:
		UnhookWindowsHookEx(g_hHook);
		PostQuitMessage(0);
		break;
	
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);

}
