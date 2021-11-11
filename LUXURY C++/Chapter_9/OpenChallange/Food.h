#pragma once
#include "GameObject.h"
#include <iostream>
using namespace std;

class Food : public GameObject
{
	int movCnt, currCnt;
public:
	Food(int startX, int startY, int distance);

	void move();
	char getShape();

	~Food();

	
};

