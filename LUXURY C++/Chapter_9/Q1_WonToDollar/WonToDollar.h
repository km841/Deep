#pragma once
#include "Converter.h"

class WonToDoller : public Converter
{
	string src;
	string dest;

public:
	WonToDoller(double ratio);
	double convert(double src);
	string getSourceString();
	string getDestString();
};

