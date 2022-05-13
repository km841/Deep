#pragma once
#include "Colume.h"
namespace BOM {

	class Colume;

	using Columes = std::vector<std::shared_ptr<Colume>>;

	class Row
	{
		HINSTANCE hInst;
		HWND hwnd;

		Columes cols;
		int height;
		int width_total = 0;

	public:
		explicit Row(HINSTANCE hInstance, HWND hwnd, int height) : hInst(hInstance), hwnd(hwnd), height(height) {}
		
		inline int GetHeight() { return height; }
		inline int GetHeight() const { return height; }

		inline int GetColumeSize() { return cols.size(); }
		inline int GetColumeSize() const { return cols.size(); }

		std::vector<HWND> GetColumeHwndList();


		inline int GetColumeID(int index) { 
			if (index >= cols.size()) {
				return 0;
			}
			return cols[index]->GetID(); 
		}
		inline int GetColumeID(int index) const { 
			if (index >= cols.size()) {
				return 0;
			}
			return cols[index]->GetID();
		}

		inline HWND GetColumeHwnd(int index) { 
			if (index >= cols.size()) return 0;
			return cols[index]->GetHwnd(); 
		}
		inline HWND GetColumeHwnd(int index) const {
			if (index >= cols.size()) return 0;
			return cols[index]->GetHwnd(); 
		}

		void MakeRow(std::initializer_list<int>&& init, bool readonly = false);
		void DrawRow(int height);

	};

}

