#include "Food.h"

enum
{
	STOP,
	MOVE
};

enum
{
	LEFT,
	DOWN,
	UP,
	RIGHT
};

Food::Food(int startX, int startY, int distance) : GameObject(startX, startY, distance), movCnt(0), currCnt(0)
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

void Food::move()
{
	int randValue = rand() % 2;
	bool flag = false;
	

	if (currCnt >= 3 && movCnt < 3 && randValue == 0)
		randValue++;

	if (randValue == 1)
	{
		while (true) {
			int randPos = rand() % 4;

			switch (randPos)
			{
			case LEFT:
				if (this->x <= 0) continue;

				else {
					this->x -= this->distance;
					flag = true;
					break;
				}
				

			case DOWN:
				if (this->y >= 9) continue;

				else {
					this->y += this->distance;
					flag = true;
					break;
				}
				

			case UP:
				if (this->y <= 0) continue;

				else {
					this->y -= this->distance;
					flag = true;
					break;
				}
				

			case RIGHT:
				if (this->x >= 19) continue;

				else {
					this->x += this->distance;
					flag = true;
					break;
				};
				
			}

			if (flag)
			{
				movCnt++;
				currCnt++;
				break;
			}

		}
		
	}

	currCnt++;

	
}

char Food::getShape()
{
	return '@';
}

Food::~Food()
{
}
