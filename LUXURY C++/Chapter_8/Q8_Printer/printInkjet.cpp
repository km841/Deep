#include "pch.h"
#include "printInkJet.h"

void printInkJet::print(int pages)
{
	if (availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return;
	}

	if (pages > availableInk)
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;

	else {
		availableInk -= pages;
		Printer::print(pages);
	}
}

void printInkJet::show()
{
	cout << "잉크젯 : " << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk << endl;
}
