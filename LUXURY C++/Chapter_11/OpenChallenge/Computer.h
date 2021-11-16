#pragma once
#include "AbstractPlayer.h"

class Computer : public AbstractPlayer
{
public:
	Computer(string name) : AbstractPlayer(name) {}
	string turn() { return gbb[rand() % 3]; }
};

