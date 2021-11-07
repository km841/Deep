#pragma once
#include "BaseArray.h"

class MyStack : public BaseArray
{
private:
	int esp;

public:
	MyStack(int m=100);
	void push(int n);
	int pop();
	int length() { return esp; };
	int capacity() { return getCapacity(); }
};

