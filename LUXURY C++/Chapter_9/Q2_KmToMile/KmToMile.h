#pragma once
#include <iostream>
#include <string>
#include "Converter.h"
using namespace std;

class KmToMile : public Converter
{
public:
	KmToMile(double ratio);
	double convert(double src);
	string getSourceString();
	string getDestString();

	~KmToMile();
};

