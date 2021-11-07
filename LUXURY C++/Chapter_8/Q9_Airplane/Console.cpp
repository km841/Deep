#include "pch.h"
#include "Console.h"

void Console::PrintMenu()
{
	int choice = 0;
	cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
}

string Console::InputName()
{
	string tmp;
	cout << "이름 입력>> ";
	getline(cin, tmp);

	return tmp;
}

int Console::InputPos()
{
	int tmp;
	cout << "좌석 번호>> ";
	cin >> tmp;
	cin.ignore();

	return tmp;
}

void Console::PrintSelectTime()
{
	cout << "07시:1, 12시:2, 17시:3>> ";
}
