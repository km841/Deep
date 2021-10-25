#include "Tower.h"

Tower::Tower() : Tower(1)
{
}

Tower::Tower(int n) : height(n)
{
}

int Tower::getHeight()
{
	return height;
}
