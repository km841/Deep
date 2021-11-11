#include "Map.h"

Map::Map()
{
	obj = new GameObject*[3];
	map = new char*[10];

	obj[0] = new Human(0, 0, 1);
	obj[1] = new Monster(4, 4, 2);
	obj[2] = new Food(9, 9, 1);

	for (int i = 0; i < 10; i++)
		map[i] = new char[20];


}

void Map::init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map[i][j] = '-';
		}
	}
}

void Map::printMap()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			for (int k = 0; k < 3; k++)
				if (obj[k]->getX() == j && obj[k]->getY() == i)
					map[i][j] = obj[k]->getShape();

			cout << map[i][j];
		}
		cout << endl;
	}
}

bool Map::rendering()
{
	for (int i = 0; i < 3; i++)
		obj[i]->move();

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (obj[k]->getX() == j && obj[k]->getY() == i) {
					map[i][j] = obj[k]->getShape();
					break;
				}

				else
					map[i][j] = '-';

				if (obj[0]->collide(obj[1]))
				{
					cout << "Game Over!!" << endl;
					return false;
				}

				if (obj[0]->collide(obj[2]))
				{
					ConsoleHelper::EndGame();
					return false;
				}
			}


			cout << map[i][j];
		}
		cout << endl;
	}
	return true;
}

Map::~Map()
{
	for (int i = 0; i < 3; i++)
	{
		delete obj[i];
	}

	delete[] obj;


	for (int i = 0; i < 10; i++)
	{
		delete[] map[i];
	}

	delete[] map;
}
