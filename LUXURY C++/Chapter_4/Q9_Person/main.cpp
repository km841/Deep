#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main() 
{
	const int PERSON_N = 3;
	Person* person = new Person[PERSON_N];
	cout << "이름과 전화 번호를 입력해 주세요" << endl;

	for (int i = 0; i < PERSON_N; i++)
	{
		cout << "사람 " << i + 1 << ">> ";
		string info;
		getline(cin, info);
		
		int prev = 0;
		int sep = info.find(' ', prev);

		string pNum = info.substr(prev, sep);
		string name = info.substr(sep + 1);
		
		person[i].set(pNum, name);
	}

	cout << "모든 사람의 이름은 ";
	
	for (int i = 0; i < PERSON_N; i++)
	{
		cout << person[i].getName() << " ";
	}
	cout << endl;

	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	
	string temp;
	getline(cin, temp);

	for (int i = 0; i < PERSON_N; i++)
	{
		if (person[i].getName() == temp)
		{
			cout << "전화 번호는 " << person[i].getTel() << endl;
			break;
		}
	}



	delete[] person;
}
