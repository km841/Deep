#include "InkJetPrinter.h"

void InkJetPrinter::print(int pages)
{
	if (availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return;
	}
	
	else if (availableInk < pages) {
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		return;
	}

	else
	{
		cout << "프린트하였습니다." << endl;
		availableCount -= pages;
		availableInk -= pages;
	}
}

void InkJetPrinter::show()
{
	cout << model << ", ";
	cout << manufacturer << ", ";
	cout << "남은 종이 " << availableCount << "장, ";
	cout << "남은 잉크 " << availableInk << endl;
}
