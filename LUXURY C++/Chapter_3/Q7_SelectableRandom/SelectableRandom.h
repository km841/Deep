#pragma once
#include "Random.h"

class SelectableRandom : public Random
{
private:
	bool set_flag;

public:
	SelectableRandom();
	void SetOddOrEven(bool flag);
	int next();
	int nextInRange(int min, int max);

};

