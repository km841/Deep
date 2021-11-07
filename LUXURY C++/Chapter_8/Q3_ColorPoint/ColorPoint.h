#pragma once
#include "Point.h"

class ColorPoint : public Point
{
	string color;

public:
	ColorPoint(int x, int y, string name);
	void setPoint(int x, int y);
	void setColor(string color);
	void show();
};

