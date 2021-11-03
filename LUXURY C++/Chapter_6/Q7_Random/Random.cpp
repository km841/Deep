#include "Random.h"

int Random::nextInt(int min, int max)
{

	return min + rand() % max;
}

char Random::nextAlphabet() {
	char ret = 65 + (rand() % 58);
	if (ret >= 91 && ret <= 96)
		ret = nextAlphabet();

	return ret;
}

double Random::nextDouble()
{
	return (double) rand() / RAND_MAX;
}
