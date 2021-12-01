#pragma once
enum Dir {
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,

	DIR = 4
};
class Food
{
	int x, y;

public:
	Food(int x, int y) : x(x), y(y) {}

	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	
	~Food() {}
};

