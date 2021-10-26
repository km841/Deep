#include "Random.h"

Random::Random()
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

int Random::next()
{
	return rand() % RAND_MAX;
}

int Random::nextInRange(int min, int max)
{
	return min + rand() % (max - 1);
}
