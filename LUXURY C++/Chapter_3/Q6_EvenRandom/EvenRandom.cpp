#include "EvenRandom.h"

int EvenRandom::next()
{
	int randValue = rand() % RAND_MAX;
	while (randValue % 2 != 0) { randValue = rand() % RAND_MAX; }
	return randValue;
}

int EvenRandom::nextInRange(int min, int max)
{
	int randValue = min + rand() % (max - 1);

	while (randValue % 2 != 0) {
		randValue = min + rand() % (max - 1);
	}

	return randValue;
}
