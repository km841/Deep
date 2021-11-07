#pragma once
#include "BaseArray.h"
class MyQueue : public BaseArray
{
private:
	int size;

public:
	MyQueue(int m = 100);
	int capacity() { return getCapacity(); }
	void enqueue(int n);
	int dequeue();
	int length() { return size; };

};

