#include "Stack.h"

Stack::Stack() :_size(0), _capacity(3) {
	_stack = new int[3];
	memset(_stack, 0, 3 * sizeof(int));
}

Stack& Stack::operator<<(int n)
{
	if (_size == _capacity)
	{
		int capacity = _capacity * 2;
		int* stack = new int[capacity];
		for (int i = 0; i < _size; i++)
		{
			stack[i] = _stack[i];
		}

		delete[] _stack;
		_stack = stack;
		_capacity = capacity;
	}

	_stack[_size++] = n;
	return *this;
}

int Stack::operator>>(int& n)
{
	n = _stack[--_size];
	return n;
}

bool Stack::operator !()
{
	return !(this->_size);
}

Stack::~Stack()
{
	if (_stack != nullptr)
	{
		delete[] _stack;
		_stack = nullptr;
	}
}
