#include "Monster.h"

enum
{
	LEFT,
	DOWN,
	UP,
	RIGHT
};

Monster::Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance)
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

void Monster::move()
{
	int randValue = rand() % 5;

	switch (randValue)
	{
	case LEFT:
		if (this->x <= 0) this->move();
		else this->x -= this->distance;
		break;

	case DOWN:
		if (this->y >= 8) this->move();
		else this->y += this->distance;
		break;

	case UP:
		if (this->y <= 0) this->move();
		else this->y -= this->distance;
		break;

	case RIGHT:
		if (this->x >= 18) this->move();
		else this->x += this->distance;
		break;
	}
}

char Monster::getShape()
{
	return 'M';
}

Monster::~Monster()
{
}
