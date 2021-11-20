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
	vector<string> temp;
	while (input != "exit") {
		cout << "단어>> ";
		getline(cin, input);

		if (input == "exit") continue;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].size() < input.size()) continue;

			if (input == v[i].substr(0, input.size())) {
				temp.emplace_back(v[i]);
			}

		}

		if (temp.empty()) {
			cout << "발견할 수 없음" << endl;
			continue;
		}

		for (int i = 0; i < temp.size(); i++)
		{
			cout << temp[i] << endl;
		}
		temp.clear();
	}

}

