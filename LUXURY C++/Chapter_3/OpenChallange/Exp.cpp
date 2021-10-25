#include "Exp.h"

Exp::Exp() : Exp(1, 1)
{
}

Exp::Exp(int a, int b) : base(a), exp(b)
{
}

Exp::Exp(int value) : Exp(value, 1)
{
}

int Exp::getValue()
{
	int sum = 1;
	for (int i = 1; i < exp+1; i++)
		sum *= base;

	return sum;
}

int Exp::getBase()
{
	return base;
}

int Exp::getExp()
{
	return exp;
}

bool Exp::equals(Exp b)
{
	return (getValue() == b.getValue());
}

Exp::~Exp()
{
}
