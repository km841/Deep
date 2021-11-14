#include "pch.h"

int main()
{
	map<string, int> m;
	
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
	
	int ch = 1;
	while (ch == 1 || ch == 2)
	{
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> ch;
		cin.ignore();

		if (ch == 1)
		{
			string name;
			int score;
			cout << "이름과 점수>> ";

			cin >> name;
			cin >> score;
			m[name] = score;
		}

		else if (ch == 2)
		{
			cout << "이름>> ";
			string name;
			getline(cin, name);

			for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
				if (it->first == name) cout << it->first << "의 점수는 " << it->second << endl;
		}
	}
}
