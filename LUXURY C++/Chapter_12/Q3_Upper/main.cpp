#include "pch.h"


int main()
{
	ifstream fin("c:\\windows\\system.ini");

	int ch;
	while ((ch = fin.get()) != EOF) {
		cout.put(toupper(ch));
	}

	fin.close();
	return 0;
}

