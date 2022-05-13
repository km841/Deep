#pragma once
const int FILENAME_MAX_SIZE = 1024;
const int OFFSET = 10;

enum {
	IDC_STATIC_ADDR = 0x9001,
	IDC_EDIT_ADDR,
	IDC_BUTTON_ADDR
};

struct WidthStruct {
	int static_size;
	int edit_size;
	int button_size;

	WidthStruct(int static_size, int edit_size, int button_size)
		: static_size(static_size), edit_size(edit_size), button_size(button_size)
	{}
};

class AddressModule
{


	HWND parentHwnd;
	HINSTANCE hInstance;

	HWND hStatic, hButton, hEdit;
	OPENFILENAME ofn { 0 };
	TCHAR lpstrFile[FILENAME_MAX_SIZE] { 0 };
	TCHAR lpstrFileTitle[FILENAME_MAX_SIZE] { 0 };

	WidthStruct ws;
	HFONT hFont = CreateFont(20, 0, 0, 0, FW_SEMIBOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));

	int height;

public:
	explicit AddressModule(HINSTANCE hInstance, HWND hwnd, int height, WidthStruct ws);

	inline OPENFILENAME* GetOfn() { return &ofn; };
	inline std::wstring GetSelectFullPath() { return std::wstring(lpstrFile); }
	inline void SetEditFilePath() { SetDlgItemText(parentHwnd, IDC_EDIT_ADDR, lpstrFile); }
	
	void DrawModule(int xPos, int yPos);
	~AddressModule() {}


};

