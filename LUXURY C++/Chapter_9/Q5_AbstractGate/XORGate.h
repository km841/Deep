#pragma once
#include "AbstractGate.h"
class XORGate : public AbstractGate
{
public:
	bool operation() { return ((x == true && y == false) || (x == false && y == true)); }
};

