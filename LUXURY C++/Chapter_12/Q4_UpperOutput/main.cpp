#include "pch.h"


int main()
{
	ifstream fin("c:\\windows\\system.ini");
	ofstream fout("c:\\temp\\system.txt");

	int ch;
	while ((ch = fin.get()) != EOF) {
		fout.put(toupper(ch));
	}

	fin.close();
	fout.close();
	return 0;
}

