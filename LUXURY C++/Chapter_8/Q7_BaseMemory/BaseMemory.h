#pragma once
class BaseMemory
{
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	~BaseMemory();

public:
	char read(int idx) { return mem[idx]; };
	void write(int idx, char val) { mem[idx] = val; }

	

};

