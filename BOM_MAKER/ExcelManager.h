#pragma once
#pragma warning(disable: 4996)
#include "Sheet.h"
#include "Row.h"
#include "Colume.h"
#include "xlnt/xlnt.hpp"


class ExcelManager
{
	// 파일명을 받아서 
	std::wstring filename;
	std::shared_ptr<BOM::Sheet>& sheet;

	xlnt::workbook wbOut;
	xlnt::worksheet wsOut;

	bool cellProperty = false;

public:
	ExcelManager(std::shared_ptr<BOM::Sheet>& sheet) : sheet(sheet) {}
	void Mapping();

	void SetProperty() { cellProperty = true; }
	bool Save(const std::string& filename);
	bool Save(const std::wstring& filename);

	~ExcelManager() {}


};

