#pragma once
#include "Random.h"

class EvenRandom : public Random
{
public:
	EvenRandom() : Random() {}
	int next();
	int nextInRange(int min, int max);
};

