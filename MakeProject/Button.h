#pragma once
#include "Button.h"

class Button
{
	int id = 0;
	HWND hwnd = 0;
	std::wstring addr;
	std::wstring name;
	POINT pos = {0, 0};
	SIZE size = { 100, 50 };
	COLORREF color = RGB(255, 255, 255);
	

public:
	Button(std::wstring addr, std::wstring name, POINT pos);

	bool SetAddr(const std::wstring& newAddr);
	bool SetName(const std::wstring& newName);

	bool SetColor(COLORREF newColor);
	bool SetPos(POINT newPos);

	bool SetHWND(HWND newHwnd);
	bool SetID(int id);

	std::wstring GetAddr();
	std::wstring GetName();
	POINT GetPos();
	COLORREF GetColor();
	HWND GetHWND();
	SIZE GetSize();
	int GetID();

	~Button() {}
	

};

