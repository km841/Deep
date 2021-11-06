#pragma once
#include <iostream>
using namespace std;

class Circle
{
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }

	friend const Circle& operator++(Circle& c);
	friend Circle operator++(Circle& c, int n);
};

