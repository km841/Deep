#pragma once
#include "Container.h"
class Cup : public Container
{
public:
	Cup(string name) : Container(name) {}
	string getName() { return "Cup"; }
};

