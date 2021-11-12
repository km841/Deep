#include "ForLoopAdder.h"

int ForLoopAdder::calculate()
{
    int total = 0;
    for (int i = getX(); i < getY() + 1; i++)
        total += i;
    return total;
}
