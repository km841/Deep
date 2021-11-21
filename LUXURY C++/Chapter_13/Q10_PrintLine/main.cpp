#include <iostream>

extern "C" int printline(int count);

int main()
{
	for (int i = 1; i < 4; i++)
	{
		printline(i);
	}
}
