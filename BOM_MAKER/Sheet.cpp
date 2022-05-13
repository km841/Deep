#include "pch.h"
#include "Sheet.h"
#include "Row.h"
#include "Colume.h"

namespace BOM {

	void BOM::Sheet::AddRow(int height, std::initializer_list<int>&& colSize, bool readonly)
	{
		std::shared_ptr<Row> row = std::make_shared<Row>(hInst, hwnd, height);
		row.get()->MakeRow(std::move(colSize), readonly);
		rows.emplace_back(std::move(row));
	}

	HwndControl Sheet::GetHwndTotalList()
	{
		HwndControl hwndList;

		for (int i = 0; i < rows.size(); i++) {
			hwndList.emplace_back(rows[i].get()->GetColumeHwndList());
		}

		return hwndList;
	}

	int Sheet::GetID(int rowIdx, int colIdx)
	{
		/* Index는 사용자 편의에 따라 1부터 진행 */

		if (rowIdx < 0) rowIdx = 0; // 0이나 그 이하일 경우의 처리
		if (rowIdx >= rows.size()) {
			/* 입력된 row 값이 너무 큽니다. */
			return 0;
		}

		int colID = rows[rowIdx].get()->GetColumeID(colIdx);
		if (!colID) {
			/* colID가 잘못되었습니다. */
			return 0;
		}

		return colID;
	}

	int Sheet::GetID(int rowIdx, int colIdx) const
	{
		/* Index는 사용자 편의에 따라 1부터 진행 */

		if (rowIdx < 0) rowIdx = 0; // 0이나 그 이하일 경우의 처리
		if (rowIdx >= rows.size()) {
			/* 입력된 row 값이 너무 큽니다. */
			return 0;
		}

		int colID = rows[rowIdx].get()->GetColumeID(colIdx);
		if (!colID) {
			/* colID가 잘못되었습니다. */
			return 0;
		}

		return colID;
	}

	void Sheet::SetData(int rowIdx, int colIdx, const std::wstring& message)
	{
		if (rowIdx - 1 >= rows.size()) {
			/* 잘못된 입력 처리 */
			return;
		}

		int currID = GetID(rowIdx - 1, colIdx - 1);
		if (!currID) {
			/* 잘못된 입력 처리 */
			return;
		}

		SetDlgItemText(hwnd, currID, message.c_str());
	}

	std::wstring Sheet::GetData(int rowIdx, int colIdx)
	{
		TCHAR tempBuff[256];
		

		if (rows.size() <= rowIdx-1) {
			return std::wstring(_T(""));
		}

		int currID = rows[rowIdx-1].get()->GetColumeID(colIdx-1);
		if (!currID) {
			return std::wstring(_T(""));
		}

		GetDlgItemText(hwnd, currID, tempBuff, 256);

		return tempBuff;
	}

	HWND Sheet::GetHwnd(int rowIdx, int colIdx)
	{
		if (rows.size() <= rowIdx - 1) {
			return 0;
		}
		
		HWND colHwnd = rows[rowIdx - 1].get()->GetColumeHwnd(colIdx - 1);
		if (!colHwnd) {
			return 0;
		}

		return colHwnd;
	}

	void BOM::Sheet::DrawSheet()
	{
		for (const auto& row : rows) {
			row.get()->DrawRow(height_total);
			height_total += row.get()->GetHeight();
		}
	}
}
