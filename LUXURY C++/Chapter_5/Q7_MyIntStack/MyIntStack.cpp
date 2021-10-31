#include "MyIntStack.h"

MyIntStack::MyIntStack() : p(), tos(0)
{}

bool MyIntStack::push(int n)
{
	if (tos < 10) {
		p[tos++] = n;
		return true;
	}

	else
		return false;
	
}

bool MyIntStack::pop(int& n)
{
	if (tos > 0) {
		n = p[--tos];
		return true;
	}

	else
		return false;
}
