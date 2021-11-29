#include "Bug.h"

Bug::Bug(int x, int y)
	: posX(x), posY(y), dir(0), tail(nullptr)
{
}

void Bug::addTail(int x, int y)
{
	tail = new Bug(x, y);
}

bool Bug::isTail()
{
	return (tail != nullptr);
}

void Bug::bugMove(int dir, const RECT& r)
{
	if (isPossible(dir, r)) {
		switch (dir) {
		case UP: setY(getY() - 40);  break;
		case RIGHT: setX(getX() + 40); break;
		case DOWN: setY(getY() + 40); break;
		case LEFT: setX(getX() - 40);  break;
		}
	}
}

bool Bug::isPossible(int dir, const RECT& r)
{
	if (dir == UP && getY() - 40 > 0) return TRUE;
	else if (dir == RIGHT && getX() + 40 < r.right) return TRUE;
	else if (dir == DOWN && getY() + 40 < r.bottom) return TRUE;
	else if (dir == LEFT && getX() - 40 > 0) return TRUE;

	return FALSE;
}

Bug::~Bug()
{
}
