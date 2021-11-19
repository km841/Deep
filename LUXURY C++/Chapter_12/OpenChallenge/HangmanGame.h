#pragma once
#include "User.h"
class HangmanGame
{
	vector<string> v;
	User* u;

public:
	HangmanGame();
	void fileLoad();
	bool question();

	~HangmanGame() { delete u; }
};

