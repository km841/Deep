#pragma once
#include <iostream>
#include <string>
#include "ConsoleHelper.h"
#include "GameObject.h"
#include "Human.h"
#include "Monster.h"
#include "Food.h"


using namespace std;

class Map
{
	GameObject** obj;
	char** map;

public:
	Map();
	void init();
	void printMap();
	bool rendering();

	~Map();



};

