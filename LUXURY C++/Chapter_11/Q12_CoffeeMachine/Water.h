#pragma once
#include "Container.h"
class Water : public Container
{

public:
	Water(string name) : Container(name) {}
	string getName() { return "Water"; }
};

