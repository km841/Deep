#pragma once
#include "GameObject.h"
#include <iostream>
using namespace std;

class Monster : public GameObject
{

public:
	Monster(int startX, int startY, int distance);
	void move();
	char getShape();

	~Monster();
};

