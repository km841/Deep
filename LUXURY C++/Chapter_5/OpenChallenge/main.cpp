#include <iostream>
#include <string>
#include "Morse.h"
using namespace std;

int main()
{
	cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << endl;
	string word;
	getline(cin, word);

	Morse m;
	string morse;
	m.text2Morse(word, morse);

	cout << morse << endl << endl;

	cout << "모스 부호를 다시 영문 텍스트로 바꿉니다." << endl;

	string conv;
	m.morse2Test(morse, conv);

	cout << word << endl;
}

