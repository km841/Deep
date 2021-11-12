#pragma once
#include <iostream>
#include <string>
#include "LoopAdder.h"

class ForLoopAdder : public LoopAdder
{
public:
	ForLoopAdder(string name = "") : LoopAdder(name) {}
	int calculate();
};

