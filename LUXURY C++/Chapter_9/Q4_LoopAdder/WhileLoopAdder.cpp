#include "WhileLoopAdder.h"

int WhileLoopAdder::calculate()
{
	int x, y, total = 0;
	x = getX();
	y = getY();
	while (x != y)
	{
		total += x++;
	}
	total += x;

	return total;
}
