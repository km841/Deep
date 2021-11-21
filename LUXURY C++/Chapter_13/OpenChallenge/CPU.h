#pragma once
#include "HardwareException.h"
class CPU
{
	string instruction;
	int op1, op2;
	char op;
	string cmd;

	void fetch() throw(HardwareException);
	void decode() throw(HardwareException);
	void execute() throw(HardwareException);

public:
	void run();
	static int stringToInt(string x) throw(string);
};

