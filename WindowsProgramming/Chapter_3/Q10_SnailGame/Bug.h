#pragma once
#include <Windows.h>

enum Dir {
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,

	DIR = 4
};

class Bug
{
	int dir;
	int posX, posY;
	Bug* tail;

public:
	Bug(int x, int y);
	void addTail(int x, int y);
	bool isTail();


	Bug* getTail() { return tail; }
	int getX() { return posX; }
	int getY() { return posY; }
	int getDir() { return dir; }
	void bugMove(int dir, const RECT& r);

	bool isPossible(int dir, const RECT& r);

	void setX(int x) { posX = x; }
	void setY(int y) { posY = y; }
	void setDir(int dir) { this->dir = dir; }


	~Bug();
};

