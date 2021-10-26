#include "SelectableRandom.h"

SelectableRandom::SelectableRandom() : Random(), set_flag(false)
{}

void SelectableRandom::SetOddOrEven(bool flag)
{
	this->set_flag = flag;
}

int SelectableRandom::next()
{
	if (set_flag == false)
	{
		int randValue = rand() % RAND_MAX;
		while (randValue % 2 != 0) { randValue = rand() % RAND_MAX; }
		return randValue;
	}

	else
	{
		int randValue = rand() % RAND_MAX;
		while (randValue % 2 == 0) { randValue = rand() % RAND_MAX; }
		return randValue;
	}
}

int SelectableRandom::nextInRange(int min, int max)
{
	if (set_flag == false)
	{
		int randValue = min + rand() % (max - 1);

		while (randValue % 2 != 0) {
			randValue = min + rand() % (max - 1);
		}

		return randValue;
	}

	else
	{
		int randValue = min + rand() % (max - 1);

		while (randValue % 2 == 0) {
			randValue = min + rand() % (max - 1);
		}

		return randValue;
	}
}
