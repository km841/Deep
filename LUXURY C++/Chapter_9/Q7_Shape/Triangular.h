#pragma once
#include "Shape.h"
class Triangular : public Shape
{
public:
	Triangular(string n = "", int w = 0, int h = 0) : Shape(n, w, h) {}
	double getArea() { return (double)width * height / 2; }

};

