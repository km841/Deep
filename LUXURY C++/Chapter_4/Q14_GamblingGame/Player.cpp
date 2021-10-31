#include "Player.h"

Player::Player()
{
	_nums = new int[MAX_NUMS];
}

Player::~Player()
{
	if (_nums != nullptr)
		delete[] _nums; _nums = nullptr;
}

int* Player::SetNumbers()
{
	for (int i = 0; i < MAX_NUMS; i++)
	{
		int randInt = rand() % MAX_NUMS;
		*(_nums + i) = randInt;
	}
	
	return this->_nums;
}

void Player::SetName(string name)
{
	this->_name = name;
}

string Player::GetName()
{
	return this->_name;
}
