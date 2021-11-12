#pragma once
#include "AbstractStack.h"
class IntStack : public AbstractStack
{
	int* stack;
	size_t volume;
	int p;

public:
	IntStack(int size) : stack(new int[size]), volume(size), p(0) {}
	~IntStack() { delete[] stack; }

	bool push(int n);
	bool pop(int& n);
	int size() { return p; }

};

