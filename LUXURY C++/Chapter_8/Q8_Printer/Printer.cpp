#include "pch.h"
#include "Printer.h"

void Printer::print(int pages)
{
	if (availableCount < pages)
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	else {
		availableCount -= pages;
		cout << "프린트 하였습니다." << endl;
	}
}
