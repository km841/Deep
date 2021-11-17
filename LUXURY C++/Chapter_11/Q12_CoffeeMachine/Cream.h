#pragma once
#include "Container.h"
class Cream : public Container
{
public:
	Cream(string name) : Container(name) {}
	string getName() { return "Cream"; }
};

