#pragma once
#include <iostream>
#include <string>
using namespace std;

class AbstractGate
{
protected:
	bool x, y;

public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

