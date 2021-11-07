#include "pch.h"
#include "MyQueue.h"
#include "BaseArray.h"

MyQueue::MyQueue(int m) : BaseArray(m), size(0)
{}

void MyQueue::enqueue(int n)
{
	put(size++, n);
}

int MyQueue::dequeue()
{
	int out = get(0);
	for (int i = 1; i < size; i++)
	{
		put(i - 1, get(i));
	}
	size--;
	return out;
}
