#include "pch.h"
#include "ColorPoint.h"
#include "Point.h"

ColorPoint::ColorPoint(int x, int y, string name) : Point(x, y)
{
	color = name;
}

void ColorPoint::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void ColorPoint::setColor(string color)
{
	this->color = color;
}

void ColorPoint::show()
{
	cout << color << "색으로 " << "(" << x << "," << y << ")에 위치한 점입니다." << endl;
}
