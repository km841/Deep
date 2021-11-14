#include "pch.h"

int main()
{
	map<string, string> m;
	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;
	
	int ch = 1;
	while (ch == 1 || ch == 2)
	{
		cout << "삽입:1, 검사:2, 종료:3>> ";
		cin >> ch;
		cin.ignore();

		if (ch == 1)
		{
			cout << "이름 암호>> ";
			string name, pass;
			cin >> name >> pass;
			
			m[name] = pass;
		}

		else if (ch == 2)
		{
			string name, pass;
			cout << "이름?";
			getline(cin, name);

			while (true)
			{
				bool flag = false;
				cout << "암호?";
				getline(cin, pass);
				
				for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
				{
					if (it->first == name && it->second == pass)
						flag = true;

				}

				if (flag) {
					cout << "통과!!" << endl;
					break;
				}

				else
				{
					cout << "실패~~" << endl;
				}

			}
			
		}
	}
}
