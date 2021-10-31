#include "MyIntStack.h"

MyIntStack::MyIntStack() : p(nullptr), size(10), tos(0)
{
}

MyIntStack::MyIntStack(int size) : size(size), tos(0)
{
	p = new int[size];
}

MyIntStack::MyIntStack(const MyIntStack& s)
{
	this->size = s.size;
	p = new int[size];
	this->tos = s.tos;

	for (int i = 0; i < size; i++)
	{
		p[i] = s.p[i];
	}
}

MyIntStack::~MyIntStack()
{
	if (p != nullptr)
	{
		delete[] p;
		p = nullptr;
	}
}

bool MyIntStack::push(int n)
{
	if (tos < size) {
		p[tos++] = n;
		return true;
	}
	else
		return false;
}

bool MyIntStack::pop(int& n)
{
	if (tos > 0)
	{
		n = p[--tos];
		return true;
	}
	else
		return false;
}
