#include "DoWhileLoopAdder.h"

int DoWhileLoopAdder::calculate()
{
	int x, y, total = 0;
	x = getX();
	y = getY();

	do
	{
		total += x++;

	} while (x != y);

	total += x;

	
	return total;
}
