#include "pch.h"


int main()
{
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);

	char buf[1024];
	int total = 0;
	while (true) {
		fin.read(buf, 1024);
		int n = fin.gcount();
		total += n;

		if (n < 1024) break;
	}

	cout << "파일의 크기는 " << total << "입니다." << endl;
}

