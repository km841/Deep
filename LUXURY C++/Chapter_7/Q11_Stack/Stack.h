#pragma once
#include <iostream>
using namespace std;
class Stack
{
	int* _stack;
	int _size;
	int _capacity;

public:
	Stack();
	Stack& operator<< (int n);
	int operator>> (int& n);

	bool operator! ();

	~Stack();
};

