#pragma once
#include <iostream>
#include <string>
#include "LoopAdder.h"
using namespace std;

class WhileLoopAdder : public LoopAdder
{	
public:
	WhileLoopAdder(string name) : LoopAdder(name) {}
	int calculate();
};

