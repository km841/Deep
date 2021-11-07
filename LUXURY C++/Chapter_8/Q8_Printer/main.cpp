#include "pch.h"
#include <iostream>
#include <string>
#include "printInkJet.h"
#include "printLazer.h"

using namespace std;

void PrintInfo(printInkJet pj, printLazer pz) { pj.show(); pz.show(); }

int main()
{
	Printer** pArr = new Printer*[2];
	pArr[0] = new printInkJet("Officejet V40", "HP", 5, 10);
	pArr[1] = new printLazer("SCX-6x45", "삼성전자", 3, 20);

	int choice = 0;
	string yesOrNo;

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	PrintInfo(*(printInkJet*)pArr[0], *(printLazer*)pArr[1]);

	while (yesOrNo != "n")
	{
		int arr[2] = { 0, };

		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		for (int i = 0; i < 2; i++)
		{
			cin >> arr[i];
		}

		pArr[arr[0]-1]->print(arr[1]);
		PrintInfo(*(printInkJet*)pArr[0], *(printLazer*)pArr[1]);
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		
		cin.ignore();
		getline(cin, yesOrNo);
		cout << endl;
	}

	delete pArr[0];
	delete pArr[1];
	delete[] pArr;
}

