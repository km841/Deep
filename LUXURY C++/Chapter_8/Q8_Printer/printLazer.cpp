#include "pch.h"
#include "printLazer.h"

void printLazer::print(int pages)
{
	if (availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		return;
	}

	if (availableToner < pages)
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;

	else {
		availableToner -= pages;
		Printer::print(pages);
	}
}

void printLazer::show()
{
	cout << "레이저 : " << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner << endl;
}
