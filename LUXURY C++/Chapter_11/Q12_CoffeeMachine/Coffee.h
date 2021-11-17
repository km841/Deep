#pragma once
#include "Container.h"
class Coffee : public Container
{
public:
	Coffee(string name) : Container(name) {}
	string getName() { return "Coffee"; }
};

