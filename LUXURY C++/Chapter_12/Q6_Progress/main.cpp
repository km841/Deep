#include "pch.h"


int main()
{
	ifstream fin("c:\\windows\\system.ini");
	ofstream fout("c:\\temp\\system.txt");

	if (!fin.is_open()) {
		cout << "입력 파일 열기 실패!" << endl;
		return 0;
	}

	if (!fout.is_open()) {
		cout << "출력 파일 열기 실패!" << endl;
		return 0;
	}

	fin.seekg(0, ios::end);
	int size = fin.tellg();
	fin.seekg(0, ios::beg);

	char buf[1024];

	for (int i = 0; ; i++) {
		fin.read(buf, size / 10);
		int n = fin.gcount();
		fout.write(buf, n);
		cout << "." << n << "B " << (i + 1) * 10 << "%" << endl;
		
		if (n < (size / 10)) break;
	}

	fin.close();
	fout.close();

	return 0;
}

