#pragma once
#include <iostream>
#include <string>
using namespace std;

class AbstractStack
{
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;

	virtual int size() = 0;
};

