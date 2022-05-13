#include "pch.h"
#include "Row.h"
#include "Colume.h"


namespace BOM {
	std::vector<HWND> Row::GetColumeHwndList()
	{
		std::vector<HWND> hwndVector;

		for (int i = 0; i < this->cols.size(); i++) {
			hwndVector.emplace_back(cols[i].get()->GetHwnd());
		}

		return hwndVector;

	}
	void Row::MakeRow(std::initializer_list<int>&& init, bool readonly)
	{
		for (auto& e : init) {
			cols.emplace_back(std::make_shared<Colume>(hwnd, e, readonly));
		}
	}


	void Row::DrawRow(int height)
	{
		for (const auto& col : cols) {
			col.get()->DrawColume(hInst, hwnd, { width_total, height }, this->height);
			width_total += col.get()->GetWidth();
		}
	}


}
