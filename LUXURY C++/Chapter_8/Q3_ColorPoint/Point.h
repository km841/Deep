#pragma once
class Point
{
protected:
	int x, y;

public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }

protected:
	void move(int x, int y) { this->x; this->y; }
};

