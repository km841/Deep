#pragma once
#include "Container.h"
class Sugar : public Container
{
public:
	Sugar(string name) : Container(name) {}
	string getName() { return "Sugar"; }
};

