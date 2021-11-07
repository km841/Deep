#include <iostream>
#include <string>
#include "pch.h"
#include "NameCircle.h"

using namespace std;

int main()
{
	NameCircle pizza[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ">> ";
		int prev = 0;
		string input;


		getline(cin, input);

		int pos = input.find(' ', prev);
		pizza[i].setValues(stoi(input.substr(prev, pos - prev)), input.substr(pos + 1, input.size() - 1));

	}
	int big = 0;
	string pizName;
	for (int i = 0; i < 5; i++)
	{
		if (big < pizza[i].getArea()) {
			big = pizza[i].getArea();
			pizName = pizza[i].getName();
		}
	}

	cout << "가장 면적이 큰 피자는 " << pizName << "입니다" << endl;

}

