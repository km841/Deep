#pragma once
#include "AbstractPlayer.h"

class Human : public AbstractPlayer
{
public:
	Human(string name) : AbstractPlayer(name) {};
	string turn();
	
	
};

