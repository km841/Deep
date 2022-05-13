#include "pch.h"
#include "ExcelManager.h"

void ExcelManager::Mapping()
{
	wsOut = wbOut.active_sheet();
	wsOut.title("BOM");
	
	xlnt::alignment center;
	center.vertical(xlnt::vertical_alignment::center);
	center.horizontal(xlnt::horizontal_alignment::center);
	center.wrap();
	
	for (int row = 0; row < this->sheet.get()->GetRowSize(); row++)
	{
		for (int col = 0; col < this->sheet.get()->GetRow(row).get()->GetColumeSize(); col++)
		{
			
			/* CONVERT UTF-8 */
			if (row != 0) {
				fs::path temp = this->sheet.get()->GetData(row + 1, col + 1);
				std::string conv_s = temp.u8string();

				wsOut.cell(xlnt::cell_reference(col + 1, row + 2)).value(conv_s);
				wsOut.cell(xlnt::cell_reference(col + 1, row + 2)).alignment(center);
			}

			else {
				fs::path temp = this->sheet.get()->GetData(row + 1, col + 1);
				std::string conv_s = temp.u8string();

				wsOut.cell(xlnt::cell_reference(col + 1, row + 1)).value(conv_s);
				wsOut.cell(xlnt::cell_reference(col + 1, row + 1)).alignment(center);
			}
			

			
		}
	}

	if (cellProperty) {
		
		/* CELL WIDTH INITIALIZATION */
		{
			wsOut.merge_cells("A1:H1");
			wsOut.column_properties(1).width = 5;
			wsOut.column_properties(2).width = 30;
			wsOut.column_properties(3).width = 30;
			wsOut.column_properties(4).width = 15;
			wsOut.column_properties(5).width = 5;
			wsOut.column_properties(6).width = 5;
			wsOut.column_properties(7).width = 15;
			wsOut.column_properties(8).width = 25;
		}

		/* TITLE ROW FONT INITIALIZATION */
		{

			xlnt::rgb_color rgb(183, 222, 232);
	
			wsOut.cell(xlnt::cell_reference(1, 1)).fill(xlnt::fill::solid(rgb));
			wsOut.cell(xlnt::cell_reference(1, 1)).font(xlnt::font().bold(true).size(35));

			wsOut.cell(xlnt::cell_reference(1, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(2, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(3, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(4, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(5, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(6, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(7, 3)).font(xlnt::font().bold(true));
			wsOut.cell(xlnt::cell_reference(8, 3)).font(xlnt::font().bold(true));
		}
	
		/* BORDER INITIALIZATION */
		{
			xlnt::border::border_property prop_;
			prop_.style(xlnt::border_style::thin);
			prop_.color(xlnt::color::black());

			xlnt::border border_top;
			xlnt::border border_bottom;
			xlnt::border border_start;
			xlnt::border border_end;

			border_top.side(xlnt::border_side::top, prop_);
			border_bottom.side(xlnt::border_side::bottom, prop_);
			border_start.side(xlnt::border_side::start, prop_);
			border_end.side(xlnt::border_side::end, prop_);


			wsOut.range("A2:H2").border(border_bottom);
			wsOut.range("A13:H13").border(border_top);
			wsOut.range("A3:A12").border(border_start);
			wsOut.range("H3:H12").border(border_end);
		}
	}
}



bool ExcelManager::Save(const std::string& filename)
{
	/* CONVERT UTF-8 */
	fs::path temp = filename;
	std::string s_conv = temp.u8string();
	wbOut.save(s_conv);

	try { 
		wbOut.save(s_conv);
	}

	catch (...) { 
		/* ERROR HANDLING */
		MessageBox(0, _T("예외가 발생했습니다.\n담당자에게 문의 바랍니다."), _T("CAPTION"), MB_OK); 
		return false;
	}
	return true;
}

bool ExcelManager::Save(const std::wstring& filename)
{
	/* CONVERT UTF-8 */
	fs::path temp = filename;
	std::string s_conv = temp.u8string();

	try {
		wbOut.save(s_conv);
	}

	catch (...) {
		MessageBox(0, _T("예외가 발생했습니다.\n담당자에게 문의 바랍니다."), _T("CAPTION"), MB_OK);
		return false;
	}


	return true;
}
