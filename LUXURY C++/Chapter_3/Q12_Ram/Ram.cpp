#include "Ram.h"

Ram::Ram()
{
	memset(mem, 0, 100 * 1024);
}

Ram::~Ram()
{
	cout << "메모리 제거됨!" << endl;
}

char Ram::read(int address)
{
	return mem[address];
}

void Ram::write(int address, char value)
{
	mem[address] = value;
}
