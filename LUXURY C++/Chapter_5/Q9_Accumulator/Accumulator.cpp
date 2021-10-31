#include "Accumulator.h"

Accumulator::Accumulator(int value) : value(value)
{}

Accumulator& Accumulator::add(int n)
{
	value += n;
	return *this;
}


