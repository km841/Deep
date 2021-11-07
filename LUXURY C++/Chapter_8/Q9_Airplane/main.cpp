#include "pch.h"
#include <iostream>
#include <string>
#include "AirlineBook.h"

using namespace std;


int main()
{
	cout << "***** 한성항공에 오신 것을 환영합니다 *****" << endl << endl;
	AirlineBook* ap = new AirlineBook;
	ap->system();
	cout << "예약 시스템을 종료합니다." << endl;

	delete ap;
}

