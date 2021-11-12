#include "IntStack.h"

bool IntStack::push(int n)
{
	if (volume == p) return false;
	stack[p++] = n;

	return true;
}

bool IntStack::pop(int& n)
{
	if (p == 0) return false;
	n = stack[--p];

	return true;
}
