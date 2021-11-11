#pragma once
#include "GameObject.h"
#include "ConsoleHelper.h"
#include <iostream>
#include <string>
using namespace std;

class Human : public GameObject
{
public:
	Human(int startX, int startY, int distance);
	void move();
	char getShape();

	~Human();
};
