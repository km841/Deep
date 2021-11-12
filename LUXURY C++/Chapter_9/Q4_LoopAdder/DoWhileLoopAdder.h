#pragma once
#include <iostream>
#include <string>
#include "LoopAdder.h"
using namespace std;

class DoWhileLoopAdder : public LoopAdder
{
public:
	DoWhileLoopAdder(string name = "") : LoopAdder(name) {}
	int calculate();

};

