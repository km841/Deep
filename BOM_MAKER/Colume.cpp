#include "pch.h"
#include "Colume.h"


namespace BOM {

	std::shared_ptr<Colume> Colume::ColumeBuilder::makeDefaultColume(HWND parentHwnd, int width)
	{
		return std::make_shared<Colume>(parentHwnd, width);
	}

	std::shared_ptr<Colume> Colume::ColumeBuilder::makeOtherColume(HWND parentHwnd, int width, HFONT hFont)
	{
		return std::make_shared<Colume>(parentHwnd, width, hFont);
	}

	Colume::Colume(HWND parentHwnd, int width, bool readonly, HFONT hFont) : parentHwnd(parentHwnd), width(width), hFont(hFont), readonly(readonly)
	{
		id = temp_id++;
	}
}
