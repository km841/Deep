#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
	srand(static_cast<unsigned int>(time(nullptr)));
	string word;

	while (true) {
		cout << ">>";
		getline(cin, word);
		if (word == "exit")
			break;

		for (int i = word.size() - 1; i > 0; i--)
			cout << word[i];
		cout << endl;
	}
}
