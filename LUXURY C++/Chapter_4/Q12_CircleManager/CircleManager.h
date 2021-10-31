#pragma once
#include "Circle.h"
class CircleManager
{
	Circle* p;
	int size;

public:
	CircleManager(int size);
	~CircleManager();

	void searchByName();
	void searchByArea();
};

