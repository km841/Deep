#include "pch.h"


int main()
{
	const char* path = "c:\\windows\\system.ini";
	ifstream fin(path, ios::in);
	vector<string> v;
	string line;

	while (getline(fin, line)) {
		v.emplace_back(line);
	}
	cout << path << "파일 읽기 완료" << endl;

	int ch = 0;
	cout << "라인 번호를 입력하세요. 1보다 작은 값을 입력하면 종료" << endl;
	while (ch >= 0) {
		cout << ": ";
		cin >> ch;
		cin.ignore();

		if (ch < 0 || ch >= v.size()+1)
			continue;

		cout << v[ch-1] << endl;
	}

	fin.close();
}

