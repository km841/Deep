#include "pch.h"
#include "Utility.h"

namespace Ut
{
	int idList[8]{
	0x2001, 0x2002,
	0x2003, 0x2004,
	0x2005, 0x2006,
	0x2007, 0x2008
	};
	enum
	{
		IDC_BUTTON_1 = 0x2001,
		IDC_BUTTON_2 = 0x2002,
		IDC_BUTTON_3 = 0x2003,
		IDC_BUTTON_4 = 0x2004,
		IDC_BUTTON_5 = 0x2005,
		IDC_BUTTON_6 = 0x2006,
		IDC_BUTTON_7 = 0x2007,
		IDC_BUTTON_8 = 0x2008,
	};

};

Utility& Utility::getInstance()
{
	static Utility instance;
	return instance;
}

void Utility::Init(HINSTANCE hInstance, HWND hwnd, const ButtonManager& manager)
{
	static POINT pos;
	static int idCount = 0;
	static HFONT hFont = CreateFont(15, 0, 0, 0, FW_SEMIBOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));
	
	auto buttonList = manager.GetButtonList();
	const size_t buttonListSize = manager.GetButtonList().size();

	if (idCount != 0) idCount = 0;
	

	if (pos.x != 0 || pos.y != 0) {
		pos.x = 0;
		pos.y = 0;
	}

	for (int i = 0; i < buttonListSize; i++)
	{
		buttonList[i].get()->SetID(Ut::idList[idCount++]);
		buttonList[i].get()->SetHWND(
			CreateWindowEx(
				0,
				L"button",
				buttonList[i].get()->GetName().c_str(),
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_MULTILINE,
				pos.x,
				pos.y,
				buttonList[i].get()->GetSize().cx,
				buttonList[i].get()->GetSize().cy,
				hwnd,
				(HMENU)(Ut::idList[idCount-1]),
				hInstance, 
				0
			));

		if ((i + 1) % 2) pos.x += 110;
		else {
			pos.x = 0;
			pos.y += 60;
		}

		SendMessage(buttonList[i].get()->GetHWND(), WM_SETFONT, (WPARAM)hFont, 0);
	}
	int iScreenCx = GetSystemMetrics(SM_CXSCREEN);
	int iScreenCy = GetSystemMetrics(SM_CYSCREEN);

	switch (buttonListSize)
	{
	case 1:
	case 2:
		SetWindowPos(hwnd, HWND_TOP, iScreenCx - 240, iScreenCy - 100, 240, 100, SWP_SHOWWINDOW);
		break;
	case 3:
	case 4:
		SetWindowPos(hwnd, HWND_TOP, iScreenCx - 240, iScreenCy - 160, 240, 160, SWP_SHOWWINDOW);
		break;
	case 5:
	case 6:
		SetWindowPos(hwnd, HWND_TOP, iScreenCx - 240, iScreenCy - 220, 240, 220, SWP_SHOWWINDOW);
		break;
	case 7:
	case 8:
		SetWindowPos(hwnd, HWND_TOP, iScreenCx - 240, iScreenCy - 280, 240, 280, SWP_SHOWWINDOW);
		break;
	}

}

void Utility::ConfigInit(HWND hDlg, const ButtonManager& manager)
{

	auto buttonList = manager.GetButtonList();
	if (buttonList.empty()) return;

	const int buttonSize = buttonList.size();

	SetDlgItemText(hDlg, IDC_EDIT_NAME1, buttonList[0].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT1, buttonList[0].get()->GetAddr().c_str());

	if (buttonSize <= 1) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME2, buttonList[1].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT2, buttonList[1].get()->GetAddr().c_str());

	if (buttonSize <= 2) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME3, buttonList[2].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT3, buttonList[2].get()->GetAddr().c_str());

	if (buttonSize <= 3) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME4, buttonList[3].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT4, buttonList[3].get()->GetAddr().c_str());

	if (buttonSize <= 4) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME5, buttonList[4].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT5, buttonList[4].get()->GetAddr().c_str());

	if (buttonSize <= 5) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME6, buttonList[5].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT6, buttonList[5].get()->GetAddr().c_str());
	
	if (buttonSize <= 6) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME7, buttonList[6].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT7, buttonList[6].get()->GetAddr().c_str());

	if (buttonSize <= 7) return;
	SetDlgItemText(hDlg, IDC_EDIT_NAME8, buttonList[7].get()->GetName().c_str());
	SetDlgItemText(hDlg, IDC_EDIT8, buttonList[7].get()->GetAddr().c_str());


}

bool Utility::Load(ButtonManager& bm)
{
	char* p = getenv("UserProfile");
	fs::path result = p;
	fs::path currUserProfile = result;
	fs::path currConfigParentPath = currUserProfile / L"AppData\\Local\\MakeProject";
	fs::path currConfigFileName = L"config.dat";

	if (!fs::exists(currConfigParentPath / currConfigFileName))
		return false;

	std::wifstream wifs(currConfigParentPath / currConfigFileName, std::ios::in);
	
	std::wstring line, word;
	
	for (auto button : bm.GetButtonList())
	{
		DestroyWindow(button.get()->GetHWND());
	}

	bm.ButtonListClear();
	while (std::getline(wifs, line))
	{
		std::wistringstream iss(line);

		static std::vector<std::wstring> wordVector;

		while (std::getline(iss, word, L'|'))
		{
			wordVector.emplace_back(word);
		}
		
		if (wordVector.size() == 2) {
			bm.RegisterButton(wordVector[0], wordVector[1]);
		}

		wordVector.clear();
	}

	return true;
}
