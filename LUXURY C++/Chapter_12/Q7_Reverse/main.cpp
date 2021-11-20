#include "pch.h"


int main()
{
	//ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	ifstream fin("c:\\temp\\system.txt", ios::in | ios::binary);
	ofstream fout("c:\\temp\\system_rev.txt", ios::out | ios::binary);

	if (!fin.is_open()) {
		cout << "입력 파일 열기 실패!" << endl;
		return 0;
	}

	if (!fout.is_open()) {
		cout << "출력 파일 열기 실패!" << endl;
		return 0;
	}

	char buf[1024];
	fin.read(buf, 1024);
	int size = fin.gcount();
	

	for (int i = 0; i < size; i++) {
		fout.put(buf[size - 1 - i]);
	}

	return 0;
}

