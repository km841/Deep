#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	cout << "문자열 입력>> ";
	string word;
	int cnt = 0;

	getline(cin, word);
	int prev = 0;
	
	int curr = word.find('a', prev);
	while (curr != string::npos)
	{
		cnt++;
		prev = curr + 1;
		curr = word.find('a', prev);
	}

	cout << "문자 a는 " << cnt << "개 있습니다.";
}

