#pragma once
#include "Circle.h"
class NameCircle : public Circle
{
	string _name;
public:
	NameCircle(int radius, string name);
	void show();
};

