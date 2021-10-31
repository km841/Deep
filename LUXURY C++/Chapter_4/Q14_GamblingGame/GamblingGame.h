#pragma once
#include "Player.h"

const int MAX_USER = 2;
class GamblingGame
{
	Player* _players;
	
public:
	GamblingGame();
	~GamblingGame();

	void SetPlayerName();
	bool NextTurn(int n);
};

