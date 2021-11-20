#include "pch.h"


int main()
{
	ifstream fin("words.txt", ios::in);
	vector<string> v;
	string line;

	while (getline(fin, line))
		v.emplace_back(line);

	cout << "... words.txt. 파일 로딩 완료" << endl;
	cout << "검색을 시작합니다. 단어를 입력해 주세요." << endl;
	
	string input;
	while (input != "exit") {
		cout << "단어>> ";
		getline(cin, input);

		if (input == "exit") continue;

		for (int i = 0; i < input.size(); i++) {
			for (int j = 0; j < 26; j++) {
				if (input[i] == (char)(j + 97)) continue;
				string word = input;
				word[i] = (char)(j + 97);

				if (find(v.begin(), v.end(), word) != v.end()) {
					cout << word << endl;
				}
			}
		}
	}

}

