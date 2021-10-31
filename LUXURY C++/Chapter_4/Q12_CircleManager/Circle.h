#pragma once
#include <string>
#include <iostream>
using namespace std;
class Circle
{
	int radius;
	string name;

public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

