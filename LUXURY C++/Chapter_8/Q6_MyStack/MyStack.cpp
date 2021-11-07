#include "pch.h"
#include "MyStack.h"
#include "BaseArray.h"

MyStack::MyStack(int m) : BaseArray(m), esp(0)
{
}

void MyStack::push(int n)
{
	put(esp++, n);
}

int MyStack::pop()
{
	return get(--esp);
}
