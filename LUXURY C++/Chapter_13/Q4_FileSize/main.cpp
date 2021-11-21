#include "pch.h"

int getFileSize(const char* file) {
	if (file == NULL) throw "파일명이 NULL 입니다.";
	ifstream fin(file);

	if (!fin) throw "파일 열기가 실패했습니다.";
	fin.seekg(0, ios::end);
	int length = fin.tellg();
	return length;
}

int main()
{
	try {
		int n = getFileSize("c:\\windows\\system.ini");
		cout << "파일 크기 = " << n << endl;

		int m = getFileSize(NULL);
		cout << "파일 크기 = " << m << endl;
	}

	catch (const char* c) {
		cout << "예외 발생 : " << c << endl;
	}

	
	
}
