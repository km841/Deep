#pragma once
#include "Button.h"

class Button;
class ButtonManager
{
	std::vector<std::shared_ptr<Button>> buttons;

	
public:
	ButtonManager() {}
	
	void RegisterButton(std::wstring addr, std::wstring name);

	std::vector<std::shared_ptr<Button>> GetButtonList();
	std::vector<std::shared_ptr<Button>> GetButtonList() const;

	inline void ButtonListClear() { buttons.clear(); }
	inline int ButtonSize() { return buttons.size(); }
	


	
};

