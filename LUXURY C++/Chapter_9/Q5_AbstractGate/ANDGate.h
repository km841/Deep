#pragma once
#include "AbstractGate.h"

class ANDGate : public AbstractGate
{
public:
	bool operation() { return x && y; }

};

