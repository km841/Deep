#include "pch.h"
#include "AddressModule.h"


AddressModule::AddressModule(HINSTANCE hInstance, HWND hwnd, int height, WidthStruct ws) 
	: hInstance(hInstance), parentHwnd(hwnd), height(height), ws(ws)
{
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = this->parentHwnd;
	ofn.hInstance = this->hInstance;
	ofn.lpstrFilter = _T("Excel file(*.xlsx)\0*.xlsx\0");
	ofn.lpstrFile = lpstrFile;
	ofn.lpstrDefExt = _T("xlsx");
	ofn.nMaxFile = FILENAME_MAX_SIZE;
	ofn.lpstrFileTitle = lpstrFileTitle;
	ofn.nMaxFileTitle = FILENAME_MAX_SIZE;
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;
}

void AddressModule::DrawModule(int xPos, int yPos)
{
	int width_total = 0;

	hStatic = CreateWindowEx(
		0, _T("static"), _T("저장할 주소"), WS_CHILD | WS_VISIBLE | SS_CENTER,
		xPos + width_total, yPos, (this->ws).static_size, this->height, this->parentHwnd, (HMENU)IDC_STATIC_ADDR, this->hInstance, 0
	);

	width_total += ws.static_size;
	width_total += OFFSET;
	

	hEdit = CreateWindowEx(
		0, _T("edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY | ES_AUTOHSCROLL,
		xPos + width_total, yPos, (this->ws).edit_size, this->height, this->parentHwnd, (HMENU)IDC_EDIT_ADDR, this->hInstance, 0
	);

	width_total += ws.edit_size;
	width_total += OFFSET;

	hButton = CreateWindowEx(
		0, _T("button"), _T("찾아보기"), WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
		xPos + width_total, yPos, (this->ws).button_size, this->height, this->parentHwnd, (HMENU)IDC_BUTTON_ADDR, this->hInstance, 0
	);

	SendMessage(hStatic, WM_SETFONT, (WPARAM)(this->hFont), 0);
	SendMessage(hEdit, WM_SETFONT, (WPARAM)(this->hFont), 0);
	SendMessage(hButton, WM_SETFONT, (WPARAM)(this->hFont), 0);
}


