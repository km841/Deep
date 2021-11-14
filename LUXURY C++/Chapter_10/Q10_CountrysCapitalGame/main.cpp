#include "pch.h"
#include "CountrysCapitalGame.h"

int main()
{
	CountrysCapitalGame ccg;
	ccg.init();
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;

	int choice = -1;
	while (choice != 3)
	{
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
		cin >> choice;
		cin.ignore();

		if (choice == 3) continue;
		if (choice == 1) {
			cout << "현재 " << ccg.getVector().size() << "개의 나라가 입력되어 있습니다." << endl;
			cout << "나라와 수도를 입력하세요(no no 이면 입력 끝)" << endl;

			while (true) 
			{
				cout << ccg.getVector().size() + 1 << ">>";
				string st[2];
				for (int i = 0; i < 2; i++)
					cin >> st[i];

				if (ccg.add(st[0], st[1])) continue;
				else break;
			}
		}

		else if (choice == 2) {
			while (ccg.quiz()) {}
		}
	}
}
