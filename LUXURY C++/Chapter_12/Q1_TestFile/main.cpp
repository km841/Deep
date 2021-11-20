#include "pch.h"


int main()
{
	ifstream fin("test.txt");
	
	int ch;
	while ((ch = fin.get()) != EOF)
		cout.put(ch);

	fin.close();
	return 0;
}

