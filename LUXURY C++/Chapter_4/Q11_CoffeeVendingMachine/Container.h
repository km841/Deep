#pragma once
#include <iostream>
#include <string>
using namespace std;
class Container
{
	int size;

public:
	Container() { size = 10; }
	void fill();
	void consume();
	int getSize();
};

