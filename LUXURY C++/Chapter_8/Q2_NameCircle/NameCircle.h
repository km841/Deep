#pragma once
#include "Circle.h"
class NameCircle : public Circle
{
	string _name;
public:
	NameCircle(int radius = 0, string name = "");
	void setValues(int radius, string name);
	string getName() { return this->_name; }
	void show();

};

