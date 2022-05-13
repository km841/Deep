#pragma once
#include "Row.h"
namespace BOM {
	class Row;
	class Colume;

	using Rows = std::vector<std::shared_ptr<Row>>;
	using HwndControl = std::vector<std::vector<HWND>>;
	class Sheet
	{
		HINSTANCE hInst;
		HWND hwnd;

		Rows rows;
		int height_total = 0;

	public:
		explicit Sheet(HINSTANCE hInstance, HWND hwnd) : hInst(hInstance), hwnd(hwnd), height_total(0) {}
		void AddRow(int height, std::initializer_list<int>&& colSize, bool readonly=false);

		HwndControl GetHwndTotalList();

		inline int GetRowSize() { return rows.size(); }
		inline int GetRowSize() const { return rows.size(); }

		inline const std::shared_ptr<Row> GetRow(int index) { return rows[index]; }
		inline const std::shared_ptr<Row> GetRow(int index) const { return rows[index]; }
		
		int GetID(int rowIdx, int colIdx);
		int GetID(int rowIdx, int colIdx) const;

		void SetData(int rowIdx, int colIdx, const std::wstring& message);
		std::wstring GetData(int rowIdx, int colIdx);

		HWND GetHwnd(int rowIdx, int colIdx);

		void DrawSheet();
	};
}

