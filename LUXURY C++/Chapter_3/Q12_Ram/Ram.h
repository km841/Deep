#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Ram
{
private:
	char mem[100 * 1024];
	int size;


public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);

};

