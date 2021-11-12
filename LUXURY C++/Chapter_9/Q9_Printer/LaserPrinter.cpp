#include "LaserPrinter.h"

void LaserPrinter::print(int pages)
{
	if (availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return;
	}

	else if (availableToner < pages) {
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		return;
	}

	else
	{
		cout << "프린트하였습니다." << endl;
		availableCount -= pages;
		availableToner -= pages;
	}
}

void LaserPrinter::show()
{
	cout << model << ", ";
	cout << manufacturer << ", ";
	cout << "남은 종이 " << availableCount << "장, ";
	cout << "남은 토너 " << availableToner << endl;
}
