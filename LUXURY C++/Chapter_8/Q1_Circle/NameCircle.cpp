#include "pch.h"
#include "NameCircle.h"

NameCircle::NameCircle(int radius, string name) : Circle(radius)
{
	_name = name;
}

void NameCircle::show()
{
	cout << "반지름이 " << getRadius() << "인 " << _name << endl;
}
