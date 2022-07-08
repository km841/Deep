#include "pch.h"
#include "ButtonManager.h"


void ButtonManager::RegisterButton(std::wstring name, std::wstring addr)
{
	static POINT pos;
	if (pos.y == 0) pos.y = 40;
	if (pos.x >= 250 && pos.y >= 500) {
		return;

	}
	buttons.emplace_back(std::make_shared<Button>(name, addr, pos));

	
	if (buttons.size() % 2) pos.x += 110;
	else {
		pos.x = 0;
		pos.y += 60;
	}
}

std::vector<std::shared_ptr<Button>> ButtonManager::GetButtonList()
{
	return buttons;
}

std::vector<std::shared_ptr<Button>> ButtonManager::GetButtonList() const
{
	return buttons;
}
