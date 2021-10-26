#include "Calculator.h"

void Calculator::setValue(int x, int y)
{
	this->a = x;
	this->b = y;
}

int Add::calculate()
{
	return a + b;
}

int Sub::calculate()
{
	return a - b;
}

int Mul::calculate()
{
	return a * b;
}

int Div::calculate()
{
	return a / b;
}
