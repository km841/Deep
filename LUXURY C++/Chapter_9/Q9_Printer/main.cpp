#include <iostream>
#include "Printer.h"
#include "LaserPrinter.h"
#include "InkJetPrinter.h"
using namespace std;


int main()
{
	Printer* p[2];

	p[0] = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	p[1] = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : "; p[0]->show();
	cout << "레이저 : "; p[1]->show();
	cout << endl;

	string choice;
	int i, j;
	

	while (choice != "n")
	{
		i = j = 0;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> i >> j;
		cin.ignore();

		p[i - 1]->print(j);
		for (int i = 0; i < 2; i++)
			p[i]->show();

		cout << "계속 프린트 하시겠습니까(y/n)>>";
		getline(cin, choice);
		cout << endl;
	}

	
	for (int i = 0; i < 2; i++) delete p[i];


}

