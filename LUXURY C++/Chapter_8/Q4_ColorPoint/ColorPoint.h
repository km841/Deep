#pragma once
#include "Point.h"

class ColorPoint : public Point
{
	string color;

public:
	ColorPoint(int x=0, int y=0, string name="BLACK");
	void setPoint(int x, int y);
	void setColor(string color);
	void show();
};

