#include "pch.h"


int main()
{
	int n;
	char grade;
	cout << "점수를 입력하세요 : ";

	try {
		cin >> n;
		cin.ignore();
		if (n < 0 || n > 100) throw "점수 입력 오류";
		
		if (n >= 0 && n < 60) grade = 'F';
		else if (n >= 60 && n < 70) grade = 'D';
		else if (n >= 70 && n < 80) grade = 'C';
		else if (n >= 80 && n < 90) grade = 'B';
		else if (n >= 90 && n <= 100) grade = 'A';

		cout << "당신의 등급은 " << grade << "입니다." << endl;
	}

	catch (const char* s) {
		cout << s << endl;
	}

	
}
