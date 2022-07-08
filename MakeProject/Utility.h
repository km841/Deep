#pragma once
#include "Button.h"
#include "ButtonManager.h"

class ButtonManager;


class Utility
{
	Utility(const Utility& other) = delete;
	void operator=(const Utility& other) = delete;
	Utility() {}

public:
	static Utility& getInstance();
	void Init(HINSTANCE hInstance, HWND hwnd, const ButtonManager& manager);
	void ConfigInit(HWND hDlg, const ButtonManager& manager);
		
	bool Load(ButtonManager& bm);
};

