#include "pch.h"


int main()
{
	ifstream fin("c:\\windows\\system.ini");

	string line;
	for (int i = 1; getline(fin, line); i++) {
		cout << i << " : " << line << endl;
	}

	fin.close();
	return 0;
}

